#include "BarraVidaEnemigo.h"
#include <iostream>

BarraVidaEnemigo::BarraVidaEnemigo(int vida, Resources *&recursos) {
	m_recursos = recursos;
	m_alto_sprite = 20;
	m_ancho_sprite = 160;
	m_size_rect = {0,0};
	m_rect = {m_size_rect.x, m_size_rect.y, m_ancho_sprite, m_alto_sprite};
	
	m_vida = vida;
	m_ultima_vida = 0;
	
	m_sprite.setTexture(m_recursos->getBarraVidaEnemigo());
	m_sprite.setTextureRect(m_rect);
	m_sprite.setScale(.5, .5);
	
	m_tipo_enemigo = 1;
	m_tipo_enemigo_cambio_sprite = 1;
}

void BarraVidaEnemigo::Actualizar ( ) {
	if(m_tipo_enemigo == 1)
		m_tipo_enemigo_cambio_sprite = 5;
	else if(m_tipo_enemigo == 2)
		m_tipo_enemigo_cambio_sprite = 4;
	if(m_vida < m_ultima_vida) {
		m_rect = {m_size_rect.x, m_size_rect.y += m_tipo_enemigo_cambio_sprite*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
		m_ultima_vida = m_vida;
	}
}

void BarraVidaEnemigo::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}

void BarraVidaEnemigo::setVida (int vida) {
	m_vida = vida;
	if(m_ultima_vida == 0) {
		m_ultima_vida = m_vida;
	}
}

void BarraVidaEnemigo::setPosition (sf::Vector2f pos) {
	m_sprite.setPosition(pos.x+12, pos.y-10);
}

void BarraVidaEnemigo::setTipoEnemigo (int tipoEnemigo) {
	m_tipo_enemigo = tipoEnemigo;
}

