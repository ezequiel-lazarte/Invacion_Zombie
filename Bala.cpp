#include "Bala.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

Bala::Bala (Resources *&recursos, int volumen): m_pos(0,0) {
	m_recursos = recursos;
	m_volumen = volumen;
	m_velocidad = 10;
	m_sprite.setTexture(m_recursos->getBala());
	m_sprite.setScale(0.02, 0.02);
}

void Bala::Actualizar () {
	if(m_lado == 'R') {
		m_pos = {m_pos.x+m_velocidad, m_pos.y};
	} else if(m_lado == 'L') {
		m_pos = {m_pos.x-m_velocidad, m_pos.y};
	}
	m_sprite.setPosition(m_pos);
}

void Bala::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}

void Bala::setPos (sf::Vector2f pos, char lado) {
	m_pos.x = pos.x;
	m_pos.y = pos.y+50;
	m_lado = lado;
	if(lado == 'R') {
		m_pos.x = m_pos.x+50;
		m_sprite.setPosition(m_pos);
	} else if(lado == 'L') {
		m_pos.x = m_pos.x+30;
		m_sprite.setPosition(m_pos);
	}
}

sf::Vector2f Bala::getPosition ( ) {
	return m_sprite.getPosition();
}

void Bala::finalizar ( ) {
	
}

