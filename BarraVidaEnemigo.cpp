#include "BarraVidaEnemigo.h"

BarraVidaEnemigo::BarraVidaEnemigo(int vida, Resources *&recursos) {
	m_recursos = recursos;
	m_alto_sprite = 20;
	m_ancho_sprite = 160;
	m_size_rect = {0,0};
	m_rect = {m_size_rect.x, m_size_rect.y, m_ancho_sprite, m_alto_sprite};
	
	m_vida = vida;
	m_cambio_sprite = m_ultima_vida = 0;
	
	m_sprite.setTexture(m_recursos->getBarraVidaEnemigo());
	m_sprite.setTextureRect(m_rect);
	m_sprite.setScale(.5, .5);
}

void BarraVidaEnemigo::Actualizar ( ) {
	if(m_vida < m_ultima_vida-m_cambio_sprite) {
		m_rect = {m_size_rect.x, m_size_rect.y+20, m_alto_sprite, m_ancho_sprite};
		m_sprite.setTextureRect(m_rect);
		m_ultima_vida = m_vida;
	}
}

void BarraVidaEnemigo::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}


void BarraVidaEnemigo::setVida (int vida) {
	m_vida = vida;
	m_ultima_vida = vida;
	if(m_cambio_sprite == 0)
		m_cambio_sprite = vida/16;
}

void BarraVidaEnemigo::setPosition (sf::Vector2f pos) {
	m_sprite.setPosition(pos.x+12, pos.y-10);
}

