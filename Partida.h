#ifndef PARTIDA_H
#define PARTIDA_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Fondo.h"
#include "Player.h"
#include "Escena.h"
#include "Juego.h"
#include <SFML/Audio/Music.hpp>
#include "Enemigo_1.h"
#include <ctime>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "Puntajes.h"
using namespace std;

class Juego;
using namespace sf;

class Partida : public Escena{
public:
	Partida();
	void Actualizar(Juego &juego) override;
	void Dibujar(RenderWindow &window) override;
	void CambiarVolumenMusica(float vol);
	void ActualizarPuntaje();
private:
	Color m_color_fondo;
	Fondo m_fondo_1;
	Player m_player;
	vector<Enemigo_1> m_enemigos;
	Music m_musica_fondo;
	int m_fps;
	Clock m_reloj;
	Time m_crono;
	Text m_vida_player, m_tiempo, m_t1;
	Font m_fuente;
	/// corazon de la vida Player
	Texture m_textura_corazon;
	Sprite m_corazon;
	/// otros
	float m_volumen;
	Enemigo_1 m_enemigo;
	// Puntajes
	string nameplayer;
	float m_puntaje_actual; // me guardo el puntaje del jugador
	Puntajes m_puntaje;
};

#endif

