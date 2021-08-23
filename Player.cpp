#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace std;
using namespace sf;

Player::Player() {
	string recurso;
	sf::Texture textura;
	for(int i=0;i<6;i++) { 
		/// adelante
		recurso = "recursos/player/player_ade/cam_adel"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_adel.push_back(textura);
		///atras
		recurso = "recursos/player/player_atras/cam_atras"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_atras.push_back(textura);
		/// ataque adelante
		recurso = "recursos/player/player_ataque_adel/sprite_"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_ataque_adel.push_back(textura);
		/// ataque atras
		recurso = "recursos/player/player_ataque_atras/sprite_"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_ataque_atras.push_back(textura);
	}
	for(int i=0;i<4;i++) { /// 0 y 1 son atras, 2 y 3 son adel
		/// Quieto
		recurso = "recursos/player/player_quieto/sprite_"+ to_string(i+1) +".png";
		textura.loadFromFile(recurso);
		m_texturas_quieto.push_back(textura);
	}
	
	m_alto_sprite = 320/3;
	m_ancho_sprite = 320/5;
	m_move = {5,0};
	m_gravedad = 6;
	/// posicion inicial
	m_pos_inicial.x = 1080/2;
	m_pos_inicial.y = 520-m_alto_sprite*.9;
	/// sprite
	m_sprite.setTexture(m_texturas_adel[0]);
	m_sprite.setScale(.3,.3);
	m_sprite.setPosition(m_pos_inicial);
	
	adel=0;
	atras = 0;
	
	m_vida = 100;
	m_danio = 1;
	
	m_cambiar_textura=0;
	m_ultima_tecla =0;
}

void Player::Actualizar () {
	if(Keyboard::isKeyPressed(Keyboard::A)) { /// 0 para la A y 1 para la D
		m_ultima_tecla = 0;
	} else if(Keyboard::isKeyPressed(Keyboard::A)) {
		m_ultima_tecla = 1;
	}
	sf::Vector2f player_pos = m_sprite.getPosition();
	/// movimientos
	MovimientoQuieto();
	MovimientoGolpea();
	MovimientoGolpeaCamina();
	MovimientoCamina();
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and player_pos.y > (m_pos_inicial.y-m_alto_sprite)) {
		m_sprite.move(0,m_move.y-m_gravedad);
		m_gravedad -= .10;
	} else if(player_pos.y<m_pos_inicial.y) {
		m_gravedad = 6;
		player_pos.y += m_gravedad;
		m_gravedad = 0;
		m_sprite.setPosition(player_pos);
	}
	if(m_gravedad<0 and player_pos.y == m_pos_inicial.y) {
		m_gravedad = 6;
	}
	// limitar player window
	player_pos = m_sprite.getPosition();
	int limite_x = 1080-m_ancho_sprite;
	
	if(player_pos.x < -35) player_pos.x = -35;
	if(player_pos.x > limite_x) player_pos.x = limite_x;
	if(player_pos.y > m_pos_inicial.y) player_pos.y = m_pos_inicial.y;
	m_sprite.setPosition(player_pos);
}

void Player::Dibujar (sf::RenderWindow & w) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		/// ataca el player
	}
	w.draw(m_sprite);
}

sf::Sprite & Player::getSprite ( ) {
	return m_sprite;
}

sf::Vector2f Player::getPos ( ) {
	return m_sprite.getPosition();
}

void Player::Finalizar ( ) {
	
}

void Player::Ataque () { /// ataque se tiene que llamar
	
}

void Player::BajarVida ( ) {
	if(m_vida>=0) {
		m_vida -= m_danio;
	} else if(m_vida<0) {
		m_vida = 0;
	}
}

int Player::getVida ( ) {
	return m_vida;
}

void Player::MovimientoGolpea ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and m_ultima_tecla == 1) {
		if(m_cambiar_textura==0) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==1) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==2) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==3) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==4) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==5) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		}
		
		m_cambiar_textura +=0.125;
		/// reinicio el contador
		if(m_cambiar_textura>=5) {
			m_cambiar_textura=0;
		}
		/// reinicio
		m_ultima_tecla = 1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and m_ultima_tecla == 0) {
		if(m_cambiar_textura==0) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==1) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==2) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==3) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==4) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==5) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		}
		
		m_cambiar_textura +=0.125;
		/// reinicio el contador
		if(m_cambiar_textura>=5) {
			m_cambiar_textura=0;
		}
		/// reinicio
		m_ultima_tecla = 0;
	}
}

