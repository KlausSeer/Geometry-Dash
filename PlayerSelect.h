#pragma once
#include "LevelSelect.h"
namespace GeomtryDash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PlayerSelect
	/// </summary>
	public ref class PlayerSelect : public System::Windows::Forms::Form
	{
	public:
		PlayerSelect(String^ Nom)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Nombre = gcnew String(Nom);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PlayerSelect()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		int Opcion = 1;
		bool Game = false;
		bool Menu = false;
		bool Activado = true;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  DeltaTime;


			 LevelSelect ^frm;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
			 String^ Nombre;
			 bool Nivel;
#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Método necesario para admitir el Diseñador. No se puede modificar
			 /// el contenido de este método con el editor de código.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PlayerSelect::typeid));
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->DeltaTime = (gcnew System::Windows::Forms::Timer(this->components));
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(197, 227);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 23);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Next";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &PlayerSelect::button1_Click);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
				 this->label1->Location = System::Drawing::Point(52, 79);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(178, 16);
				 this->label1->TabIndex = 2;
				 this->label1->Text = L"Selecciona el Personaje";
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(12, 227);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(75, 23);
				 this->button2->TabIndex = 3;
				 this->button2->Text = L"Menu";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &PlayerSelect::button2_Click);
				 // 
				 // DeltaTime
				 // 
				 this->DeltaTime->Tick += gcnew System::EventHandler(this, &PlayerSelect::DeltaTime_Tick);
				 // 
				 // button3
				 // 
				 this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
				 this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->button3->Location = System::Drawing::Point(8, 119);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(80, 80);
				 this->button3->TabIndex = 4;
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &PlayerSelect::button3_Click);
				 // 
				 // button4
				 // 
				 this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
				 this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->button4->Location = System::Drawing::Point(100, 119);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(80, 80);
				 this->button4->TabIndex = 5;
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &PlayerSelect::button4_Click);
				 // 
				 // button5
				 // 
				 this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
				 this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->button5->Location = System::Drawing::Point(189, 119);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(80, 80);
				 this->button5->TabIndex = 6;
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->Click += gcnew System::EventHandler(this, &PlayerSelect::button5_Click);
				 // 
				 // PlayerSelect
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(280, 257);
				 this->Controls->Add(this->button5);
				 this->Controls->Add(this->button4);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->button1);
				 this->Name = L"PlayerSelect";
				 this->Text = L"PlayerSelect";
				 this->Deactivate += gcnew System::EventHandler(this, &PlayerSelect::PlayerSelect_Deactivate);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
					public:bool GetNivel()
					{
						return Nivel;
					}
			 public: bool GetInGame()
			 {
				 return Game;
			 }

			 public:bool GetMenu()
			 {
				 return Menu;
			 }
public:bool GetActivado()
{
	return Activado;
}

	public:String^ GetNombre()
	{
		return Nombre;
	}
	

	public: int GetPersonaje()
	{
		return Opcion;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		frm = gcnew LevelSelect(Nombre, Opcion);
		Game = true;
		frm->Show();
			this->Hide();
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	Menu = true;
	Activado = false;
	this->Hide();
}
private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
	if(!frm->GetGame())
	{
		if (!frm->Visible)
		{
			this->Show();
			Nivel = frm->GetNivel();
			frm->Close();
			Game = false;
			if (frm->GetMenu())
			{
				Menu = true;
				this->Hide();
			}
				
			this->DeltaTime->Stop();
		}
	}
}
private: System::Void PlayerSelect_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (!Menu)
	{
		if (!frm->GetGame())
		{
			if (frm->GetActivado())
			{
				if (frm->Enabled)
					this->DeltaTime->Start();
			}
		}
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	button3->FlatStyle = FlatStyle::Flat;
	button4->FlatStyle = FlatStyle::Popup;
	button5->FlatStyle = FlatStyle::Popup;
	Opcion = 1;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	button3->FlatStyle = FlatStyle::Popup;
	button4->FlatStyle = FlatStyle::Flat;
	button5->FlatStyle = FlatStyle::Popup;
	Opcion = 2;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	button3->FlatStyle = FlatStyle::Popup;
	button4->FlatStyle = FlatStyle::Popup;
	button5->FlatStyle = FlatStyle::Flat;
	Opcion = 3;
}
};
}
