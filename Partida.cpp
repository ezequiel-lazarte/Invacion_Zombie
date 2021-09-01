#include "Partida.h"
#include "Menu.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "GameOver.h"
#include <SFML/Graphics/Color.hpp>
#include "Enemigo_1.h"
#include <iostream>
using namespace std;

Partida::Partida() : m_color_fondo(20,110,255) {
	m_volumen = 10;
	m_musica_fondo.setVolume(m_volumen);
	srand(time(NULL)*time(NULL));
	m_posDesde = -3800;
	m_posHasta = 3800;
	m_numeroEnemigos1 = 13;
	m_numeroEnemigos2 = 3;
	for(int i=0;i<m_numeroEnemigos1;i++) {
		m_enemigos1.resize(m_enemigos1.size() + 1);
		Enemigo_1 enemigo1;
		m_enemigos1[i] = enemigo1;
		m_enemigos1[i].SetPosEnemigo((rand()*rand())%(m_posHasta - m_posDesde) + m_posDesde);
		m_retraso1.resize(m_retraso1.size() + 1);
		m_retraso1[i] = 0;
	}
	for(int i=0;i<m_numeroEnemigos2;i++) {
		m_enemigos2.resize(m_enemigos2.size() + 1);
		Enemigo_2 enemigo2;
		m_enemigos2[i] = enemigo2;
		m_enemigos2[i].SetPosEnemigo((rand()*rand())%(m_posHasta - m_posDesde) + m_posDesde);
		
		m_retraso2.resize(m_retraso2.size() + 1);
		m_retraso2[i] = 0;
	}
	m_buffer.loadFromFile("recursos/musica/Lost.wav");
	m_musica_fondo.setBuffer(m_buffer);
	m_musica_fondo.play();
	m_musica_fondo.setLoop(true);
	m_crono = m_reloj.restart();
	
	m_fuente.loadFromFile("recursos/fuentes/cave-story.ttf");
	m_vida_player.setFont(m_fuente);
	
	m_vida_player.setString(to_string(m_player.getVida()));
	m_vida_player.setPosition(50,10);
	m_vida_player.setCharacterSize(30);
	m_vida_player.setFillColor(Color::Red);
	
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
	
	m_textura_corazon.loadFromFile("recursos/player/corazon.png");
	m_corazon.setTexture(m_textura_corazon);
	m_corazon.setPosition(10,12);
	m_corazon.setScale(.13,.13);
}

void Partida::Actualizar (Juego &juego) {
	m_crono = m_reloj.getElapsedTime();
	aux = m_crono.asSeconds();
	m_tiempo.setString(to_string(aux));
	m_fps = juego.ObtenerFps();
	/// Keyboard
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		m_musica_fondo.stop();
		for(int i=0;i<m_enemigos1.size();i++) {
			m_enemigos1[i].Finalizar();
		}
		for(int i=0;i<m_enemigos2.size();i++) {
			m_enemigos2[i].Finalizar();
		}
		m_player.Finalizar();
		juego.CambiarEscena(new Menu());
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::F)) {
		m_player.Ataque();
		for(int i=0;i<m_enemigos1.size();i++) {
			if(m_player.Colision(m_enemigos1[i])) {
				m_enemigos1[i].BajarVida();
			}
		}
		for(int i=0;i<m_enemigos2.size();i++) {
			if(m_player.Colision(m_enemigos2[i])) {
				m_enemigos2[i].BajarVida();
			}
		}
	}
	if(m_player.getVida()>0) {
		for(int i=0;i<m_enemigos1.size();i++) {
			if(m_enemigos1[i].Colision(m_player) and m_enemigos1[i].getVida()>0) {
				m_retraso1[i] += 1;
				if(m_retraso1[i] > 30) { // el enemigo de tipo 1 tarda mas en atacar
					m_player.BajarVida();
				}
			} else if(!m_enemigos1[i].Colision(m_player)) {
				m_retraso1[i] = 0;
			}
		}
		for(int i=0;i<m_enemigos2.size();i++) {
			if(m_enemigos2[i].Colision(m_player) and m_enemigos2[i].getVida()>0) {
				m_retraso2[i] += 1;
				if(m_retraso2[i] > 15) { // el enemigo de tipo 2 tarda menos en atacar
					m_player.BajarVida();
				}
			} else if(!m_enemigos2[i].Colision(m_player)) {
				m_retraso2[i] = 0;
			}
		}
	} else if(m_player.getVida()<=0) {
		m_musica_fondo.stop();
		for(size_t i=0;i<m_enemigos1.size();i++) {
			m_enemigos1[i].Finalizar();
		}
		for(size_t i=0;i<m_enemigos2.size();i++) {
			m_enemigos2[i].Finalizar();
		}
		m_player.Finalizar();
		juego.CambiarEscena(new GameOver());
	}
	CrearEnemigos();
	/// vida jugador
	m_vida_player.setString(to_string(m_player.getVida()));
	m_player.Actualizar();
	for(size_t i=0;i<m_enemigos1.size();i++) {
		m_enemigos1[i].Actualizar();
		m_enemigos1[i].setPosPlayer(m_player.getPos());
	}
	for(size_t i=0;i<m_enemigos2.size();i++) {
		m_enemigos2[i].Actualizar();
		m_enemigos2[i].getPosPlayer(m_player.getPos());
	}
	m_fondo_1.Actualizar();
	ActualizarPuntaje();
}

void Partida::Dibujar (RenderWindow & window) {
	m_fondo_1.Dibujar(window);
	m_player.Dibujar(window);
	for(size_t i=0;i<m_enemigos1.size();i++) {
		m_enemigos1[i].Dibujar(window);
	}
	for(size_t i=0;i<m_enemigos2.size();i++) {
		m_enemigos2[i].Dibujar(window);
	}
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
		/// llamo a
		string nombre_player = "John";
		int tiempo = 777;
	}
}

void Partida::CrearEnemigos ( ) {
	m_posDesde = -3800;
	m_posHasta = 3800;
	for(size_t i=0;i<m_enemigos1.size();i++) {
		if(m_enemigos1[i].getVida() <= 0) {
			Enemigo_1 enemigo1;
			enemigo1.SetPosEnemigo(m_posDesde);
			m_enemigos1[i] = enemigo1;
		}
	}
	for(size_t i=0;i<m_enemigos2.size();i++) {
		if(m_enemigos2[i].getVida() <= 0) {
			Enemigo_2 enemigo2;
			enemigo2.SetPosEnemigo(m_posHasta);
			m_enemigos2[i] = enemigo2;
		}
	}
}

