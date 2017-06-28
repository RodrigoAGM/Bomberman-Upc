#include "Player.h"
using namespace System;
Player::Player(int x, int y, string Nickname)
{
	Random rand;
	this->x = x;
	this->y = y;
	this->Nickname = Nickname;
	this->width = 45;
	this->height = 45; 
	this->dx = 0;
	this->dy = 0;
	this->portion = Rectangle(0, 0, 0, 0);
	this->speed = 0;
	R = rand.Next(0, 256);
	G = rand.Next(0, 256);
	B = rand.Next(0, 256);
}


Player::~Player()
{
}

void Player::paint(BufferedGraphics ^buffer) {
	SolidBrush ^mybrush = gcnew SolidBrush(Color::FromArgb(R, G, B));
	buffer->Graphics->FillRectangle(mybrush, x, y, width, height);
	x += dx;
	y += dy;
}
void Player::move(BufferedGraphics ^buffer) {
	switch (direccion)
	{
	case Direcciones::Abajo:
		dx = 0;
		dy = 45;
		last = Abajo;
		break;
	case Direcciones::Arriba:
		dx = 0;
		dy = -45;
		last = Arriba;
		break;
	case Direcciones::Derecha:

		dx = 45;
		dy = 0;
		last = Derecha;
		break;
	case Direcciones::Izquierda:


		dx = -45;
		dy = 0;
		last = Izquierda;
		break;
	case Direcciones::Ninguna:
		dx = dy = 0;
		/*switch (ultima)
		{
		case Arriba:
		indiceX = 0;
		indiceY = 3;
		break;
		case Abajo:
		indiceX = 0;
		indiceY = 0;
		break;
		case Izquierda:
		indiceX = 0;
		indiceY = 1;
		break;
		case Derecha:
		indiceX = 0;
		indiceY = 2;
		break;
		}*/
	}
	paint(buffer);
}
int Player::getX() { return x; }
int Player::getY() { return y; }
void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }
int Player::getNumberbombs(){ return Number_bombs; }
int Player::getSpeed() { return speed; }
/*void Player::letBombs(){}
void Player::kicksBombs(){}
void Player::throwBombs(){}
void Player::collectPower(){}*/