#include "Puntajes.h"
#include "Menu.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

Puntajes::Puntajes()  {
	m_musica.openFromFile("recursos/musica/puntajes.wav");
	m_musica.play();
	m_fuente.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	m_titulo.setFont(m_fuente);
	
	m_binaryname = "Binarios/Puntajes.dat";
	
	m_titulo.setPosition(260,-30);
	m_titulo.setFillColor(sf::Color {180,0,0});
	m_titulo.setString("Mejores Puntajes");
	m_titulo.setCharacterSize(90);
	/// Vector de Puntajes
	m_nro_puntajes = 5;
	Puntaje aux1;
	aux1.tiempo = 0;
	aux1.nameplayer = "Vacio";
	
	for(int i=0;i<m_nro_puntajes;i++) {
		m_puntajes.push_back(aux1);
	}
	
	/// Puntajes
	string aux;
	Text t1;
	for(int i=0;i<m_nro_puntajes;i++) {
		aux = "Top " + to_string(i+1) + ": " + m_puntajes[i].nameplayer + " \nTiempo: " + to_string(m_puntajes[i].tiempo);
		t1.setFont(m_fuente);
		t1.setCharacterSize(30);
		t1.setPosition(30,85*(i+1));
		t1.setString(aux);
		t1.setFillColor(sf::Color {180,0,0});
		
		m_posiciones.push_back(t1);
	}
	/// binario
	m_archi.open(m_binaryname, ios::binary|ios::app);
	if(!m_archi.is_open()) {
		cout << "Error al abrir el archivo puntajes.dat" << endl;
	}
	LeerDatos();
}

void Puntajes::Actualizar (Juego & juego) {
	m_musica.setLoop(true);
	
	if(Keyboard::isKeyPressed(Keyboard::Escape)) {
		m_musica.stop();
		juego.CambiarEscena(new Menu());
	}
}

void Puntajes::Dibujar (sf::RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(m_titulo);
	for(int i=0;i<m_nro_puntajes;i++) {
		window.draw(m_posiciones[i]);
	}
	window.display();
}

void Puntajes::CambiarVolumenMusica (float vol) {
	m_musica.setVolume(vol);
}

void Puntajes::LeerDatos ( ) { // listo ya tengo los datos en un vector de struct Puntaje y i no hay los escribo en el binario
	
	if(m_archi.tellg()/sizeof(Puntaje) != 0) {
		char auxchar[256];
		Puntaje aux;
		for(int i=0;i<m_nro_puntajes;i++) { /// supongo que esta en una linea el puntaje y al lado su nombre con un total de 5 datos a leer
			m_archi.read(auxchar,sizeof(auxchar));
			aux.nameplayer = auxchar;
			m_archi.read(reinterpret_cast<char*>(&aux.tiempo), sizeof(aux.tiempo));
			m_puntajes[i] = aux;
		}
	} else {
		char auxchar[256];
		Puntaje aux;
		for(int i=0;i<m_nro_puntajes;i++) {
			aux = m_puntajes[i];
			strcpy(auxchar, aux.nameplayer.c_str());
			
			m_archi.write(auxchar,sizeof(auxchar));
			m_archi.write(reinterpret_cast<char*>(&aux.tiempo), sizeof(aux.tiempo));
		}
	}
	
}

void Puntajes::GuardarUnPuntajeNuevo (string nameplayer, int tiempo) {
	Puntaje aux = {nameplayer, tiempo};
	m_puntajes.push_back(aux);
	sort(m_puntajes.begin(),m_puntajes.end(), CompararPuntajes);
	m_puntajes.pop_back();
}
bool CompararPuntajes(Puntaje p1, Puntaje p2) {
	if(p1.tiempo < p2.tiempo)
		return true;
	else
		return false;
}