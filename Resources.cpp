#include "Resources.h"
#include "Funciones.h"

Resources::Resources ( ) : m_pos(-1), m_url("") {
	
}

/** ****************** ************ ***** TEXTURES ***** ************ ****************** **/

sf::Texture &Resources::getBala ( ) {
	m_url = "recursos/player/bala/bala.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture & Resources::getCreditos ( ) {
	m_url = "recursos/fondos/creditos/creditos.jpg";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getEnemigo_1 ( ) {
	m_url = "recursos/enemigos/enemigo1/textura_enemigo_1.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getGameOver ( ) {
	m_url = "recursos/GameOver/gameover.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getGuardarPuntajes ( ) {
	m_url = "recursos/fondos/puntajes.jpg";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getPartida ( ) {
	m_url = "recursos/fondos/escenario/fondo.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getPuntajes ( ) {
	m_url = "recursos/fondos/puntajes.jpg";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture & Resources::getSol ( ) {
	m_url = "recursos/fondos/escenario/sol.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture & Resources::getLuna ( ) {
	m_url = "recursos/fondos/escenario/luna.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getMenu ( ) {
	m_url = "recursos/fondos/fondo.jpg";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture & Resources::getCorazon ( ) {
	m_url = "recursos/player/corazon.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getEnemigo_2 ( ) {
	m_url = "recursos/enemigos/enemigo2/textura_enemigo_2.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getButtonsMenu ( ) {
	m_url = "recursos/botones/buttons.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getFondo_ciudad ( ) {
	m_url = "recursos/fondos/partida/fondos/fondo_ciudad.jpg";
	return getTexture_or_insert(m_t, m_url);
}

/// player

texture_t & Resources::getPlayerQuieto ( ) {
	m_url = "recursos/player/player_quieto.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getPlayerCamina ( ) {
	m_url = "recursos/player/player_caminar.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getPlayerGolpeQuieto ( ) {
	m_url = "recursos/player/player_golpe_quieto.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getPlayerGolpeCamina ( ) {
	m_url = "recursos/player/player_golpe_camina.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getPlayerDisparaQuieto ( ) {
	m_url = "recursos/player/player_quieto_arma.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getPlayerDisparaCamina ( ) {
	m_url = "recursos/player/player_corre_arma.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getBarraVidaEnemigo ( ) {
	m_url = "recursos/partida/vida_enemigo.png";
	return getTexture_or_insert(m_t, m_url);
}

texture_t & Resources::getBotiquin ( ) {
	m_url = "recursos/partida/botiquin.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getMuerteEnemigo ( ) {
	m_url = "recursos/enemigos/enemigo1/textura_enemigo_1_muerte.png";
	return getTexture_or_insert(m_t, m_url);
}

sf::Texture &Resources::getMuerteEnemigo2 ( ) {
	m_url = "recursos/enemigos/enemigo2/textura_enemigo_2_muerte.png";
	return getTexture_or_insert(m_t, m_url);
}

/** ****************** ************ ***** SOUNDS EFECTS ***** ************ ****************** **/

sf::SoundBuffer & Resources::getBufferEnemigo_1 ( ) {
	m_url = "recursos/musica/zombie1.wav";
	return getBuffer_or_insert(m_s, m_url);
}

sf::SoundBuffer & Resources::getBufferVozGameOver ( ) {
	m_url = "recursos/gameOver/voz_gameover.wav";
	return getBuffer_or_insert(m_s, m_url);
}

sf::SoundBuffer & Resources::getBufferGolpe ( ) {
	m_url = "recursos/musica/golpe.wav";
	return getBuffer_or_insert(m_s, m_url);
}

sf::SoundBuffer & Resources::getBufferDisparo() {
	m_url = "recursos/musica/disparo.wav";
	return getBuffer_or_insert(m_s, m_url);
}

sf::SoundBuffer & Resources::getBufferPaso() {
	m_url = "recursos/musica/paso.wav";
	return getBuffer_or_insert(m_s, m_url);
}

sf::SoundBuffer & Resources::getBufferImpacto() {
	m_url = "recursos/sounds/impacto_bala.wav";
	return getBuffer_or_insert(m_s, m_url);
}

sf::SoundBuffer & Resources::getBufferRecargaPistola() {
	m_url = "recursos/sounds/recarga_pistola.wav";
	return getBuffer_or_insert(m_s, m_url);
}

sf::SoundBuffer & Resources::getBufferCambioOpcion() {
	m_url = "recursos/sounds/cambio_opcion.wav";
	return getBuffer_or_insert(m_s, m_url);
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
	m_url = "recursos/fuentes/Cave-Story.ttf";
	return getFont_or_insert(m_f, m_url);
}

sf::Font & Resources::getFont2 ( ) {
	m_url = "recursos/fuentes/Games.ttf";
	return getFont_or_insert(m_f, m_url);
}
