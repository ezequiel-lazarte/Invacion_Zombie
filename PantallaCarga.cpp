#include "PantallaCarga.h"
#include <SFML/Graphics/Texture.hpp>
#include "Partida.h"
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include "Resources.h"
using namespace std;
using namespace sf;
PantallaCarga::PantallaCarga(int &volumen, Resources *recursos) {
	m_volumen = volumen;
	m_recursos = recursos;
	sf::Texture aux;
	for(int i=0;i<8;i++) {
		aux.loadFromFile("recursos/pantallacarga/soldado/sprite_"+to_string(i+1)+".png");
		m_texturas.push_back(aux);
	}
	m_sprite.setTexture(m_texturas[0]);
	m_sprite.setPosition(835,400);
	m_sprite.setScale(.3,.3);
	m_cambiar_textura = 0;
	m_t1.setFont(m_recursos->getFont());
	m_t1.setString("Cargando...");
	m_t1.setFillColor(Color::Red);
	m_t1.setCharacterSize(40);
	m_t1.setPosition(480,440);
}

void PantallaCarga::Actualizar (Juego & juego) {
	if(m_crono.asSeconds() >= 0) juego.CambiarEscena(new Partida(m_volumen, m_recursos));
	m_sprite.setTexture(m_texturas[m_cambiar_textura]);
	if(m_cambiar_textura>=7) m_cambiar_textura=0;
	m_cambiar_textura +=1;
	m_crono = m_reloj.getElapsedTime();
}

void PantallaCarga::Dibujar (sf::RenderWindow & window) {
	window.clear();
	window.draw(m_sprite);
	window.draw(m_t1);
	window.display();
}
