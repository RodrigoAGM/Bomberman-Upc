#include "Map.h"

Map::Map()
{
	Width = 15;
	Heigth = 15;
}

Map::~Map()
{
}

void Map::Read_Map(int n, BufferedGraphics ^buffer, Bitmap^ Bsolido,
	Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto) {

	ifstream fn;

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
	int matriz[15][15];
	for (int i = 0; i < Heigth; ++i) {

		getline(fn, linea);
		stringstream ss(linea);
		for (int j = 0; j < Width; ++j) {
			getline(ss, aux, ',');
			matriz[i][j] = atoi(aux.c_str());
		}
	}

	if (n < 11) {
		//Lee Enemigos
		getline(fn, aux); Number_enemy = atoi(aux.c_str());
		for (int i = 0; i < Number_enemy; ++i) {
			int xtemp, ytemp;
			getline(fn, linea); stringstream ss(linea);
			getline(ss, aux, ','); xtemp = atoi(aux.c_str());
			getline(ss, aux, ','); ytemp = atoi(aux.c_str());
			Enemies.push_back(new Enemy(xtemp, ytemp));
		}
	}

	//Lee Poderes
	getline(fn, aux); Number_Power = atoi(aux.c_str());
	for (int i = 0; i < Number_Power; ++i) {
		int xtemp, ytemp;
		getline(fn, linea); stringstream ss(linea);
		getline(ss, aux, ','); xtemp = atoi(aux.c_str());
		getline(ss, aux, ','); ytemp = atoi(aux.c_str());
		Powerups.push_back(new PowerUp(xtemp, ytemp));
	}

	Draw_Map(matriz, buffer, Bsolido, BDestructible, BBorde, BPasto);
	fn.close();
}
void Map::Draw_Map(int map[15][15], BufferedGraphics ^buffer, Bitmap^ Bsolido,
	Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto) {

	int xForm = 0; int yForm = 0;
	for (int i = 0; i < Heigth; ++i) {
		for (int j = 0; j < Width; ++j) {

			if (map[i][j] == 0) { buffer->Graphics->DrawImage(BPasto, xForm, yForm, 45, 45); }
			else if (map[i][j] == 1) { buffer->Graphics->DrawImage(BBorde, xForm, yForm, 45, 45); }
			else if (map[i][j] == 2) { buffer->Graphics->DrawImage(Bsolido, xForm, yForm, 45, 45); }
			else if (map[i][j] == 3) { buffer->Graphics->DrawImage(BDestructible, xForm, yForm, 45, 45); }
			xForm += 45;
		}
		yForm += 45;
		xForm = 0;
	}
}


