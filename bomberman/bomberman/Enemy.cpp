#include "Enemy.h"

Enemy::Enemy(int xM, int yM)
{
	this->xM = xM;
	this->yM = yM;
	x = 45;
	y = 45;
	speed = 1;
	dx = 1;
	dy = 1;
}



Enemy::~Enemy()
{
}

int Enemy::Get_speed() { return speed; }
int Enemy::Get_xM() { return xM; }
int Enemy::Get_yM() { return yM; }
int Enemy::Get_x() { return x; }
int Enemy::Get_y() { return y; }
int Enemy::Get_dx() { return dx; }
int Enemy::Get_dy() { return dy; }

void Enemy::Set_speed(int value) { speed = value; }
void Enemy::Set_xM(int value) { xM = value; }
void Enemy::Set_yM(int value) { yM = value; }
void Enemy::Set_x(int value) { x = value; }
void Enemy::Set_y(int value) { y = value; }
void Enemy::Set_dx(int value) { dx = value; }
void Enemy::Set_dy(int value) { dy = value; }

void Enemy::Draw(BufferedGraphics ^buffer, Bitmap ^Enemigo, int matriz[15][15]) {
	SolidBrush ^mybrush = gcnew SolidBrush(Color::FromArgb(50, 50, 50));
	buffer->Graphics->FillRectangle(mybrush, x, y, 45, 45);
	//buffer->Graphics->DrawImage(Enemigo, x, y, 35, 35);
	Move(matriz);
}

void Enemy::Move(int matriz[15][15]) {

	if ((matriz[yM][xM - 1] == 2 || matriz[yM][xM - 1] == 3) /*&& (matriz[yM][xM - 1] == 2 || matriz[yM][xM - 1] == 3)*/) {
		if (matriz[yM + 1][xM] == 2 || matriz[yM + 1][xM] == 3) {
			yM += 1;
			y += dy;
		}
		else {
			yM -= 1;
			y -= dy;
		}
	}
	else {

		if (matriz[yM][xM + 1] == 2 || matriz[yM][xM + 1] == 3) {
			xM -= 1;
			x -= dx;
		}
		else {
			xM += 1;
			x += dx;
		}
	}
}