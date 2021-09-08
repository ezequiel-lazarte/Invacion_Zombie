#ifndef PARTIDA_H
#define PARTIDA_H
#include <SFML/Graphics.hpp>
#include "Fondo.h"
#include "Player.h"
#include "Escena.h"
#include "Juego.h"
#include "Enemigo_1.h"
#include <ctime>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Enemigo_2.h"
using namespace std;

class Juego;
using namespace sf;

class Partida : public Escena{
public:
	Partida();
	void Actualizar(Juego &juego) override;
	void CrearEnemigos();
	void Dibujar(RenderWindow &window) override;
	void CambiarVolumenMusica(float vol);
	void ActualizarPuntaje();
private:
	Color m_color_fondo;
	Fondo m_fondo_1;
	Player m_player;
	vector<Enemigo_1> m_enemigos1;
	vector<Enemigo_2> m_enemigos2;
	vector<int> m_retraso1;
	vector<int> m_retraso2;
	SoundBuffer m_buffer;
	Sound m_musica_fondo;
	Clock m_reloj;
	Time m_crono;
	Text m_vida_player, m_tiempo, m_t1;
	Font m_fuente;
	Texture m_textura_corazon;
	Sprite m_corazon;
	string nameplayer; // nombre del jugador
	float m_puntaje_actual; // me guardo el puntaje del jugador
	float m_volumen;
	int m_numeroEnemigos1, m_numeroEnemigos2;
	int aux;
	int m_posDesde, m_posHasta;
};

#endif

