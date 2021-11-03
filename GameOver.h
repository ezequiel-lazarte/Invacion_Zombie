#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Escena.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "ImputBox.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Resources.h"

class GameOver : public Escena {
public:
	GameOver(int &volumen, Resources *recursos);
	void Actualizar (Juego & juego);
	void Dibujar (sf::RenderWindow & window);
	void Finalizar();
	void CambiarVolumenMusica(float vol);
private:
	sf::Sprite m_gameOver;
	Sound m_musica_gameOver;
	Sound m_voz_gameover;
	sf::Text m_t1, m_text;
	sf::Clock m_reloj;
	sf::Time m_crono;
	sf::RenderWindow *m_window;
	Resources *m_recursos;
	int m_volumen;
};

#endif

