#ifndef RESOURCES_H
#define RESOURCES_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
using namespace std;

class Resources {
public:
	Resources();
	sf::Texture &getBala();
	sf::Texture &getCreditos();
	sf::Texture &getEnemigo_1();
	sf::Texture &getFondo();
	sf::Texture &getGameOver();
	sf::Texture &getGuardarPuntajes();
	sf::Texture &getMenu();
	sf::Texture &getPantallaCarga();
	sf::Texture &getPartida();
	sf::Texture &getPlayer();
	sf::Texture &getPuntajes();
	sf::SoundBuffer &getBufferCreditos();
	sf::SoundBuffer &getBufferEnemigo_1();
	sf::SoundBuffer &getBufferGameOver();
	sf::SoundBuffer &getBufferMenu();
	sf::SoundBuffer &getBufferPartida();
	sf::SoundBuffer &getBufferPuntajes();
	sf::Font &getFont();
private:
	sf::Texture m_texture;
	sf::SoundBuffer m_buffer;
	sf::Font m_font;
	vector<sf::Texture> m_t;
	vector<sf::SoundBuffer> m_s;
	vector<sf::Font> m_f;
};

#endif
