#include "PowerUp.h"

PowerUp::PowerUp(int x, int y)
{
	this->x = x;
	this->y = y;


}
PowerUp::PowerUp(int type,int x, int y)
{
	this->x = x;
	this->y = y;
	this->type = type;
}

PowerUp::~PowerUp()
{

}
void PowerUp::paintPowerUP(Graphics^g, Bitmap^img) {
	width = img->Width ;
	height = img->Height ;

	Rectangle portion;
	switch (type) {
	case 1:
		portion = Rectangle(width * 2, height * 0, width, height);
		break;
	case 2:
		portion = Rectangle(width * 3, height * 0, width, height);
		break;
	case 3:
		portion = Rectangle(width * 4, height * 0, width, height);
		break;
	case 4:
		portion = Rectangle(width * 0, height * 1, width, height);
		break;
	case 5:
		portion = Rectangle(width * 3, height * 1, width, height);
	}
	g->DrawImage(img, x, y, portion, GraphicsUnit::Pixel);
	counter++;
}
Rectangle PowerUp::returnRectangle() {
	return Rectangle(x, y, 45, 45);
}
int PowerUp::getType() {
	return type;
}
int PowerUp::getCounter() {
	return counter;
}