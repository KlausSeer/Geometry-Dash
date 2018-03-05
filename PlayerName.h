#pragma once
#include "PlayerSelect.h"
namespace GeomtryDash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PlayerName
	/// </summary>
	public ref class PlayerName : public System::Windows::Forms::Form
	{
	public:
		PlayerName(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Nombre = gcnew String("");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PlayerName()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		bool Activado = true;
		bool MostrandoFrm = false;
		int Per;
		bool Nivel;
		PlayerSelect^ PS;
	private: System::Windows::Forms::Timer^  DeltaTime;
			 String^ Nombre;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PlayerName::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DeltaTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Next";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PlayerName::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(90, 117);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &PlayerName::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(73, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ingrese su Nombre:";
			// 
			// DeltaTime
			// 
			this->DeltaTime->Interval = 1000;
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &PlayerName::DeltaTime_Tick);
			// 
			// PlayerName
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(281, 255);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"PlayerName";
			this->Text = L"PlayerName";
			this->Deactivate += gcnew System::EventHandler(this, &PlayerName::PlayerName_Deactivate);
			this->Enter += gcnew System::EventHandler(this, &PlayerName::PlayerName_Enter);
			this->Leave += gcnew System::EventHandler(this, &PlayerName::PlayerName_Leave);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:bool GetNivel()
		{
			return Nivel;
		}
		public:bool GetActivado()
		{
			return Activado;
		}
		
	   public:bool GetMostrando()
		{
			return MostrandoFrm;
		}
	public:String^ GetNombre()
	{
		return Nombre;
	}
	public: int GetPersonaje()
	{
		return Per;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		Nombre = textBox1->Text;
		PS = gcnew PlayerSelect(Nombre);
		this->Hide();
		MostrandoFrm = true;
		PS->Show();
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void PlayerName_Leave(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void PlayerName_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void PlayerName_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if(!PS->GetInGame())
	{
		if (PS->GetActivado())
	{
		if (PS->Enabled)
			this->DeltaTime->Start();
	}
	}
}
private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (!PS->GetInGame())
	{
		if (!PS->Visible)
		{
			this->Show();
			Per = PS->GetPersonaje();
			Nivel = PS->GetNivel();
			PS->Close();
			MostrandoFrm = false;
			if (PS->GetMenu())
				this->Hide();
			this->DeltaTime->Stop();
		}
	}
}
};
}
