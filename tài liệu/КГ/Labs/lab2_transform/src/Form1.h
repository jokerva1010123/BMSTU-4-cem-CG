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
#pragma region Windows Form Designer generated code
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
	private: System::Windows::Forms::Button^  btnInit;
	private: System::Windows::Forms::TextBox^  txtA;
	private: System::Windows::Forms::TextBox^  txtB;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TextBox^  txtSx;

	private: System::Windows::Forms::Button^  btnScale;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtAng;


	private: System::Windows::Forms::Button^  btnRotate;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnShift;
	private: System::Windows::Forms::TextBox^  txtDx;
	private: System::Windows::Forms::TextBox^  txtDy;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  txtC;
	private: System::Windows::Forms::TextBox^  txtD;
	private: System::Windows::Forms::NumericUpDown^  nmrPrecisionCir;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  txtR;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  txtSy;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  txtCx;




	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  txtCy;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  btnBack;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::NumericUpDown^  nmrPrecisionPar;
	private: System::Windows::Forms::Label^  label15;



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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnInit = (gcnew System::Windows::Forms::Button());
			this->txtA = (gcnew System::Windows::Forms::TextBox());
			this->txtB = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtSy = (gcnew System::Windows::Forms::TextBox());
			this->txtSx = (gcnew System::Windows::Forms::TextBox());
			this->btnScale = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtAng = (gcnew System::Windows::Forms::TextBox());
			this->btnRotate = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnShift = (gcnew System::Windows::Forms::Button());
			this->txtDx = (gcnew System::Windows::Forms::TextBox());
			this->txtDy = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtC = (gcnew System::Windows::Forms::TextBox());
			this->txtD = (gcnew System::Windows::Forms::TextBox());
			this->nmrPrecisionCir = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtR = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtCx = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtCy = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->nmrPrecisionPar = (gcnew System::Windows::Forms::NumericUpDown());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrPrecisionCir))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrPrecisionPar))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::AliceBlue;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(532, 388);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// btnInit
			// 
			this->btnInit->Location = System::Drawing::Point(560, 201);
			this->btnInit->Name = L"btnInit";
			this->btnInit->Size = System::Drawing::Size(114, 23);
			this->btnInit->TabIndex = 1;
			this->btnInit->Text = L"Инициализировать";
			this->btnInit->UseVisualStyleBackColor = true;
			this->btnInit->Click += gcnew System::EventHandler(this, &Form1::btnInit_Click);
			// 
			// txtA
			// 
			this->txtA->Location = System::Drawing::Point(28, 19);
			this->txtA->Name = L"txtA";
			this->txtA->Size = System::Drawing::Size(50, 20);
			this->txtA->TabIndex = 2;
			this->txtA->Text = L"0";
			// 
			// txtB
			// 
			this->txtB->Location = System::Drawing::Point(108, 19);
			this->txtB->Name = L"txtB";
			this->txtB->Size = System::Drawing::Size(50, 20);
			this->txtB->TabIndex = 3;
			this->txtB->Text = L"0";
			// 
			// tabControl1
			// 
			this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(553, 316);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(200, 84);
			this->tabControl1->TabIndex = 8;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->txtSy);
			this->tabPage1->Controls->Add(this->txtSx);
			this->tabPage1->Controls->Add(this->btnScale);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(192, 55);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Масштаб";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(107, 6);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(26, 13);
			this->label12->TabIndex = 8;
			this->label12->Text = L"kY: ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 6);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(26, 13);
			this->label11->TabIndex = 7;
			this->label11->Text = L"kX: ";
			// 
			// txtSy
			// 
			this->txtSy->Location = System::Drawing::Point(139, 3);
			this->txtSy->Name = L"txtSy";
			this->txtSy->Size = System::Drawing::Size(50, 20);
			this->txtSy->TabIndex = 4;
			this->txtSy->Text = L"1,0";
			// 
			// txtSx
			// 
			this->txtSx->Location = System::Drawing::Point(35, 3);
			this->txtSx->Name = L"txtSx";
			this->txtSx->Size = System::Drawing::Size(50, 20);
			this->txtSx->TabIndex = 4;
			this->txtSx->Text = L"1,0";
			// 
			// btnScale
			// 
			this->btnScale->Location = System::Drawing::Point(49, 29);
			this->btnScale->Name = L"btnScale";
			this->btnScale->Size = System::Drawing::Size(118, 23);
			this->btnScale->TabIndex = 6;
			this->btnScale->Text = L"Масштабировать";
			this->btnScale->UseVisualStyleBackColor = true;
			this->btnScale->Click += gcnew System::EventHandler(this, &Form1::btnScale_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Transparent;
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->txtAng);
			this->tabPage2->Controls->Add(this->btnRotate);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(192, 55);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Поворот";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(70, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"o";
			// 
			// txtAng
			// 
			this->txtAng->Location = System::Drawing::Point(38, 16);
			this->txtAng->Name = L"txtAng";
			this->txtAng->Size = System::Drawing::Size(33, 20);
			this->txtAng->TabIndex = 4;
			this->txtAng->Text = L"0,0";
			// 
			// btnRotate
			// 
			this->btnRotate->Location = System::Drawing::Point(97, 15);
			this->btnRotate->Name = L"btnRotate";
			this->btnRotate->Size = System::Drawing::Size(75, 23);
			this->btnRotate->TabIndex = 6;
			this->btnRotate->Text = L"Повернуть";
			this->btnRotate->UseVisualStyleBackColor = true;
			this->btnRotate->Click += gcnew System::EventHandler(this, &Form1::btnRotate_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::Transparent;
			this->tabPage3->Controls->Add(this->label2);
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Controls->Add(this->btnShift);
			this->tabPage3->Controls->Add(this->txtDx);
			this->tabPage3->Controls->Add(this->txtDy);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(192, 55);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Сдвиг";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(107, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"dY :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"dX :";
			// 
			// btnShift
			// 
			this->btnShift->Location = System::Drawing::Point(56, 29);
			this->btnShift->Name = L"btnShift";
			this->btnShift->Size = System::Drawing::Size(86, 23);
			this->btnShift->TabIndex = 6;
			this->btnShift->Text = L"Переместить";
			this->btnShift->UseVisualStyleBackColor = true;
			this->btnShift->Click += gcnew System::EventHandler(this, &Form1::btnShift_Click);
			// 
			// txtDx
			// 
			this->txtDx->Location = System::Drawing::Point(35, 3);
			this->txtDx->Name = L"txtDx";
			this->txtDx->Size = System::Drawing::Size(50, 20);
			this->txtDx->TabIndex = 4;
			this->txtDx->Text = L"0,0";
			// 
			// txtDy
			// 
			this->txtDy->Location = System::Drawing::Point(139, 3);
			this->txtDy->Name = L"txtDy";
			this->txtDy->Size = System::Drawing::Size(50, 20);
			this->txtDy->TabIndex = 4;
			this->txtDy->Text = L"0,0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"cX";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(86, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"cY";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"cX";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(86, 22);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(20, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"cY";
			// 
			// txtC
			// 
			this->txtC->Location = System::Drawing::Point(28, 19);
			this->txtC->Name = L"txtC";
			this->txtC->Size = System::Drawing::Size(50, 20);
			this->txtC->TabIndex = 2;
			this->txtC->Text = L"0";
			// 
			// txtD
			// 
			this->txtD->Location = System::Drawing::Point(108, 19);
			this->txtD->Name = L"txtD";
			this->txtD->Size = System::Drawing::Size(50, 20);
			this->txtD->TabIndex = 3;
			this->txtD->Text = L"0";
			// 
			// nmrPrecisionCir
			// 
			this->nmrPrecisionCir->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nmrPrecisionCir->Location = System::Drawing::Point(71, 71);
			this->nmrPrecisionCir->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrPrecisionCir->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nmrPrecisionCir->Name = L"nmrPrecisionCir";
			this->nmrPrecisionCir->Size = System::Drawing::Size(43, 20);
			this->nmrPrecisionCir->TabIndex = 10;
			this->nmrPrecisionCir->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 73);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Точность:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(120, 73);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"точек";
			// 
			// txtR
			// 
			this->txtR->Location = System::Drawing::Point(64, 45);
			this->txtR->Name = L"txtR";
			this->txtR->Size = System::Drawing::Size(50, 20);
			this->txtR->TabIndex = 13;
			this->txtR->Text = L"50";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(44, 48);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(15, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"R";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->txtCx);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->txtCy);
			this->groupBox1->Location = System::Drawing::Point(553, 259);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(196, 51);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Центр преобразований:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(98, 22);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(17, 13);
			this->label14->TabIndex = 8;
			this->label14->Text = L"Y:";
			// 
			// txtCx
			// 
			this->txtCx->Location = System::Drawing::Point(42, 19);
			this->txtCx->Name = L"txtCx";
			this->txtCx->Size = System::Drawing::Size(50, 20);
			this->txtCx->TabIndex = 4;
			this->txtCx->TextChanged += gcnew System::EventHandler(this, &Form1::txt_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(19, 22);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(17, 13);
			this->label13->TabIndex = 7;
			this->label13->Text = L"X:";
			// 
			// txtCy
			// 
			this->txtCy->Location = System::Drawing::Point(121, 19);
			this->txtCy->Name = L"txtCy";
			this->txtCy->Size = System::Drawing::Size(50, 20);
			this->txtCy->TabIndex = 4;
			this->txtCy->TextChanged += gcnew System::EventHandler(this, &Form1::txt_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txtA);
			this->groupBox2->Controls->Add(this->txtB);
			this->groupBox2->Controls->Add(this->txtR);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->nmrPrecisionCir);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Location = System::Drawing::Point(560, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(164, 98);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Окружность";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->txtD);
			this->groupBox3->Controls->Add(this->txtC);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->nmrPrecisionPar);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Location = System::Drawing::Point(560, 116);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(164, 79);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Парабола";
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(680, 201);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(57, 23);
			this->btnBack->TabIndex = 1;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &Form1::btnBack_Click);
			// 
			// nmrPrecisionPar
			// 
			this->nmrPrecisionPar->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nmrPrecisionPar->Location = System::Drawing::Point(71, 45);
			this->nmrPrecisionPar->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrPrecisionPar->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nmrPrecisionPar->Name = L"nmrPrecisionPar";
			this->nmrPrecisionPar->Size = System::Drawing::Size(43, 20);
			this->nmrPrecisionPar->TabIndex = 10;
			this->nmrPrecisionPar->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->nmrPrecisionPar->ValueChanged += gcnew System::EventHandler(this, &Form1::nmrPrecisionPar_ValueChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(8, 47);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(57, 13);
			this->label15->TabIndex = 11;
			this->label15->Text = L"Точность:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(120, 47);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(35, 13);
			this->label16->TabIndex = 12;
			this->label16->Text = L"точек";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(761, 414);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnInit);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"[КГ] ЛР №2";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrPrecisionCir))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrPrecisionPar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	private:

		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

		System::Void btnInit_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e);

		System::Void btnShift_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnScale_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnRotate_Click(System::Object^  sender, System::EventArgs^  e);

		System::Void txt_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void nmrPrecisionPar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

