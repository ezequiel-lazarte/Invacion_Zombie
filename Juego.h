#ifndef JUEGO_H
#define JUEGO_H
#include "Fondo.h"
#include <SFML/Graphics.hpp>
#include "Escena.h"
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
using namespace sf;
class Escena;

class Juego {
public:
	Juego();
	void Jugar();
	void ProcesarEventos();
	void Actualizar();
	void Dibujar();
	void CambiarEscena(Escena *Proxima_Escena);
	int & ObtenerFps();
private:
	RenderWindow m_window;
	Escena *m_escena;
	Escena *m_proxima_escena = nullptr;
	int m_fps;
	Clock m_reloj;
	Time m_cronometro;
	
};

#endif

