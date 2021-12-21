#ifndef FONDO_H
#define FONDO_H
#include "Entidad.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "Resources.h"
using namespace sf;
class Fondo : public Entidad {
public:
	Fondo();
	void Actualizar ( );
	void Dibujar (sf::RenderWindow & w);
	int GetNumeroNoches();
	~Fondo();
private:
	Vector2f m_proporcion, m_move_sol, m_pos_sol;
	Sprite m_sol;
	Color m_color_fondo;
	sf::Uint8 rojo, verde, azul;
	Texture m_fondo, m_textura_sol;
	Resources *m_recursos;
	float gravedad;
	int ultima_textura, diferencia, m_nro_noches; /// 0 para sol y 1 para luna
};

#endif

