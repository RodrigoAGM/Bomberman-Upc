#pragma once

using namespace System::Drawing;
class CEnemigo
{
private:
	Rectangle img_enemy, porcion;
	int x, y, ancho, alto, indx, indy, dx,dy;

public:
	CEnemigo();
	~CEnemigo();
	void dibujar_enemy(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo);
	void mover(Graphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo);

};

CEnemigo::CEnemigo()
{
	x = 0, y = 0, ancho = 0, alto = 0, indx = 0, indy = 0, dx = 5, dy = 5;
	//img_enemy = Rectangle(0, 0, 32, 32);
	this->porcion = porcion;

}
CEnemigo::~CEnemigo()
{

}



void CEnemigo::dibujar_enemy(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo)
{


	Rectangle EnemyReal = System::Drawing::Rectangle(x + 10 + dx, y + 15 * 2, (ancho - 21) * 2, (alto - 25) * 2);
	Buffer->Graphics->DrawRectangle(Pens::White, EnemyReal);

	ancho = bmp->Width / 4;
	alto = bmp->Height / 2;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{

			Rectangle img_enemy = Rectangle(0, 0, 32, 32);

			if (Mapa[i][j] == 0)
				Buffer->Graphics->DrawRectangle(Pens::Transparent, 0, 0, 32, 32);
			else
				if (Mapa[i][j] == 1)
				{
					Buffer->Graphics->DrawRectangle(Pens::Transparent, 0, 0, 32, 32);
					if (EnemyReal.IntersectsWith(img_enemy)) { x = 224 - 32; y = 192 + 64; }
				}
			//IMPLEMENTAR PARA LOS DEMAS MAPAS.... pendiente...
		}
	}

	Rectangle  porcion_imagen = Rectangle(indx*ancho, indy*alto, ancho, alto);
	Buffer->Graphics->DrawImage(bmp, x, y, porcion_imagen, GraphicsUnit::Pixel);
	indx++;

	if (indx >= 4)
	{
		indx = 0;
	}
}


void  CEnemigo::mover(Graphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			
			if (Mapa[i][j] == 1)
			{
				
				if (x + dx <= 224 - 64 + 32 || x + dx + ancho>Buffer->VisibleClipBounds.Width - 256)
				{

					dx *= -1;
					
				}
			
			}
			//IMPLEMENTAR PARA LOS DEMAS MAPAS.... pendiente...
		}
	}
	x += dx;
	//y+=dy; 
}