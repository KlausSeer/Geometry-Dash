#pragma once
#include "GameManager.h"
namespace SegundaVersion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			GM = new GameManager();
			Tramp = new Trampolin(300, 450, 20);
			Grav = new Gravedad(500, 420, 50);
			Grav2 = new Gravedad(1800, 120, 50);
			GM->Agregar(Tramp);
			GM->Agregar(Grav);
			GM->Agregar(Grav2);
			g = this->CreateGraphics();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete g;
				delete GM;
			}
		}
	private: System::Windows::Forms::Timer^  DeltaTime;
	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ g;
		GameManager* GM;
		Figura* Grav;
		Figura* Grav2;
	private: System::Windows::Forms::Timer^  PhysicsTime;
	private: System::Windows::Forms::Label^  label1;
		Figura* Tramp;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->DeltaTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->PhysicsTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DeltaTime
			// 
			this->DeltaTime->Enabled = true;
			this->DeltaTime->Interval = 34;
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &MyForm::DeltaTime_Tick);
			// 
			// PhysicsTime
			// 
			this->PhysicsTime->Enabled = true;
			this->PhysicsTime->Interval = 17;
			this->PhysicsTime->Tick += gcnew System::EventHandler(this, &MyForm::PhysicsTime_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		BufferedGraphicsContext  ^ BufferedSpace = BufferedGraphicsManager::Current;
		BufferedGraphics ^ BG = BufferedSpace->Allocate(g, ClientRectangle);
		
		GM->Update(BG->Graphics);

		GM->MostrarObjetos(BG->Graphics);
		BG->Render(g);

		//GM->Temp(0.35);
		delete BG;
		delete BufferedSpace;
		label1->Text = "X: " + GM->GetPlayer()->Getx().ToString() + " Y: " +  GM->GetPlayer()->Gety().ToString();
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Space && !GM->GetPlayer()->GetSaltando() &&!GM->GetPlayer()->GetEnAire())
		{
			GM->SetTemp(0);
			GM->GetPlayer()->SetSaltando(true);
		}
			
	}
	private: System::Void PhysicsTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		GM->CheckColisions();
	}
};
}
