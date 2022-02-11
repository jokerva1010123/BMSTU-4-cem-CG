#pragma once

#include <windows.h>
#include "paint.h"
#include "polygon_editor.h"


namespace src {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
#define DR System::Windows::Forms::DialogResult

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
#pragma region Windows Form Designer generated code

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pctCanvas;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::PictureBox^  pctColorMain;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pctColorFill;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  pctColorBack;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ColorDialog^  dlgColor;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pctCanvas = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->pctColorMain = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pctColorFill = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pctColorBack = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dlgColor = (gcnew System::Windows::Forms::ColorDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctCanvas))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorFill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// pctCanvas
			// 
			this->pctCanvas->BackColor = System::Drawing::Color::AliceBlue;
			this->pctCanvas->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctCanvas->Location = System::Drawing::Point(12, 12);
			this->pctCanvas->Name = L"pctCanvas";
			this->pctCanvas->Size = System::Drawing::Size(554, 481);
			this->pctCanvas->TabIndex = 0;
			this->pctCanvas->TabStop = false;
			this->pctCanvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pctCanvas_MouseMove);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->pctColorMain);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->pctColorFill);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->pctColorBack);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(572, 396);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(139, 97);
			this->groupBox4->TabIndex = 14;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Цвета:";
			// 
			// pctColorMain
			// 
			this->pctColorMain->BackColor = System::Drawing::Color::Black;
			this->pctColorMain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorMain->Location = System::Drawing::Point(6, 19);
			this->pctColorMain->Name = L"pctColorMain";
			this->pctColorMain->Size = System::Drawing::Size(20, 20);
			this->pctColorMain->TabIndex = 9;
			this->pctColorMain->TabStop = false;
			this->pctColorMain->Click += gcnew System::EventHandler(this, &Form1::pct_PickColor);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Цвет заливки";
			// 
			// pctColorFill
			// 
			this->pctColorFill->BackColor = System::Drawing::Color::Red;
			this->pctColorFill->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorFill->Location = System::Drawing::Point(6, 71);
			this->pctColorFill->Name = L"pctColorFill";
			this->pctColorFill->Size = System::Drawing::Size(20, 20);
			this->pctColorFill->TabIndex = 10;
			this->pctColorFill->TabStop = false;
			this->pctColorFill->Click += gcnew System::EventHandler(this, &Form1::pct_PickColor);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(32, 52);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Цвет фона";
			// 
			// pctColorBack
			// 
			this->pctColorBack->BackColor = System::Drawing::Color::AliceBlue;
			this->pctColorBack->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorBack->Location = System::Drawing::Point(6, 45);
			this->pctColorBack->Name = L"pctColorBack";
			this->pctColorBack->Size = System::Drawing::Size(20, 20);
			this->pctColorBack->TabIndex = 10;
			this->pctColorBack->TabStop = false;
			this->pctColorBack->Click += gcnew System::EventHandler(this, &Form1::pct_PickColor);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Цвет пера";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(572, 370);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(61, 20);
			this->numericUpDown1->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(569, 354);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Задержка (мс):";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(723, 505);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->pctCanvas);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"[КГ] ЛР №5";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctCanvas))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorFill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		cPolygonEditor *editor;

		//клик по
		System::Void pctCanvas_Click(System::Object^  sender, System::EventArgs^  e)
		{
		}
		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			editor = new cPolygonEditor(pctCanvas);
		}

		//изменение цвета
		System::Void pct_PickColor(System::Object^  sender, System::EventArgs^  e)
		{
			if (dlgColor->ShowDialog() != DR::OK)
				return;

			PictureBox^ p = (PictureBox^) sender;
			p->BackColor = dlgColor->Color;
			editor->Refresh(pctColorBack->BackColor, pctColorFill->BackColor, pctColorMain->BackColor);
		}
private: System::Void pctCanvas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }
};
}

