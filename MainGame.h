#pragma once
#include <vector>
#include "Player.h"
#include "Trampolin.h"
#include "Portal.h"
#include "Tile.h"
#include "Triangulo.h"
namespace PrimeraVersion {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MainGame
	/// </summary>
	public ref class MainGame : public System::Windows::Forms::Form
	{
	public:
		MainGame(void)
		{
			InitializeComponent();
			Trampo = new Tile(300, 450, 20);
			Trampo2 = new Trampolin(410, 400, 20);
			Portalcillo = new Portal(570, 300, 20);
			Portalcillo2 = new Portal(800, 150, 20);
			Cuadradito = new Player(30, 500, 30);
			Tilecito = new Tile(800, 470, 20);
			g = CreateGraphics();
			i = new double(0);
			Vec->push_back(Trampo);
			Vec->push_back(Trampo2);
			Vec->push_back(Portalcillo);
			Vec->push_back(Portalcillo2);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MainGame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  DeltaTime;
	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		double *i;
		std::vector<Figura*> *Vec = new std::vector<Figura*>;
		Trampolin* Trampo2;
		Portal* Portalcillo;
		Portal* Portalcillo2;
		Tile* Trampo;
		Player* Cuadradito;
		Tile* Tilecito;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  PhysicsTime;
			 Graphics^ g;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->DeltaTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PhysicsTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// DeltaTime
			// 
			this->DeltaTime->Enabled = true;
			this->DeltaTime->Interval = 60;
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &MainGame::DeltaTime_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// PhysicsTime
			// 
			this->PhysicsTime->Enabled = true;
			this->PhysicsTime->Interval = 120;
			this->PhysicsTime->Tick += gcnew System::EventHandler(this, &MainGame::PhysicsTime_Tick);
			// 
			// MainGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label1);
			this->Name = L"MainGame";
			this->Text = L"MainGame";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainGame::MainGame_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		BufferedGraphicsContext  ^ BufferedSpace = BufferedGraphicsManager::Current;
		BufferedGraphics ^ BG = BufferedSpace->Allocate(g, ClientRectangle);

		if (Cuadradito->ImpulseState())
		{
			if(*i <= Cuadradito->GetTiempo())
			Cuadradito->Impulso(*i);
			else
			{
				Cuadradito->Impulsar(false);
			}

		}

		
		else if (Cuadradito->JumpState())
		{
			if (*i <= Cuadradito->GetTiempo())
				Cuadradito->MoverP(*i);
			else
			{
				Cuadradito->Saltar(false);
				
			}
		}
		
		else
		{
			Cuadradito->SetDx(Cuadradito->Getx()+5);
			Cuadradito->SetDy(Cuadradito->GetLim());
			Cuadradito->Mover();
		}

			
		*i += 0.35;
		
		label1->Text = "X: " + Cuadradito->Getx().ToString() + " Y: " + Cuadradito->Gety().ToString() + " Lim: " + Cuadradito->GetLim().ToString();
		//else
		//	label1->Text = "No hay Colision";
		Pen^ P = gcnew Pen(Color::BlueViolet);
		BG->Graphics->DrawRectangle(P, 0, 531, 1500, 10);
		BG->Graphics->DrawRectangle(P, 0, 81, 1500, 10);
		
		Trampo->Mostrar(BG->Graphics);
		Trampo2->Mostrar(BG->Graphics);
		Portalcillo->Mostrar(BG->Graphics);
		Portalcillo2->Mostrar(BG->Graphics);
		Cuadradito->Mostrar(BG->Graphics);
		Tilecito->Mostrar(BG->Graphics);

		BG->Render(g);

		delete BG;
		delete BufferedSpace;
	}
	private: System::Void MainGame_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::J && !Cuadradito->JumpState() && !Cuadradito->ImpulseState())
		{
			Cuadradito->Saltar(true);
			*i = 0;
		}
	}
	private: System::Void PhysicsTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		for (unsigned int j = 0; j < Vec->size(); j++)
		{
			Cuadradito->CheckColision(Vec->at(j), i);
		}
		
	}
};
}
