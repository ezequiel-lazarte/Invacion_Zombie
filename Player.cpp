#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cmath>
using namespace std;
using namespace sf;

Player::Player(int &volumen, Resources *&recursos) {
	m_recursos = recursos;
	m_volumen = volumen*0.5;
	
	m_disparo.setBuffer(m_recursos->getBufferDisparo());
	m_disparo.setVolume(m_volumen);
	m_golpe.setBuffer(m_recursos->getBufferGolpe());
	m_golpe.setVolume(m_volumen);
	m_paso.setBuffer(m_recursos->getBufferPaso());
	m_paso.setVolume(m_volumen*3);
	m_impacto_bala.setBuffer(m_recursos->getBufferImpacto());
	m_impacto_bala.setVolume(m_volumen);
	m_recarga_escopeta.setBuffer(m_recursos->getBufferRecargaPistola());
	m_recarga_escopeta.setVolume(m_volumen*2);
	
	m_quieto = m_recursos->getPlayerQuieto();
	m_camina = m_recursos->getPlayerCamina();
	m_pegaQuieto = m_recursos->getPlayerGolpeQuieto();
	m_pegaCamina = m_recursos->getPlayerGolpeCamina();
	m_disparaQuieto = m_recursos->getPlayerDisparaQuieto();
	m_disparaCamina = m_recursos->getPlayerDisparaCamina();
	
	m_arma = 1;
	
	setPlayer();
	
	adel=0;
	atras = 0;
	
	m_vida = 100;
	m_danio = 1;
	
	m_cambiar_textura=0;
	m_ultima_tecla =0;
	m_lado = 'L';
	
	m_clock.restart();
	m_tiempoAhora = m_tiempoDespues = m_tiempoRecarga = 0;
	
	m_si_disparo = m_dar_golpe = false;
	
	m_move_quieto = m_move_camina = m_move_pegaQuieto = m_move_pegaCamina = m_move_disparaQuieto = m_move_disparaCamina = m_tiempoGolpear = 0;
}

void Player::setPlayer () {
	m_alto_sprite = 320*.9;
	m_ancho_sprite = 320*.9;
	m_move = {4,0};
	m_gravedad = 6;
	m_pos_inicial.x = 1080/2;
	m_pos_inicial.y = 510-m_alto_sprite*.3;
	m_sprite.setTexture(m_recursos->getPlayerDisparaCamina());
	m_sprite.setPosition(m_pos_inicial);
	m_sprite.setScale(.3,.3);
	
	m_size_rect = {0,0};
	m_alto_sprite = 320;
	m_ancho_sprite = 320;
	m_rect = {m_size_rect.x+320, m_size_rect.y, m_alto_sprite, m_ancho_sprite};
}

void Player::Actualizar () {
	controlMovimientos();
	movimientoTeclas();
	controlArmas();
	animaciones();
	disparar();
}

void Player::Dibujar (sf::RenderWindow & w) {
	for(int i=0; i<m_balas.size(); i++) {
		m_balas[i].Dibujar(w);
	}
	w.draw(m_sprite);
}

sf::Sprite & Player::getSprite ( ) {
	return m_sprite;
}

sf::Vector2f Player::getPos ( ) {
	return m_sprite.getPosition();
}

void Player::Finalizar ( ) {
	m_golpe.stop();
	m_disparo.stop();
	m_recarga_escopeta.stop();
	m_paso.stop();
	m_impacto_bala.stop();
	for(int i; i<m_balas.size(); i++) m_balas[i].finalizar();
}

void Player::setVidaCura(int cura){
	m_vida = cura;
}

void Player::BajarVida ( ) {
	if(m_vida>=0) m_vida -= m_danio;
	if(m_vida<0) m_vida = 0;
}

int Player::getVida ( ) {
	return m_vida;
}

void Player::golpe ( ) {
	m_golpe.play();
}

void Player::sonidoDisparo ( ) {
	m_disparo.play();
}

void Player::generarDisparo () {
	m_disparo.play();
	Bala bala(m_recursos, m_volumen);
	bala.setPos(m_sprite.getPosition(), m_lado);
	m_balas.push_back(bala);
}

