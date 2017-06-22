#include "Enemy.h"

Enemy::Enemy(int xM, int yM)
{
	this->xM = xM;
	this->yM = yM;
	x = 0;
	y = 0;
	speed = 1;
	dx = 0;
	dy = 0;
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
