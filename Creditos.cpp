#include "Creditos.h"
#include "Menu.h"

Creditos::Creditos(int &volumen, Resources *&recursos) {
	m_volumen = volumen;
	m_recursos = recursos;
	m_musica.openFromFile(m_recursos->getMusicCreditos());
	m_musica.setVolume(m_volumen);
	m_musica.play();
	m_color = {180,180,0};
	m_move = {0,1};
	m_t1.setFont(m_recursos->getFont());
	m_t1.setFillColor(m_color);
	m_t1.setPosition(400,-30);
	m_t1.setCharacterSize(90);
	m_t1.setString("Creditos");
	m_t2.setFont(m_recursos->getFont());
	m_t2.setFillColor(m_color);
	m_t2.setPosition(300,130);
	m_t2.setCharacterSize(40);
	m_t2.setString("Animacion:          Lazarte Ezequiel \n\nMusica:                Lazarte Ezequiel \n\nProgramador:   Lazarte Ezequiel \n                               Enrique Ismael \n                               Watters Francisco");
	
	m_sprite.setTexture(m_recursos->getCreditos());
	m_sprite.setPosition(0,0); 
	m_sprite.setScale(1.1,1.1);
	m_musica.setLoop(true);
}

void Creditos::Actualizar (Juego & juego) {
	m_t1.move(m_move);
	m_t2.move(m_move);
	if(m_t1.getPosition().y >= 500) { // si el texto esta por debajo de 500, respawmea arriba
		m_t1.setPosition(400,-350);
		m_t2.setPosition(300,-190);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		m_musica.stop();
		juego.CambiarEscena(new Menu(m_volumen, m_recursos));
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
