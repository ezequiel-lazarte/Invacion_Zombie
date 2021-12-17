#ifndef BALA_H
#define BALA_H
#include "Entidad.h"
#include "Resources.h"

class Bala {
public:
	Bala(Resources *recursos);
	void Actualizar();
	void Dibujar(sf::RenderWindow & w);
	void setPos(sf::Vector2f pos, char lado);
	sf::Vector2f getPosition();
	void finalizar();
private:
	sf::Sprite m_sprite;
	sf::Vector2f m_pos;
	Resources *m_recursos;
	int m_velocidad;
	char m_lado;
};

#endif
