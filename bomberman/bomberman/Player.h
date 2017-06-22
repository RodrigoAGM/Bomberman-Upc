#pragma once
#include <string>

using namespace std;

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

public:

	Player(int x, int y, string Nickname);
	~Player();
	void letBombs();
	void kicksBombs();
	void walk();
	void throwBombs();
	void collectPower();
};