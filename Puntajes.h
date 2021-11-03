#ifndef PUNTAJES_H
#define PUNTAJES_H
#include "Escena.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <fstream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Resources.h"
using namespace std;

struct Puntaje {
	string nameplayer;
};

bool CompararPuntajes(Puntaje p1, Puntaje p2);

class Puntajes : public Escena {
public:
	Puntajes(int &volumen, Resources *recursos);
	void Actualizar (Juego & juego) override;
	void LeerDatos();
	void Dibujar (sf::RenderWindow & window) override;
	void GuardarUnPuntajeNuevo(string nameplayer);
	void CambiarVolumenMusica(float vol);
private:
	Sprite m_fondo;
	Sound m_musica;
	Text m_titulo;
	vector<Text> m_posiciones;
	string m_binaryname;
	fstream m_archi;
	static vector<Puntaje> m_puntajes;
	Resources *m_recursos;
	int m_nro_puntajes, m_volumen;
};

#endif

















 
