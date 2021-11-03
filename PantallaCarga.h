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
#include "Resources.h"
using namespace std;

class PantallaCarga : public Escena {
public:
	PantallaCarga(int &volumen, Resources *recursos);
	void Actualizar(Juego &juego);
	void Dibujar(sf::RenderWindow &window);
private:
	Resources *m_recursos;
	Clock m_reloj;
	Time m_crono;
	vector<sf::Texture> m_texturas;
	Sprite m_sprite;
	Text m_t1;
	int m_cambiar_textura, m_volumen;
};

#endif

