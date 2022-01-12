#ifndef BOTIQUIN_H
#define BOTIQUIN_H
#include "Entidad.h"
#include "Resources.h"

class Botiquin : public Entidad {
public:
	Botiquin();
	Botiquin(Resources *&recursos);
	void setRecursos(Resources *&recursos);
	void Actualizar();
	void Dibujar(sf::RenderWindow & w);
	void Animaciones();
	void setPosEnemigo(sf::Vector2f pos);
	void Finalizar();
	void setDibujar(bool dibujar);
	bool getDibujar();
private:
	sf::Vector2f m_pos_enemigo;
	Resources *m_recursos;
	bool m_dibujar;
	int m_caida;
};

#endif

