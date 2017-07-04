#pragma once
#include <string>
#include "Jugador.h"

using namespace System::Drawing;
using namespace std;

class CPoder
{
private:
	int xM;
	int yM;
	int Tipo;

public:
	CPoder(int tipo, int x, int y);
	~CPoder();
	int Get_Tipo();
	int Get_X();
	int Get_Y();
	void Poder_Muerte(CJugador *oJugador);
	void Poder_Bloques(CJugador *oJugador);
	void Poder_Corazon(CJugador *oJugador);
};