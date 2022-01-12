#ifndef BOTIQUIN_H
#define BOTIQUIN_H
#include "Entidad.h"
#include "Resources.h"

class Botiquin : public Entidad {
public:
	Botiquin(Resources *&recursos);
	void Actualizar ( );
	void Dibujar (sf::RenderWindow & w);
	void Animaciones();
	void Finalizar();
private:
	sf::Vector2f m_pos_enemigo;
	Resources *m_recursos;
};

#endif

