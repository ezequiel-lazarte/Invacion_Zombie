#include "Fondo.h"
#include <SFML/Graphics/Color.hpp>

Fondo::Fondo() : rojo(0), verde(0), azul(0) {
	GenerarFondoAleatorio();
	m_sprite.setTexture(m_textura);
	m_sprite.setPosition(0,0);
	
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
	/// colores
	rojo = 0;
	verde = 100;
	azul = 255;
	m_color_fondo = {rojo,verde,azul};
	m_nro_noches = 0;
}

void Fondo::Actualizar ( ) {
	///sol/luna
	m_sol.move(m_move_sol);
	m_move_sol.y += gravedad;
	
	if(m_sol.getPosition().x>=1100) {
		if(ultima_textura==1) { // noche
			m_nro_noches++;
			m_textura_sol.loadFromFile("recursos/fondos/escenario/luna.png");
			m_sol.setTexture(m_textura_sol);
			ultima_textura = 0;
			verde =0;
			azul =0; 
		} else { // dia
			m_textura_sol.loadFromFile("recursos/fondos/escenario/sol.png");
			m_sol.setTexture(m_textura_sol);
			ultima_textura = 1;
			verde =100;
			azul =255; 
		}
		m_color_fondo = {rojo,verde,azul}; 
		m_sol.setPosition(m_pos_sol);
		m_move_sol.y = -.2;
	}
	/// cambio de noche a dia
	if(ultima_textura==1) { // se hace de noche
		if(m_sol.getPosition().x>920 and verde>=0 and azul>=0) {
			verde -=.1;
			azul -=.255;
		}
	} else { // se hace de dia
		if(m_sol.getPosition().x>880 and verde<100 and azul<255) {
			verde +=.1*12;
			azul +=.255*12;
		}
	}
	m_color_fondo = {rojo,verde,azul};
}

void Fondo::Dibujar (sf::RenderWindow & w) {
	w.clear(m_color_fondo);
	w.draw(m_sol);
	w.draw(m_sprite);
}

int Fondo::GetNumeroNoches ( ) {
	return m_nro_noches;
}

Fondo::~Fondo ( ) {
	m_recursos = NULL;
}

void Fondo::GenerarFondoAleatorio ( ) {
	int n = numeroAleatorio();
	if(n < 25) {
		m_textura.loadFromFile("recursos/partida/fondos/decierto.png");
	} else if(n >= 25 && n <50) {
		m_textura.loadFromFile("recursos/partida/fondos/ciudad.png");
	} else if(n >= 50 && n <75) {
		m_textura.loadFromFile("recursos/partida/fondos/nieve.png");
	} else if(n >= 75 && n <100) {
		m_textura.loadFromFile("recursos/partida/fondos/campo.png");
	}
}

int Fondo::numeroAleatorio ( ) {
	srand(time(NULL));
	int num = 1+rand()%(101-1);
	return num;
}

