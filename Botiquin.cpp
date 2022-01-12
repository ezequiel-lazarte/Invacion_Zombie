#include "Botiquin.h"

Botiquin::Botiquin(Resources *&recursos) {
	m_recursos = recursos;
	m_sprite.setTexture(recursos->getBotiquin());
	
	m_size_rect = {0,0};
	m_alto_sprite = 20;
	m_ancho_sprite = 160;
	m_rect = {m_size_rect.x, m_size_rect.y, m_alto_sprite, m_ancho_sprite};
	m_sprite.setTextureRect(m_rect);
}

void Botiquin::Actualizar () {
	Animaciones();
}

void Botiquin::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}

void Botiquin::Animaciones ( ) {
	
}

void Botiquin::Finalizar ( ) {
	
}
