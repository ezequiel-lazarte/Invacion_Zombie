#ifndef DATOSDEPARTIDA_H
#define DATOSDEPARTIDA_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Data {
	string name;
	int tiempo, kills;
};

inline bool mayor_kills_o_tiempo(Data d1, Data d2);

class DatosDePartida {
public:
	DatosDePartida();
	void abrirParaLectura();
	void crearBinario();
	void setNombrePlayer(const string &name);
	void setTiempo(const int &tiempo);
	void setKills(const int &kills);
	void guardarPuntaje();
	string getNombrePlayer(int pos);
	int getTiempo(int pos);
	int getKills(int pos);
	int getSizeData();
private:
	void leerData();
	void ordenaPuntajes();
	ifstream m_archi_read;
	ofstream m_archi_write;
	vector<Data> m_dataGame;
	string m_nameplayer, m_nameBinary;
	int m_tiempo, m_kills, m_nro_puntajes;
};

#endif

