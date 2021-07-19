#ifndef CREDITOS_H
#define CREDITOS_H
#include "Escena.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

using namespace sf;

class Creditos : public Escena {
public:
	Creditos();
	void Actualizar (Juego & juego);
	void Dibujar (sf::RenderWindow & window);
	void CambiarVolumenMusica(float vol);
private:
	SoundBuffer m_buffer;
	Sound m_musica;
	Vector2f m_move;
	Color m_color;
	Text m_t1, m_t2;
	Font m_fuente;
	Texture m_textura;
	Sprite m_sprite;
};

#endif

