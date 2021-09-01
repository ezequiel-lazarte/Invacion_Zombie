#include "Enemigo_1.h"
#include <SFML/System/Vector2.hpp>
#include <ctime>

Enemigo_1::Enemigo_1() {
	m_size_rect.x = 0;
	m_size_rect.y = 0;
	m_alto_sprite = 144;
	m_ancho_sprite = 144;

	m_sonido1.loadFromFile("recursos/musica/zombie1.wav");
	m_sound_zombie.setBuffer(m_sonido1);
	m_sound_zombie.setVolume(20);
	m_move_adel = 0;
	m_move_atras = 0;
	m_move = {1.3,0};
	m_danio = 80;
	m_textura.loadFromFile("recursos/enemigos/enemigo1/textura_enemigo_1.png");
	/// por ahora solo 6 texturas
	m_vida = 300;
}

void Enemigo_1::SetPosEnemigo (float x) {
	m_posEnemigo.x = x;
	m_posEnemigo.y = 412;
	if(m_posEnemigo.x <= 0 or m_posEnemigo.x >= 1080) ;
	else m_posEnemigo.x -= 1950;
	m_rect = {m_size_rect.x, m_size_rect.y,m_alto_sprite, m_ancho_sprite};
	m_sprite.setTexture(m_textura);
	m_sprite.setTextureRect(m_rect);
	m_sprite.setScale(0.75,0.75);
	m_sprite.setPosition(m_posEnemigo);
}

void Enemigo_1::Actualizar () {
	if(m_vida<=0) Finalizar();
	Animaciones();
}

void Enemigo_1::Dibujar (sf::RenderWindow & w) {
	if(m_vida>0) w.draw(m_sprite);
}

void Enemigo_1::setPosPlayer (sf::Vector2f pos_player) {
	m_pos_player = pos_player;
}

void Enemigo_1::Finalizar ( ) {
	m_sound_zombie.stop();
}

void Enemigo_1::BajarVida ( ) {
	if(m_vida>0) m_vida -= m_danio;
}

bool Enemigo_1::Ataque ( ) {
	m_rect = {m_size_rect.x+144*2,m_size_rect.y,m_alto_sprite, m_ancho_sprite};
	m_sprite.setTextureRect(m_rect);
	if(m_pos_player.y == m_sprite.getPosition().y and m_vida>0) return true;
	return false;
}

void Enemigo_1::CambiarVolumenMusica (float vol) {
	m_sound_zombie.setVolume(vol);
}

sf::Vector2f Enemigo_1::getPos ( ) {
	return m_sprite.getPosition();
}

int Enemigo_1::getVida ( ) {
	return m_vida;
}

void Enemigo_1::Animaciones ( ) {
	if(m_sprite.getPosition().x<m_pos_player.x) {
		if(m_move_adel==0) {
			m_rect = {m_size_rect.x*m_move_adel,m_size_rect.y,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_adel==1) {
			m_rect = {m_size_rect.x*m_move_adel,m_size_rect.y,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_adel==2) {
			m_rect = {m_size_rect.x*m_move_adel,m_size_rect.y,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_adel==3) {
			m_rect = {m_size_rect.x*m_move_adel,m_size_rect.y,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_adel==4) {
			m_rect = {m_size_rect.x*m_move_adel,m_size_rect.y,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_adel==5) {
			m_rect = {m_size_rect.x*m_move_adel,m_size_rect.y,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		}
		m_sprite.move(m_move);
		m_move_adel +=0.03125;
		/// reinicio el contador
		if(m_move_adel>=5) {
			m_move_adel=0;
		}
	} else if(m_sprite.getPosition().x>m_pos_player.x) {
		if(m_move_atras==0) {
			m_rect = {m_size_rect.x*m_move_atras,m_size_rect.y+144,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_atras==1) {
			m_rect = {m_size_rect.x*m_move_atras,m_size_rect.y+144,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_atras==2) {
			m_rect = {m_size_rect.x*m_move_atras,m_size_rect.y+144,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_atras==3) {
			m_rect = {m_size_rect.x*m_move_atras,m_size_rect.y+144,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_atras==4) {
			m_rect = {m_size_rect.x*m_move_atras,m_size_rect.y+144,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		} else if(m_move_atras==5) {
			m_rect = {m_size_rect.x*m_move_atras,m_size_rect.y+144,m_alto_sprite, m_ancho_sprite};
			m_sprite.setTextureRect(m_rect);
		}
		m_sprite.move(-m_move);
		m_move_atras+=0.03125;
		/// reinicio el contador
		if(m_move_atras>=5) {
			m_move_atras=0;
		}
	}
}

