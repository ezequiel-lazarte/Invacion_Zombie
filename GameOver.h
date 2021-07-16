#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Escena.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class GameOver : public Escena {
public:
	GameOver();
	void Actualizar (Juego & juego);
	void Dibujar (sf::RenderWindow & window);
	void Finalizar();
	void CambiarVolumenMusica(float vol);
private:
	sf::Sprite m_gameOver;
	sf::Texture m_text_gameOver;
	sf::Music m_musica_gameOver, m_voz_gameover;
	sf::Text m_t1;
	sf::Font m_fuente;
};

#endif

