#ifndef CREDITOS_H
#define CREDITOS_H
#include "Escena.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Resources.h"

using namespace sf;

class Creditos : public Escena {
public:
	Creditos(int &volumen, Resources *recursos);
	void Actualizar (Juego & juego);
	void Dibujar (sf::RenderWindow & window);
	void CambiarVolumenMusica(float vol);
private:
	Sound m_musica;
	Vector2f m_move;
	Color m_color;
	Text m_t1, m_t2;
	Sprite m_sprite;
	Resources *m_recursos;
	int m_volumen;
};

#endif

