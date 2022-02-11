#pragma once

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
	private: System::Windows::Forms::Button^  btnCalc;
	protected: 

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  nmrSpectreNum;


	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::CheckBox^  chkDrawBack;
	private: System::Windows::Forms::PictureBox^  pctColorMain;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  pctColorBack;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Button^  btnSpectre;
	private: System::Windows::Forms::Button^  btnDraw;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::ComboBox^  cmbMethods;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  nmrAxisY;

	private: System::Windows::Forms::NumericUpDown^  nmrAxisX;
	private: System::Windows::Forms::Label^  lblOy;


	private: System::Windows::Forms::Label^  lblOxRad;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::NumericUpDown^  nmrY;

	private: System::Windows::Forms::NumericUpDown^  nmrX;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::NumericUpDown^  nmrSpectreStep;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::RadioButton^  rdbCircle;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox6;

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
			this->btnCalc = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nmrSpectreNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->chkDrawBack = (gcnew System::Windows::Forms::CheckBox());
			this->pctColorMain = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pctColorBack = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSpectre = (gcnew System::Windows::Forms::Button());
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbMethods = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->nmrAxisY = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmrAxisX = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblOy = (gcnew System::Windows::Forms::Label());
			this->lblOxRad = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->nmrY = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmrX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->nmrSpectreStep = (gcnew System::Windows::Forms::NumericUpDown());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->rdbCircle = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreNum))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrAxisY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrAxisX))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreStep))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnCalc
			// 
			this->btnCalc->Location = System::Drawing::Point(533, 96);
			this->btnCalc->Name = L"btnCalc";
			this->btnCalc->Size = System::Drawing::Size(75, 23);
			this->btnCalc->TabIndex = 32;
			this->btnCalc->Text = L"Измерить";
			this->btnCalc->UseVisualStyleBackColor = true;
			this->btnCalc->Click += gcnew System::EventHandler(this, &Form1::btnCalc_Click);
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(105, 54);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(30, 13);
			this->label8->TabIndex = 29;
			this->label8->Text = L"Шаг:";
			// 
			// nmrSpectreNum
			// 
			this->nmrSpectreNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->nmrSpectreNum->Location = System::Drawing::Point(141, 19);
			this->nmrSpectreNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nmrSpectreNum->Name = L"nmrSpectreNum";
			this->nmrSpectreNum->Size = System::Drawing::Size(48, 20);
			this->nmrSpectreNum->TabIndex = 28;
			this->nmrSpectreNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(66, 21);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 13);
			this->label7->TabIndex = 27;
			this->label7->Text = L"Количество:";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->chkDrawBack);
			this->groupBox4->Controls->Add(this->pctColorMain);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->pctColorBack);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(498, 141);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(141, 127);
			this->groupBox4->TabIndex = 26;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Цвета:";
			// 
			// chkDrawBack
			// 
			this->chkDrawBack->Location = System::Drawing::Point(6, 91);
			this->chkDrawBack->Name = L"chkDrawBack";
			this->chkDrawBack->Size = System::Drawing::Size(104, 30);
			this->chkDrawBack->TabIndex = 13;
			this->chkDrawBack->Text = L"Рисовать цветом фона";
			this->chkDrawBack->UseVisualStyleBackColor = true;
			this->chkDrawBack->CheckedChanged += gcnew System::EventHandler(this, &Form1::chkDrawBack_CheckedChanged);
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
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(42, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Цвет фона";
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
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(271, 426);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 25;
			this->btnClear->Text = L"Очистить";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// btnSpectre
			// 
			this->btnSpectre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnSpectre->Location = System::Drawing::Point(6, 49);
			this->btnSpectre->Name = L"btnSpectre";
			this->btnSpectre->Size = System::Drawing::Size(62, 23);
			this->btnSpectre->TabIndex = 24;
			this->btnSpectre->Text = L"Спектр";
			this->btnSpectre->UseVisualStyleBackColor = true;
			this->btnSpectre->Click += gcnew System::EventHandler(this, &Form1::btnSpectre_Click);
			// 
			// btnDraw
			// 
			this->btnDraw->Location = System::Drawing::Point(271, 396);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(75, 23);
			this->btnDraw->TabIndex = 23;
			this->btnDraw->Text = L"Отрисовать";
			this->btnDraw->UseVisualStyleBackColor = true;
			this->btnDraw->Click += gcnew System::EventHandler(this, &Form1::btnDraw_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->cmbMethods);
			this->groupBox3->Location = System::Drawing::Point(498, 44);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(141, 46);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Алгоритм отрисовки:";
			// 
			// cmbMethods
			// 
			this->cmbMethods->FormattingEnabled = true;
			this->cmbMethods->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Стандартный", L"Средняя точка", L"Каноническое уравнение", 
				L"Параметрическое уравнение", L"Брезенхем"});
			this->cmbMethods->Location = System::Drawing::Point(6, 19);
			this->cmbMethods->Name = L"cmbMethods";
			this->cmbMethods->Size = System::Drawing::Size(129, 21);
			this->cmbMethods->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->nmrAxisY);
			this->groupBox2->Controls->Add(this->nmrAxisX);
			this->groupBox2->Controls->Add(this->lblOy);
			this->groupBox2->Controls->Add(this->lblOxRad);
			this->groupBox2->Location = System::Drawing::Point(118, 376);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(130, 78);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметры:";
			// 
			// nmrAxisY
			// 
			this->nmrAxisY->Location = System::Drawing::Point(61, 52);
			this->nmrAxisY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrAxisY->Name = L"nmrAxisY";
			this->nmrAxisY->Size = System::Drawing::Size(63, 20);
			this->nmrAxisY->TabIndex = 7;
			this->nmrAxisY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// nmrAxisX
			// 
			this->nmrAxisX->Location = System::Drawing::Point(61, 22);
			this->nmrAxisX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrAxisX->Name = L"nmrAxisX";
			this->nmrAxisX->Size = System::Drawing::Size(63, 20);
			this->nmrAxisX->TabIndex = 6;
			this->nmrAxisX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {150, 0, 0, 0});
			// 
			// lblOy
			// 
			this->lblOy->AutoSize = true;
			this->lblOy->Location = System::Drawing::Point(6, 55);
			this->lblOy->Name = L"lblOy";
			this->lblOy->Size = System::Drawing::Size(40, 13);
			this->lblOy->TabIndex = 3;
			this->lblOy->Text = L"Ось Y:";
			// 
			// lblOxRad
			// 
			this->lblOxRad->AutoSize = true;
			this->lblOxRad->Location = System::Drawing::Point(6, 25);
			this->lblOxRad->Name = L"lblOxRad";
			this->lblOxRad->Size = System::Drawing::Size(40, 13);
			this->lblOxRad->TabIndex = 2;
			this->lblOxRad->Text = L"Ось X:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->nmrY);
			this->groupBox1->Controls->Add(this->nmrX);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 376);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(100, 78);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Центр:";
			// 
			// nmrY
			// 
			this->nmrY->Location = System::Drawing::Point(29, 52);
			this->nmrY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrY->Name = L"nmrY";
			this->nmrY->Size = System::Drawing::Size(63, 20);
			this->nmrY->TabIndex = 5;
			// 
			// nmrX
			// 
			this->nmrX->Location = System::Drawing::Point(29, 22);
			this->nmrX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrX->Name = L"nmrX";
			this->nmrX->Size = System::Drawing::Size(63, 20);
			this->nmrX->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 54);
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
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::AliceBlue;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 358);
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// nmrSpectreStep
			// 
			this->nmrSpectreStep->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->nmrSpectreStep->Location = System::Drawing::Point(141, 52);
			this->nmrSpectreStep->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->nmrSpectreStep->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nmrSpectreStep->Name = L"nmrSpectreStep";
			this->nmrSpectreStep->Size = System::Drawing::Size(48, 20);
			this->nmrSpectreStep->TabIndex = 31;
			this->nmrSpectreStep->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// rdbCircle
			// 
			this->rdbCircle->AutoSize = true;
			this->rdbCircle->Location = System::Drawing::Point(6, 19);
			this->rdbCircle->Name = L"rdbCircle";
			this->rdbCircle->Size = System::Drawing::Size(87, 17);
			this->rdbCircle->TabIndex = 33;
			this->rdbCircle->Text = L"Окружность";
			this->rdbCircle->UseVisualStyleBackColor = true;
			this->rdbCircle->CheckedChanged += gcnew System::EventHandler(this, &Form1::rdbCircle_CheckedChanged);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->radioButton1);
			this->groupBox5->Controls->Add(this->rdbCircle);
			this->groupBox5->Location = System::Drawing::Point(498, 274);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(141, 66);
			this->groupBox5->TabIndex = 34;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Фигура:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(6, 42);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(62, 17);
			this->radioButton1->TabIndex = 33;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Эллипс";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->nmrSpectreNum);
			this->groupBox6->Controls->Add(this->nmrSpectreStep);
			this->groupBox6->Controls->Add(this->btnSpectre);
			this->groupBox6->Controls->Add(this->label7);
			this->groupBox6->Controls->Add(this->label8);
			this->groupBox6->Location = System::Drawing::Point(444, 376);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(195, 78);
			this->groupBox6->TabIndex = 35;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Спектр:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 466);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->btnCalc);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnDraw);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"[КГ] ЛР №4";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreNum))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrAxisY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrAxisX))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreStep))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void Form1::pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void Form1::pctColorMain_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void Form1::pctColorBack_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void Form1::chkDrawBack_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void Form1::btnClear_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void Form1::btnDraw_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void Form1::btnSpectre_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void Form1::btnCalc_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void rdbCircle_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		{

			if (rdbCircle->Checked)
			{
				lblOxRad->Text = "Радиус:";
			}
			else
			{
				lblOxRad->Text = "Ось X:";
			}
			lblOy->Visible = !lblOy->Visible;
			nmrAxisY->Visible = !nmrAxisY->Visible;
		}
};
}

