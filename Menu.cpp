#include "Menu.h"
#include "Resources.h"
#include "Puntajes.h"
#include "Creditos.h"
#include "PantallaCarga.h"

Menu::Menu(int volumen, Resources *resources) {
	m_resources = resources;
	m_volumen = volumen;
	m_background.setTexture(m_resources->getMenu());
	m_background.setScale(1.2,1.24);
	
	m_music.openFromFile(m_resources->getMusicMenu());
	m_music.setVolume(m_volumen);
	m_music.play();
	m_music.setLoop(true);
	
	m_cambio_opcion.setBuffer(m_resources->getBufferCambioOpcion());
	m_cambio_opcion.setVolume(m_volumen+50);
	
	/// Text
	m_color = {0,180,0};
	m_titulo.setFont(m_resources->getFont2());
	m_titulo.setFillColor(m_color);
	m_titulo.setString("Invasion Zombie");
	m_titulo.setPosition(200,20);
	m_titulo.setCharacterSize(80);
	
	m_play.setFont(m_resources->getFont2());
	m_play.setString("Jugar");
	m_play.setPosition(480, 190);
	m_play.setCharacterSize(40);
	m_play.setFillColor(sf::Color(255,255,255));
	
	m_score.setFont(m_resources->getFont2());
	m_score.setString("Puntajes");
	m_score.setPosition(440, 250);
	m_score.setCharacterSize(40);
	m_score.setFillColor(sf::Color(33,33,33));
	
	m_credits.setFont(m_resources->getFont2());
	m_credits.setString("Creditos");
	m_credits.setPosition(440, 310);
	m_credits.setCharacterSize(40);
	m_credits.setFillColor(sf::Color(33,33,33));
	
	m_exit.setFont(m_resources->getFont2());
	m_exit.setString("Salir");
	m_exit.setPosition(480, 370);
	m_exit.setCharacterSize(40);
	m_exit.setFillColor(sf::Color(33,33,33));
	
	m_ultimo_texto = 1;
	m_retraso_cambiar_opcion = 0.1;
	m_tiempo = 0+m_retraso_cambiar_opcion;
	m_reloj.restart();
}

void Menu::Actualizar (Juego &juego) {
	if(m_reloj.getElapsedTime().asSeconds() >= m_tiempo) {
		AnimacionTexto();
		m_tiempo = m_reloj.getElapsedTime().asSeconds()+m_retraso_cambiar_opcion;
	}
	ControlOpciones(juego);
}

void Menu::Dibujar (sf::RenderWindow &window) {
	window.clear(sf::Color(33,33,33));
	window.draw(m_background);
	window.draw(m_titulo);
	window.draw(m_play);
	window.draw(m_score);
	window.draw(m_credits);
	window.draw(m_exit);
	window.display();
}

void Menu::AnimacionTexto ( ) {
	m_r1 = m_g1 = m_b1 = 255;
	m_r2 = m_g2 = m_b2 = 33;
	AnimacionTextoUp();
	AnimacionTextoDown();
}

void Menu::AnimacionTextoUp ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 1) {
		m_cambio_opcion.play();
		m_play.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_exit.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 4;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 2) {
		m_cambio_opcion.play();
		m_score.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_play.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 1;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 3) {
		m_cambio_opcion.play();
		m_credits.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_score.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 2;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 4) {
		m_cambio_opcion.play();
		m_exit.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_credits.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 3;
		return;
	}
}

void Menu::AnimacionTextoDown ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 1) {
		m_cambio_opcion.play();
		m_play.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_score.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 2;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 2) {
		m_cambio_opcion.play();
		m_score.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_credits.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 3;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 3) {
		m_cambio_opcion.play();
		m_credits.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_exit.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 4;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 4) {
		m_cambio_opcion.play();
		m_exit.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_play.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 1;
		return;
	}
}

void Menu::ControlOpciones (Juego &juego) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 1) {
		Finalizar();
		juego.CambiarEscena(new PantallaCarga(m_volumen, m_resources));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 2) {
		Finalizar();
		juego.CambiarEscena(new Puntajes(m_volumen, m_resources, true));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 3) {
		Finalizar();
		juego.CambiarEscena(new Creditos(m_volumen, m_resources));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 4) {
		Finalizar();
		juego.Finalizar();
	}
}

void Menu::Finalizar ( ) {
	m_music.stop();
	m_cambio_opcion.stop();
}
