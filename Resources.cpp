#include "Resources.h"
#include "Funciones.h"

Resources::Resources ( ) : m_pos(-1), m_url("") {
	
}

/** ****************** ************ ***** TEXTURES ***** ************ ****************** **/

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

sf::Texture &Resources::getGameOver ( ) {
	m_texture.loadFromFile("recursos/GameOver/gameover.png");
	m_pos = 3;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getGuardarPuntajes ( ) {
	m_texture.loadFromFile("recursos/fondos/puntajes.jpg");
	m_pos = 4;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getPantallaCarga ( ) {
	return m_t[0]; //Falta armar el png del soldado
}

sf::Texture &Resources::getPartida ( ) {
	m_texture.loadFromFile("recursos/fondos/escenario/fondo.png");
	m_pos = 5;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getPuntajes ( ) {
	m_texture.loadFromFile("recursos/fondos/puntajes.jpg");
	m_pos = 6;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture & Resources::getSol ( ) {
	m_texture.loadFromFile("recursos/fondos/escenario/sol.png");
	m_pos = 7;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture & Resources::getLuna ( ) {
	m_texture.loadFromFile("recursos/fondos/escenario/luna.png");
	m_pos = 8;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getMenu ( ) {
	m_texture.loadFromFile("recursos/fondos/fondo.jpg");
	m_pos = 9;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture & Resources::getCorazon ( ) {
	m_texture.loadFromFile("recursos/player/corazon.png");
	m_pos = 10;
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

sf::Texture &Resources::getFondo_ciudad ( ) {
	m_texture.loadFromFile("recursos/fondos/partida/fondos/fondo_ciudad.jpg");
	m_pos = 13;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

/// player

texture_t & Resources::getPlayerQuieto ( ) {
	m_texture.loadFromFile("recursos/player/player_quieto.png");
	m_pos = 13;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getPlayerCamina ( ) {
	m_texture.loadFromFile("recursos/player/player_caminar.png");
	m_pos = 14;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getPlayerGolpeQuieto ( ) {
	m_texture.loadFromFile("recursos/player/player_golpe_quieto.png");
	m_pos = 15;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getPlayerGolpeCamina ( ) {
	m_texture.loadFromFile("recursos/player/player_golpe_camina.png");
	m_pos = 16;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getPlayerDisparaQuieto ( ) {
	m_texture.loadFromFile("recursos/player/player_quieto_arma.png");
	m_pos = 17;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getPlayerDisparaCamina ( ) {
	m_texture.loadFromFile("recursos/player/player_corre_arma.png");
	m_pos = 18;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getBarraVidaEnemigo ( ) {
	m_texture.loadFromFile("recursos/partida/vida_enemigo.png");
	m_pos = 19;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

texture_t & Resources::getBotiquin ( ) {
	m_texture.loadFromFile("recursos/partida/botiquin.png");
	m_pos = 20;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

/** ****************** ************ ***** SOUNDS EFECTS ***** ************ ****************** **/

sf::SoundBuffer & Resources::getBufferEnemigo_1 ( ) {
	m_buffer.loadFromFile("recursos/musica/zombie1.wav");
	m_pos = 1;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferVozGameOver ( ) {
	m_buffer.loadFromFile("recursos/gameOver/voz_gameover.wav");
	m_pos = 3;
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

sf::SoundBuffer & Resources::getBufferPaso() {
	m_buffer.loadFromFile("recursos/musica/paso.wav");
	m_pos = 9;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferImpacto() {
	m_buffer.loadFromFile("recursos/sounds/impacto_bala.wav");
	m_pos = 10;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferRecargaPistola() {
	m_buffer.loadFromFile("recursos/sounds/recarga_pistola.wav");
	m_pos = 11;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}

sf::SoundBuffer & Resources::getBufferCambioOpcion() {
	m_buffer.loadFromFile("recursos/sounds/cambio_opcion.wav");
	m_pos = 12;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}


/** ****************** ************ ***** MUSIC ***** ************ ****************** **/

string Resources::getMusicCreditos ( ) {
	m_url = "recursos/musica/creditos.wav";
	return m_url;
}

string Resources::getMusicGameOver ( ) {
	m_url = "recursos/musica/gameover.wav";
	return m_url;
}

string Resources::getMusicMenu ( ) {
	m_url = "recursos/musica/Bewitched.wav";
	return m_url;
}

string Resources::getMusicPartida ( ) {
	m_url = "recursos/musica/Lost.wav";
	return m_url;
}

string Resources::getMusicPuntajes ( ) {
	m_url = "recursos/musica/puntajes.wav";
	return m_url;
}

/** ****************** ************ ***** FONTS ***** ************ ****************** **/

sf::Font & Resources::getFont ( ) {
	m_font.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	m_pos = 0;
	return getFont_or_insert(m_f, m_font, m_pos);
}

sf::Font & Resources::getFont2 ( ) {
	m_font.loadFromFile("recursos/fuentes/Games.ttf");
	m_pos = 1;
	return getFont_or_insert(m_f, m_font, m_pos);
}
