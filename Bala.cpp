#include "Bala.h"

Bala::Bala ( ): m_pos(0,0) {
	m_velocidad = 3;
	m_textura.loadFromFile("recursos/player/bala/bala.png");
	m_sprite.setTexture(m_textura);
}

void Bala::Actualizar (sf::Vector2f pos) {
	m_pos = pos;
}

void Bala::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}

