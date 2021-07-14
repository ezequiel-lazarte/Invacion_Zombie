#ifndef PUNTAJES_H
#define PUNTAJES_H
#include "Escena.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <SFML/Audio/Music.hpp>
#include <fstream>
using namespace std; 

struct Puntaje {
	string nameplayer;
	int tiempo;
};

bool CompararPuntajes(Puntaje p1, Puntaje p2);

class Puntajes : public Escena {
public:
	Puntajes();
	void Actualizar (Juego & juego) override;
	void LeerDatos();
	void Dibujar (sf::RenderWindow & window) override;
	void GuardarUnPuntajeNuevo(string nameplayer, int tiempo);
	void CambiarVolumenMusica(float vol);
private:
	Music m_musica;
	Text m_titulo;
	Font m_fuente;
	int m_nro_puntajes;
	vector<Text> m_posiciones;
	string m_binaryname;
	fstream m_archi;
	vector<Puntaje> m_puntajes;
};

#endif

 
