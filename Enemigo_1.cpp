#include "Enemigo_1.h"
#include <cmath>
#include <SFML/Graphics/Texture.hpp>
using namespace std;

Enemigo_1::Enemigo_1(Resources *&recursos) : m_barra_vida(100, recursos) {
	m_recursos = recursos;
	m_size_rect = {0,0};
	m_alto_sprite = 144;
	m_ancho_sprite = 144;
	m_rect = {m_size_rect.x+144, m_size_rect.y, m_alto_sprite, m_ancho_sprite};
	
	m_sonido1.loadFromFile("recursos/sounds/zombie.wav");
	m_sound_zombie.setBuffer(m_sonido1);
	
	m_move_sprite = 0;
	m_move = {1.3,0};
	
	m_move_sprite_es_cero = false;
}

void Enemigo_1::SetPosEnemigo (float x) {
	m_posEnemigo.x = x;
	m_posEnemigo.y = 412;
	if(m_posEnemigo.x >= 0 and m_posEnemigo.x < 1080) m_posEnemigo.x -= 1950;
	m_sprite.setScale(0.75,0.75);
	m_sprite.setPosition(m_posEnemigo);
	
	m_barra_vida.setPosition(m_posEnemigo);
}

void Enemigo_1::Actualizar () {
	if(m_vida<=0) Finalizar();
	m_barra_vida.Actualizar();
	Animaciones();
	
	/// actualizo la pos de la barra de vida
	m_barra_vida.setPosition(m_sprite.getPosition());
	m_barra_vida.setVida(m_vida);
}

void Enemigo_1::Dibujar (sf::RenderWindow & w) {
	if(m_vida>-21) w.draw(m_sprite);
	m_barra_vida.Dibujar(w);
}

void Enemigo_1::setPosPlayer (sf::Vector2f pos_player) {
	m_pos_player = pos_player;
}

void Enemigo_1::Finalizar ( ) {
	m_sound_zombie.stop();
}

void Enemigo_1::BajarVida ( ) {
	if(m_vida>0 && m_tipo_arma == 1) m_vida -= m_danio;
	else if(m_vida>0 && m_tipo_arma == 2) m_vida -=m_danio;
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
	if(m_vida <= 0) {
		if(!m_move_sprite_es_cero) {
			m_move_sprite = 1;
			m_move_sprite_es_cero = true;
		}
		m_sprite.setTexture(m_recursos->getMuerteEnemigo());
		if(m_move_sprite == 0) m_vida = -21;
	}
	m_move_sprite += 0.03125;
	if(m_sprite.getPosition().x<m_pos_player.x) {
		m_rect = {m_size_rect.x+int(ceil(m_move_sprite)*144), m_size_rect.y, m_alto_sprite, m_ancho_sprite};
		if(m_vida > 0) m_sprite.move(m_move);
		else m_sprite.move(0,0);
	}
	if(m_sprite.getPosition().x>m_pos_player.x) {
		m_rect = {m_size_rect.x+int(ceil(m_move_sprite)*144), m_size_rect.y+144, m_alto_sprite, m_ancho_sprite};
		if(m_vida > 0) m_sprite.move(-m_move);
		else m_sprite.move(0,0);
	}
	m_sprite.setTextureRect(m_rect);
	if(m_move_sprite>=6) m_move_sprite=0;
}

void Enemigo_1::setTexture (sf::Texture &t) {
	m_sprite.setTexture(t);
}

void Enemigo_1::setVida (int vida) {
	m_vida = vida;
	
	m_barra_vida.setVida(m_vida);
	if(m_vida == 50) 
		m_barra_vida.setTipoEnemigo(1);
	if(m_vida == 100)
		m_barra_vida.setTipoEnemigo(2);
}

void Enemigo_1::setTipoArma (int nroArma) {
	m_tipo_arma = nroArma;
	if(m_tipo_arma == 1) m_danio = 1000;
	if(m_tipo_arma == 2) m_danio = 20;
}

void Enemigo_1::playSonidoZombie ( ) {
	m_sound_zombie.play();
}

