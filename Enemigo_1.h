#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H
#include "Entidad.h"
#include <vector>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
using namespace std;

class Enemigo_1 : public Entidad {
public:
	Enemigo_1();
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
	int getVida();
	sf::Vector2f getPos();
private:
	sf::SoundBuffer m_sonido1;
	sf::Sound m_sound_zombie;
	sf::Vector2f m_move, m_pos_player, m_posEnemigo;
	float m_move_sprite;
	int m_tipo_arma;
};

#endif

