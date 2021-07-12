#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Entidad {
public:
	Entidad();
	virtual void Actualizar()=0;
	virtual void Dibujar(sf::RenderWindow &w)=0;
	bool Colision(const Entidad &e) const;
protected:
	sf::Texture m_textura;
	sf::Sprite m_sprite;
	float m_alto_sprite, m_ancho_sprite;
	int m_vida, m_danio;
};

#endif

