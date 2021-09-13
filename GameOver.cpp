#include "GameOver.h"
#include "Menu.h"
#include "Creditos.h"
#include "GuardarPuntaje.h"

GameOver::GameOver() {
	m_text_gameOver.loadFromFile("recursos/GameOver/gameover.png");
	m_gameOver.setTexture(m_text_gameOver);
	m_gameOver.setScale(1.1,1.1);
	m_gameOver.setPosition(-25,0);
	
	m_buffer1.loadFromFile("recursos/gameOver/gameover.wav");
	m_musica_gameOver.setBuffer(m_buffer1);
	m_musica_gameOver.play();
	m_musica_gameOver.setLoop(true);
	/// sonidos
	m_buffer2.loadFromFile("recursos/gameOver/voz_gameover.wav");
	m_voz_gameover.setBuffer(m_buffer2);
	m_voz_gameover.play();
	m_voz_gameover.setVolume(30);
	/// textos
	m_fuente.loadFromFile("recursos/fuentes/cave-story.ttf");
	m_t1.setFont(m_fuente);
	m_t1.setString("Haga Click para guardar el puntaje");
	m_t1.setPosition(380,460);
}

void GameOver::Actualizar (Juego & juego) {
	if(Mouse::isButtonPressed(Mouse::Left)) {
		m_musica_gameOver.stop();
		m_voz_gameover.stop();
		juego.CambiarEscena(new GuardarPuntaje());
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

void GameOver::Finalizar ( ) {
	m_musica_gameOver.stop();
	m_voz_gameover.stop();
}

