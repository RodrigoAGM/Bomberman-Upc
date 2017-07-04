#include "Poder.h"

CPoder::CPoder(int type, int x, int y)
{
	this->xM = x;
	this->yM = y;
	this->Tipo = type;
}

CPoder::~CPoder()
{

}
int CPoder::Get_Tipo() {
	return Tipo;
}
int CPoder::Get_X() { return xM; }
int CPoder::Get_Y() { return yM; }
void CPoder::Poder_Muerte(CJugador *oJugador) {
	if (oJugador->Get_Vidas() == 0) { oJugador->Set_Vidas(-1); }
	else {
		oJugador->Respawn();
	}
}
void CPoder::Poder_Bloques(CJugador *oJugador) {
	oJugador->Set_Bloques(true);
}

void CPoder::Poder_Corazon(CJugador *oJugador) {
	oJugador->Set_Vidas(oJugador->Get_Vidas() + 1);
}