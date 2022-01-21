#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H
#include "Entidad.h"
#include <vector>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Resources.h"
#include "BarraVidaEnemigo.h"
using namespace std;

class Enemigo_1 : public Entidad {
public:
	Enemigo_1(Resources *&recursos);
	void SetPosEnemigo(float x);
	void Actualizar();
	void Dibujar(sf::RenderWindow & w);
	void CambiarVolumenMusica(float vol);
	void Animaciones();
	void BajarVida();
	void Finalizar();
	void playSonidoZombie();
	void setPosPlayer(sf::Vector2f pos_player);
	void setTexture(sf::Texture &t);
	void setVida(int vida);
	void setTipoArma(int nroArma);
	void setTipoEnemigo(int tipoEnemigo);
	int getVida();
	sf::Vector2f getPos();
private:
	Resources *m_recursos;
	BarraVidaEnemigo m_barra_vida;
	sf::SoundBuffer m_sonido1;
	sf::Sound m_sound_zombie;
	sf::Vector2f m_move, m_pos_player, m_posEnemigo;
	float m_move_sprite;
	int m_tipo_arma, m_tipo_enemigo;
	bool m_move_sprite_es_cero;
};

#endif

