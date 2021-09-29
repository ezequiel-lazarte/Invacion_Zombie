#include "Resources.h"

Resources::Resources ( ) {
	m_t = new sf::Texture[12];
	m_s = new sf::SoundBuffer[7];
	m_f = new sf::Font[1];
	m_texture.loadFromFile("recursos/player/bala/bala.png");
	*(m_t) = m_texture;
	m_texture.loadFromFile("recursos/fondos/creditos/creditos.jpg");
	*(m_t+1) = m_texture;
	m_texture.loadFromFile("recursos/enemigos/enemigo1/textura_enemigo_1.png");
	*(m_t+2) = m_texture;
	m_texture.loadFromFile("recursos/fondos/escenario/fondo.png");
	*(m_t+3) = m_texture;
	m_texture.loadFromFile("recursos/GameOver/gameover.png");
	*(m_t+4) = m_texture;
	m_texture.loadFromFile("recursos/fondos/puntajes.jpg");
	*(m_t+5) = m_texture;
	m_texture.loadFromFile("recursos/fondos/escenario/sol.png");
	*(m_t+6) = m_texture;
	m_texture.loadFromFile("recursos/fondos/escenario/luna.png");
	*(m_t+7) = m_texture;
	m_texture.loadFromFile("recursos/fondos/fondo.jpg");
	*(m_t+8) = m_texture;
	m_texture.loadFromFile("recursos/fondos/fondo.jpg");
	*(m_t+8) = m_texture;
	m_texture.loadFromFile("recursos/player/corazon.png");
	*(m_t+9) = m_texture;
	m_texture.loadFromFile("recursos/fondos/puntajes.jpg");
	*(m_t+10) = m_texture;
	m_texture.loadFromFile("recursos/enemigos/enemigo1/textura_enemigo_1.png");
	*(m_t+11) = m_texture;
	
	m_buffer.loadFromFile("recursos/musica/creditos.wav");
	*(m_s) = m_buffer;
	m_buffer.loadFromFile("recursos/musica/zombie1.wav");
	*(m_s+1) = m_buffer;
	m_buffer.loadFromFile("recursos/gameOver/gameover.wav");
	*(m_s+2) = m_buffer;
	m_buffer.loadFromFile("recursos/gameOver/voz_gameover.wav");
	*(m_s+3) = m_buffer;
	m_buffer.loadFromFile("recursos/musica/Bewitched.wav");
	*(m_s+4) = m_buffer;
	m_buffer.loadFromFile("recursos/musica/Lost.wav");
	*(m_s+5) = m_buffer;
	m_buffer.loadFromFile("recursos/musica/puntajes.wav");
	*(m_s+6) = m_buffer;
	m_font.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	*(m_f) = m_font;
}

sf::Texture &Resources::getBala ( ) {
	return m_t[0];
}

sf::Texture & Resources::getCreditos ( ) {
	return m_t[1];
}

sf::Texture &Resources::getEnemigo_1 ( ) {
	return m_t[2];
}

sf::Texture &Resources::getEnemigo_2 ( ) {
	return m_t[11];
}

sf::Texture &Resources::getFondo ( ) {
	return m_t[3];
}

sf::Texture &Resources::getGameOver ( ) {
	return m_t[4];
}

sf::Texture &Resources::getGuardarPuntajes ( ) {
	return m_t[5];
}

sf::Texture &Resources::getMenu ( ) {
	return m_t[8];
}

sf::Texture &Resources::getPantallaCarga ( ) {
	return m_t[0]; //Falta armar el png del soldado
}

sf::Texture &Resources::getPartida ( ) {
	return m_t[3];
}

sf::Texture &Resources::getPlayer ( ) {
	return m_t[0]; //Falta armar el png completo de player
}

sf::Texture &Resources::getPuntajes ( ) {
	return m_t[10];
}

sf::SoundBuffer & Resources::getBufferCreditos ( ) {
	return m_s[0];
}

sf::SoundBuffer & Resources::getBufferEnemigo_1 ( ) {
	return m_s[1];
}

sf::SoundBuffer & Resources::getBufferGameOver ( ) {
	return m_s[2];
}

sf::SoundBuffer & Resources::getBufferVozGameOver ( ) {
	return m_s[3];
}

sf::SoundBuffer & Resources::getBufferMenu ( ) {
	return m_s[4];
}

sf::SoundBuffer & Resources::getBufferPartida ( ) {
	return m_s[5];
}

sf::SoundBuffer & Resources::getBufferPuntajes ( ) {
	return m_s[6];
}

sf::Font & Resources::getFont ( ) {
	return m_f[0];
}

Resources::~Resources ( ) {
	delete []m_t;
	delete []m_s;
	delete []m_f;
}

