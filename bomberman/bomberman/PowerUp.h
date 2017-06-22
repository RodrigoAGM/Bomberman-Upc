#pragma once
#include <string>
using namespace System::Drawing;
using namespace std;

class PowerUp
{
private:

	int x;
	int y;
	int type;
	Rectangle pice;
	int width;
	int height;
	int counter;
public:

	PowerUp(int x, int y);
	PowerUp(int type,int x, int y);
	~PowerUp();
	void paintPowerUP(Graphics^g, Bitmap^img);
	Rectangle returnRectangle();
	int getType();
	int getCounter();
};