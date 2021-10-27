#ifndef GUARDARPUNTAJE_H
#define GUARDARPUNTAJE_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Escena.h"
#include "Juego.h"
#include "Puntajes.h"
#include <string>

using namespace std;

class GuardarPuntaje : public Escena{
public:
	GuardarPuntaje();
	void Actualizar (Juego & juego) override;
	void Dibujar (sf::RenderWindow & window) override;
	void CambiarVolumenMusica(float vol);
	void Procesar_evento(sf::Event evento);
	Font m_fuente;
private:
	Texture m_textura_fondo;
	Sprite m_fondo;
	SoundBuffer m_buffer;
	Sound m_musica;
	Text m_titulo;
};


#endif
