#pragma once
enum COLORS
{
	RED, GREEN, BLUE, BLACK, WHITE, LIGHTBLUE

};
class Enemy
{
private:
	int speed;
public:
	Enemy();
	~Enemy();
	void Move();
};

