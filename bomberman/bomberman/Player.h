#include<string>
using namespace std;
enum COLORS
{
	RED, GREEN, BLUE, BLACK, WHITE,LIGHTBLUE
	
};
class Player
{
	int vidas;
	string nickname;
	COLORS color;
public:
	Player();
	~Player();
};