void Player::MovimientoGolpeaCamina ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if(m_cambiar_textura==0) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==1) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==2) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==3) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==4) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		} else if(m_cambiar_textura==5) {
			m_sprite.setTexture(m_texturas_ataque_adel[m_cambiar_textura]);
		}
		
		
		m_sprite.move(m_move);
		
		
		m_cambiar_textura +=0.125;
		/// reinicio el contador
		if(m_cambiar_textura>=5) {
			m_cambiar_textura=0;
		}
		/// reinicio
		m_ultima_tecla = 1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if(m_cambiar_textura==0) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==1) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==2) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==3) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==4) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		} else if(m_cambiar_textura==5) {
			m_sprite.setTexture(m_texturas_ataque_atras[m_cambiar_textura]);
		}
		
		
		m_sprite.move(-m_move);
		
		m_cambiar_textura +=0.125;
		/// reinicio el contador
		if(m_cambiar_textura>=5) {
			m_cambiar_textura=0;
		}
		/// reinicio
		
		
		m_ultima_tecla = 0;
	}
}

void Player::MovimientoCamina ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		if(adel==0) {
			m_sprite.setTexture(m_texturas_adel[adel]);
		} else if(adel==1) {
			m_sprite.setTexture(m_texturas_adel[adel]);
		} else if(adel==2) {
			m_sprite.setTexture(m_texturas_adel[adel]);
		} else if(adel==3) {
			m_sprite.setTexture(m_texturas_adel[adel]);
		} else if(adel==4) {
			m_sprite.setTexture(m_texturas_adel[adel]);
		} else if(adel==5) {
			m_sprite.setTexture(m_texturas_adel[adel]);
		}
		m_sprite.move(m_move);
		adel +=0.125;
		/// reinicio el contador
		if(adel>=5) {
			adel=0;
		}
		/// reinicio por si preciona esa tecla
		atras = 0;
		
		m_ultima_tecla = 1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		if(atras==0) {
			m_sprite.setTexture(m_texturas_atras[atras]);
		} else if(atras==1) {
			m_sprite.setTexture(m_texturas_atras[atras]);
		} else if(atras==2) {
			m_sprite.setTexture(m_texturas_atras[atras]);
		} else if(atras==3) {
			m_sprite.setTexture(m_texturas_atras[atras]);
		} else if(atras==4) {
			m_sprite.setTexture(m_texturas_atras[atras]);
		} else if(atras==5) {
			m_sprite.setTexture(m_texturas_atras[atras]);
		}
		
		m_sprite.move(-m_move);
		atras +=0.125;
		/// reinicio el contador
		if(atras>=5) {
			atras=0;
		}
		/// reinicio
		adel = 0;
		
		m_ultima_tecla = 0;
	}
}

void Player::MovimientoQuieto ( ) {
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F) and !sf::Keyboard::isKeyPressed(sf::Keyboard::A) and m_ultima_tecla==0) {
		if(adel==0) {
			m_sprite.setTexture(m_texturas_quieto[adel]);
		} else if(adel==1) {
			m_sprite.setTexture(m_texturas_quieto[adel]);
		} 
		
		adel +=0.0625;
		/// reinicio el contador
		if(adel>=2) {
			adel=0;
		}
		/// reinicio por si preciona esa tecla
		atras = 2;
		
		m_ultima_tecla = 0;
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !sf::Keyboard::isKeyPressed(sf::Keyboard::F) and m_ultima_tecla==1) {
		if(atras==2) {
			m_sprite.setTexture(m_texturas_quieto[atras]);
		} else if(atras==3) {
			m_sprite.setTexture(m_texturas_quieto[atras]);
		}
		
		atras +=0.0625;
		/// reinicio el contador
		if(atras>=4) {
			atras=2;
		}
		/// reinicio
		adel = 0;
		
		m_ultima_tecla = 1;
	}
}

