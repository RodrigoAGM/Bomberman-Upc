#pragma once
using namespace System::Drawing;

class Enemy
{
private:

	int speed;
	int xM;
	int yM;
	int x;
	int y;
	int dx;
	int dy;

public:

	Enemy(int x, int y);
	~Enemy();

	int Get_speed();
	int Get_xM();
	int Get_yM();
	int Get_x();
	int Get_y();
	int Get_dx();
	int Get_dy();

	void Set_speed(int value);
	void Set_xM(int value);
	void Set_yM(int value);
	void Set_x(int value);
	void Set_y(int value);
	void Set_dx(int value);
	void Set_dy(int value);

	void Move(int matriz[15][15]);
	void Draw(BufferedGraphics ^buffer, Bitmap ^Enemigo, int matriz[15][15]);
};