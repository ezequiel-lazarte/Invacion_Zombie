#include "Fondo.h"
#include <SFML/Graphics/Color.hpp>

Fondo::Fondo() : rojo(0), verde(0), azul(0) {
	m_textura.loadFromFile("recursos/fondos/escenario/fondo.png");
	m_sprite.setTexture(m_textura);
	m_proporcion = {1560,375};/// ancho y alto
	int diferencia = 520-m_proporcion.y;
	m_sprite.setPosition(0,diferencia);
	
	
	ultima_textura = 1;
	
	// sol
	m_textura_sol.loadFromFile("recursos/fondos/escenario/sol.png");
	m_sol.setTexture(m_textura_sol);
	m_pos_sol = {-100,100};
	m_sol.setPosition(m_pos_sol);
	m_sol.setScale(2.5,2.5);
	m_move_sol = {.5,-.2};
	gravedad = 0.00016;
	
	// luna
	m_textura_luna.loadFromFile("recursos/fondos/escenario/luna.png");
	/// colores
	rojo =0;
	verde = 100;
	azul = 200;
	m_color_fondo = {rojo,verde,azul};
}

void Fondo::Actualizar ( ) {
	/// IA del sol/luna
	m_sol.move(m_move_sol);
	m_move_sol.y += gravedad;
	
	if(m_sol.getPosition().x>=1100) {
		if(ultima_textura==1) { // noche
			m_sol.setTexture(m_textura_luna);
			ultima_textura = 0;
			verde =0;
			azul =0;
			m_color_fondo = {rojo,verde,azul}; 
		} else { // dia
			m_sol.setTexture(m_textura_sol);
			ultima_textura = 1;
			verde =100;
			azul =255;
			m_color_fondo = {rojo,verde,azul}; 
		}
		m_sol.setPosition(m_pos_sol);
		m_move_sol.y = -.2;
	}
	/// cambio de noche a dia
	if(ultima_textura==1) {
		if(m_sol.getPosition().x>720 and verde>0 and azul>0) {
			verde -=.13;
			azul -=.26;
			m_color_fondo = {rojo,verde,azul}; 
		}
	} else {
		if(m_sol.getPosition().x>720 and verde<100 and azul<255) {
			verde +=.13;
			azul +=.26;
			m_color_fondo = {rojo,verde,azul}; 
		}
	}
}

void Fondo::Dibujar (sf::RenderWindow & w) {
	w.clear(m_color_fondo);
	w.draw(m_sol);
	w.draw(m_sprite);
}
