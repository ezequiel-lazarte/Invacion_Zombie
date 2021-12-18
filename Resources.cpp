#include "Resources.h"
#include "Funciones.h"

Resources::Resources ( ) : m_pos(-1) {
	
}

sf::Texture &Resources::getBala ( ) {
	m_texture.loadFromFile("recursos/player/bala/bala.png");
	m_pos = 0;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture & Resources::getCreditos ( ) {
	m_texture.loadFromFile("recursos/fondos/creditos/creditos.jpg");
	m_pos = 1;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getEnemigo_1 ( ) {
	m_texture.loadFromFile("recursos/enemigos/enemigo1/textura_enemigo_1.png");
	m_pos = 2;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getFondo ( ) {
	m_texture.loadFromFile("recursos/fondos/escenario/fondo.png");
	m_pos = 3;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getGameOver ( ) {
	m_texture.loadFromFile("recursos/GameOver/gameover.png");
	m_pos = 4;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getGuardarPuntajes ( ) {
	m_texture.loadFromFile("recursos/fondos/puntajes.jpg");
	m_pos = 5;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getPantallaCarga ( ) {
	return m_t[0]; //Falta armar el png del soldado
}

sf::Texture &Resources::getPartida ( ) {
	m_texture.loadFromFile("recursos/fondos/escenario/fondo.png");
	m_pos = 3;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getPlayer ( ) {
	return m_t[0]; //Falta armar el png completo de player
}

sf::Texture &Resources::getPuntajes ( ) {
	m_texture.loadFromFile("recursos/fondos/puntajes.jpg");
	m_pos = 5;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture & Resources::getSol ( ) {
	m_texture.loadFromFile("recursos/fondos/escenario/sol.png");
	m_pos = 6;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture & Resources::getLuna ( ) {
	m_texture.loadFromFile("recursos/fondos/escenario/luna.png");
	m_pos = 7;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getMenu ( ) {
	m_texture.loadFromFile("recursos/fondos/fondo.jpg");
	m_pos = 8;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture & Resources::getCorazon ( ) {
	m_texture.loadFromFile("recursos/player/corazon.png");
	m_pos = 9;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getEnemigo_2 ( ) {
	m_texture.loadFromFile("recursos/enemigos/enemigo2/textura_enemigo_2.png");
	m_pos = 11;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getButtonsMenu ( ) {
	m_texture.loadFromFile("recursos/botones/buttons.png");
	m_pos = 12;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::SoundBuffer & Resources::getBufferCreditos ( ) {
	m_buffer.loadFromFile("recursos/musica/creditos.wav");
	m_pos = 0;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferEnemigo_1 ( ) {
	m_buffer.loadFromFile("recursos/musica/zombie1.wav");
	m_pos = 1;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferGameOver ( ) {
	m_buffer.loadFromFile("recursos/gameOver/gameover.wav");
	m_pos = 2;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferVozGameOver ( ) {
	m_buffer.loadFromFile("recursos/gameOver/voz_gameover.wav");
	m_pos = 3;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferMenu ( ) {
	m_buffer.loadFromFile("recursos/musica/Bewitched.wav");
	m_pos = 4;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferPartida ( ) {
	m_buffer.loadFromFile("recursos/musica/Lost.wav");
	m_pos = 5;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferPuntajes ( ) {
	m_buffer.loadFromFile("recursos/musica/puntajes.wav");
	m_pos = 6;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferGolpe ( ) {
	m_buffer.loadFromFile("recursos/musica/golpe.wav");
	m_pos = 7;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferDisparo() {
	m_buffer.loadFromFile("recursos/musica/disparo.wav");
	m_pos = 8;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::Font & Resources::getFont ( ) {
	m_font.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	m_pos = 0;
	return getFont_or_insert(m_f, m_font, m_pos);
}
