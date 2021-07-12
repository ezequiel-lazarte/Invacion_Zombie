#include "Entidad.h"

Entidad::Entidad() {
	
}


bool Entidad::Colision (const Entidad & e) const {
	auto r1 = this->m_sprite.getGlobalBounds();
	auto r2 = e.m_sprite.getGlobalBounds();
	return r1.intersects(r2);
}

