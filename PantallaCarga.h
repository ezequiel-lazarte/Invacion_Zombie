#ifndef PANTALLACARGA_H
#define PANTALLACARGA_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <vector>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace std;

class PantallaCarga : public Escena {
public:
	PantallaCarga();
	void Actualizar(Juego &juego);
	void Dibujar(sf::RenderWindow &window);
private:
	Clock m_reloj;
	Time m_crono;
	vector<sf::Texture> m_texturas;
	Sprite m_sprite;
	
	int m_cambiar_textura;
	
	Text m_t1;
	Font m_fuente;
};

#endif

