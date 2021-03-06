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
	texture_t &getGameOver();
	texture_t &getGuardarPuntajes();
	texture_t &getMenu();
	texture_t &getPartida();
	texture_t &getPuntajes();
	texture_t &getCorazon();
	texture_t &getSol();
	texture_t &getLuna();
	texture_t &getButtonsMenu();
	texture_t &getPlayerQuieto();
	texture_t &getPlayerCamina();
	texture_t &getPlayerGolpeQuieto();
	texture_t &getPlayerGolpeCamina();
	texture_t &getPlayerDisparaQuieto();
	texture_t &getPlayerDisparaCamina();
	texture_t &getBarraVidaEnemigo();
	texture_t &getBotiquin();
	texture_t &getFondo_ciudad();
	texture_t &getMuerteEnemigo();
	texture_t &getMuerteEnemigo2();
	///sounds
	sound_t &getBufferEnemigo_1();
	sound_t &getBufferVozGameOver();
	sound_t &getBufferGolpe();
	sound_t &getBufferDisparo();
	sound_t &getBufferPaso();
	sound_t &getBufferImpacto();
	sound_t &getBufferRecargaPistola();
	sound_t &getBufferCambioOpcion();
	/// Music
	string getMusicCreditos();
	string getMusicGameOver();
	string getMusicMenu();
	string getMusicPartida();
	string getMusicPuntajes();
	///fonts
	font_t &getFont();
	font_t &getFont2();
private:
	texture_t m_texture;
	sound_t m_buffer;
	font_t m_font;

	map<string, texture_t> m_t;
	map<string, sound_t> m_s;
	map<string, font_t> m_f;
	
	string m_url;
	int m_pos;
};

#endif
