#include "Partida.h"
#include "Menu.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "GameOver.h"
#include <SFML/Graphics/Color.hpp>
#include "Enemigo_1.h"

#include <iostream>
using namespace std;
using namespace sf;

Partida::Partida() : m_color_fondo(20,110,255), m_enemigo(1000) {
	m_musica_fondo.openFromFile("recursos/musica/Lost.wav");
	m_musica_fondo.play();
	m_musica_fondo.setVolume(30);
	/// cronometros y reloj
	m_crono = m_reloj.restart();
	/// fuentes
	m_fuente.loadFromFile("recursos/fuentes/cave-story.ttf");
	m_vida_player.setFont(m_fuente);
	/// texto vida player
	m_vida_player.setString(to_string(m_player.getVida()));
	m_vida_player.setPosition(50,10);
	m_vida_player.setCharacterSize(30);
	m_vida_player.setFillColor(Color::Red);
	///texto tiempo y texto palabra tiempo
	m_t1.setFont(m_fuente);
	m_t1.setString("Tiempo:");
	m_t1.setPosition(220,10);
	m_t1.setCharacterSize(30);
	m_t1.setFillColor(Color::Red);
	
	m_tiempo.setFont(m_fuente);
	m_tiempo.setString(to_string(m_crono.asSeconds()));
	m_tiempo.setPosition(300,10);
	m_tiempo.setCharacterSize(30);
	m_tiempo.setFillColor(Color::Red);
	/// textura corazon vida player
	m_textura_corazon.loadFromFile("recursos/player/corazon.png");
	m_corazon.setTexture(m_textura_corazon);
	m_corazon.setPosition(10,12);
	m_corazon.setScale(.13,.13);
	/// volumen partida
	m_volumen = 0;
	m_player.CambiarVolumenMusica(m_volumen);
	m_enemigo.CambiarVolumenMusica(m_volumen);
	m_musica_fondo.setVolume(m_volumen);
	
}

void Partida::Actualizar (Juego &juego) {
	m_crono = m_reloj.getElapsedTime();
	int aux = m_crono.asSeconds();
	m_tiempo.setString(to_string(aux));
	/// obtengo el fps del juego
	m_fps = juego.ObtenerFps();
	/// musica
	m_musica_fondo.setLoop(true);
	/// Keyboard
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		m_musica_fondo.stop();
		for(int i=0;i<m_enemigos.size();i++) {
			m_enemigos[i].Finalizar();
		}
		m_enemigo.Finalizar();
		m_player.Finalizar();
		juego.CambiarEscena(new Menu());
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::F)) {
		m_player.Ataque();
		if(m_player.Colision(m_enemigo)) {
			m_enemigo.BajarVida();
		}
	}
	if(m_player.getVida()>0) {
		for(int i=0;i<m_enemigos.size();i++) {
			if(m_enemigos[i].Colision(m_player)) {//m_enemigos.Ataque() and m_player.getVida()>0) {
				m_player.BajarVida();
			} 
		}
		if(m_enemigo.Colision(m_player) and m_enemigo.getVida()>0) {
			m_player.BajarVida();
		}
	} else if(m_player.getVida()<=0) {
		m_musica_fondo.stop();
		for(size_t i=0;i<m_enemigos.size();i++) {
			m_enemigos[i].Finalizar();
		}
		m_enemigo.Finalizar();
		m_player.Finalizar();
		juego.CambiarEscena(new GameOver());
	}
	/// vida Player
	m_vida_player.setString(to_string(m_player.getVida()));
	/// update
	
	m_player.Actualizar();
	for(size_t i=0;i<m_enemigos.size();i++) {
		m_enemigos[i].Actualizar();
		m_enemigos[i].getPosPlayer(m_player.getPos());
	}
	m_enemigo.Actualizar();
	m_enemigo.getPosPlayer(m_player.getPos());
	m_fondo_1.Actualizar();
	ActualizarPuntaje();
}

void Partida::Dibujar (RenderWindow & window) {
	//dibujar
	m_fondo_1.Dibujar(window);
	m_player.Dibujar(window);
	for(size_t i=0;i<m_enemigos.size();i++) {
		m_enemigos[i].Dibujar(window);
	}
	m_enemigo.Dibujar(window);
	window.draw(m_vida_player);
	window.draw(m_tiempo);
	window.draw(m_t1);
	window.draw(m_corazon);
	window.display();
}

void Partida::CambiarVolumenMusica (float vol) {
	m_musica_fondo.setVolume(vol);
}

void Partida::ActualizarPuntaje ( ) {
	if(m_player.getVida()>0) {
		m_puntaje_actual = m_crono.asSeconds();
	}
	if(m_player.getVida()<=0) {
		/// llamo a m_puntaje.GuardarUnPuntajeNuevo();
	}
}

