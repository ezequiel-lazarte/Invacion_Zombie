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
#include "Resources.h"

using namespace std;

class GuardarPuntaje : public Escena{
public:
	GuardarPuntaje(int &volumen, Resources *recursos);
	void Actualizar (Juego & juego) override;
	void Dibujar (sf::RenderWindow & window) override;
	void Procesar_evento(sf::Event evento);
	Font m_fuente;
private:
	Sprite m_fondo;
	Sound m_musica;
	Text m_titulo;
	int m_volumen;
	Resources *m_recursos;
};


#endif
