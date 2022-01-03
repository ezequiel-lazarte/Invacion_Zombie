#include "Partida.h"
#include "Menu.h"
#include "GameOver.h"
#include <iostream>
using namespace std;

Partida::Partida(int &volumen, Resources *recursos) : 
		m_color_fondo(20,110,255), m_player(volumen, recursos) {
	m_data = new DatosDePartida;
	m_volumen = volumen;
	m_recursos = recursos;
	srand(time(NULL));
	m_posDesde = -2500;
	m_posHasta = 2500;
	m_numeroEnemigos1 = 10;
	m_numeroEnemigos2 = 10;
	for(int i=0;i<m_numeroEnemigos1;i++) {
		m_enemigos.resize(m_enemigos.size() + 1);
		enemigo.setTexture(m_recursos->getEnemigo_1());
		enemigo.setVida(40);
		enemigo.setDanio(300);
		m_enemigos[i] = enemigo;
		m_enemigos[i].SetPosEnemigo(rand()%(m_posHasta - m_posDesde) + m_posDesde);
	}
	for(int i=m_numeroEnemigos1;i<m_numeroEnemigos2;i++) {
		m_enemigos.resize(m_enemigos.size() + 1);
		enemigo.setTexture(m_recursos->getEnemigo_2());
		enemigo.setVida(110);
		enemigo.setDanio(500);
		m_enemigos[i] = enemigo;
		m_enemigos[i].SetPosEnemigo(rand()%(m_posHasta - m_posDesde) + m_posDesde);
	}
	m_musica_fondo.setBuffer(m_recursos->getBufferPartida());
	m_musica_fondo.play();
	m_musica_fondo.setLoop(true);
	m_crono = m_reloj.restart();
	
	m_vida_player.setFont(m_recursos->getFont());
	
	m_vida_player.setString(to_string(m_player.getVida()));
	m_vida_player.setPosition(50,10);
	m_vida_player.setCharacterSize(30);
	m_vida_player.setFillColor(Color::Red);
	
	m_t1.setFont(m_recursos->getFont());
	m_t1.setString("Tiempo:");
	m_t1.setPosition(220,10);
	m_t1.setCharacterSize(30);
	m_t1.setFillColor(Color::Red);
	
	m_tiempo.setFont(m_recursos->getFont());
	m_tiempo.setString(to_string(m_crono.asSeconds()));
	m_tiempo.setPosition(300,10);
	m_tiempo.setCharacterSize(30);
	m_tiempo.setFillColor(Color::Red);
	
	m_nro_kills = 0;
	
	m_nro_kill.setFont(m_recursos->getFont());
	m_nro_kill.setString("Kills: " + to_string(m_nro_kills));
	m_nro_kill.setPosition(460, 10);
	m_nro_kill.setCharacterSize(30);
	m_nro_kill.setFillColor(Color::Red);
	
	m_corazon.setTexture(m_recursos->getCorazon());
	m_corazon.setPosition(10,12);
	m_corazon.setScale(.13,.13);
	
	m_pos_player = m_player.getPosInicial();
	
	m_tiempoActual = 0;
	
	m_tiempoParaSumarEnemigos = 15;
}

void Partida::Actualizar (Juego &juego) {
	m_crono = m_reloj.getElapsedTime();
	aux = m_crono.asSeconds();
	m_tiempo.setString(to_string(aux));
	CrearEnemigos();
	GestionEnemigos();
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		m_musica_fondo.stop();
		for(int i=0;i<m_enemigos.size();i++) {
			m_enemigos[i].Finalizar();
		}
		m_player.Finalizar();
		juego.CambiarEscena(new Menu(m_volumen, m_recursos));
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
		juego.CambiarEscena(new GameOver(m_volumen, m_recursos, m_data));
	}
	if(m_player.getVida() > 0 && m_player.getPos().y >= m_player.getPosInicial().y && (m_pos_player.x > m_player.getPos().x+120 || m_pos_player.x < m_player.getPos().x-120)) {
		m_player.sonidoPaso();
		m_pos_player = m_player.getPos();
	}
	m_vida_player.setString(to_string(m_player.getVida()));
	m_player.Actualizar();
	m_fondo_1.Actualizar();
	ActualizarPuntaje();
}

