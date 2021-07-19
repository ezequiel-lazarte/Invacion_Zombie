#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "Partida.h"
#include <SFML/Audio/Sound.hpp>
#include "Puntajes.h"
#include "Creditos.h"
#include "PantallaCarga.h"

Menu::Menu(){
	/// musica
	m_buffer.loadFromFile("recursos/musica/Bewitched.wav");
	m_musica_inicio.setBuffer(m_buffer);
	m_musica_inicio.play();
	m_musica_inicio.setLoop(true);
	/// titulo
	m_color = {0,180,0};
	m_fuente.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	m_t1.setFont(m_fuente);
	m_t1.setFillColor(m_color);
	m_t1.setString("Invacion Zombie");
	m_t1.setPosition(200,-20);
	m_t1.setCharacterSize(120);
	/// Text 2
	m_color2 = {180,0,0};
	m_t2.setFont(m_fuente);
	m_t2.setFillColor(m_color2);
	m_t2.setString("Click para jugar!!!");
	m_t2.setPosition(360,420);
	m_t2.setCharacterSize(50);
	/// text Puntajes
	m_color3 = {0,150,180};
	m_t3.setFont(m_fuente);
	m_t3.setFillColor(m_color3);
	m_t3.setString("Pulsa \"P\" \npara ver \nlos mejores \npuntajes");
	m_t3.setPosition(30,260);
	m_t3.setCharacterSize(35);
	/// texto creditos
	m_color4 = {150,0,180};
	m_t4.setFont(m_fuente);
	m_t4.setFillColor(m_color4);
	m_t4.setString("Pulsa \"H\" \npara ver \nlos creditos");
	m_t4.setPosition(900,260);
	m_t4.setCharacterSize(35);
	/// Fondo
	m_textura_fondo.loadFromFile("recursos/fondos/fondo.jpg");
	m_fondo.setTexture(m_textura_fondo);
	m_fondo.setPosition(0,0);
	m_fondo.setScale(1.2,1.24);
	
}
void Menu::Actualizar (Juego &juego) {
	if(m_mouse.isButtonPressed(m_mouse.Left)) {
		m_musica_inicio.stop();
		juego.CambiarEscena(new PantallaCarga());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		m_musica_inicio.stop();
		juego.CambiarEscena(new Puntajes());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		m_musica_inicio.stop();
		juego.CambiarEscena(new Creditos());
	}
}

void Menu::Dibujar (RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(m_fondo);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.draw(m_t4);
	window.display();
}

void Menu::CambiarVolumenMusica (float vol) {
	m_musica_inicio.setVolume(vol);
}

