#include "GameOver.h"
#include "Menu.h"
#include "Creditos.h"
#include "GuardarPuntaje.h"

GameOver::GameOver(int &volumen, Resources *recursos) {
	m_recursos = recursos;
	m_gameOver.setTexture(m_recursos->getGameOver());
	m_gameOver.setScale(1.1,1.1);
	m_gameOver.setPosition(-25,0);
	
	m_musica_gameOver.setBuffer(m_recursos->getBufferGameOver());
	m_musica_gameOver.play();
	m_musica_gameOver.setLoop(true);
	/// sonidos
	m_voz_gameover.setBuffer(m_recursos->getBufferVozGameOver());
	m_voz_gameover.play();
	m_voz_gameover.setVolume(30);
	/// textos
	m_t1.setFont(m_recursos->getFont());
	m_t1.setString("Haga Click para guardar el puntaje");
	m_t1.setPosition(380,460);
	
	m_crono = m_reloj.restart();
	
	
	m_text.setFont(m_recursos->getFont());
	m_text.setString("Ingrese su usuario (hasta 10 letras):");
	m_text.setCharacterSize(25);
	m_text.setFillColor(sf::Color::Blue);
	m_text.setPosition(100,20);
}

void GameOver::Actualizar (Juego & juego) {
	m_crono = m_reloj.getElapsedTime();
	if(m_crono.asSeconds() >= 2) {
		
	}
	if(Mouse::isButtonPressed(Mouse::Left)) {
		m_musica_gameOver.stop();
		m_voz_gameover.stop();
		sf::Event evento;
		juego.CambiarEscena(new GuardarPuntaje(m_volumen, m_recursos, evento));
	}
}

void GameOver::Dibujar (sf::RenderWindow & window) {
	m_window = &window;
	window.clear();
	window.draw(m_text);
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

