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
	/// Resumen de Highscores
	/// </summary>
	public ref class Highscores : public System::Windows::Forms::Form
	{
	public:
		Highscores(bool B)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Nivel = B;
			GM = new GameManager(Nivel);
			G = this->CreateGraphics();

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Highscores()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		GameManager* GM;
		Graphics^ G;
		bool Nivel;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Highscores::typeid));
			this->SuspendLayout();
			// 
			// Highscores
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"Highscores";
			this->Text = L"Highscores";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Highscores::Highscores_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Highscores::Highscores_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Highscores_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void Highscores_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		GM->ShowRanking(G);
	}
	};
}
