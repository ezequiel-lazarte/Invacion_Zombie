#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"

class Juego;
class Escena {
public:
	Escena();
	virtual void Actualizar(Juego &juego)=0;
	virtual void Dibujar(sf::RenderWindow &window)=0;
private:
};

#endif

