#ifndef BALA_H
#define BALA_H
#include "Entidad.h"

class Bala {
public:
	Bala();
	void Actualizar(sf::Vector2f pos);
	void Dibujar(sf::RenderWindow & w);
private:
	sf::Texture m_textura;
	sf::Sprite m_sprite;
	sf::Vector2f m_pos;
	int m_velocidad;
};

#endif
