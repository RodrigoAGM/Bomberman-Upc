#include "Gestor.h"

CGestor::CGestor(string Nombre, string Nombre2, int num, int nivel)
{
	oJugador = new CJugador(45, 45, Nombre);
	oMapa = new CMapa();
	Matriz = new int*[15];
	for (int i = 0; i < 15; ++i) {
		Matriz[i] = new int[15];
	}
	for (int i = 0; i < 3; i++) {
		oBomba.push(new CBomba());
		oBomba2.push(new CBomba());
	}
	Nivel = nivel;
	MapaCargado = false;
	oJugador2 = new CJugador(45, 45, Nombre2);
	NJugadores = num;
}

CGestor::~CGestor()
{
}

int CGestor::Get_Nivel() { return Nivel; }
void CGestor::Set_Nivel(int value) { Nivel = value; }
CMapa* CGestor::Get_Mapa() { return oMapa; }
CJugador* CGestor::Get_Jugador() { return oJugador; }
CJugador* CGestor::Get_Jugador2() { return oJugador2; }
int CGestor::Get_NJugadores() { return NJugadores; }
bool CGestor::Carga_Nivel_UnJugador() {
	if (Nivel <= 10) {
		Get_Bomba()->setcontador(1); Get_Bomba()->setColocar(false);
		oMapa->Leer_Mapa_unJugador(Matriz, Nivel, oJugador);
		return true;
	}
	return false;
}
bool CGestor::Carga_Nivel_Dos_Jugadores() {
	if (Nivel <= 20) {
		Get_Bomba()->setcontador(1); Get_Bomba()->setColocar(false);
		Get_Bomba2()->setcontador(1); Get_Bomba2()->setColocar(false);
		oMapa->Leer_Mapa_DosJugadores(Matriz, Nivel, oJugador, oJugador2);
		return true;
	}
	return false;
}
void CGestor::Dibuja_Nivel(BufferedGraphics ^buffer, Bitmap^ Bsolido, Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto) {
	oMapa->Dibujar_Mapa(Matriz, buffer, Bsolido, BDestructible, BBorde, BPasto);
	Dibujar_Enemigos(buffer);
	if (NJugadores == 1) {
		Colision_Enemigo_Jugador(oJugador); RecogePoderes(oJugador);
		oJugador->Mover(Matriz, MapaCargado, Nivel, buffer);
	}
	else {
		if(oJugador->Get_Vidas() != -1){ 
			Colision_Enemigo_Jugador(oJugador); RecogePoderes(oJugador); 
			oJugador->Mover(Matriz, MapaCargado, Nivel, buffer);
		}
		if (oJugador2->Get_Vidas() != -1) { 
			Colision_Enemigo_Jugador(oJugador2); RecogePoderes(oJugador2); 
			oJugador2->Mover(Matriz, MapaCargado, Nivel, buffer);
		}
	}
	
}
void CGestor::Plantar_Bomba(BufferedGraphics ^buffer, Bitmap^ bmp1, Bitmap^ bmp2) {
	
	if (!oBomba.empty()) {
		CBomba* bombaFront = oBomba.front();
		if (NJugadores == 1) {
			bombaFront->Bomba(buffer, bmp1, bmp2, Matriz, oMapa, oJugador, NULL);
		}
		else {
			bombaFront->Bomba(buffer, bmp1, bmp2, Matriz, oMapa, oJugador, oJugador2);
		}
	}
}
CBomba *CGestor::Get_Bomba() {
	return oBomba.front();
}
void CGestor::Plantar_Bomba2(BufferedGraphics ^buffer, Bitmap^ bmp1, Bitmap^ bmp2) {
	
	if (!oBomba2.empty()) {
		CBomba* bombaFront = oBomba2.front();
		bombaFront->Bomba(buffer, bmp1, bmp2, Matriz, oMapa, oJugador2, oJugador);
	}
}
CBomba *CGestor::Get_Bomba2() {
	return oBomba2.front();
}
bool CGestor::Get_MapaCargado() { return MapaCargado; }
void CGestor::Set_MapaCargado(bool value) { MapaCargado = value; }
void CGestor::Dibujar_Enemigos(BufferedGraphics ^buffer) {
	for (int i = 0; i < oMapa->Get_NEnemigos(); ++i) {
		oMapa->Get_Enemigos()[i]->Dibujar(buffer, Matriz);
	}
}
void CGestor::Colision_Enemigo_Jugador(CJugador *oJ) {
	
	int xMaux = oJ->Get_xM(), yMaux = oJ->Get_yM();
	if (oMapa->Get_Enemigo(xMaux, yMaux) != NULL) {
		if (oJ->Get_Vidas() == 0) { oJ->Set_Vidas(-1); }
		else { oJ->Respawn(); }
	}
}
void CGestor::RecogePoderes(CJugador *oJ) {
	if (Matriz[oJ->Get_yM()][oJ->Get_xM()] == 10) {
		Matriz[oJ->Get_yM()][oJ->Get_xM()] = 0;
		oMapa->Get_Poder(oJ->Get_xM(), oJ->Get_yM())->Poder_Muerte(oJ);
	}
	else if (Matriz[oJ->Get_yM()][oJ->Get_xM()] == 11) {
		Matriz[oJ->Get_yM()][oJ->Get_xM()] = 0;
		oMapa->Get_Poder(oJ->Get_xM(), oJ->Get_yM())->Poder_Corazon(oJ);
	}
	else if (Matriz[oJ->Get_yM()][oJ->Get_xM()] == 12) {
		Matriz[oJ->Get_yM()][oJ->Get_xM()] = 0;
		oMapa->Get_Poder(oJ->Get_xM(), oJ->Get_yM())->Poder_Bloques(oJ);
	}
}
void CGestor::ColarBomba() {
	oBomba.pop();
	if (oBomba.size() == 0) {
		oBomba.push(new CBomba());
		oBomba.push(new CBomba());
		oBomba.push(new CBomba());
	}
}
void CGestor::ColarBomba2() {
	oBomba2.pop();
	if (oBomba2.size() == 0) {
		oBomba2.push(new CBomba());
		oBomba2.push(new CBomba());
		oBomba2.push(new CBomba());
	}
}