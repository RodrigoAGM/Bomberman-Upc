#include "Mapa.h"

CMapa::CMapa()
{
	Ancho = 15;
	Alto = 15;
}

CMapa::~CMapa()
{
}

void CMapa::Leer_Mapa_unJugador(int **mapa, int n, CJugador* oJ) {

	ifstream fn; 

	for (int i = 0; i < Poderes.size(); ++i) {
		delete Poderes[i];
	}
	for (int i = 0; i < Enemigos.size(); ++i) {
		delete Enemigos[i];
	}
	Poderes.clear(); Enemigos.clear();

	switch (n)
	{
	case 1:
		fn.open("Mapa1.txt"); break;
	case 2:
		fn.open("Mapa2.txt"); break;
	case 3:
		fn.open("Mapa3.txt"); break;
	case 4:
		fn.open("Mapa4.txt"); break;
	case 5:
		fn.open("Mapa5.txt"); break;
	case 6:
		fn.open("Mapa6.txt"); break;
	case 7:
		fn.open("Mapa7.txt"); break;
	case 8:
		fn.open("Mapa8.txt"); break;
	case 9:
		fn.open("Mapa9.txt"); break;
	case 10:
		fn.open("Mapa10.txt"); break;
	}

	string linea, aux;

	//Lee Matriz
	for (int i = 0; i < Alto; ++i) {

		getline(fn, linea);
		stringstream ss(linea);
		for (int j = 0; j < Ancho; ++j) {
			getline(ss, aux, ',');
			mapa[i][j] = atoi(aux.c_str());
		}
	}

	if (n < 11) {
		//Lee Enemigos
		getline(fn, aux); Numero_Enemigos = atoi(aux.c_str());
		for (int i = 0; i < Numero_Enemigos; ++i) {
			int xtemp, ytemp;
			getline(fn, linea); stringstream ss(linea);
			getline(ss, aux, ','); xtemp = atoi(aux.c_str());
			getline(ss, aux, ','); ytemp = atoi(aux.c_str());
			Enemigos.push_back(new CEnemigo(xtemp, ytemp));
		}
	}

	//Lee Poderes
	getline(fn, aux); Numero_Poderes = atoi(aux.c_str());
	for (int i = 0; i < Numero_Poderes; ++i) {
		int xtemp, ytemp, tipotemp;
		getline(fn, linea); stringstream ss(linea);
		getline(ss, aux, ','); tipotemp = atoi(aux.c_str());
		getline(ss, aux, ','); xtemp = atoi(aux.c_str());
		getline(ss, aux, ','); ytemp = atoi(aux.c_str());
		Poderes.push_back(new CPoder(tipotemp, xtemp, ytemp));
	}

	getline(fn, linea); stringstream ss1(linea);
	getline(ss1, aux, ','); xSalida= atoi(aux.c_str());
	getline(ss1, aux, ','); ySalida = atoi(aux.c_str());

	getline(fn, linea); stringstream ss2(linea);
	getline(ss2, aux, ','); oJ->Set_xM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ->Set_yM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ->Set_X(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ->Set_Y(atoi(aux.c_str()));

	fn.close();
}
void CMapa::Leer_Mapa_DosJugadores(int **mapa, int n, CJugador* oJ1, CJugador* oJ2) {

	ifstream fn;

	for (int i = 0; i < Poderes.size(); ++i) {
		delete Poderes[i];
	}
	for (int i = 0; i < Enemigos.size(); ++i) {
		delete Enemigos[i];
	}
	Poderes.clear(); Enemigos.clear();

	switch (n)
	{
	case 11:
		fn.open("Mapa11.txt"); break;
	case 12:
		fn.open("Mapa12.txt"); break;
	case 13:
		fn.open("Mapa13.txt"); break;
	case 14:
		fn.open("Mapa14.txt"); break;
	case 15:
		fn.open("Mapa15.txt"); break;
	case 16:
		fn.open("Mapa16.txt"); break;
	case 17:
		fn.open("Mapa17.txt"); break;
	case 18:
		fn.open("Mapa18.txt"); break;
	case 19:
		fn.open("Mapa19.txt"); break;
	case 20:
		fn.open("Mapa20.txt"); break;
	}

	string linea, aux;

	//Lee Matriz
	for (int i = 0; i < Alto; ++i) {

		getline(fn, linea);
		stringstream ss(linea);
		for (int j = 0; j < Ancho; ++j) {
			getline(ss, aux, ',');
			mapa[i][j] = atoi(aux.c_str());
		}
	}

	//Lee Enemigos
	getline(fn, aux); Numero_Enemigos = atoi(aux.c_str());
	for (int i = 0; i < Numero_Enemigos; ++i) {
		int xtemp, ytemp;
		getline(fn, linea); stringstream ss(linea);
		getline(ss, aux, ','); xtemp = atoi(aux.c_str());
		getline(ss, aux, ','); ytemp = atoi(aux.c_str());
		Enemigos.push_back(new CEnemigo(xtemp, ytemp));
	}

	//Lee Poderes
	getline(fn, aux); Numero_Poderes = atoi(aux.c_str());
	for (int i = 0; i < Numero_Poderes; ++i) {
		int xtemp, ytemp, tipotemp;
		getline(fn, linea); stringstream ss(linea);
		getline(ss, aux, ','); tipotemp = atoi(aux.c_str());
		getline(ss, aux, ','); xtemp = atoi(aux.c_str());
		getline(ss, aux, ','); ytemp = atoi(aux.c_str());
		Poderes.push_back(new CPoder(tipotemp, xtemp, ytemp));
	}

	getline(fn, linea); stringstream ss1(linea);
	getline(ss1, aux, ','); xSalida = atoi(aux.c_str());
	getline(ss1, aux, ','); ySalida = atoi(aux.c_str());

	getline(fn, linea); stringstream ss2(linea);
	getline(ss2, aux, ','); oJ1->Set_xM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ1->Set_yM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ1->Set_X(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ1->Set_Y(atoi(aux.c_str()));

	getline(fn, linea); stringstream ss3(linea);
	getline(ss3, aux, ','); oJ2->Set_xM(atoi(aux.c_str()));
	getline(ss3, aux, ','); oJ2->Set_yM(atoi(aux.c_str()));
	getline(ss3, aux, ','); oJ2->Set_X(atoi(aux.c_str()));
	getline(ss3, aux, ','); oJ2->Set_Y(atoi(aux.c_str()));

	fn.close();
}
void CMapa::Dibujar_Mapa(int **mapa, BufferedGraphics ^buffer, Bitmap^ Bsolido, Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto) {

	int xForm = 0; int yForm = 0;
	for (int i = 0; i < Alto; ++i) {
		for (int j = 0; j < Ancho; ++j) {

			if (mapa[i][j] == 0) { buffer->Graphics->DrawImage(BPasto, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 1) { buffer->Graphics->DrawImage(BBorde, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 2) { buffer->Graphics->DrawImage(Bsolido, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 3) { buffer->Graphics->DrawImage(BDestructible, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 5) { buffer->Graphics->DrawImage(Image::FromFile("Salida.png"), xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 10) { buffer->Graphics->DrawImage(Image::FromFile("Poder_Muerte.jpg"), xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 11) { buffer->Graphics->DrawImage(Image::FromFile("Poder_Corazon.png"), xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 12) { buffer->Graphics->DrawImage(Image::FromFile("Poder_Bloques.png"), xForm, yForm, 45, 45); }
			xForm += 45;
		}
		yForm += 45;
		xForm = 0;
	}
}
int CMapa::Get_NEnemigos() { return Numero_Enemigos; }
int CMapa::Get_NPoderes(){ return Numero_Poderes; }
vector<CEnemigo*> CMapa::Get_Enemigos() { return Enemigos; }
vector<CPoder*> CMapa::Get_Poderes() { return Poderes; }
int CMapa::Get_XSalida() { return xSalida; }
int CMapa::Get_YSalida() { return ySalida; }
CPoder *CMapa::Get_Poder(int xM, int yM) {

	for (int i = 0; i < Poderes.size(); ++i) {
		if (Poderes[i]->Get_X() == xM && Poderes[i]->Get_Y() == yM) {
			return Poderes[i];
		}
	}
	return NULL;
}
CEnemigo *CMapa::Get_Enemigo(int xM, int yM) {

	for (int i = 0; i < Enemigos.size(); ++i) {
		if (Enemigos[i]->Get_xM() == xM && Enemigos[i]->Get_yM() == yM) {
			if (Enemigos[i]->Get_Muerto() == false) {
				return Enemigos[i];
			}
		}
	}
	return NULL;
}