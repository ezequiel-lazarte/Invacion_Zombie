#include "DatosDePartida.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

DatosDePartida::DatosDePartida() : m_dataGame(5, {"Vacio", 0, 0}) {
	m_nameplayer = "Vacio";
	m_tiempo = m_kills = 0;
	m_nameBinary = "Puntajes/Puntajes.dat";
	m_nro_puntajes = 5;
	
	abrirParaLectura();
}

void DatosDePartida::abrirParaLectura ( ) {
	m_archi_read.open(m_nameBinary, ios::binary|ios::ate);
	if(!m_archi_read.is_open()) {
		cerr << "Error al abrir el archivo puntajes.dat" << endl;
		crearBinario();
		abrirParaLectura();
		return;
	}
	leerData();
	m_archi_read.close();
}

void DatosDePartida::crearBinario ( ) {
	m_archi_write.open(m_nameBinary, ios::binary|ios::trunc);
	m_archi_write.seekp(0);
	char name[10] = "Vacio";
	int aux = 0;
	for(unsigned int i=0; i<m_nro_puntajes; i++) {
		strcpy(name, m_dataGame[i].name.c_str());
		m_archi_write.write(name, sizeof(name));
		m_archi_write.write(reinterpret_cast<char*>(&aux),sizeof(aux));
		m_archi_write.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	m_archi_write.close();
}

void DatosDePartida::setNombrePlayer (const string &name) {
	m_nameplayer = name;
}

void DatosDePartida::setKills (const int & kills) {
	m_kills = kills;
}

void DatosDePartida::guardarPuntaje ( ) {
	Data d1 = {m_nameplayer, m_tiempo, m_kills};
	m_dataGame.push_back(d1);
	ordenaPuntajes(); /// ordena los 6 puntajes
	m_dataGame.pop_back(); /// borro el ultimo que sobra
	
	m_archi_write.open(m_nameBinary, ios::binary|ios::trunc);
	if(!m_archi_write.is_open()) {
		cerr << "Error el binario no se pudo abrir para escritura" << endl;
	}
	
	m_archi_write.seekp(0);
	char name[10] = "";
	for(unsigned int i=0; i<m_nro_puntajes; i++) {
		strcpy(name, m_dataGame[i].name.c_str());
		m_archi_write.write(name, sizeof(name));
		m_archi_write.write(reinterpret_cast<char*>(&m_dataGame[i].tiempo),sizeof(m_dataGame[i].tiempo));
		m_archi_write.write(reinterpret_cast<char*>(&m_dataGame[i].kills),sizeof(m_dataGame[i].kills));
	}
	m_archi_write.close();
	leerData();
}

void DatosDePartida::leerData ( ) {
	int tam_bytes = m_archi_read.tellg();
	int cant_data = tam_bytes/sizeof(Data);
	m_archi_read.seekg(0);
	
	Data aux;
	char name[10] = "";
	if(cant_data != 0) {
		for(int i=0;i<m_nro_puntajes;i++) {
			m_archi_read.read(name, sizeof(name));
			aux.name = name;
			m_archi_read.read(reinterpret_cast<char*>(&aux.tiempo), sizeof(aux.tiempo));
			m_archi_read.read(reinterpret_cast<char*>(&aux.kills), sizeof(aux.kills));
			m_dataGame[i] = aux;
		}
	}
	ordenaPuntajes();
}

void DatosDePartida::setTiempo (const int &tiempo) {
	m_tiempo = tiempo;
}

string DatosDePartida::getNombrePlayer (int pos) {
	return m_dataGame[pos].name;
}

int DatosDePartida::getTiempo (int pos) {
	return m_dataGame[pos].tiempo;
}

int DatosDePartida::getKills (int pos) {
	return m_dataGame[pos].kills;
}

inline bool mayor_kills_o_tiempo (Data d1, Data d2) {
	if(d1.kills >= d2.kills) {
		if(d1.kills == d2.kills && d1.tiempo >= d2.tiempo) 
			return true;
	} else
	   return false;
	return true;
}

void DatosDePartida::ordenaPuntajes () {
	sort(m_dataGame.begin(), m_dataGame.end(), mayor_kills_o_tiempo);
}

int DatosDePartida::getSizeData ( ) {
	return m_dataGame.size();
}

