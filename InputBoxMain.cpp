#include <SFML/Graphics.hpp>
#include "ImputBox.h" // este es el header de la clase, adentro tiene un pequeña ayuda
#include "GuardarPuntaje.h"
#include "Puntajes.h"

#include <iostream>
using namespace std;
using namespace sf;


void InputText::ventana(sf::Event e, DatosDePartida *data) {
	// crea una ventana
	sf::RenderWindow w(VideoMode(1080,520), " ");
	// cargar una fuente para los textos
	sf::Font font;
	font.loadFromFile("recursos/fuentes/Cave-Story.ttf");
	// crear un texto comun
	sf::Text text_comun("Ingrese su usuario (hasta 10 letras):",font);
	text_comun.setCharacterSize(25);
	text_comun.setFillColor(sf::Color::Blue);
	text_comun.setPosition(100,20);
	// texto que ingresa el usuario
	InputText text_entrada(font, 30,sf::Color::Black);
	text_entrada.setPosition(120,50);
	text_entrada.setMaxChars(10); // no mas de 10 caracteres
	text_entrada.setSingleWord(true); // no permitir ingresar espacios, para que sea solo una palabra
	// bucle principal
	while(w.isOpen()) {
		
		// procesar eventos
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				w.close();	
			}  else { 
				if (e.type==sf::Event::KeyPressed && e.key.code==sf::Keyboard::Return) { // si apretó enter, se toma la palabra y se la agrega a la lista
					string string_ingresado = text_entrada.getValue();// obtener la palabra que se ingresó
					cout<<string_ingresado;
					data->setNombrePlayer(string_ingresado);
					data->guardarPuntaje();
//					Puntajes B;
//					B.GuardarUnPuntajeNuevo(string_ingresado);
					return;
					
				} else{
					text_entrada.processEvent(e); // para que el texto tome las teclas que pulsamos
				}
			}
			// dibujar
			w.clear(Color(255,255,255,255));
			text_entrada.update(); // para que el texto se dibuje correctamente (hay que hacer esta llamada despues de processEvent y antes del draw)
			w.draw(text_comun);
			w.draw(text_entrada);
			w.display();
		}
		
	}
	
}
