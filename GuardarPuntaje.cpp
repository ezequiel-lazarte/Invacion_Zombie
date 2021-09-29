#include "GuardarPuntaje.h"
#include "Puntajes.h"
#include "Menu.h"
#include "Juego.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "ImputBox.h"
using namespace std;



GuardarPuntaje:: GuardarPuntaje(){
	abierto = false;
	
	
	m_textura_fondo.loadFromFile("recursos/fondos/puntajes.jpg");
	m_fondo.setTexture(m_textura_fondo);
	m_fondo.setScale(1.1,1.3);
	
	
	m_buffer.loadFromFile("recursos/musica/puntajes.wav");
	m_musica.setBuffer(m_buffer);
	m_musica.play();
	m_musica.setLoop(true);
	
	m_fuente.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	m_titulo.setFont(m_fuente);
	
	m_titulo.setPosition(260,-30);
	m_titulo.setFillColor(sf::Color {180,0,0});
	m_titulo.setString("Guardar Puntaje");
	m_titulo.setCharacterSize(90);

}


void GuardarPuntaje::Actualizar (Juego & juego) {
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)&& abierto ==true){
	m_musica.stop();
	juego.CambiarEscena(new Menu());
	}
}

void GuardarPuntaje::CambiarVolumenMusica(float vol){
	m_musica.setVolume(vol);
}


void GuardarPuntaje::Dibujar (sf::RenderWindow & window){
	window.clear({0,0,0});
	window.draw(m_fondo);
	window.draw(m_titulo);
	window.display();
}

void GuardarPuntaje:: Procesar_evento(sf::Event evento){
	InputText A(m_fuente, 30, sf::Color::Red);
	A.ventana(evento);
	
	
	//m_musica.stop();
	//m_juego->CambiarEscena(new Menu());
}



