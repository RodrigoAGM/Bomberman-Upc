#include<string>
using namespace std;
enum COLORS
{
	RED, GREEN, BLUE, BLACK, WHITE
};
class Player
{
	string nickname;
	COLORS color;
public:
	Player();
	~Player();

	void setNickname(string nickname) {
		this->nickname = nickname;
	}

	string getNickname() {
		return this->nickname;
	}

};

