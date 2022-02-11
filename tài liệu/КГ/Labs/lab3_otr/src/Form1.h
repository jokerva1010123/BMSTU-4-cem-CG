//
//		формочка, йай!
//
#pragma once
#include "paint.h"

namespace src {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;





	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  nmrY1;
	private: System::Windows::Forms::NumericUpDown^  nmrX1;
	private: System::Windows::Forms::NumericUpDown^  nmrY2;
	private: System::Windows::Forms::NumericUpDown^  nmrX2;
	private: System::Windows::Forms::GroupBox^  groupBox3;




	private: System::Windows::Forms::Button^  btnDraw;
	private: System::Windows::Forms::Button^  btnSpectre;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::PictureBox^  pctColorMain;
	private: System::Windows::Forms::PictureBox^  pctColorBack;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::CheckBox^  chkDrawBack;
	private: System::Windows::Forms::NumericUpDown^  nmrRadius;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  cmbMethods;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  nmrSpectreStep;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  btnCalc;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->nmrY1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmrX1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->nmrY2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmrX2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbMethods = (gcnew System::Windows::Forms::ComboBox());
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			this->btnSpectre = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->pctColorMain = (gcnew System::Windows::Forms::PictureBox());
			this->pctColorBack = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->chkDrawBack = (gcnew System::Windows::Forms::CheckBox());
			this->nmrRadius = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nmrSpectreStep = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->btnCalc = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX2))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrRadius))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreStep))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::AliceBlue;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 320);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->nmrY1);
			this->groupBox1->Controls->Add(this->nmrX1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 338);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(100, 78);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Точка 1:";
			// 
			// nmrY1
			// 
			this->nmrY1->Location = System::Drawing::Point(29, 52);
			this->nmrY1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrY1->Name = L"nmrY1";
			this->nmrY1->Size = System::Drawing::Size(63, 20);
			this->nmrY1->TabIndex = 5;
			// 
			// nmrX1
			// 
			this->nmrX1->Location = System::Drawing::Point(29, 22);
			this->nmrX1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrX1->Name = L"nmrX1";
			this->nmrX1->Size = System::Drawing::Size(63, 20);
			this->nmrX1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Y:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"X:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->nmrY2);
			this->groupBox2->Controls->Add(this->nmrX2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Location = System::Drawing::Point(147, 338);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(100, 78);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Точка 2:";
			// 
			// nmrY2
			// 
			this->nmrY2->Location = System::Drawing::Point(29, 52);
			this->nmrY2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrY2->Name = L"nmrY2";
			this->nmrY2->Size = System::Drawing::Size(63, 20);
			this->nmrY2->TabIndex = 7;
			this->nmrY2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// nmrX2
			// 
			this->nmrX2->Location = System::Drawing::Point(29, 22);
			this->nmrX2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrX2->Name = L"nmrX2";
			this->nmrX2->Size = System::Drawing::Size(63, 20);
			this->nmrX2->TabIndex = 6;
			this->nmrX2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {150, 0, 0, 0});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Y:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"X:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->cmbMethods);
			this->groupBox3->Location = System::Drawing::Point(498, 60);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(141, 52);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Алгоритм отрисовки:";
			// 
			// cmbMethods
			// 
			this->cmbMethods->FormattingEnabled = true;
			this->cmbMethods->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Стандартный", L"ЦДА", L"Брезенхема (действительный)", 
				L"Брезенхема (целочисленный)", L"Брезенхема (сглаживание)"});
			this->cmbMethods->Location = System::Drawing::Point(6, 19);
			this->cmbMethods->Name = L"cmbMethods";
			this->cmbMethods->Size = System::Drawing::Size(129, 21);
			this->cmbMethods->TabIndex = 0;
			// 
			// btnDraw
			// 
			this->btnDraw->Location = System::Drawing::Point(290, 358);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(75, 23);
			this->btnDraw->TabIndex = 6;
			this->btnDraw->Text = L"Отрисовать";
			this->btnDraw->UseVisualStyleBackColor = true;
			this->btnDraw->Click += gcnew System::EventHandler(this, &Form1::btnDraw_Click);
			// 
			// btnSpectre
			// 
			this->btnSpectre->Location = System::Drawing::Point(436, 369);
			this->btnSpectre->Name = L"btnSpectre";
			this->btnSpectre->Size = System::Drawing::Size(75, 23);
			this->btnSpectre->TabIndex = 7;
			this->btnSpectre->Text = L"Спектр";
			this->btnSpectre->UseVisualStyleBackColor = true;
			this->btnSpectre->Click += gcnew System::EventHandler(this, &Form1::btnSpectre_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(290, 388);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 8;
			this->btnClear->Text = L"Очистить";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// pctColorMain
			// 
			this->pctColorMain->BackColor = System::Drawing::Color::DarkGreen;
			this->pctColorMain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorMain->Location = System::Drawing::Point(6, 19);
			this->pctColorMain->Name = L"pctColorMain";
			this->pctColorMain->Size = System::Drawing::Size(30, 30);
			this->pctColorMain->TabIndex = 9;
			this->pctColorMain->TabStop = false;
			this->pctColorMain->Click += gcnew System::EventHandler(this, &Form1::pctColorMain_Click);
			// 
			// pctColorBack
			// 
			this->pctColorBack->BackColor = System::Drawing::Color::AliceBlue;
			this->pctColorBack->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorBack->Location = System::Drawing::Point(6, 55);
			this->pctColorBack->Name = L"pctColorBack";
			this->pctColorBack->Size = System::Drawing::Size(30, 30);
			this->pctColorBack->TabIndex = 10;
			this->pctColorBack->TabStop = false;
			this->pctColorBack->Click += gcnew System::EventHandler(this, &Form1::pctColorBack_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(42, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Цвет пера";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(42, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Цвет фона";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->chkDrawBack);
			this->groupBox4->Controls->Add(this->pctColorMain);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->pctColorBack);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(498, 171);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(141, 129);
			this->groupBox4->TabIndex = 13;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Цвета:";
			// 
			// chkDrawBack
			// 
			this->chkDrawBack->Location = System::Drawing::Point(13, 91);
			this->chkDrawBack->Name = L"chkDrawBack";
			this->chkDrawBack->Size = System::Drawing::Size(104, 30);
			this->chkDrawBack->TabIndex = 13;
			this->chkDrawBack->Text = L"Рисовать цветом фона";
			this->chkDrawBack->UseVisualStyleBackColor = true;
			this->chkDrawBack->CheckedChanged += gcnew System::EventHandler(this, &Form1::chkDrawBack_CheckedChanged);
			// 
			// nmrRadius
			// 
			this->nmrRadius->Location = System::Drawing::Point(567, 360);
			this->nmrRadius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrRadius->Name = L"nmrRadius";
			this->nmrRadius->Size = System::Drawing::Size(48, 20);
			this->nmrRadius->TabIndex = 15;
			this->nmrRadius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(517, 363);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Радиус:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(531, 388);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(30, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Шаг:";
			// 
			// nmrSpectreStep
			// 
			this->nmrSpectreStep->Location = System::Drawing::Point(567, 386);
			this->nmrSpectreStep->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->nmrSpectreStep->Name = L"nmrSpectreStep";
			this->nmrSpectreStep->Size = System::Drawing::Size(48, 20);
			this->nmrSpectreStep->TabIndex = 17;
			this->nmrSpectreStep->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::HighlightText;
			this->label9->Location = System::Drawing::Point(588, 388);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(11, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"°";
			// 
			// btnCalc
			// 
			this->btnCalc->Location = System::Drawing::Point(534, 118);
			this->btnCalc->Name = L"btnCalc";
			this->btnCalc->Size = System::Drawing::Size(75, 23);
			this->btnCalc->TabIndex = 18;
			this->btnCalc->Text = L"Измерить";
			this->btnCalc->UseVisualStyleBackColor = true;
			this->btnCalc->Click += gcnew System::EventHandler(this, &Form1::btnCalc_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(653, 428);
			this->Controls->Add(this->btnCalc);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->nmrRadius);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnSpectre);
			this->Controls->Add(this->btnDraw);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->nmrSpectreStep);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX2))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrRadius))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreStep))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		canvasstruct *Easel;
		Color pencolor;
		Color canvascolor;

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void pctColorMain_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void pctColorBack_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void chkDrawBack_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnSpectre_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnCalc_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
};
}

