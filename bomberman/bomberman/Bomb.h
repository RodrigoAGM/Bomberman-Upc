#pragma once
class Bomb
{
private:

	int Rank;
	bool Colocated;

public:

	Bomb();
	~Bomb();
	void UseBombs();
	void Move();
};