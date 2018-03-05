#pragma once
#include "GameManager.h"
#include "Highscores.h"
namespace GeomtryDash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GameOver
	/// </summary>
	public ref class GameOver : public System::Windows::Forms::Form
	{
	public:
		GameOver(String^ Nom, GameManager* Game)
		{
			InitializeComponent();
			//
			//TODb O: agregar código de constructor aquí
			//
			GM = new GameManager(*Game);
			Nombre = gcnew String(Nom);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GameOver()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		GameManager* GM;
	private: System::Windows::Forms::Button^  button3;
			 String^ Nombre;
			 bool Menu = false;
			 bool Activado = true;
			 bool SHighscore = false;
			 bool Nivel;
			 Highscores^ High;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Método necesario para admitir el Diseñador. No se puede modificar
			 /// el contenido de este método con el editor de código.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameOver::typeid));
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(12, 227);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 23);
				 this->button1->TabIndex = 0;
				 this->button1->Text = L"Reset";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &GameOver::button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(197, 227);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(75, 23);
				 this->button2->TabIndex = 1;
				 this->button2->Text = L"Highscore";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &GameOver::button2_Click);
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(107, 227);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(75, 23);
				 this->button3->TabIndex = 2;
				 this->button3->Text = L"Menu";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &GameOver::button3_Click);
				 // 
				 // GameOver
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(283, 256);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->Name = L"GameOver";
				 this->Text = L"GameOver";
				 this->Load += gcnew System::EventHandler(this, &GameOver::GameOver_Load);
				 this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameOver::GameOver_Paint);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	public:bool GetSHighscore()
	{
		return SHighscore;
	}
	public:bool GetMenu()
	{
		return Menu;
	}
	public: bool GetActivado()
	{
		return Activado;
	}
			 void MarshalString(String^ s, string& os)
			 {
				 using namespace Runtime::InteropServices;
				 const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
			 }


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Activado = false;
		this->Hide();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		High = gcnew Highscores(Nivel);
		SHighscore = true;
		High->ShowDialog();
		SHighscore = false;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{

		string nombre;
		MarshalString(Nombre, nombre);
		GM->RegistrarPuntuacion(nombre);
		Activado = false;
		Menu = true;
		this->Hide();
	}
	private: System::Void GameOver_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	}
private: System::Void GameOver_Load(System::Object^  sender, System::EventArgs^  e) {
	Nivel = GM->GetComplete();

}
};
}