void Partida::Dibujar (RenderWindow & window) {
	m_fondo_1.Dibujar(window);
	m_player.Dibujar(window);
	for(size_t i=0;i<m_enemigos.size();i++) m_enemigos[i].Dibujar(window);
	window.draw(m_vida_player);
	window.draw(m_nro_kill);
	window.draw(m_tiempo);
	window.draw(m_t1);
	window.draw(m_corazon);
	window.display();
}

void Partida::ActualizarPuntaje ( ) {
	if(m_player.getVida()>0) {
		m_puntaje_actual = m_crono.asSeconds();
	}
	if(m_player.getVida()<=0) {
		m_data->setTiempo((int)m_puntaje_actual/10);
	}
}

void Partida::CrearEnemigos ( ) {
	m_posDesde = -3800;
	m_posHasta = 3800;
	for(size_t i=0;i<m_numeroEnemigos1;i++) {
		if(m_enemigos[i].getVida() <= 0) {
			enemigo.setVida(40);
			enemigo.setDanio(300);
			enemigo.setTexture(m_recursos->getEnemigo_1());
			enemigo.SetPosEnemigo(m_posDesde);
			m_enemigos[i] = enemigo;
		}
	}
	for(size_t i=m_numeroEnemigos1;i<m_enemigos.size();i++) {
		if(m_enemigos[i].getVida() <= 0) {
			enemigo.setVida(110);
			enemigo.setDanio(500);
			enemigo.setTexture(m_recursos->getEnemigo_2());
			enemigo.SetPosEnemigo(m_posHasta);
			m_enemigos[i] = enemigo;
		}
	}
}

void Partida::GestionEnemigos ( ) {
	m_tiempoActual = m_reloj.getElapsedTime().asSeconds();
	if(m_tiempoActual >= m_tiempoParaSumarEnemigos) {
		int num = numeroAleatorio();
		Enemigo_1 enemy;
		
		if(num % 2 == 0) {
			enemy.setTexture(m_recursos->getEnemigo_1());
			enemy.setVida(40);
			enemy.setDanio(300);
			enemy.SetPosEnemigo(rand()%(m_posHasta - m_posDesde) + m_posDesde);
			m_numeroEnemigos1++;
		} else {
			enemy.setTexture(m_recursos->getEnemigo_2());
			enemy.setVida(110);
			enemy.setDanio(500);
			enemy.SetPosEnemigo(rand()%(m_posHasta - m_posDesde) + m_posDesde);
			m_numeroEnemigos2++;
		}
		if(m_tiempoActual == 400) {
			std::cout << "xs";
		}
		m_enemigos.push_back(enemy);
		m_tiempoParaSumarEnemigos = m_tiempoActual+5;
	}
	for(int i=0;i<m_enemigos.size();i++) {
		m_enemigos[i].setTipoArma(m_player.getArma());
		m_enemigos[i].Actualizar();
		m_enemigos[i].setPosPlayer(m_player.getPos());
		
//		if(m_enemigos[i].getPos().x >= 0 && m_enemigos[i].getPos().x <= 1080) 
//			m_enemigos[i].playSonidoZombie();
		
		if(m_player.Colision(m_enemigos[i]) && m_player.getVida()>0 && Keyboard::isKeyPressed(Keyboard::Key::F) && m_player.getArma() == 1) {
			m_player.golpe();
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::F) && m_player.Colision(m_enemigos[i]) && m_player.getArma() == 1) {
			m_enemigos[i].BajarVida();
			if(m_enemigos[i].getVida() <= 0) {
				++m_nro_kills;
				m_nro_kill.setString("Kills: " + to_string(m_nro_kills));
			}
		}
		m_disparos = m_player.getDisparos();
		for(int j=0; j < m_player.getDisparos().size(); j++) {
			if(m_enemigos[i].Colision(m_player.getDisparos()[j])) {
				m_enemigos[i].BajarVida();
				m_player.sonidoImpacto();
				m_player.borrarBala(j);
				if(m_enemigos[i].getVida() <= 0) {
					++m_nro_kills;
					m_nro_kill.setString("Kills: " + to_string(m_nro_kills));
				}
			}
		}
	}
}

int Partida::numeroAleatorio ( ) {
	srand(time(NULL));
	int num = 1+rand()%(101-1);
	return num;
}

