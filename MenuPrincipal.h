#pragma once
#include "PlayerName.h"
#include "PlayerSelect.h"
#include "Highscores.h"
namespace GeomtryDash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Name = gcnew String("");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		PlayerName^ Nombre;
		String ^ Name;
		Highscores^ High;
		bool Clicked = false;
	private: System::Windows::Forms::Timer^  DeltaTime;
			 int Per = 0;
			 bool Nivel;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->DeltaTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(107, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(197, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Highscores";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuPrincipal::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 227);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Datos";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuPrincipal::button3_Click);
			// 
			// DeltaTime
			// 
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &MenuPrincipal::DeltaTime_Tick);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Deactivate += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Deactivate);
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->Leave += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Leave);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Nombre = gcnew PlayerName();
		this->Hide();
		Nombre->Show();
	}
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (!Nombre->Visible)
		{
			if (!Nombre->GetMostrando())
			{
			this->Show();
			Per = Nombre->GetPersonaje();
			Name = Nombre->GetNombre();
			Nivel = Nombre->GetNivel();
			Nombre->Close();
			this->DeltaTime->Stop();
			}
		}
	}
private: System::Void MenuPrincipal_Leave(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void MenuPrincipal_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (!Clicked)
	{
		if (!Nombre->GetMostrando())
		{
			if (Nombre->GetActivado())
			{
				if (Nombre->Enabled)
					this->DeltaTime->Start();
			}
		}

	}

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Name == "")
	{
		Nombre = gcnew PlayerName();
		this->Hide();
		Nombre->Show();
	}

	if (Name != "")
	{
		MyForm ^frm = gcnew MyForm(Per, Name, Nivel);
		this->Hide();
		this->DeltaTime->Stop();
		frm->ShowDialog();
		this->Show();
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	High = gcnew Highscores(true);
	Clicked = true;
	High->ShowDialog();
}
};
}
