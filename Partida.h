#ifndef PARTIDA_H
#define PARTIDA_H
#include <SFML/Graphics.hpp>
#include "Fondo.h"
#include "Player.h"
#include "Escena.h"
#include "Juego.h"
#include "Enemigo_1.h"
#include "Resources.h"
#include <ctime>
#include <vector>
using namespace std;

class Juego;
using namespace sf;

class Partida : public Escena{
public:
	Partida(int &volumen, Resources *recursos);
	void Actualizar(Juego &juego) override;
	void CrearEnemigos();
	void Dibujar(RenderWindow &window) override;
	void ActualizarPuntaje();
private:
	vector<Enemigo_1> m_enemigos;
	Color m_color_fondo;
	Fondo m_fondo_1;
	Player m_player;
	Enemigo_1 enemigo;
	Sound m_musica_fondo;
	Resources *m_recursos;
	Sprite m_corazon;
	Clock m_reloj;
	Time m_crono;
	Text m_vida_player, m_tiempo, m_t1;
	string nameplayer; // nombre del jugador
	float m_puntaje_actual; // me guardo el puntaje del jugador
	int m_numeroEnemigos1, m_numeroEnemigos2, aux, m_posDesde, m_posHasta, m_volumen;
};

#endif

