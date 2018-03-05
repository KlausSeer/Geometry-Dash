#pragma once
#include "MyForm.h"
#include "GameManager.h"
namespace GeomtryDash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de LevelSelect
	/// </summary>
	public ref class LevelSelect : public System::Windows::Forms::Form
	{
	public:
		LevelSelect(String^ Nom, int opcion)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Op = opcion;
			Nombre = gcnew String(Nom);
			GM = new GameManager();
			this->Game = false;
			Menu = false;
			Activado = true;
			Nivel = false;
			Complete = false;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~LevelSelect()
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
		/// Variable del diseñador necesaria.
		/// </summary>


	private: System::Windows::Forms::Timer^  DeltaTime;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
			 GameManager* GM;
			 bool Game;
			 bool Menu;
			 bool Activado;
			 bool Nivel;
			 String^ Nombre;
			 MyForm ^frm;
			 bool Complete;

			 int Op;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LevelSelect::typeid));
			this->DeltaTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// DeltaTime
			// 
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &LevelSelect::DeltaTime_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Next";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LevelSelect::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 87);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 100);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LevelSelect::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(172, 87);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 100);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &LevelSelect::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 227);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Menu";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &LevelSelect::button4_Click);
			// 
			// LevelSelect
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"LevelSelect";
			this->Text = L"LevelSelect";
			this->Deactivate += gcnew System::EventHandler(this, &LevelSelect::LevelSelect_Deactivate);
			this->Load += gcnew System::EventHandler(this, &LevelSelect::LevelSelect_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		void CheckWin()
		{
			GM->LeerHighscores();
			for (unsigned int i = 0; i < GM->GetParticipantes().size(); i++)
			{
				if (GM->GetParticipantes()[i]->GetCompleto())
					Complete = true;
			}
			
		}
				public:bool GetNivel()
				{
					return Nivel;
				} 
	public:bool GetMenu()
	{
		return Menu;
	}
	public:bool GetGame()
	{
 		return this->Game;
	}
	public:bool GetActivado()
	{
		return Activado;
	}
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (!frm->GetOver())
		{
			if (!frm->Visible)
			{
				this->Show();
				frm->Close();
				this->Game = false;
				if (frm->GetMenu())
				{
					Menu = true;
					this->Hide();
				}

				this->DeltaTime->Stop();
			}
		}

	}
	private: System::Void LevelSelect_Deactivate(System::Object^  sender, System::EventArgs^  e) {
		if (!Menu)
		{
			if (!frm->GetOver())
			{
				if (frm->GetActivado())
				{
					if (frm->Enabled)
						this->DeltaTime->Start();
				}
			}
		}

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		frm = gcnew MyForm(Op, Nombre, Nivel);
		this->Hide();
		this->Game = true;
		frm->Show();

	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	Menu = true;
	Activado = false;
	this->Hide();

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Nivel = false;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
if(Complete)
	Nivel = true;
}
private: System::Void LevelSelect_Load(System::Object^  sender, System::EventArgs^  e) {
	CheckWin();
}
};
}
