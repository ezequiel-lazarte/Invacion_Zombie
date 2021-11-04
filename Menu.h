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

class Menu : public Escena{
public:
	Menu(int &volumen, Resources *recursos);
	void Actualizar(Juego &juego) override;
	void Dibujar(RenderWindow &window) override;
	void CambiarVolumenMusica(float vol=50);
private:
	sf::Color m_color, m_color2, m_color3, m_color4;
	sf::Sound m_musica_inicio;
	sf::Mouse m_mouse;
	sf::Texture m_button;
	sf::Text m_t1, m_play, m_credits, m_scores, m_exit;
	sf::Sprite m_fondo, m_buttonPlay, m_buttonCredits, m_buttonScores, m_buttonExit;
	sf::IntRect m_rect;
	sf::Vector2i m_size_rect, m_pos_mouse;
	Resources *m_recursos;
	int m_volumen;
};

#endif
