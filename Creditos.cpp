#include "Creditos.h"
#include "Menu.h"

Creditos::Creditos() {
	m_buffer.loadFromFile("recursos/musica/creditos.wav");
	m_musica.setBuffer(m_buffer);
	m_musica.play();
	m_fuente.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	m_color = {180,180,0};
	m_move = {0,1};
	m_t1.setFont(m_fuente);
	m_t1.setFillColor(m_color);
	m_t1.setPosition(400,-30);
	m_t1.setCharacterSize(90);
	m_t1.setString("Creditos");
	m_t2.setFont(m_fuente);
	m_t2.setFillColor(m_color);
	m_t2.setPosition(300,130);
	m_t2.setCharacterSize(40);
	m_t2.setString("Animacion: 		 Lazarte Ezequiel \n\nMusica:				Lazarte Ezequiel \n\nProgramador:   Lazarte Ezequiel");
	
	m_textura.loadFromFile("recursos/fondos/creditos/creditos.jpg");
	m_sprite.setTexture(m_textura);
	m_sprite.setPosition(0,0);
	m_sprite.setScale(1.1,1.1);
	m_musica.setLoop(true);
}

void Creditos::Actualizar (Juego & juego) {
	m_t1.move(m_move);
	m_t2.move(m_move);
	if(m_t1.getPosition().y >= 500) { // si el texto esta por debajo de 500, respawmea arriba
		m_t1.setPosition(400,-300);
		m_t2.setPosition(300,-140);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		m_musica.stop();
		juego.CambiarEscena(new Menu());
	}
}
void Creditos::Dibujar (sf::RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(m_sprite);
	window.draw(m_t1);
	window.draw(m_t2);
	window.display();
}

void Creditos::CambiarVolumenMusica (float vol) {
	m_musica.setVolume(vol);
}
