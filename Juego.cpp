#include "Juego.h"
#include <iostream>
#include "Menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;

Juego::Juego() : m_window(VideoMode(1080,520), "Invación Zombie") {
	m_fps = 60;
	// limite de fps
	m_window.setFramerateLimit(m_fps);
	m_escena = new Menu(); // escena principal
}
/// metodo principal
void Juego::Jugar ( ) {
	/// Bucle Principal
	while(m_window.isOpen()) {
		m_cronometro = m_reloj.getElapsedTime(); // obtengo tiempo transcurrido
		if(m_cronometro.asSeconds() > 1/m_fps) { // 1 segundo dividido 60 fps
			ProcesarEventos();
			m_reloj.restart(); // reinicio el reloj
		}
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
	// Procesar eventos
	Event evento;
	while(m_window.pollEvent(evento)) {
		if(evento.type == Event::Closed)
			m_window.close();
	}
	
}
void Juego::Actualizar ( ) {
	m_escena->Actualizar(*this);
}
void Juego::Dibujar () {
	m_escena->Dibujar(m_window);
}

void Juego::CambiarEscena (Escena *Proxima_Escena) {
	m_proxima_escena = Proxima_Escena;
}

int & Juego::ObtenerFps ( ) {
	return m_fps;
}

