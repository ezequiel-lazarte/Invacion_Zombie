#ifndef BALA_H
#define BALA_H
#include "Entidad.h"
#include "Resources.h"
#include <SFML/Audio/Sound.hpp>

class Bala : public Entidad {
public:
	Bala(Resources *&recursos, int volumen);
	void Actualizar();
	void Dibujar(sf::RenderWindow & w);
	void setPos(sf::Vector2f pos, char lado);
	void finalizar();
	sf::Vector2f getPosition();;
private:
	sf::Vector2f m_pos;
	Resources *m_recursos;
	int m_velocidad, m_volumen;
	char m_lado;
};

#endif
