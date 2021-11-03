#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "Partida.h"
#include <SFML/Audio/Sound.hpp>
#include "Puntajes.h"
#include "Creditos.h"
#include "PantallaCarga.h"

Menu::Menu(int &volumen, Resources *recursos){
	m_recursos = recursos;
	m_volumen = volumen;
	m_pos_mouse = {0,0};
	m_musica_inicio.setBuffer(m_recursos->getBufferMenu());
	m_musica_inicio.play();
	m_musica_inicio.setLoop(true);
	
	m_color = {0,180,0};
	m_t1.setFont(m_recursos->getFont());
	m_t1.setFillColor(m_color);
	m_t1.setString("Invasion Zombie");
	m_t1.setPosition(200,-20);
	m_t1.setCharacterSize(120);
	
	m_fondo.setTexture(m_recursos->getMenu());
	m_fondo.setPosition(0,0);
	m_fondo.setScale(1.2,1.24);
	m_musica_inicio.setVolume(30);
	
	/// Botones del menu
	m_rect = {0, 0, 600, 204}; /// {posX, posY, sizeX, sizeY}
	m_buttonPlay.setTexture(m_recursos->getButtonsMenu());
	m_buttonPlay.setTextureRect(m_rect);
	m_buttonPlay.setPosition(480, 180);
	m_buttonPlay.setScale(0.2,0.2);
	
	m_rect = {0, 200, 600, 195};
	m_buttonScores.setTexture(m_recursos->getButtonsMenu());
	m_buttonScores.setTextureRect(m_rect);
	m_buttonScores.setPosition(480, 240);
	m_buttonScores.setScale(0.2,0.2);
	
	m_rect = {0, 400, 600, 190};
	m_buttonCredits.setTexture(m_recursos->getButtonsMenu());
	m_buttonCredits.setTextureRect(m_rect);
	m_buttonCredits.setPosition(480, 300);
	m_buttonCredits.setScale(0.2,0.2);
	
	/// Textos de los botones
	
	m_color = {0,0,0};
	m_play.setFont(m_recursos->getFont());
	m_play.setString("Play");
	m_play.setFillColor(m_color);
	m_play.setPosition(520, 182);
	m_play.setCharacterSize(25);
	
	m_color = {0,0,0};
	m_scores.setFont(m_recursos->getFont());
	m_scores.setString("Puntajes");
	m_scores.setFillColor(m_color);
	m_scores.setPosition(505, 242);
	m_scores.setCharacterSize(25);
	
	m_color = {0,0,0};
	m_credits.setFont(m_recursos->getFont());
	m_credits.setString("Creditos");
	m_credits.setFillColor(m_color);
	m_credits.setPosition(505, 302);
	m_credits.setCharacterSize(25);
}
void Menu::Actualizar (Juego &juego) {
	m_pos_mouse = sf::Mouse::getPosition(juego.getWindow());
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		m_musica_inicio.stop();
		/// en juego implementar el metodo finalizar
	}
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if(485 < m_pos_mouse.x && m_pos_mouse.x < 592) {
			if(182 < m_pos_mouse.y && m_pos_mouse.y < 218) {
				m_musica_inicio.stop();
				juego.CambiarEscena(new PantallaCarga(m_volumen, m_recursos));
			}
		}
		if(485 < m_pos_mouse.x && m_pos_mouse.x < 592) {
			if(241 < m_pos_mouse.y && m_pos_mouse.y < 277) {
				m_musica_inicio.stop();
				juego.CambiarEscena(new Puntajes(m_volumen, m_recursos));
			}
		}
		if(485 < m_pos_mouse.x && m_pos_mouse.x < 592) {
			if(300 < m_pos_mouse.y && m_pos_mouse.y < 336) {
				m_musica_inicio.stop();
				juego.CambiarEscena(new Creditos(m_volumen, m_recursos));
			}
		}
		/// aca implementar para el boton salir
	}
}

void Menu::Dibujar (RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(m_fondo);
	window.draw(m_t1);
	window.draw(m_buttonPlay);
	window.draw(m_buttonScores);
	window.draw(m_buttonCredits);
	window.draw(m_play);
	window.draw(m_scores);
	window.draw(m_credits);
	window.display();
}

void Menu::CambiarVolumenMusica (float vol) {
	m_volumen = vol;
}
