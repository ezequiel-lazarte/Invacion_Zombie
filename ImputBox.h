#ifndef IMPUTBOX_H
#define IMPUTBOX_H
#include <string>
#include "DatosDePartida.h"

using namespace std;
/**
* Esta clase sirve para facilitar la entrada de strings en una ventana de sfml-2.x.
* Hereda de sf::Text, así que se usa como un sf::Text. 
* 	- Se lo crea pasandole una fuente, un tamaño y un color (los dos últimos opcionales).
* 	- Se le puede cambiar el formato al texto con los mismos métodos que sf::Text. 
* 	- Se lo dibuja con el método draw de la ventana igual que con los sprites.
* 	- Lo importante es pasarle los eventos del bucle de eventos mediante el método 
* 	  processEvent, que retorna true si era un evento de su interes, o false en caso 
* 		contrario.
* 	- Y además antes de dibujarlo hay que llamar a su método update, en caso contrario 
* 	  no se verá nada.
* 	
* 	Ejemplode uso:
*				...
*				// crear una instancia
* 			InputText text_entrada(font,30,sf::Color::Black);
* 			text_entrada.setPosition(120,50);
*				...
* 			// bucle principal
* 			while(w.isOpen()) { // w seria la ventana
* 				// procesar eventos
* 				Event e;
* 				while(w.pollEvent(e)) {
* 					if (text_entrada.processEvent(e)) {} // si retorna true, es porque procesó el evento
* 					else if (e.type == ....
* 					...
* 				}
* 				// dibujar
* 				text_entrada.update(); // para que el texto se dibuje correctamente (hay que llamar a update ante de pasarselo a draw)
* 				w.draw(text_entrada);
* 				...
* 				w.display();
* 			}
*
* Version: 2014-02-19
**/

class InputText:public sf::Text {
	sf::Clock clock;
	std::string value;
	bool is_down[sf::Keyboard::KeyCount];
	void TestKey(sf::Keyboard::Key k, char c) {
		bool was_down=is_down[int(k)];
		is_down[int(k)]=sf::Keyboard::isKeyPressed(k);
		if (is_down[int(k)] && !was_down) value+=c;
	}
	unsigned int max_chars;
	bool editable;
	bool single_word;
	DatosDePartida data;
public:
	void ventana(sf::Event e, DatosDePartida *data);
	InputText() {}
	InputText(const sf::Font &font, int size=30, sf::Color color=sf::Color::Black) {
		for(int i=0;i<sf::Keyboard::KeyCount;i++) is_down[i]=true;
		max_chars=0;
		single_word=false;
		editable=true;
		setFont(font);
		setCharacterSize(size);
		setFillColor(color);
	}
	bool processEvent(const sf::Event &event) {
		if (!editable) return false;
		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode=='\b') {
				if (value.size()) value.erase(value.size()-1,1);
			} else if (event.text.unicode>=32 && event.text.unicode<128) {
				if (!max_chars || value.size()<max_chars) 
					if (!single_word || event.text.unicode!=' ')
						value += static_cast<char>(event.text.unicode);
			}
			return true;
		}
		return false;
	}
	void setMaxChars(unsigned int max) { max_chars=max; }
	void update() {
		if (editable && int(clock.getElapsedTime().asSeconds()*3)%2)
			setString(value+"|");
		else 
			setString(value);
	}
	void setEditable(bool value) { editable=value; }
	void setSingleWord(bool value) { single_word=value; }
	std::string getValue() { return value; }
	void reset() { value.clear(); }
};

#endif
