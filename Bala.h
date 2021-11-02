#ifndef BALA_H
#define BALA_H
#include "Entidad.h"
#include "Resources.h"

class Bala {
public:
	Bala(Resources *recursos);
	void Actualizar(sf::Vector2f pos);
	void Dibujar(sf::RenderWindow & w);
private:
	sf::Sprite m_sprite;
	sf::Vector2f m_pos;
	Resources *m_recursos;
	int m_velocidad;
};

#endif
