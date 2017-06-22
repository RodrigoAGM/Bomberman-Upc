#include "Player.h"

Player::Player(int x, int y, string Nickname)
{
	this->x = x;
	this->y = y;
	this->Nickname = Nickname;
	this->width = 0;
	this->height = 0; 
	this->dx = 0;
	this->dy = 0;
	this->portion = Rectangle(0, 0, 0, 0);
	this->speed = 0;
}


Player::~Player()
{
}

void Player::paint(Graphics^g, Bitmap^img){
	width = img->Width;
	height = img->Height;
	portion = Rectangle(0, 50, width, height);
	g->DrawImage(img, x, y, portion, GraphicsUnit::Pixel);

}
void Player::move(int **matriz, int index, bool pass,bool passb){
	int dx1 = 10;
	int dy1 = 10;
	int velocidad = 10;
	int h = 600;
	int w = 600;
	if (pass != true) {
		switch (index) {
		case 1:
			if (y + h > 715) {
				dx = 0;
				dy = 0;
			}
			else
				dy = speed;
			break;

		case 3:
			if (y - dy1 < 70) {
				dx = 0;
				dy = 0;
			}
			else
				dy = -speed;
			break;

		}

		x += dx;
		y += dy;

		dx = 0;
		dy = 0;
	}
	if (passb != true) {
		switch (index) {
		case 0:
			if (x - dx1 < 70) {
				dx = 0;
				dy = 0;
			}
			else
				dx = -speed;
			break;
		case 2:
			if (x + w > 691) {
				dx = 0;
				dy = 0;
			}
			else
				dx = speed;
			break;
		}
		x += dx;
		y += dy;

		dx = 0;
		dy = 0;
	}
	pass = false;
}
int Player::getX(){ return x; }
int Player::getY(){ return y; }
void Player::setDX(int dx) { this->dx = dx; }
void Player::setDY(int dy) { this->dy = dy; }
int Player::getNumberbombs(){ return Number_bombs; }
int Player::getSpeed() { return speed; }
/*void Player::letBombs(){}
void Player::kicksBombs(){}
void Player::throwBombs(){}
void Player::collectPower(){}*/