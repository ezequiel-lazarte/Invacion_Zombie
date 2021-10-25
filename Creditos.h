#ifndef CREDITOS_H
#define CREDITOS_H
#include "Escena.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Resources.h"

using namespace sf;

class Creditos : public Escena {
public:
	Creditos();
	void Actualizar (Juego & juego);
	void Dibujar (sf::RenderWindow & window);
	void CambiarVolumenMusica(float vol);
	~Creditos();
private:
	SoundBuffer m_buffer;
	Sound m_musica;
	Vector2f m_move;
	Color m_color;
	Text m_t1, m_t2;
	Font m_fuente;
	Texture m_textura;
	Sprite m_sprite;
	Resources *m_resources;
};

#endif

