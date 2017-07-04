#include "Jugador.h"
using namespace System;

CJugador::CJugador(int x, int y, string Nickname)
{
	Random rand;
	Vidas = 3;
	this->x = x;
	this->y = y;
	this->Nombre = Nickname;
	this->Ancho = 45;
	this->Alto = 45;
	this->dx = 0;
	this->dy = 0;
	this->xM = 1;
	this->yM = 1;
	this->Velocidad = 0;
	Bloques = false;
	R = rand.Next(0, 256);
	G = rand.Next(0, 256);
	B = rand.Next(0, 256);
}


CJugador::~CJugador()
{
}

void CJugador::Dibujar(BufferedGraphics ^buffer) {
	SolidBrush ^mybrush = gcnew SolidBrush(Color::FromArgb(R, G, B));
	buffer->Graphics->FillRectangle(mybrush, x, y, Ancho, Alto);
	x += dx;
	y += dy;
}
void CJugador::Mover(int **matriz, bool &cargado, int &nivel, BufferedGraphics ^buffer) {

	switch (Direccion)
 	{
	case Direcciones::Abajo:
		if (matriz[yM + 1][xM] == 0 || matriz[yM + 1][xM] == 10 || matriz[yM + 1][xM] == 11 ||
			matriz[yM + 1][xM] == 12) {
			dx = 0; dy = 45; yM++;
		}
		else if (Bloques && (matriz[yM + 1][xM] == 3)) {
			dx = 0; dy = 45; yM++;
		}
		else if (matriz[yM + 1][xM] == 5) {
			nivel++; cargado = false; Bloques = false;
		}
		else {
			dx = 0; dy = 0;
		}

		Ultima = Abajo;
		break;
	case Direcciones::Arriba:
		if (matriz[yM - 1][xM] == 0 || matriz[yM - 1][xM] == 10 || matriz[yM - 1][xM] == 11 ||
			matriz[yM - 1][xM] == 12) {
			dx = 0; dy = -45; yM--;
		}
		else if (Bloques && (matriz[yM - 1][xM] == 3)) {
			dx = 0; dy = -45; yM--;
		}
		else if (matriz[yM - 1][xM] == 5) {
			nivel++; cargado = false; Bloques = false;
		}
		else {
			dx = 0; dy = 0;
		}

		Ultima = Arriba;
		break;
	case Direcciones::Derecha:
		if (matriz[yM][xM + 1] == 0 || matriz[yM][xM + 1] == 10 || matriz[yM][xM + 1] == 11 ||
			matriz[yM][xM + 1] == 12) {
			dx = 45; dy = 0; xM++; 
		}
		else if(Bloques && (matriz[yM][xM + 1] == 3)) {
			dx = 45; dy = 0; xM++;
		}
		else if (matriz[yM][xM + 1] == 5) {
			nivel++; cargado = false; Bloques = false;
		}
		else {
			dx = 0; dy = 0;
		}

		Ultima = Derecha;
		break;
	case Direcciones::Izquierda:
		if (matriz[yM][xM - 1] == 0 || matriz[yM][xM - 1] == 10 || matriz[yM][xM - 1] == 11 ||
			matriz[yM][xM - 1] == 12) {
			dx = -45; dy = 0; xM--; 
		}
		else if (Bloques && (matriz[yM][xM - 1] == 3)) {
			dx = -45; dy = 0; xM--;
		}
		else if (matriz[yM][xM - 1] == 5) {
			nivel++; cargado = false; Bloques = false;
		}
		else {
			dx = 0; dy = 0;
		}

		Ultima = Izquierda;
		break;
	case Direcciones::Ninguna:
		dx = dy = 0;
	}
	Dibujar(buffer);
}
int CJugador::Get_X() { return x; }
int CJugador::Get_Y() { return y; }
void CJugador::Set_X(int x) { this->x = x; }
void CJugador::Set_Y(int y) { this->y = y; }
int CJugador::Get_NBombas() { return Numero_Bombas; }
int CJugador::Get_Velocidad() { return Velocidad; }
int CJugador::Get_xM() { return xM; }
int CJugador::Get_yM() { return yM; }
bool CJugador::Get_Bloques() { return Bloques; }
void CJugador::Set_Bloques(bool value) { Bloques = value; }
int CJugador::Get_Vidas() { return Vidas; }
void CJugador::Set_Vidas(int value) { Vidas = value; }
void CJugador::Set_xM(int xM) { this->xM = xM; xMInicio = xM; }
void CJugador::Set_yM(int yM) { this->yM = yM; yMInicio = yM; }
void CJugador::Respawn() {
	if (Vidas > 0) {
		Vidas--; Bloques = false;
		xM = xMInicio; x = xM * 45;
		yM = yMInicio; y = yM * 45;
	}
}