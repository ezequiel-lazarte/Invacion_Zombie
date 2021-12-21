#ifndef RESOURCES_H
#define RESOURCES_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
using namespace std;

typedef sf::Texture texture_t;
typedef sf::SoundBuffer sound_t;
typedef sf::Font font_t;
typedef map<int, texture_t>::iterator iterator_t;
typedef map<int, sound_t>::iterator iterator_s;
typedef map<int, font_t>::iterator iterator_f;

class Resources {
public:
	Resources();
	/// textures
	texture_t &getBala();
	texture_t &getCreditos();
	texture_t &getEnemigo_1();
	texture_t &getEnemigo_2();
	texture_t &getFondo();
	texture_t &getGameOver();
	texture_t &getGuardarPuntajes();
	texture_t &getMenu();
	texture_t &getPantallaCarga();
	texture_t &getPartida();
	texture_t &getPlayer();
	texture_t &getPuntajes();
	texture_t &getCorazon();
	texture_t &getSol();
	texture_t &getLuna();
	texture_t &getButtonsMenu();
	texture_t &getPlayerCamina();
	///sounds
	sound_t &getBufferCreditos();
	sound_t &getBufferEnemigo_1();
	sound_t &getBufferGameOver();
	sound_t &getBufferVozGameOver();
	sound_t &getBufferMenu();
	sound_t &getBufferPartida();
	sound_t &getBufferPuntajes();
	sound_t &getBufferGolpe();
	sound_t &getBufferDisparo();
	sound_t &getBufferPaso();
	sound_t &getBufferImpacto();
	sound_t &getBufferRecargaPistola();
	///fonts
	font_t &getFont();
private:
	texture_t m_texture;
	sound_t m_buffer;
	font_t m_font;

	map<int, texture_t> m_t;
	map<int, sound_t> m_s;
	map<int, font_t> m_f;
	
	int m_pos;
};

#endif
