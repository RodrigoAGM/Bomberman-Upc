#pragma once
#include "FormUnJugador.h"

namespace BombermanUPC_Final {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormInicio
	/// </summary>
	public ref class FormInicio : public System::Windows::Forms::Form
	{
	public:
		FormInicio(void)
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
		~FormInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btnUnJugador;
	private: System::Windows::Forms::Button^  btnDosJugadores;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormInicio::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnUnJugador = (gcnew System::Windows::Forms::Button());
			this->btnDosJugadores = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(734, 536);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnUnJugador
			// 
			this->btnUnJugador->BackColor = System::Drawing::Color::Red;
			this->btnUnJugador->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnUnJugador->Font = (gcnew System::Drawing::Font(L"Elephant", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUnJugador->ForeColor = System::Drawing::Color::Transparent;
			this->btnUnJugador->Location = System::Drawing::Point(90, 486);
			this->btnUnJugador->Name = L"btnUnJugador";
			this->btnUnJugador->Size = System::Drawing::Size(183, 43);
			this->btnUnJugador->TabIndex = 1;
			this->btnUnJugador->Text = L"Un Jugador";
			this->btnUnJugador->UseVisualStyleBackColor = false;
			this->btnUnJugador->Click += gcnew System::EventHandler(this, &FormInicio::btnUnJugador_Click);
			// 
			// btnDosJugadores
			// 
			this->btnDosJugadores->BackColor = System::Drawing::Color::Red;
			this->btnDosJugadores->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDosJugadores->Font = (gcnew System::Drawing::Font(L"Elephant", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDosJugadores->ForeColor = System::Drawing::Color::Transparent;
			this->btnDosJugadores->Location = System::Drawing::Point(464, 486);
			this->btnDosJugadores->Name = L"btnDosJugadores";
			this->btnDosJugadores->Size = System::Drawing::Size(183, 43);
			this->btnDosJugadores->TabIndex = 2;
			this->btnDosJugadores->Text = L"Dos Jugadores";
			this->btnDosJugadores->UseVisualStyleBackColor = false;
			this->btnDosJugadores->Click += gcnew System::EventHandler(this, &FormInicio::btnDosJugadores_Click);
			// 
			// FormInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 535);
			this->Controls->Add(this->btnDosJugadores);
			this->Controls->Add(this->btnUnJugador);
			this->Controls->Add(this->pictureBox1);
			this->MaximumSize = System::Drawing::Size(746, 574);
			this->MinimumSize = System::Drawing::Size(746, 574);
			this->Name = L"FormInicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BombermanUPC";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnUnJugador_Click(System::Object^  sender, System::EventArgs^  e) {
		FormUnJugador^ Form1 = gcnew FormUnJugador("Jugador1", "", 1);
		this->Hide();  Form1->ShowDialog(); this->Close();

	}
	private: System::Void btnDosJugadores_Click(System::Object^  sender, System::EventArgs^  e) {

		FormUnJugador^ Form1 = gcnew FormUnJugador("Jugador1", "Jugador2", 2);
		this->Hide();  Form1->ShowDialog(); this->Close();
	}
};
}
