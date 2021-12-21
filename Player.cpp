#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace std;
using namespace sf;

Player::Player(int &volumen, Resources *recursos) {
	m_recursos = recursos;
	m_volumen = volumen*0.5;
	
	m_disparo.setBuffer(m_recursos->getBufferDisparo());
	m_disparo.setVolume(m_volumen);
	m_golpe.setBuffer(m_recursos->getBufferGolpe());
	m_golpe.setVolume(m_volumen);
	m_paso.setBuffer(m_recursos->getBufferPaso());
	m_paso.setVolume(m_volumen+90);
	
	string recurso;
	m_arma = 1;
	sf::Texture textura;
	for(int i=0;i<6;i++) { 
		/// adelante
		recurso = "recursos/player/player_ade/cam_adel"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_adel.push_back(textura);
		///atras
		recurso = "recursos/player/player_atras/cam_atras"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_atras.push_back(textura);
		/// ataque adelante
		recurso = "recursos/player/player_ataque_adel/sprite_"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_ataque_adel.push_back(textura);
		/// ataque atras
		recurso = "recursos/player/player_ataque_atras/sprite_"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_ataque_atras.push_back(textura);
	}
	for(int i=0;i<4;i++) { /// 0 y 1 son atras, 2 y 3 son adel
		/// Quieto
		recurso = "recursos/player/player_quieto/sprite_"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_quieto.push_back(textura);
	}
	
	m_alto_sprite = 320/3;
	m_ancho_sprite = 320/5;
	m_move = {4,0};
	m_gravedad = 6;
	m_pos_inicial.x = 1080/2;
	m_pos_inicial.y = 520-m_alto_sprite*.9;
	m_sprite.setTexture(m_texturas_adel[0]);
	m_sprite.setScale(.3,.3);
	m_sprite.setPosition(m_pos_inicial);
	
	adel=0;
	atras = 0;
	
	m_vida = 100;
	m_danio = 1;
	
	m_cambiar_textura=0;
	m_ultima_tecla =0;
	m_lado = 'L';
}

void Player::Actualizar () {
	if(Keyboard::isKeyPressed(Keyboard::A)) { /// 0 para la A y 1 para la D
		m_ultima_tecla = 0;
		m_lado = 'L';
	} else if(Keyboard::isKeyPressed(Keyboard::D)) {
		m_ultima_tecla = 1;
		m_lado = 'R';
	}
	/// si el jugador toca el num 1 se ponen los puños si usa el 2 se pone el arma
	if(Keyboard::isKeyPressed(Keyboard::Num1)) {
		m_arma = 1;
		/// se saca el arma y se dejan los puños
	}
	if(Keyboard::isKeyPressed(Keyboard::Num2)) {
		m_arma = 2;
		/// se pone el arma
	}
	sf::Vector2f player_pos = m_sprite.getPosition();
	MovimientoQuieto();
	MovimientoGolpea();
	MovimientoGolpeaCamina();
	MovimientoCamina();
	for(auto it=m_balas.begin(); it != m_balas.end(); it++) {
		it->Actualizar();
		if(it->getPosition().x > 1090 || it->getPosition().x < 0) {
			it = m_balas.erase(it);
			it--;
		}
	}
	if(m_arma == 2 && Keyboard::isKeyPressed(Keyboard::F)) {
		m_disparo.play();
		generarDisparo();
	}
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
	int limite_x = 1080-m_ancho_sprite;
	
	if(player_pos.x < -35) player_pos.x = -35;
	if(player_pos.x > limite_x) player_pos.x = limite_x;
	if(player_pos.y > m_pos_inicial.y) player_pos.y = m_pos_inicial.y;
	m_sprite.setPosition(player_pos);
}

void Player::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
	/// la bala se tendria que dibujar cuando se dispare
	for(int i=0; i<m_balas.size(); i++) {
		m_balas[i].Dibujar(w);
	}
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
}

void Player::BajarVida ( ) {
	if(m_vida>=0) m_vida -= m_danio;
	if(m_vida<0) m_vida = 0;
}

int Player::getVida ( ) {
	return m_vida;
}

void Player::MovimientoGolpea ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and m_ultima_tecla == 1) {
		m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		
		m_cambiar_textura +=0.125;
		if(m_cambiar_textura>=5) m_cambiar_textura=0;
		m_ultima_tecla = 1;
		m_lado = 'R';
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and m_ultima_tecla == 0) {
		m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		
		m_cambiar_textura +=0.125;
		if(m_cambiar_textura>=5) m_cambiar_textura=0;
		m_ultima_tecla = 0;
		m_lado = 'L';
	}
	
}

void Player::MovimientoGolpeaCamina ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		m_sprite.move(m_move);
		
		m_cambiar_textura +=0.125;
		if(m_cambiar_textura>=5) m_cambiar_textura=0;
		m_ultima_tecla = 1;
		m_lado = 'R';
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		m_sprite.move(-m_move);
		m_cambiar_textura +=0.125;
		if(m_cambiar_textura>=5) m_cambiar_textura=0;
		
		m_ultima_tecla = 0;
		m_lado = 'L';
	}
}

void Player::MovimientoCamina ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		m_sprite.setTexture(m_texturas_adel[adel]);
		m_sprite.move(m_move);
		adel +=0.125;
		if(adel>=5) adel=0;
		atras = 0;
		
		m_ultima_tecla = 1;
		m_lado = 'R';
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		m_sprite.setTexture(m_texturas_atras[atras]);
		
		m_sprite.move(-m_move);
		atras +=0.125;
		if(atras>=5) atras=0;
		adel = 0;
		
		m_ultima_tecla = 0;
		m_lado = 'L';
	}
}

void Player::MovimientoQuieto ( ) {
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F) and !sf::Keyboard::isKeyPressed(sf::Keyboard::A) and m_ultima_tecla==0) {
		m_sprite.setTexture(m_texturas_quieto[adel]);
		
		adel +=0.0625;
		if(adel>=2) adel=0;
		atras = 2;
		
		m_ultima_tecla = 0;
		m_lado = 'L';
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F) and m_ultima_tecla==1) {
		m_sprite.setTexture(m_texturas_quieto[atras]);
		
		atras +=0.0625;
		if(atras>=4) atras=2;
		adel = 0;
		
		m_ultima_tecla = 1;
		m_lado = 'R';
	}
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

void Player::borrarBala (vector<Bala>::iterator it) {
	if(it != m_balas.end()) m_balas.erase(it);
}

void Player::sonidoPaso () {
	m_paso.play();
}

sf::Vector2f Player::getPosInicial ( ) {
	return m_pos_inicial;
}

