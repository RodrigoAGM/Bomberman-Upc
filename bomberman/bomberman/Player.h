#include<string>
using namespace std;
enum COLORS
{
	RED, GREEN, BLUE, BLACK, WHITE,LIGHTBLUE
	
};
class Player
{
	int Lifes;
	string Nickname;
	COLORS Color;
	int Number_bombs;
	int Items;
	int Power;

public:
	Player();
	~Player();
	void letBombs();
	void kicksBombs();
	void walk();
	void throwBombs();
	void collectPower();
};

