#pragma once
#include <string>

using namespace std;
using namespace System::Drawing;

enum Direcciones { Ninguna, Arriba, Abajo, Izquierda, Derecha };

class CJugador
{
	int Vidas;
	string Nombre;
	int Numero_Bombas;
	int Items;
	int Poder;
	int x;
	int y;
	int xMInicio;
	int yMInicio;
	int dx;
	int dy;
	int Ancho;
	int Alto;
	int xM;
	int yM;
	int Velocidad;
	bool Bloques;
	int R;
	int G;
	int B;
	Direcciones Ultima;

public:
	Direcciones Direccion;
	CJugador(int x, int y, string Nickname);
	~CJugador();
	void Dibujar(BufferedGraphics ^buffer);
	void Mover(int **matriz, bool &cargado, int &nivel, BufferedGraphics ^buffer);
	int Get_X();
	int Get_Y();
	void Set_X(int x);
	void Set_Y(int y);
	int Get_xM();
	int Get_yM();
	void Set_xM(int xM);
	void Set_yM(int yM);
	bool Get_Bloques();
	void Set_Bloques(bool value);
	int Get_Vidas();
	void Set_Vidas(int value);
	int Get_NBombas();
	int Get_Velocidad();
	void Respawn();
};