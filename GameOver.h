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
#include "GameOver.h"
#include <SFML/Audio/Music.hpp>

class GameOver : public Escena {
public:
	GameOver(int &volumen, Resources *recursos, DatosDePartida *data);
	void Actualizar (Juego & juego);
	void Dibujar (sf::RenderWindow & window);
	void Finalizar();
	void CambiarVolumenMusica(float vol);
private:
	sf::Sprite m_gameOver;
	Music m_musica_gameOver;
	Sound m_voz_gameover;
	sf::Text m_guardarPuntaje, m_text;
	sf::IntRect m_rect;
	sf::Vector2i m_size_rect, m_pos_mouse;
	sf::Texture m_button;
	sf::Sprite m_buttonSave;
	Resources *m_recursos;
	int m_volumen;
};

#endif

