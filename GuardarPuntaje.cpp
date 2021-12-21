#include "GuardarPuntaje.h"
#include "Puntajes.h"
#include "Menu.h"
#include "Juego.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "ImputBox.h"
using namespace std;



GuardarPuntaje:: GuardarPuntaje(int &volumen, Resources *recursos, sf::Event evento, DatosDePartida *data) {
	m_puntajes = new Puntajes(volumen, recursos);
	m_puntajes->setData(data);
	m_recursos = recursos;
	m_volumen = volumen;
	m_fondo.setTexture(m_recursos->getGuardarPuntajes());
	m_fondo.setScale(1.1,1.3);
	
	m_musica.setBuffer(m_recursos->getBufferPuntajes());
	m_musica.play();
	m_musica.setLoop(true);
	
	m_titulo.setFont(m_recursos->getFont());
	
	m_titulo.setPosition(260,-30);
	m_titulo.setFillColor(sf::Color {180,0,0});
	m_titulo.setString("Guardar Puntaje");
	m_titulo.setCharacterSize(90);
	
	InputText A(m_recursos->getFont(),30,sf::Color::Black);
	A.ventana(evento, data);
}

void GuardarPuntaje::Actualizar (Juego & juego) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		m_musica.stop();
		juego.CambiarEscena(new Menu(m_volumen, m_recursos));
	}
}

void GuardarPuntaje::Dibujar (sf::RenderWindow & window){
	window.clear({0,0,0});
	window.draw(m_fondo);
	window.draw(m_titulo);
	window.display();
}


GuardarPuntaje::~GuardarPuntaje ( ) {
	delete m_puntajes;
}

