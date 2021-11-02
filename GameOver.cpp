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
	
	m_inputText.setStyles(m_recursos->getFont(), 10);
	m_inputText.setPosition(120,50);
	m_inputText.setMaxChars(10); // no mas de 10 caracteres
	m_inputText.setSingleWord(true); // no permitir ingresar espacios, para que sea solo una palabra
	
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
	if(Mouse::isButtonPressed(Mouse::Left) and m_inputText.getSizeNamePlayer() > 0) {
		m_musica_gameOver.stop();
		m_voz_gameover.stop();
		juego.CambiarEscena(new GuardarPuntaje(m_volumen, m_recursos));
	}
}

void GameOver::Dibujar (sf::RenderWindow & window) {
	m_window = &window;
	window.clear();
	window.draw(m_text);
	window.draw(m_inputText);
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

void GameOver::Procesar_evento (Event evento) {
	while(m_window->isOpen()) {
		while(m_window->pollEvent(evento)) {
			if(evento.type == Event::Closed)
				m_window->close();	
			else if (evento.type==sf::Event::KeyPressed && evento.key.code==sf::Keyboard::Return) { // si apretó enter, se toma la palabra y se la agrega a la lista
				string string_ingresado = m_inputText.getValue(); // obtener la palabra que se ingresó
				Puntajes B(m_volumen, m_recursos);
				B.GuardarUnPuntajeNuevo(string_ingresado);
				return;
				
			} else m_inputText.processEvent(evento); // para que el texto tome las teclas que pulsamos
		}
		m_inputText.update(); // para que el texto se dibuje correctamente (hay que hacer esta llamada despues de processEvent y antes del draw)
	}
}
