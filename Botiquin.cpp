#include "Botiquin.h"

Botiquin::Botiquin(Resources *&recursos) {
	m_recursos = recursos;
	m_sprite.setTexture(recursos->getBotiquin());
	m_sprite.setScale(.3, .3);
	m_dibujar = false;
	m_pos_enemigo = {0,0};
	m_caida = 0;
}

void Botiquin::setRecursos (Resources *&recursos) {
	m_recursos = recursos;
	m_sprite.setTexture(recursos->getBotiquin());
	m_dibujar = false;
}

void Botiquin::Actualizar () {
	Animaciones();
	m_caida++;
	if(m_caida % 2 == 0 && m_sprite.getPosition().y <= 480) {
		m_sprite.setPosition(m_pos_enemigo.x, m_pos_enemigo.y+20+m_caida);
	}
	
}

void Botiquin::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}

void Botiquin::Animaciones ( ) {
	
}

void Botiquin::Finalizar ( ) {
	
}

void Botiquin::setPosEnemigo (sf::Vector2f pos) {
	m_pos_enemigo = pos;
}

bool Botiquin::getDibujar ( ) {
	return m_dibujar;
}

void Botiquin::setDibujar (bool dibujar) {
	m_dibujar = dibujar;
}
