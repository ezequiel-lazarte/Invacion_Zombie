#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Resources.h"
using namespace sf;

class Menu : public Escena{
public:
	Menu(int &volumen, Resources *recursos);
	void Actualizar(Juego &juego) override;
	void Dibujar(RenderWindow &window) override;
	void CambiarVolumenMusica(float vol=0);
private:
	Text m_t1, m_t2, m_t3, m_t4;
	Color m_color, m_color2, m_color3, m_color4;
	Sound m_musica_inicio;
	Mouse m_mouse;
	Sprite m_fondo;
	Resources *m_recursos;
	int m_volumen;
};

#endif