bool Player::armaDeFuego ( ) {
	return (m_arma==1) ? false : true;
}

int Player::getArma ( ) {
	return m_arma;
}

vector<Bala> Player::getDisparos ( ) {
	return m_balas;
}

void Player::borrarBala (int pos) {
	vector<Bala>::iterator it = m_balas.begin()+pos;
	m_balas.erase(it);
}

void Player::sonidoPaso () {
	m_paso.play();
}

void Player::sonidoImpacto ( ) {
	m_impacto_bala.play();
}

sf::Vector2f Player::getPosInicial ( ) {
	return m_pos_inicial;
}

void Player::disparar ( ) {
	m_tiempoAhora = m_clock.getElapsedTime().asSeconds();
	for(auto it=m_balas.begin(); it != m_balas.end(); it++) {
		it->Actualizar();
		if(it->getPosition().x > 1090 || it->getPosition().x < 0) {
			it = m_balas.erase(it);
			it--;
		}
	}
	if(m_arma == 2 && Keyboard::isKeyPressed(Keyboard::F) && m_tiempoAhora >= m_tiempoDespues+2) {
		generarDisparo();
		m_tiempoDespues = m_tiempoAhora;
		m_tiempoRecarga = m_tiempoAhora;
		m_si_disparo = true;
	}
	if(m_tiempoAhora >= m_tiempoRecarga+1 && m_si_disparo) {
		m_recarga_escopeta.play();
		m_si_disparo = false;
	}
}

void Player::controlArmas ( ) {
	/// si el jugador toca el num 1 se ponen los puños si usa el 2 se pone la escopeta
	if(Keyboard::isKeyPressed(Keyboard::Num1)) {
		m_arma = 1;
	}
	if(Keyboard::isKeyPressed(Keyboard::Num2)) {
		m_arma = 2;
	}
}

void Player::movimientoTeclas ( ) {
	if(Keyboard::isKeyPressed(Keyboard::A)) { /// 0 para la A y 1 para la D
		m_ultima_tecla = 0;
		m_lado = 'L';
	} else if(Keyboard::isKeyPressed(Keyboard::D)) {
		m_ultima_tecla = 1;
		m_lado = 'R';
	}
}

void Player::controlMovimientos ( ) {
	sf::Vector2f player_pos = m_sprite.getPosition();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and player_pos.y > (m_pos_inicial.y-m_alto_sprite)) {
		m_sprite.move(0,m_move.y-m_gravedad);
		m_gravedad -= .10;
	} else if(player_pos.y<m_pos_inicial.y) {
		m_gravedad = 6;
		player_pos.y += m_gravedad;
		m_gravedad = 0;
		m_sprite.setPosition(player_pos);
	}
	if(m_gravedad<0 and player_pos.y == m_pos_inicial.y) m_gravedad = 6;
	player_pos = m_sprite.getPosition();
	int limite_x = 1080-70;
	
	if(player_pos.x < -35) player_pos.x = -35;
	if(player_pos.x > limite_x) player_pos.x = limite_x;
	if(player_pos.y > m_pos_inicial.y) player_pos.y = m_pos_inicial.y;
	m_sprite.setPosition(player_pos);
}

void Player::controlGolpear ( ) {
	/// limitar al jugador a golpear por un cierto tiempo, luego inabilitarlo por unos segundos hasta que recupere las fuerzas
	if(m_clock.getElapsedTime().asSeconds() >= m_tiempoGolpear) {
		m_dar_golpe = true;
		m_tiempoGolpear = m_clock.getElapsedTime().asSeconds()+10;
	}
}

