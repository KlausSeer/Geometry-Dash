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
			Tramp = new Tile(300, 450, 60);
			Grav = new Gravedad(700, 420, 50, true);
			Grav2 = new Portal(1800, 120, 50, true);
			Grav3 = new Portal(2600, 420, 50, false);
			GM->Agregar(Tramp);
			GM->Agregar(Grav);
			GM->Agregar(Grav2);
			GM->Agregar(Grav3);
			imgTrampolin = gcnew Bitmap("Trampolin.png");
			imgNave = gcnew Bitmap("Nave.png");
			imgPlayer = gcnew Bitmap("Jugador.png");
			imgEspina = gcnew Bitmap("Fuego.png");
			imgTile = gcnew Bitmap("Tile.png");
			imgPortal1 = gcnew Bitmap("Portal.png");
			imgPortal2 = gcnew Bitmap("Portal2.png");
			imgFondo = gcnew Bitmap("background.png");
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
		Figura* Grav3;
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
	private: System::Windows::Forms::Timer^  PhysicsTime;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label4);
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
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		BufferedGraphicsContext  ^ BufferedSpace = BufferedGraphicsManager::Current;
		BufferedGraphics ^ BG = BufferedSpace->Allocate(g, ClientRectangle);

		int height = g->VisibleClipBounds.Height;
		int width = g->VisibleClipBounds.Width;

		Rectangle Cut(0, 0, width, height);
		Brush^ B = gcnew TextureBrush(imgTile);
		GM->Update(BG->Graphics);

		if (_x > imgFondo->Width / 2)
		{
			Rectangle Nuevo(width - _x, _y, width, height);
			Cut = Nuevo;
			//BG->Graphics->DrawImage(imgFondo, Cut, _x, _y, imgFondo->Width / 2, imgFondo->Height, GraphicsUnit::Pixel);
			_x = 0;
		}

		BG->Graphics->DrawImage(imgFondo, Cut, _x, _y, imgFondo->Width / 2, imgFondo->Height, GraphicsUnit::Pixel);
		//BG->Graphics->FillRectangle(B, _x, 530, 1900, 20);
		//BG->Graphics->FillRectangle(B, _x, 75, 1900, 20);
		GM->MostrarObjetos(BG->Graphics, imgNave, imgPlayer,  imgTile, imgPortal1, imgPortal2, imgEspina, imgTrampolin);
		BG->Render(g);
		

		_x += 5;


		//GM->Temp(0.35);
		delete BG;
		delete BufferedSpace;
		label1->Text = "X: " + GM->GetPlayer()->Getx().ToString() + " Y: " + GM->GetPlayer()->GetDy().ToString() + " Saltos: " + GM->GetN_Saltos() + " Limite: " + GM->GetPlayer()->GetLim();
			label2->Text = " Aire: " + GM->GetPlayer()->GetEnAire().ToString();
			label3->Text = " Tile: " + GM->GetPlayer()->GetTiled().ToString();
			label4->Text = " Colision: " + GM->GetPlayer()->GetOnColision().ToString();
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
		if (e->KeyCode == Keys::Q)
		{
			GM->GetPlayer()->SetEnPortal(true);
			GM->GetPlayer()->Tranformar();
		}
			
	}
	private: System::Void PhysicsTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		GM->CheckColisions();
		if(GM->GetPlayer()->GetEnPortal())
		GM->Transformar();
	}
};
}
