#include "Bala.h"

Bala::Bala (Resources *recursos): m_pos(0,0) {
	m_recursos = recursos;
	m_velocidad = 3;
	m_sprite.setTexture(m_recursos->getBala());
}

void Bala::Actualizar (sf::Vector2f pos) {
	m_pos = pos;
}

void Bala::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}

