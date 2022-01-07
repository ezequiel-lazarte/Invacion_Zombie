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
#include "ImputBox.h"

using namespace std;

class GuardarPuntaje : public Escena{
public:
	GuardarPuntaje(int &volumen, Resources *&recursos, sf::Event evento, DatosDePartida *&data);
	void Actualizar (Juego & juego) override;
	void Dibujar (sf::RenderWindow & window) override;
	~GuardarPuntaje();
private:
	Sprite m_fondo;
	Text m_titulo;
	Resources *m_recursos;
	Puntajes *m_puntajes;
	InputText m_ingresoTexto;
	DatosDePartida *m_data;
	int m_volumen;
};


#endif
