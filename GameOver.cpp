#include "GameOver.h"
#include "Menu.h"
#include "Creditos.h"

GameOver::GameOver() {
	m_text_gameOver.loadFromFile("recursos/GameOver/gameover.png");
	m_gameOver.setTexture(m_text_gameOver);
	
//	m_musica_gameOver.openFromFile("recursos/gameOver/gameover.wav");
//	m_musica_gameOver.play();
	/// sonidos
	m_voz_gameover.openFromFile("recursos/gameOver/voz_gameover.wav");
	m_voz_gameover.play();
	m_voz_gameover.setVolume(30);
	
	/// textos
	m_fuente.loadFromFile("recursos/fuentes/cave-story.ttf");
	m_t1.setFont(m_fuente);
	m_t1.setString("Precione Click para continuar");
	m_t1.setPosition(400,460);
}

void GameOver::Actualizar (Juego & juego) {
//	m_musica_gameOver.setLoop(true);
	if(Mouse::isButtonPressed(Mouse::Left)) {
//		m_musica_gameOver.stop();
		m_voz_gameover.stop();
		juego.CambiarEscena(new Creditos());
	}
}

void GameOver::Dibujar (sf::RenderWindow & window) {
	window.clear();
	window.draw(m_gameOver);
	window.draw(m_t1);
	window.display();
}


void GameOver::CambiarVolumenMusica (float vol) {
	m_musica_gameOver.setVolume(vol);
	m_voz_gameover.setVolume(vol);
}

