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

using namespace std;

class Player : public Entidad {
public:
	Player();
	void Actualizar ( );
	void Dibujar (sf::RenderWindow & w);
	void Ataque();
	sf::Sprite &getSprite();
	sf::Vector2f getPos();
	void BajarVida();
	int getVida();
	void MovimientoGolpea();
	void MovimientoGolpeaCamina();
	void MovimientoCamina();
	void MovimientoQuieto();
	void Finalizar();
private:
	sf::Vector2f m_move;
	vector<sf::Texture> m_texturas_adel;
	vector<sf::Texture> m_texturas_atras;
	vector<sf::Texture> m_texturas_ataque_atras;
	vector<sf::Texture> m_texturas_ataque_adel;
	vector<sf::Texture> m_texturas_quieto; /// 0 y 1 son atras, 2 y 3 son adel
	float adel, atras; // contador para cambiar de sprite
	float m_gravedad;
	sf::Vector2f m_pos_inicial;
	int m_vida;
	float m_cambiar_textura;
	int m_ultima_tecla;
};

#endif

