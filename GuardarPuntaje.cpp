#include "GuardarPuntaje.h"
#include "Puntajes.h"
#include "Menu.h"
#include "Juego.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;


GuardarPuntaje:: GuardarPuntaje(){
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
	
	m_textoEntrada.setFont(m_fuente);
	m_textoEntrada.setFillColor(sf::Color {180,0,0});
	m_textoEntrada.setPosition(260,-60);
}

void GuardarPuntaje::Actualizar (Juego & juego) {
	
	/*
	String e;
	if (sf::Event::KeyEvent::code == e ){
		
		 // para que el texto tome las teclas que pulsamos
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		//guarda puntaje
		m_musica.stop();
		juego.CambiarEscena(new Menu());
		
	}
	
	m_textoEntrada.update(); // para que el texto se dibuje correctamente (hay que hacer esta llamada despues de processEvent y antes del draw)
	*/
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		//guarda puntaje
		m_musica.stop();
		juego.CambiarEscena(new Menu());
		
	}
}

void GuardarPuntaje::CambiarVolumenMusica(float vol){
	m_musica.setVolume(vol);
}
void GuardarPuntaje::TestKey(sf::Keyboard::Key k, char c) {
	bool was_down=is_down[int(k)];
	is_down[int(k)]=sf::Keyboard::isKeyPressed(k);
	if (is_down[int(k)] && !was_down) value+=c;
}
void GuardarPuntaje::InputText(){
	for(int i=0;i<sf::Keyboard::KeyCount;i++) is_down[i]=true;
	max_chars=10;
	single_word=true;
	editable=true;
}	
bool GuardarPuntaje::processEvent(const sf::Event &event) {
	if (!editable) return false;
	if (event.type == sf::Event::TextEntered) {
		if (event.text.unicode=='\b') {
			if (value.size()) value.erase(value.size()-1,1);
		} else if (event.text.unicode>=32 && event.text.unicode<128) {
			if (!max_chars || value.size()<max_chars) 
				if (!single_word || event.text.unicode!=' ')
					value += static_cast<char>(event.text.unicode);
		}
		return true;
	}
	return false;
}

void GuardarPuntaje::setMaxChars(unsigned int max){
	max_chars = max;
}
void GuardarPuntaje::update() {
	if (editable && int(clock.getElapsedTime().asSeconds()*3)%2)
		String(value+"|");
	else 
		String(value);
}

void GuardarPuntaje::setEditable(bool value) { 
	editable=value; 
}
void GuardarPuntaje::setSingleWord(bool value) { 
	single_word=value; 
}
string GuardarPuntaje::getValue() { 
	return value; 
}
void GuardarPuntaje::reset() { 
	value.clear(); 
}

void GuardarPuntaje::Dibujar (sf::RenderWindow & window){
	window.draw(m_titulo);
	window.clear({0,0,0});
	window.draw(m_fondo);
	window.draw(m_titulo);
	window.draw(m_textoEntrada);
	window.display();
}
