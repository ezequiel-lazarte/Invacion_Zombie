#ifndef GUARDARPUNTAJE_H
#define GUARDARPUNTAJE_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Escena.h"
#include "Juego.h"
#include <string>

using namespace std;

class GuardarPuntaje : public Escena, sf::Text{
public:
	GuardarPuntaje();
	void Actualizar (Juego & juego) override;
	
	void Dibujar (sf::RenderWindow & window) override;
	
	void CambiarVolumenMusica(float vol);
	
	bool processEvent(const Event &event);
	
	void InputText();
	
	void setMaxChars(unsigned int max);
	
	void update();
	
	void setEditable(bool value);
	
	void setSingleWord(bool value);
	
	string getValue();
	
	void reset();
	
private:
	Texture m_textura_fondo;
	Sprite m_fondo;
	SoundBuffer m_buffer;
	Sound m_musica;
	Text m_titulo;
	Text m_textoEntrada;
	Font m_fuente;
	Clock clock;
	string value;
	bool is_down[sf::Keyboard::KeyCount];
	void TestKey(sf::Keyboard::Key k, char c);
	unsigned int max_chars;
	bool editable;
	bool single_word;
};


#endif
