#pragma once
#include <string>

using namespace std;
using namespace System::Drawing;
enum COLORS
{
	RED, GREEN, BLUE, BLACK, WHITE, LIGHTBLUE
};
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
public:

	Player(int x, int y, string Nickname);
	~Player();
	void paint(Graphics^g, Bitmap^img);
	void move(Graphics^g, int index, bool pass,bool passb);
	int getX();
	int getY();
	void setDX(int dx);
	void setDY(int dy);
	int getNumberbombs();
	int getVelocidad();
	/*void letBombs();
	void kicksBombs();
	void throwBombs();
	void collectPower();*/
};