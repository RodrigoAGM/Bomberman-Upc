#pragma once
#include "Jugador.h"
#include "Mapas.h"
#include "Bombas.h"
#include "Enemigo.h"

namespace DemoJuegoBomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for formulario
	/// </summary>
	public ref class formulario : public System::Windows::Forms::Form
	{
	public:
		CJugador *jugador1;
		CBombas *Obj;
		Bitmap ^BmpJugador = gcnew Bitmap("bomberman.png");
		Bitmap ^BmpNivel1 = gcnew Bitmap("mapa1.png");
		Bitmap ^BmpNivel2 = gcnew Bitmap("mapa2.png");
		Bitmap ^BmpNivel3 = gcnew Bitmap("mapa3.png");
		Bitmap ^BmpNivel4 = gcnew Bitmap("mapa4.png");
		Bitmap ^BmpNivel5 = gcnew Bitmap("mapa5.png");
		Bitmap ^BmpBomba = gcnew Bitmap("Explocion.png");
		Bitmap ^BmpDetonar = gcnew Bitmap("Bomba.png");
		CEnemigo*objEnemy;
		Bitmap^ bmp_enemy;

	private: System::Windows::Forms::PictureBox^  pcbEnemy;
	private: System::Windows::Forms::Timer^  timer2;

	public:
		Bitmap ^BmpPared = gcnew Bitmap("Pared.png");
	public:
		formulario(void)
		{
			InitializeComponent();
			jugador1 = new CJugador(565,20);
			Obj = new CBombas();
			BmpJugador->MakeTransparent(BmpJugador->GetPixel(0, 0));
			BmpDetonar->MakeTransparent(BmpDetonar->GetPixel(0, 0));
			objEnemy = new CEnemigo();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~formulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:

	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(formulario::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pcbEnemy = (gcnew System::Windows::Forms::PictureBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcbEnemy))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 150;
			this->timer1->Tick += gcnew System::EventHandler(this, &formulario::timer1_Tick);
			// 
			// pcbEnemy
			// 
			this->pcbEnemy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pcbEnemy.Image")));
			this->pcbEnemy->Location = System::Drawing::Point(123, 78);
			this->pcbEnemy->Name = L"pcbEnemy";
			this->pcbEnemy->Size = System::Drawing::Size(128, 64);
			this->pcbEnemy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pcbEnemy->TabIndex = 1;
			this->pcbEnemy->TabStop = false;
			this->pcbEnemy->Visible = false;
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &formulario::timer2_Tick);
			// 
			// formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 650);
			this->Controls->Add(this->pcbEnemy);
			this->Name = L"formulario";
			this->Text = L"formulario";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &formulario::PresionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &formulario::SoltarTecla);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcbEnemy))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^G;
		G = this->CreateGraphics();
		BufferedGraphicsContext^Espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^Canvas = Espacio->Allocate(G, this->ClientRectangle);



		bmp_enemy = gcnew Bitmap(this->pcbEnemy->Image);
		bmp_enemy->MakeTransparent(bmp_enemy->GetPixel(1, 1));
		int g_ancho_enemigo = (int)G->VisibleClipBounds.Width;
		int g_largo_enemigo = (int)G->VisibleClipBounds.Height;

		if (jugador1->getNivel() == 1){
			Rectangle rFondo = Rectangle(0, 0, BmpNivel1->Width, BmpNivel1->Height);
			Canvas->Graphics->DrawImage(BmpNivel1, 0, 0, rFondo, GraphicsUnit::Pixel);
			jugador1->Mover(Canvas, BmpJugador, Mapa1, BmpNivel1);
			Obj->Dibujar(Canvas, BmpPared, Mapa1);
			if (Obj->getColocar() == true && Obj->getContador() != 0)
			{
				Obj->Bomba(Canvas, BmpDetonar, BmpBomba,Mapa1);
			}
			objEnemy->mover(Canvas->Graphics, bmp_enemy, Mapa1, BmpNivel1);
			objEnemy->dibujar_enemy(Canvas,bmp_enemy,Mapa1,BmpNivel1);
		}
		else
		{
			if (jugador1->getNivel() == 2){
				Rectangle rFondo = Rectangle(0, 0, BmpNivel2->Width, BmpNivel2->Height);
				Canvas->Graphics->DrawImage(BmpNivel2, 0, 0, rFondo, GraphicsUnit::Pixel);
				jugador1->Mover(Canvas, BmpJugador, Mapa2, BmpNivel2);
				Obj->Dibujar(Canvas, BmpPared, Mapa2);
				if (Obj->getColocar() == true && Obj->getContador() != 0)
				{
					Obj->Bomba(Canvas, BmpDetonar, BmpBomba,Mapa2);
				}
			}
			else{
				if (jugador1->getNivel() == 3){
					Rectangle rFondo = Rectangle(0, 0, BmpNivel3->Width, BmpNivel3->Height);
					Canvas->Graphics->DrawImage(BmpNivel3, 0, 0, rFondo, GraphicsUnit::Pixel);
					jugador1->Mover(Canvas, BmpJugador, Mapa3, BmpNivel3);
					Obj->Dibujar(Canvas, BmpPared, Mapa3);
					if (Obj->getColocar() == true && Obj->getContador() != 0)
					{
						Obj->Bomba(Canvas, BmpDetonar, BmpBomba,Mapa3);
					}
				}
				else
				{
					if (jugador1->getNivel() == 4){
						Rectangle rFondo = Rectangle(0, 0, BmpNivel4->Width, BmpNivel4->Height);
						Canvas->Graphics->DrawImage(BmpNivel4, 0, 0, rFondo, GraphicsUnit::Pixel);
						jugador1->Mover(Canvas, BmpJugador, Mapa4, BmpNivel4);
						Obj->Dibujar(Canvas, BmpPared, Mapa4);
						if (Obj->getColocar() == true && Obj->getContador() != 0)
						{
							Obj->Bomba(Canvas, BmpDetonar, BmpBomba,Mapa4);
						}
					}
					else
					{
						if (jugador1->getNivel() == 5){
							Rectangle rFondo = Rectangle(0, 0, BmpNivel5->Width, BmpNivel5->Height);
							Canvas->Graphics->DrawImage(BmpNivel5, 0, 0, rFondo, GraphicsUnit::Pixel);
							jugador1->Mover(Canvas, BmpJugador, Mapa5, BmpNivel5);
							Obj->Dibujar(Canvas, BmpPared, Mapa5);
							if (Obj->getColocar() == true&&Obj->getContador()!=0)
							{
								Obj->Bomba(Canvas, BmpDetonar, BmpBomba,Mapa5);
							}
						}
					}
				}
			}
		}
		Canvas->Render(G);
		delete G;
		delete Espacio;
		delete Canvas;
	}
	private: System::Void PresionarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		switch (e->KeyCode)
		{
		case Keys::W:
			jugador1->Direcion = Direcciones::Arriba;
			break;
		case Keys::A:
			jugador1->Direcion = Direcciones::Izquierda;
			break;
		case Keys::S:
			jugador1->Direcion = Direcciones::Abajo;
			break;
		case Keys::D:
			jugador1->Direcion = Direcciones::Derecha;
			break;
		
		case Keys::L:{
			Obj->setColocar(true);
			Obj->setX(jugador1->getX());
			Obj->setY(jugador1->getY());

		}			break;

		default:

			break;
		}
	}
	private: System::Void SoltarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		jugador1->Direcion = Direcciones::Ninguna;

	}


private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

}
};
}
