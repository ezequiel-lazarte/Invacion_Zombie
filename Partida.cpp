#include "Partida.h"
#include "Menu.h"
#include "GameOver.h"
#include "Enemigo_1.h"
#include <iostream>
using namespace std;

Partida::Partida() : m_color_fondo(20,110,255) {
	m_volumen = 30;
	m_musica_fondo.setVolume(m_volumen);
	srand(time(NULL));
	m_posDesde = -2500;
	m_posHasta = 2500;
	m_numeroEnemigos1 = 7;
	m_numeroEnemigos2 = 7;
	m_texture_aux = m_recursos.getEnemigo_1();
	for(int i=0;i<m_numeroEnemigos1;i++) {
		m_enemigos.resize(m_enemigos.size() + 1);
		enemigo1.setTexture(m_texture_aux);
		enemigo1.setVida(80);
		enemigo1.setDanio(300);
		m_enemigos[i] = enemigo1;
		m_enemigos[i].SetPosEnemigo(rand()%(m_posHasta - m_posDesde) + m_posDesde);
	}
	for(int i=m_numeroEnemigos1;i<m_numeroEnemigos2;i++) {
		m_enemigos.resize(m_enemigos.size() + 1);
		Enemigo_1 enemigo2;
		enemigo1.setVida(30);
		enemigo1.setDanio(800);
		m_enemigos[i] = enemigo2;
		m_enemigos[i].SetPosEnemigo(rand()%(m_posHasta - m_posDesde) + m_posDesde);
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
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		m_musica_fondo.stop();
		for(int i=0;i<m_enemigos.size();i++) {
			m_enemigos[i].Finalizar();
		}
		m_player.Finalizar();
		juego.CambiarEscena(new Menu());
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::F)) {
		for(int i=0;i<m_enemigos.size();i++) {
			if(m_player.Colision(m_enemigos[i])) {
				m_enemigos[i].BajarVida();
			}
		}
	}
	if(m_player.getVida()>0) {
		for(int i=0;i<m_enemigos.size();i++) {
			if(m_enemigos[i].Colision(m_player) and m_enemigos[i].getVida()>0) {
				m_player.BajarVida();
			} 
		}
	} else if(m_player.getVida()<=0) {
		m_musica_fondo.stop();
		for(size_t i=0;i<m_enemigos.size();i++) {
			m_enemigos[i].Finalizar();
		}
		m_player.Finalizar();
		juego.CambiarEscena(new GameOver());
	}
	CrearEnemigos();
	/// vida jugador
	m_vida_player.setString(to_string(m_player.getVida()));
	m_player.Actualizar();
	for(size_t i=0;i<m_enemigos.size();i++) {
		m_enemigos[i].Actualizar();
		m_enemigos[i].setPosPlayer(m_player.getPos());
	}
	m_fondo_1.Actualizar();
	ActualizarPuntaje();
}

void Partida::Dibujar (RenderWindow & window) {
	m_fondo_1.Dibujar(window);
	m_player.Dibujar(window);
	for(size_t i=0;i<m_enemigos.size();i++) {
		m_enemigos[i].Dibujar(window);
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
	for(size_t i=0;i<m_numeroEnemigos1;i++) {
		if(m_enemigos[i].getVida() <= 0) {
			Enemigo_1 enemigo1;
			enemigo1.setVida(80);
			enemigo1.setDanio(300);
			enemigo1.setTexture(m_recursos.getEnemigo_1());
			enemigo1.SetPosEnemigo(m_posDesde);
			m_enemigos[i] = enemigo1;
		}
	}
	for(size_t i=m_numeroEnemigos1;i<m_enemigos.size();i++) {
		if(m_enemigos[i].getVida() <= 0) {
			Enemigo_1 enemigo2;
			enemigo1.setVida(30);
			enemigo1.setDanio(800);
			enemigo2.SetPosEnemigo(m_posHasta);
			m_enemigos[i] = enemigo2;
		}
	}
}

