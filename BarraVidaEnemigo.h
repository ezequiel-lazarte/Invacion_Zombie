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
	void setTipoEnemigo(int tipoEnemigo);
private:
	float m_vida, m_cambio_sprite, m_ultima_vida;
	Resources *m_recursos;
	int m_tipo_enemigo, m_tipo_enemigo_cambio_sprite;
};

#endif

