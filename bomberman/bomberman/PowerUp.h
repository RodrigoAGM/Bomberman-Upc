#pragma once
#include <string>

using namespace std;

class PowerUp
{
private:

	int x;
	int y;
	string type;

public:

	PowerUp(int x, int y);
	~PowerUp();
	void usePowerUp();
};