#pragma once
#include "Poder.h"
#include "Enemigo.h"
#include "Jugador.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using namespace System::Drawing;

class CMapa
{
private:

	int Ancho;
	int Alto;
	int Numero_Enemigos;
	int Numero_Poderes;
	int xSalida;
	int ySalida;
	vector<CEnemigo*> Enemigos;
	vector<CPoder*> Poderes;

public:

	CMapa();
	~CMapa();
	void Leer_Mapa_unJugador(int **mapa, int n, CJugador* oJ);
	void Leer_Mapa_DosJugadores(int **mapa, int n, CJugador* oJ1, CJugador* oJ2);
	void Dibujar_Mapa(int **mapa, BufferedGraphics ^buffer, Bitmap^ Bsolido, Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto);
	int Get_NEnemigos();
	int Get_NPoderes();
	vector<CEnemigo*> Get_Enemigos();
	vector<CPoder*> Get_Poderes();
	int Get_XSalida();
	int Get_YSalida();
	CPoder *Get_Poder(int xM, int yM);
	CEnemigo *Get_Enemigo(int xM, int yM);
};