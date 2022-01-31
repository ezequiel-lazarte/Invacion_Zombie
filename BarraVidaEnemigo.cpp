#include "BarraVidaEnemigo.h"
#include <iostream>

BarraVidaEnemigo::BarraVidaEnemigo(int vida, Resources *&recursos) {
	m_recursos = recursos;
	m_alto_sprite = 20;
	m_ancho_sprite = 160;
	m_size_rect = {0,0};
	m_rect = {m_size_rect.x, m_size_rect.y, m_ancho_sprite, m_alto_sprite};
	
	m_vida = vida;
	
	m_sprite.setTexture(m_recursos->getBarraVidaEnemigo());
	m_sprite.setTextureRect(m_rect);
	m_sprite.setScale(.5, .5);
}

void BarraVidaEnemigo::Actualizar ( ) {
	if(m_vida > m_vida_inicial*0.9 && m_vida <= m_vida_inicial*1) {
		m_rect = {m_size_rect.x, m_size_rect.y = 1*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.8 && m_vida <= m_vida_inicial*0.9) {
		m_rect = {m_size_rect.x, m_size_rect.y = 2*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.7 && m_vida <= m_vida_inicial*0.8) {
		m_rect = {m_size_rect.x, m_size_rect.y = 3*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.6 && m_vida <= m_vida_inicial*0.7) {
		m_rect = {m_size_rect.x, m_size_rect.y = 4*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.5 && m_vida <= m_vida_inicial*0.6) {
		m_rect = {m_size_rect.x, m_size_rect.y = 5*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.4 && m_vida <= m_vida_inicial*0.5) {
		m_rect = {m_size_rect.x, m_size_rect.y = 7*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.3 && m_vida <= m_vida_inicial*0.4) {
		m_rect = {m_size_rect.x, m_size_rect.y = 9*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.2 && m_vida <= m_vida_inicial*0.3) {
		m_rect = {m_size_rect.x, m_size_rect.y = 11*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > m_vida_inicial*0.1 && m_vida <= m_vida_inicial*0.2) {
		m_rect = {m_size_rect.x, m_size_rect.y = 12*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida > 0 && m_vida <= m_vida_inicial*0.1) {
		m_rect = {m_size_rect.x, m_size_rect.y = 14*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
	if(m_vida <= 0) {
		m_rect = {m_size_rect.x, m_size_rect.y = 16*20, m_ancho_sprite, m_alto_sprite};
		m_sprite.setTextureRect(m_rect);
	}
}

void BarraVidaEnemigo::Dibujar (sf::RenderWindow & w) {
	if(m_vida > 0)
		w.draw(m_sprite);
}

void BarraVidaEnemigo::setVida (int vida) {
	m_vida = vida;
}

void BarraVidaEnemigo::setPosition (sf::Vector2f pos) {
	m_sprite.setPosition(pos.x+12, pos.y-10);
}

