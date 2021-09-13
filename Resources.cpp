#include "Resources.h"

Resources::Resources ( ) {
	m_texture.loadFromFile("recursos/player/bala/bala.png");
	m_t.push_back(m_texture);
	m_texture.loadFromFile("recursos/fondos/creditos/creditos.jpg");
	m_t.push_back(m_texture);
	m_texture.loadFromFile("recursos/enemigos/enemigo1/textura_enemigo_1.png");
	m_t.push_back(m_texture);
//	m_texture.loadFromFile("recursos/fondos/escenario/fondo.png");
//	m_t.push_back(m_texture);
//	m_texture.loadFromFile("recursos/fondos/escenario/sol.png");
//	m_t.push_back(m_texture);
//	m_texture.loadFromFile("recursos/fondos/escenario/luna.png");
//	m_t.push_back(m_texture);
//	m_texture.loadFromFile("recursos/GameOver/gameover.png");
//	m_t.push_back(m_texture);
//	m_texture.loadFromFile("recursos/fondos/fondo.jpg");
//	m_t.push_back(m_texture);
//	m_texture.loadFromFile("recursos/player/corazon.png");
//	m_t.push_back(m_texture);
//	m_texture.loadFromFile("recursos/fondos/puntajes.jpg");
//	m_t.push_back(m_texture);
	
//	m_buffer.loadFromFile("recursos/musica/creditos.wav");
//	m_s.push_back(m_buffer);
//	m_buffer.loadFromFile("recursos/musica/zombie1.wav");
//	m_s.push_back(m_buffer);
//	m_buffer.loadFromFile("recursos/gameOver/gameover.wav");
//	m_s.push_back(m_buffer);
//	m_buffer.loadFromFile("recursos/gameOver/voz_gameover.wav");
//	m_s.push_back(m_buffer);
//	m_buffer.loadFromFile("recursos/musica/Bewitched.wav");
//	m_s.push_back(m_buffer);
//	m_buffer.loadFromFile("recursos/musica/Lost.wav");
//	m_s.push_back(m_buffer);
//	m_buffer.loadFromFile("recursos/musica/puntajes.wav");
//	m_s.push_back(m_buffer);
	
//	m_font.loadFromFile("recursos/fuentes/Cave-Story.ttf");
//	m_f.push_back(m_font);
}

sf::Texture &Resources::getBala ( ) {
	
}

sf::Texture &Resources::getEnemigo_1 ( ) {
	return m_t[2];
}

sf::Texture &Resources::getFondo ( ) {
	
}

sf::Texture &Resources::getGameOver ( ) {
	
}

sf::Texture &Resources::getGuardarPuntajes ( ) {
	
}

sf::Texture &Resources::getMenu ( ) {
	
}

sf::Texture &Resources::getPantallaCarga ( ) {
	
}

sf::Texture &Resources::getPartida ( ) {
	
}

sf::Texture &Resources::getPlayer ( ) {
	
}

sf::Texture &Resources::getPuntajes ( ) {
	
}

sf::Texture & Resources::getCreditos ( ) {
	
}

sf::SoundBuffer & Resources::getBufferCreditos ( ) {
	
}

sf::SoundBuffer & Resources::getBufferEnemigo_1 ( ) {
	
}

sf::SoundBuffer & Resources::getBufferGameOver ( ) {
	
}

sf::SoundBuffer & Resources::getBufferMenu ( ) {
	
}

sf::SoundBuffer & Resources::getBufferPartida ( ) {
	
}

sf::SoundBuffer & Resources::getBufferPuntajes ( ) {
	
}

sf::Font & Resources::getFont ( ) {
	
}

