#ifndef DATOSDEPARTIDA_H
#define DATOSDEPARTIDA_H
#include <string>
using namespace std;

class DatosDePartida {
public:
	DatosDePartida();
	void setNombrePlayer(const string &name);
	void setTiempo(const int &tiempo);
	string getNombrePlayer();
	int getTiempo();
private:
	string m_nameplayer;
	int m_tiempo;
};

#endif

