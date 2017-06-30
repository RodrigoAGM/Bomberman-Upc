#pragma once
#include "Map.h"

namespace bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		Bitmap^ Bsolido = gcnew Bitmap("BSolido.png");
		Bitmap^ BDestructible = gcnew Bitmap("BDestructible.png");
		Bitmap^ BBorde = gcnew Bitmap("BBorde.png");
		Bitmap^ BPasto = gcnew Bitmap("BPasto.png");
		Map *mapa = new Map();
		Player *player1 = new Player(45,45,"asd");
		Enemy *o = new Enemy(0, 0);

	private: System::Windows::Forms::Timer^  timer1;
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 90;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(675, 676);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext  ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacio->Allocate(g, this->ClientRectangle);
		int matriz[15][15] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{1,0,3,0,3,0,3,0,3,0,3,3,3,0,1 },
			{1,0,2,3,2,3,2,0,2,3,2,3,2,3,1 },
			{1,3,3,0,3,0,3,3,0,0,3,0,3,0,1 },
			{1,0,2,3,2,3,2,0,2,3,2,3,2,3,1 },
			{1,3,0,3,0,0,3,0,3,0,3,0,0,3,1 },
			{1,0,2,0,2,3,2,3,2,0,2,3,2,0,1 },
			{1,3,3,0,3,0,3,0,3,0,3,0,3,0,1 },
			{1,0,2,3,2,3,2,3,2,3,2,0,2,3,1 },
			{1,3,0,0,0,3,3,0,3,0,3,3,3,0,1 },
			{1,3,2,3,2,0,2,3,2,3,2,0,2,0,1 },
			{1,0,3,0,0,3,0,3,0,3,0,3,0,3,1 },
			{1,3,2,0,2,0,2,0,2,3,2,0,2,0,1 },
			{1,0,3,0,3,3,0,3,0,0,3,3,0,3,1 },
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
		GraphicsUnit::Pixel;
		mapa->Read_Map(1, buffer, Bsolido, BDestructible, BBorde, BPasto);
		//player1->move(buffer);
		o->Draw(buffer, BBorde, matriz);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			player1->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			player1->direccion = Direcciones::Abajo;
			break;
		case Keys::Left:
			player1->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			player1->direccion = Direcciones::Derecha;
			break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		player1->direccion = Direcciones::Ninguna;
	}
	};
}
