#ifndef PUNTAJES_H
#define PUNTAJES_H
#include "Escena.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <fstream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace std;

struct Puntaje {
	string nameplayer;
};

bool CompararPuntajes(Puntaje p1, Puntaje p2);

class Puntajes : public Escena {
public:
	Puntajes();
	void Actualizar (Juego & juego) override;
	void LeerDatos();
	void Dibujar (sf::RenderWindow & window) override;
	void GuardarUnPuntajeNuevo(string nameplayer);
	void CambiarVolumenMusica(float vol);
private:
	Texture m_textura_fondo;
	Sprite m_fondo;
	SoundBuffer m_buffer;
	Sound m_musica;
	Text m_titulo;
	Font m_fuente;
	vector<Text> m_posiciones;
	string m_binaryname;
	fstream m_archi;
	vector<Puntaje> m_puntajes;
	int m_nro_puntajes;
};

#endif

 
