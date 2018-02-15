#pragma once
#include "GameManager.h"
namespace GeomtryDash {

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
			imgTrampolin = gcnew Bitmap("Trampolin.png");
			imgNave = gcnew Bitmap("Nave.png");
			imgPlayer = gcnew Bitmap("Jugador.png");
			imgEspina = gcnew Bitmap("Fuego.png");
			imgTile = gcnew Bitmap("Tile.png");
			imgPortal1 = gcnew Bitmap("Portal.png");
			imgPortal2 = gcnew Bitmap("Portal2.png");
			imgFondo = gcnew Bitmap("background.png");
			g = this->CreateGraphics();
			height = g->VisibleClipBounds.Height;
			width = g->VisibleClipBounds.Width;
			BufferedSpace = BufferedGraphicsManager::Current;
			BG = BufferedSpace->Allocate(g, ClientRectangle);
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
				delete imgNave;
				delete imgPlayer;
				delete imgEspina;
				delete imgTile;
				delete imgPortal1;
				delete imgPortal2;
				delete imgTrampolin;
				delete imgFondo;
				delete BufferedSpace;
				delete BG;
			}
		}
	private: System::Windows::Forms::Timer^  DeltaTime;
	private: System::Windows::Forms::Timer^  PhysicsTime;
	protected:


	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ g;
		GameManager* GM;
		Bitmap^ imgNave;
		Bitmap^ imgPlayer;
		Bitmap^ imgEspina;
		Bitmap^ imgTile;
		Bitmap^ imgPortal1;
		Bitmap^ imgPortal2;
		Bitmap^ imgTrampolin;
		Bitmap^ imgFondo;
		int _x = 0;
		int _y = 0;
		int height;
		int width;
		BufferedGraphicsContext  ^ BufferedSpace;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
			 BufferedGraphics ^ BG;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PhysicsTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		GM->CheckColisions();
		if (GM->GetPlayer()->GetEnPortal())
			GM->Transformar();
	}
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		BG->Graphics->Clear(Color::Black);
		
		GM->Update(BG->Graphics);

		GM->MostrarObjetos(BG->Graphics, imgNave, imgPlayer, imgTile, imgPortal1, imgPortal2, imgEspina, imgTrampolin);
		BG->Render(g);

		label1->Text = "EnAire: " + GM->GetPlayer()->GetEnAire().ToString();
		label2->Text = "Saltando: " + GM->GetPlayer()->GetSaltando().ToString();
		label3->Text = "Tiled: " + GM->GetPlayer()->GetTiled().ToString() + " Y: " + GM->GetPlayer()->Gety().ToString();

	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Space && !GM->GetPlayer()->GetSaltando())
		{
			if (!GM->GetPlayer()->GetEnAire())
			{
				if (!GM->GetPlayer()->GetTransformado())
					GM->AumentarSalto();
				GM->SetTemp(0);
				GM->GetPlayer()->SetSaltando(true);

			}
		}

	}
};
}