void Player::animaciones ( ) {
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 1
	   && !(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionQuieto(); /// sin arma
		m_arma = 1;
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 1 
		&& (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionCamina(); /// sin arma
		m_arma = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 1 
	   && !(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionGolpeaQuieto(); /// sin arma golpe
		m_arma = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 1 
		&& (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionGolpeaCamina(); /// sin arma golpe
		m_arma = 1;
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 2 
		&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionDisparaQuieto();
		m_arma = 2;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 2 
		&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionDisparaQuieto();
		m_arma = 2;
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 2 
		&& (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionDisparaCamina();
		m_arma = 2;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_arma == 2 
	   && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		animacionDisparaCamina();
		m_arma = 2;
	}
}

void Player::animacionQuieto ( ) {
	m_sprite.setTexture(m_quieto);
	m_move_quieto += 0.03125;
	if(m_lado == 'R') {
		m_rect = {m_size_rect.x+int(ceil(m_move_quieto)*320), m_size_rect.y, m_alto_sprite, m_ancho_sprite};
	}
	if(m_lado == 'L') {
		m_rect = {m_size_rect.x+int(ceil(m_move_quieto)*320), m_size_rect.y+320, m_alto_sprite, m_ancho_sprite};
	}
	m_sprite.setTextureRect(m_rect);
	if(m_move_quieto>=5) m_move_quieto=0;
}

void Player::animacionCamina ( ) {
	m_sprite.setTexture(m_camina);
	m_move_camina += 0.03125;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_rect = {m_size_rect.x+int(ceil(m_move_camina)*320), m_size_rect.y, m_alto_sprite, m_ancho_sprite};
		m_sprite.move(m_move);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_rect = {m_size_rect.x+int(ceil(m_move_camina)*320), m_size_rect.y+320, m_alto_sprite, m_ancho_sprite};
		m_sprite.move(-m_move);
	}
	m_sprite.setTextureRect(m_rect);
	if(m_move_camina>=5) m_move_camina=0;
}

void Player::animacionGolpeaQuieto ( ) {
	m_sprite.setTexture(m_pegaQuieto);
	m_move_pegaQuieto += 0.03125;
	if(m_lado == 'R') {
		m_rect = {m_size_rect.x+int(ceil(m_move_pegaQuieto)*320), m_size_rect.y, m_alto_sprite, m_ancho_sprite};
	}
	if(m_lado == 'L') {
		m_rect = {m_size_rect.x+int(ceil(m_move_pegaQuieto)*320), m_size_rect.y+320, m_alto_sprite, m_ancho_sprite};
	}
	m_sprite.setTextureRect(m_rect);
	if(m_move_pegaQuieto>=5) m_move_pegaQuieto=0;
}

void Player::animacionGolpeaCamina ( ) {
	m_sprite.setTexture(m_pegaCamina);
	m_move_pegaCamina += 0.03125;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_rect = {m_size_rect.x+int(ceil(m_move_pegaCamina)*320), m_size_rect.y, m_alto_sprite, m_ancho_sprite};
		m_sprite.move(m_move);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_rect = {m_size_rect.x+int(ceil(m_move_pegaCamina)*320), m_size_rect.y+320, m_alto_sprite, m_ancho_sprite};
		m_sprite.move(-m_move);
	}
	m_sprite.setTextureRect(m_rect);
	if(m_move_pegaCamina>=5) m_move_pegaCamina=0;
}

void Player::animacionDisparaQuieto ( ) {
	m_sprite.setTexture(m_disparaQuieto);
	m_move_disparaQuieto += 0.03125;
	if(m_lado == 'R') {
		m_rect = {m_size_rect.x+int(ceil(m_move_disparaQuieto)*320), m_size_rect.y, m_alto_sprite, m_ancho_sprite};
	}
	if(m_lado == 'L') {
		m_rect = {m_size_rect.x+int(ceil(m_move_disparaQuieto)*320), m_size_rect.y+320, m_alto_sprite, m_ancho_sprite};
	}
	m_sprite.setTextureRect(m_rect);
	if(m_move_disparaQuieto>=5) m_move_disparaQuieto=0;
}

void Player::animacionDisparaCamina ( ) {
	m_sprite.setTexture(m_disparaCamina);
	m_move_disparaCamina += 0.03125;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_rect = {m_size_rect.x+int(ceil(m_move_disparaCamina)*320), m_size_rect.y, m_alto_sprite, m_ancho_sprite};
		m_sprite.move(m_move);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_rect = {m_size_rect.x+int(ceil(m_move_disparaCamina)*320), m_size_rect.y+320, m_alto_sprite, m_ancho_sprite};
		m_sprite.move(-m_move);
	}
	m_sprite.setTextureRect(m_rect);
	if(m_move_disparaCamina>=5) m_move_disparaCamina=0;
}
