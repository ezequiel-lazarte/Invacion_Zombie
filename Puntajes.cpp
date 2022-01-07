#include "Puntajes.h"
#include "Menu.h"
#include "ImputBox.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

Puntajes::Puntajes(int &volumen, Resources *recursos, bool musica_on, DatosDePartida *data)  {
	m_musica_on = musica_on;
	m_volumen = volumen;
	m_recursos = recursos;
	m_fondo.setTexture(m_recursos->getPuntajes());
	m_fondo.setScale(1.1,1.3);
	if(m_musica_on) {
		m_musica.openFromFile(m_recursos->getMusicPuntajes());
		m_musica.play();
		m_musica.setLoop(true);
		
	}
	m_data = data;
	actualizarData();
	m_titulo.setFont(m_recursos->getFont());
	
	m_titulo.setPosition(260,-30);
	m_titulo.setFillColor(sf::Color {180,0,0});
	m_titulo.setString("Mejores Puntajes");
	m_titulo.setCharacterSize(90);
}

void Puntajes::Actualizar (Juego & juego) {
	if(Keyboard::isKeyPressed(Keyboard::Escape)) {
		Finalizar();
		juego.CambiarEscena(new Menu(m_volumen, m_recursos));
	}
}

void Puntajes::CambiarVolumenMusica (float vol) {
	m_musica.setVolume(vol);
}

void Puntajes::Dibujar (sf::RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(m_fondo);
	window.draw(m_titulo);
	for(int i=0;i<m_data->getSizeData();i++) {
		window.draw(m_posiciones[i]);
	}
	window.display();
}

void Puntajes::actualizarData ( ) {
	m_posiciones.clear();
	string aux;
	Text t1;
	for(int i=0;i<5;i++) {
		aux = "Top " + to_string(i+1) + ": " + m_data->getNombrePlayer(i) + 
			" \nKills: " + to_string(m_data->getKills(i)) + " \nTiempo: " + to_string(m_data->getTiempo(i));
		t1.setFont(m_recursos->getFont());
		t1.setCharacterSize(30);
		t1.setPosition(30,85*(i+1));
		t1.setString(aux);
		t1.setFillColor(sf::Color {180,0,0});
		m_posiciones.push_back(t1);
	}
}

void Puntajes::Finalizar ( ) {
	if(m_musica_on)	m_musica.stop();
}

Puntajes::~Puntajes ( ) {
	Finalizar();
	delete m_data;
}
