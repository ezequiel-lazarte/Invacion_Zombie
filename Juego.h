#ifndef JUEGO_H
#define JUEGO_H
#include "Fondo.h"
#include <SFML/Graphics.hpp>
#include "Escena.h"
#include "Resources.h"

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
	RenderWindow &getWindow();
	~Juego();
private:
	RenderWindow m_window;
	Escena *m_escena;
	Escena *m_proxima_escena = nullptr;
	Resources *m_recursos;
	int m_fps, m_volumen;
};

#endif

