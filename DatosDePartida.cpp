#include "DatosDePartida.h"

DatosDePartida::DatosDePartida() { /// mover todo lo que sea guardar datos o leer datos a esta clase
	m_nameplayer = "Vacio";
	m_tiempo = 0;
}

void DatosDePartida::setNombrePlayer (const string &name) {
	m_nameplayer = name;
}

void DatosDePartida::setTiempo (const int &tiempo) {
	m_tiempo = tiempo;
}

string DatosDePartida::getNombrePlayer ( ) {
	return m_nameplayer;
}

int DatosDePartida::getTiempo ( ) {
	return m_tiempo;
}

