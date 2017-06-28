#pragma once
#include <string>

using namespace std;
using namespace System::Drawing;
enum COLORS
{
	RED, GREEN, BLUE, BLACK, WHITE, LIGHTBLUE
};
enum Direcciones { Ninguna, Arriba, Abajo, Izquierda, Derecha };
class Player
{
	int Lifes;
	string Nickname;
	COLORS Color;
	int Number_bombs;
	int Items;
	int Power;
	int x;
	int y;
	int dx;
	int dy;
	int width;
	int height;
	Rectangle portion;
	int speed;
	int R;
	int G;
	int B;
	Direcciones last;
public:
	Direcciones direccion;
	Player(int x, int y, string Nickname);
	~Player();
	void paint(BufferedGraphics ^buffer);
	void move(BufferedGraphics ^buffer);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getNumberbombs();
	int getSpeed();
	/*void letBombs();
	void kicksBombs();
	void throwBombs();
	void collectPower();*/
};