#ifndef PLAYER_H
#define PLAYER_H
#include "Entidad.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Resources.h"
#include <SFML/Audio/Sound.hpp>
#include "Bala.h"

using namespace std;

class Player : public Entidad {
public:
	Player(int &volumen, Resources *recursos);
	void Actualizar ();
	void Dibujar (sf::RenderWindow & w);
	sf::Sprite &getSprite();
	sf::Vector2f getPos();
	void BajarVida();
	int getVida();
	void MovimientoGolpea();
	void MovimientoGolpeaCamina();
	void MovimientoCamina();
	void MovimientoQuieto();
	void golpe();
	void sonidoDisparo();
	void generarDisparo();
	bool armaDeFuego();
	void borrarBala(vector<Bala>::iterator it);
	vector<Bala> getDisparos();
	int getArma();
	void Finalizar();
private:
	sf::Vector2f m_pos_inicial;
	sf::Vector2f m_move;
	sf::Sound m_golpe, m_disparo;
	vector<sf::Texture> m_texturas_adel;
	vector<sf::Texture> m_texturas_atras;
	vector<sf::Texture> m_texturas_ataque_atras;
	vector<sf::Texture> m_texturas_ataque_adel;
	vector<sf::Texture> m_texturas_quieto; /// 0 y 1 son atras, 2 y 3 son adel
	size_t m_ultima_tecla;
	size_t m_vida;
	Resources *m_recursos;
	vector<Bala> m_balas;
	int m_volumen, m_alto_sprite;
	float m_cambiar_textura;
	float adel, atras; // contador para cambiar de sprite
	float m_gravedad;
	int m_arma;
	char m_lado;
};

#endif

