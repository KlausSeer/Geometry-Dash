#pragma once
#include "GameManager.h"
#include "GameOver.h"

namespace GeomtryDash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(int N, String^ Nom)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Nombre = gcnew String(Nom);
			Op = N;
			GM = new GameManager();
			imgTrampolin = gcnew Bitmap("Trampolin.png");
			imgNave = gcnew Bitmap("Nave.png");
			if(Op == 1)
				imgPlayer = gcnew Bitmap("Jugador1.png");
			else if (Op == 2)
				imgPlayer = gcnew Bitmap("Jugador2.png");
			else if (Op == 3)
				imgPlayer = gcnew Bitmap("Jugador3.png");
			imgEspina = gcnew Bitmap("Fuego.png");
			imgTile = gcnew Bitmap("Tile.png");
			imgPortal1 = gcnew Bitmap("Portal.png");
			imgPortal2 = gcnew Bitmap("Portal2.png");
			imgFondo = gcnew Bitmap("background.jpg");
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
				delete Nombre;
				delete imgNave;
				delete imgPlayer;
				delete imgEspina;
				delete imgTile;
				delete imgPortal1;
				delete imgPortal2;
				delete imgTrampolin;
				delete imgFondo;
				delete BG;
				delete BufferedSpace;
				delete GM;
				delete g;
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
		String^ Nombre;
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
		int __x = 0;
		int height;
		int width;
		int Op;
		int Intentos = 0;
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
			this->DeltaTime->Interval = 15;
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &MyForm::DeltaTime_Tick);
			// 
			// PhysicsTime
			// 
			this->PhysicsTime->Enabled = true;
			this->PhysicsTime->Interval = 15;
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
		if (!GM->GetPlayer()->GetVivo())
		{
			DeltaTime->Stop();
			PhysicsTime->Stop();

			GameOver^ Go = gcnew GameOver(Nombre, GM);
			Go->ShowDialog();

			g->Clear(Color::Black);
			_x = __x = 0;

			GM->~GameManager();
			GM = new GameManager();
			GM->SetIntentos(++Intentos);

			PhysicsTime->Start();
			DeltaTime->Start();
		}
		if (GM->GetPlayer()->GetEnPortal())
			GM->Transformar();
	}
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		Rectangle Pantalla(_x, 0, width, height);
		Rectangle Nuevo(0, 0, width, height);

		BG->Graphics->Clear(Color::Black);
		
		BG->Graphics->DrawImage(imgFondo, 0, 0, Pantalla, GraphicsUnit::Pixel);

		GM->Update(BG->Graphics);

		_x += 14;

		if (_x + width > imgFondo->Width)
		{
			BG->Graphics->DrawImage(imgFondo, width - __x, 0, Nuevo, GraphicsUnit::Pixel);
			__x += 14;

			if (__x  > 1300)
			{
				_x = 0;
				__x = 0;
			}
				
		}

		GM->MostrarObjetos(BG->Graphics, imgNave, imgPlayer, imgTile, imgPortal1, imgPortal2, imgEspina, imgTrampolin);

		//label1->Text = "Width: " + width.ToString();
		//label2->Text = "_x: " + _x.ToString();
		//label3->Text = "__x: " + __x.ToString() + " img: " + imgFondo->Width.ToString();
		//
		BG->Render(g);
		/*label1->Text = "EnAire: " + GM->GetPlayer()->GetEnAire().ToString();
		label2->Text = "Saltando: " + GM->GetPlayer()->GetSaltando().ToString();
		label3->Text = "Tiled: " + GM->GetPlayer()->GetTiled().ToString() + " Y: " + GM->GetPlayer()->Gety().ToString();*/

		//label1->Text = "Saltos: " + GM->GetN_Saltos();
		//label2->Text = "Intentos: " + GM->GetN_Intentos();
		//label3->Text = "Porcentaje: " + GM->GetN_Progreso();
		
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
		if (e->KeyCode == Keys::E)
			this->Close();
	}
};


}
