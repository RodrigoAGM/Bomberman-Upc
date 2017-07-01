#pragma once


using namespace System::Drawing;
using namespace std;
using namespace System;


class CBombas
{
public:
	int x;
	int y;
	bool colocar;
	int Indicex;
	int contador;
	int derecha;
	int izquierda;
	int arriba;
	int abajo;
	int IndiceY_E;

public:
	CBombas();
	~CBombas();
	bool setColocar(bool colocar){ return(this->colocar = colocar); }
	int setX(int x){ return(this->x = x); }
	int setY(int y){ return(this->y = y); }
	bool getColocar(){ return colocar; }
	int setcontador(int contador){ return(this->contador = contador); }
	int getContador(){return contador;}
	void Colicion(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], int i, int j, int X, int Y, int Ancho, int Alto);
	void Dibujar(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20]);
	void Bomba(BufferedGraphics^Buffer, Bitmap^bmp2, Bitmap^bmp3, int Mapa[20][20]);
	void Colicion_B(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], int i, int j, int X, int Y, int Ancho, int Alto, int x, int y, int IndiceX);
	void Colicion_P(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], int i, int j, int X, int Y, int Ancho, int Alto, int x, int y, int IndiceX);

};

CBombas::CBombas(){
    x = 0;
    y = 0;
	colocar = false;
	Indicex = 0;
	contador = 1;
    derecha=1;
    izquierda=1;
    arriba=1;
    abajo=1;
	IndiceY_E=3;
}


CBombas::~CBombas(){}


void CBombas::Colicion(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], int i, int j, int X, int Y, int Ancho, int Alto){

	int ind = 0;
	if (i >= 20){ return; }
	else
	{
		if (j < 20){
			if (Mapa[i][j] == 0){

			}
				if ( Mapa[i][j] == 7){
					ind = 1;
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho*ind, Alto, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(X, Y, Ancho, Alto );
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
				}
				if (Mapa[i][j] == 10){
					ind = 2;
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * ind, Alto, Ancho, Alto-5);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(X, Y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
				}	
				if (Mapa[i][j] == 11){
					ind = 3;
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * ind, Alto, Ancho, Alto-5);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(X, Y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
				}	
				if (Mapa[i][j] == 12){
					ind = 4;
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * ind, Alto, Ancho, Alto-5);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(X, Y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
				}	
				if (Mapa[i][j] == 13){
					ind = 5;
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * ind, Alto, Ancho, Alto-5);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(X, Y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
				}

			Colicion(Buffer, bmp, Mapa, i, j + 1, X + 32, Y,Ancho,Alto);
		}
		else
		{
			Colicion(Buffer, bmp, Mapa, i + 1, 0, 0, Y + 32,Ancho,Alto);
		}
	}
}
void CBombas::Dibujar(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20]){

		Colicion(Buffer, bmp, Mapa, 0, 0, 0, 0, 32, 32);

}


void CBombas::Bomba(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap^bmp2, int Mapa[20][20]){
	    int Ancho = 59;
		int Alto = 100;
		System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * Indicex+3, 0, Ancho, Alto);
		System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x + 12, y + 10, Ancho*0.45, Alto*0.45);
		Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);

		Indicex++;
		contador++;
		if (Indicex>=3){ 
			Indicex = 1;
		}
		if (contador >= 30){ Indicex = 0; colocar = false; contador = 0; contador++; 

		Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 26, 0);
		Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 39, y + 26, 5);
		Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 12, y + 26, 6);
		Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 51, 4);
		Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 3, 3);
		
		Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 26, 0);
		Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 39, y + 26, 5);
		Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 12, y + 26, 6);
		Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 51, 4);
		Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 3, 3);

		

		return; }

}

void CBombas::Colicion_B(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], int i, int j, int X, int Y, int Ancho, int Alto,int x,int y,int IndiceX_E){
	Random rand;
	int cambio = rand.Next(9, 20);
	if (i >= 20){ return; }
	else
	{
		if (j < 20){
			System::Drawing::Rectangle  Jugador1 = System::Drawing::Rectangle(x  , y , (Ancho-17 ) , (Alto-20) );
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador1);
		
			System::Drawing::Rectangle  Rec1 = System::Drawing::Rectangle(X, Y, 32, 32);

			if (Mapa[i][j] == 0 ){
			
				if (Jugador1.IntersectsWith(Rec1)){
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, 0, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
				}
			}

			if (Mapa[i][j] == 7 ){

				if (Jugador1.IntersectsWith(Rec1)){
					
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, 0, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
					if (cambio > 14)
						Mapa[i][j] = 0;
					else
						Mapa[i][j] = cambio;
				}

			}
		
			Colicion_B(Buffer, bmp, Mapa, i, j + 1, X + 32, Y, Ancho, Alto,x,y,IndiceX_E);
		}
		else
		{
			Colicion_B(Buffer, bmp, Mapa, i + 1, 0, 0, Y + 32, Ancho, Alto,x,y,IndiceX_E);
		}
	}

}

void CBombas::Colicion_P(BufferedGraphics^Buffer, Bitmap^bmp, int Mapa[20][20], int i, int j, int X, int Y, int Ancho, int Alto, int x, int y, int IndiceX_E){

	if (i >= 20){ return; }
	else
	{
		if (j < 20){
			System::Drawing::Rectangle  Jugador1 = System::Drawing::Rectangle(x, y, (Ancho - 17), (Alto - 20));
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador1);

			System::Drawing::Rectangle  Rec1 = System::Drawing::Rectangle(X, Y, 32, 32);

	

			if (Mapa[i][j] == 10 || Mapa[i][j] == 11 || Mapa[i][j] == 12 || Mapa[i][j] == 13 ){

				if (Jugador1.IntersectsWith(Rec1)){

					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, 0, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
						Mapa[i][j] = 0;
				}

			}

			Colicion_B(Buffer, bmp, Mapa, i, j + 1, X + 32, Y, Ancho, Alto, x, y, IndiceX_E);
		}
		else
		{
			Colicion_B(Buffer, bmp, Mapa, i + 1, 0, 0, Y + 32, Ancho, Alto, x, y, IndiceX_E);
		}
	}

}

