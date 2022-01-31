#ifndef BARRAVIDAENEMIGO_H
#define BARRAVIDAENEMIGO_H
#include "Entidad.h"
#include "Resources.h"

class BarraVidaEnemigo : public Entidad {
public:
	BarraVidaEnemigo(int vida, Resources *&recursos);
	void Actualizar();
	void Dibujar(sf::RenderWindow & w);
	void setVida(int vida);
	void setPosition(sf::Vector2f pos);
private:
	float m_vida, m_vida_inicial;
	Resources *m_recursos;
};

#endif

