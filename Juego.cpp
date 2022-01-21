#include "Juego.h"
#include <iostream>
#include "Menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;

Juego::Juego() : m_window(VideoMode(1080,520), "Invasión Zombie") {
	m_fps = 60;
	m_volumen = 30;
	m_recursos = new Resources;
	m_window.setFramerateLimit(m_fps);
	m_window.setVerticalSyncEnabled(true);
	m_escena = new Menu(m_volumen, m_recursos);
}

void Juego::Jugar ( ) {
	while(m_window.isOpen()) {
		ProcesarEventos();
		Actualizar();
		Dibujar();
		if(m_proxima_escena) {
			delete m_escena;
			m_escena = m_proxima_escena;
			m_proxima_escena = nullptr;
		}
	}
}
void Juego::ProcesarEventos ( ) {
	Event evento;
	while(m_window.pollEvent(evento)) {
		if(evento.type == Event::Closed) m_window.close();
		else m_escena-> Procesar_evento(evento);
	}
}
void Juego::Actualizar ( ) {
	m_escena->Actualizar(*this);
}
void Juego::Dibujar () {
	m_escena->Dibujar(m_window);
}

void Juego::Finalizar ( ) {
	m_window.close();
}

RenderWindow & Juego::getWindow ( ) {
	return m_window;
}

void Juego::CambiarEscena (Escena *Proxima_Escena) {
	m_proxima_escena = Proxima_Escena;
}

Juego::~Juego ( ) {
	delete m_recursos;
	delete m_escena;
}

