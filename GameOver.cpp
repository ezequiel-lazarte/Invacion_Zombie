#include "GameOver.h"
#include "Menu.h"
#include "Creditos.h"
#include "GuardarPuntaje.h"

GameOver::GameOver(int &volumen, Resources *recursos, DatosDePartida *&data) {
	m_volumen = volumen;
	m_recursos = recursos;
	m_data = data;
	m_gameOver.setTexture(m_recursos->getGameOver());
	m_gameOver.setScale(1.1,1.1);
	m_gameOver.setPosition(-25,0); 
	
	m_musica_gameOver.openFromFile(m_recursos->getMusicGameOver());
	m_musica_gameOver.play();
	m_musica_gameOver.setVolume(m_volumen);
	m_musica_gameOver.setLoop(true);
	
	m_voz_gameover.setBuffer(m_recursos->getBufferVozGameOver());
	m_voz_gameover.play();
	m_voz_gameover.setVolume(m_volumen);
	
	m_guardarPuntaje.setFont(m_recursos->getFont());
	m_guardarPuntaje.setString("Guardar Puntaje");
	m_guardarPuntaje.setFillColor(Color::Black);
	m_guardarPuntaje.setPosition(451,458);
	
	
	m_rect = {0, 0, 600, 204}; /// {posX, posY, sizeX, sizeY}
	m_buttonSave.setTexture(m_recursos->getButtonsMenu());
	m_buttonSave.setTextureRect(m_rect);
	m_buttonSave.setPosition(415, 460);
	m_buttonSave.setScale(0.4,0.2);
	
	m_text.setFont(m_recursos->getFont());
	m_text.setString("Ingrese su usuario (hasta 10 letras):");
	m_text.setCharacterSize(25);
	m_text.setFillColor(sf::Color::Blue);
	m_text.setPosition(100,20);
}

void GameOver::Actualizar (Juego & juego) {
	m_pos_mouse = sf::Mouse::getPosition(juego.getWindow());
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if(430 < m_pos_mouse.x && m_pos_mouse.x < 638) {
			if(463 < m_pos_mouse.y && m_pos_mouse.y < 496) {
				Finalizar();
				sf::Event evento;
				juego.CambiarEscena(new GuardarPuntaje(m_volumen, m_recursos, evento, m_data));
			}
		}
	}
}

void GameOver::Dibujar (sf::RenderWindow & window) {
	window.clear();
	window.draw(m_text);
	window.draw(m_gameOver);
	window.draw(m_buttonSave);
	window.draw(m_guardarPuntaje);
	window.display();
}
void GameOver::Finalizar ( ) {
	m_musica_gameOver.stop();
	m_voz_gameover.stop();
}

