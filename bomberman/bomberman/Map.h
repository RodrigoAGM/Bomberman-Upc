#pragma once
#include "Player.h"
#include "PowerUp.h"
#include "Enemy.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using namespace System::Drawing;

class Map
{
private:

	int Width;
	int Heigth;
	int Number_enemy;
	int Number_Power;
	vector<Enemy*> Enemies;
	vector<PowerUp*> Powerups;

public:

	Map();
	~Map();
	void Read_Map(int n, BufferedGraphics ^buffer, Bitmap^ Bsolido,
		Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto);
	void Draw_Map(int map[15][15], BufferedGraphics ^buffer, Bitmap^ Bsolido,
		Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto);
};