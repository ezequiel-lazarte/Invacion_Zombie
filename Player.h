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
	Player(int &volumen, Resources *&recursos);
	void Actualizar ();
	void Dibujar (sf::RenderWindow & w);
	void BajarVida();
	void setPlayer();
	void movimientoTeclas();
	void controlMovimientos();
	void controlArmas();
	void controlGolpear();
	void golpe();
	void disparar();
	void sonidoDisparo();
	void sonidoPaso();
	void sonidoImpacto();
	void generarDisparo();
	void borrarBala(int pos);
	void Finalizar();
	sf::Vector2f getPosInicial();
	sf::Sprite &getSprite();
	sf::Vector2f getPos();
	vector<Bala> getDisparos();
	bool armaDeFuego();
	int getArma();
	int getVida();
private:
	void animaciones();
	void animacionQuieto();
	void animacionCamina();
	void animacionGolpeaQuieto();
	void animacionGolpeaCamina();
	void animacionDisparaQuieto();
	void animacionDisparaCamina();
	sf::Vector2f m_pos_inicial;
	sf::Vector2f m_move;
	sf::Sound m_golpe, m_disparo, m_paso, m_impacto_bala, m_recarga_escopeta;
	sf::Clock m_clock;
	sf::Texture m_quieto, m_camina, m_pegaQuieto, m_pegaCamina, m_disparaQuieto, m_disparaCamina;
	size_t m_ultima_tecla;
	size_t m_vida;
	Resources *m_recursos;
	vector<Bala> m_balas;
	int m_volumen, m_alto_sprite;
	float m_cambiar_textura, m_tiempoDespues, m_tiempoAhora, m_tiempoRecarga, m_tiempoGolpear;
	float adel, atras; // contador para cambiar de sprite
	float m_gravedad, m_move_quieto, m_move_camina, m_move_pegaQuieto, m_move_pegaCamina, m_move_disparaQuieto, m_move_disparaCamina;
	int m_arma;
	char m_lado;
	bool m_si_disparo, m_dar_golpe;
};

#endif

