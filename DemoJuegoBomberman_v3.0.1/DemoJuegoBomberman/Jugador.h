#pragma once

using namespace System::Drawing;
enum Direcciones{ Ninguna, Arriba, Abajo, Derecha, Izquierda };
class CJugador
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int nivel;
	Direcciones Ultima;
	int Alto;
	int Ancho;
	int IndiceX;
	int IndiceY;
public:
	Direcciones Direcion;
	CJugador();
	~CJugador();
	CJugador(int x, int y);
	int getNivel(){ return nivel; }
	int getX(){ return x; }
	int getY(){ return y; }
	void Dibujar(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20],Bitmap ^fondo);
	void Dibujar_Muerte(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo);
	void Coliciones(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo, int i, int j, int X, int Y);
	void Mover(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20],Bitmap ^fondo);
};

CJugador::CJugador()
{
}


CJugador::~CJugador()
{
}

CJugador::CJugador(int x, int y){
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	nivel = 1;
	Direcion = Direcciones::Ninguna;
	Ultima = Direcciones::Abajo;
	Alto = 33;
	Ancho = 33;
	IndiceX = IndiceY = 0;

}

void CJugador::Coliciones(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo, int i, int j, int X, int Y){

	if (i >= 20){ return; }
	else
	{
		if (j < 20){
			System::Drawing::Rectangle  Jugador1 = System::Drawing::Rectangle(x + 10 + dx, y + 15 * 2, (Ancho - 21) * 2, (Alto - 25) * 2);
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador1);
			System::Drawing::Rectangle  Jugador2 = System::Drawing::Rectangle(x + 10, y + 15 * 2 + dy, (Ancho - 21) * 2, (Alto - 25) * 2);
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador2);
			
					System::Drawing::Rectangle  Rec1 = System::Drawing::Rectangle(X, Y, 32, 32);

					
						if (Mapa[i][j] == 1 || Mapa[i][j] == 7){
							if (Jugador1.IntersectsWith(Rec1))dx = 0;
							if (Jugador2.IntersectsWith(Rec1))dy = 0;
						}
						if (Mapa[i][j] == 3){
					
							if (Jugador1.IntersectsWith(Rec1)){ nivel++; x = 18; y = 20; }
							if (Jugador2.IntersectsWith(Rec1)){ nivel++; x = 18; y = 20; }
						}
						
						if (Mapa[i][j] == 2){
							//hacer que se vuelva mas lento la muerte 
							if (Jugador1.IntersectsWith(Rec1) || Jugador2.IntersectsWith(Rec1)){
								IndiceY = 4; IndiceX = 0;
								Dibujar_Muerte(Buffer, bmp, Mapa, fondo);
								x = 25; y = 20;

							}
						}
					
			
			Coliciones(Buffer, bmp, Mapa, fondo, i, j+1, X+32, Y);
		}
		else
		{
			Coliciones(Buffer, bmp, Mapa, fondo, i+1, 0, 0, Y+32);
		}
	}
}

void CJugador::Dibujar_Muerte(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo){
	bool a = true;
	while (a)
	{
		System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho*IndiceX, Alto*IndiceY, Ancho, Alto);
		System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, Ancho * 1.5, Alto * 1.5);
		Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
		IndiceX++;
		if (IndiceX >= 1000){
			a = false;
		}
	}
}

void CJugador::Dibujar(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], Bitmap ^fondo){

	Coliciones(Buffer, bmp, Mapa, fondo, 0, 0, 0, 0);

	System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho*IndiceX, Alto*IndiceY, Ancho, Alto);
	System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, Ancho * 1.5, Alto * 1.5);
	Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
	x = dx + x;
	y = dy + y;

}
void CJugador::Mover(BufferedGraphics^Buffer, Bitmap^ bmp, int Mapa[20][20], Bitmap ^fondo){
	Direcion == Arriba ? Ancho = 33 : Ancho = 33;

	switch (Direcion)
	{
	case Direcciones::Abajo:
		IndiceY = 0;
		if (IndiceX > 0 && IndiceX < 3)
			++IndiceX;
		else
			IndiceX = 1;
		dx = 0;
		dy = 5;
		Ultima = Abajo;
		break;
	case Direcciones::Arriba:
		IndiceY = 2;
		if (IndiceX >= 0 && IndiceX < 3)
			++IndiceX;
		else
			IndiceX = 0;
		dx = 0;
		dy = -5;
		Ultima = Arriba;
		break;
	case Direcciones::Derecha:
		IndiceY = 1;
		if (IndiceX > 0 && IndiceX < 3)
			++IndiceX;
		else
			IndiceX = 1;
		dx = 5;
		dy = 0;
		Ultima = Derecha;
		break;
	case Direcciones::Izquierda:
		IndiceY = 3;
		if (IndiceX > 0 && IndiceX < 3)
			++IndiceX;
		else
			IndiceX = 1;
		dx = -5;
		dy = 0;
		Ultima = Izquierda;
		break;
	case Direcciones::Ninguna:
		dx = dy = 0;
		switch (Ultima)
		{
		case Direcciones::Abajo:
			IndiceY = 0;
			IndiceX = 0;
			break;
		case Direcciones::Arriba:
			IndiceY = 2;
			IndiceX = 0;
			break;
		case Direcciones::Derecha:
			IndiceY = 1;
			IndiceX = 0;
			break;
		case Direcciones::Izquierda:
			IndiceY = 3;
			IndiceX = 0;
			break;
		default:
			break;
		}
		break;
	}

	Dibujar(Buffer, bmp, Mapa, fondo);
}