#pragma once

#include "stdafx.h"

#include "alg.h"

namespace Lab4 {

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
	private:
		Graphics^ currGraph;
        SolidBrush^ brUse;
        BufferedGraphics^ buffer;				// буфер для рендеринга
        BufferedGraphicsContext^ bufferContext;  // создание буфера
        Pen^ drPen;
        SolidBrush^ brClear;
	private: System::Windows::Forms::ColorDialog^  cdEllipse;
	private: System::Windows::Forms::ComboBox^  cbMethod;


		Color color;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			currGraph = pbDraw->CreateGraphics();
			bufferContext = gcnew BufferedGraphicsContext();
			buffer = bufferContext->Allocate(currGraph, pbDraw->ClientRectangle);
			brUse = gcnew SolidBrush(color.Black);
			brClear = gcnew SolidBrush(color.White);
			drPen = gcnew Pen (color.Black);

			buffer->Graphics->FillRectangle(brClear, 0, 0, 500, 500);
			buffer->Render(currGraph);
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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tpEllipse;
	private: System::Windows::Forms::NumericUpDown^  nmERX;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  nmEY;
	private: System::Windows::Forms::Label^  Label2;
	private: System::Windows::Forms::NumericUpDown^  nmEX;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  tpCircle;
	private: System::Windows::Forms::TabPage^  tpElSpectre;
	private: System::Windows::Forms::TabPage^  tpElCircle;
	private: System::Windows::Forms::NumericUpDown^  nmERY;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  nmCR;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::NumericUpDown^  nmCY;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  nmCX;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  nmSESY;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::NumericUpDown^  nmSESX;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::NumericUpDown^  nmSERY;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::NumericUpDown^  nmSERX;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::NumericUpDown^  nmSEY;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  nmSEX;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  nmSCSCR;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::NumericUpDown^  nmSCR;

	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::NumericUpDown^  nmSCY;

	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::NumericUpDown^  nmSCX;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Button^  btnDrawColor;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Button^  btnClearColor;
	private: System::Windows::Forms::Button^  btnDraw;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  lbTime;
	private: System::Windows::Forms::PictureBox^  pbDraw;


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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tpEllipse = (gcnew System::Windows::Forms::TabPage());
			this->nmERY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nmERX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->nmEY = (gcnew System::Windows::Forms::NumericUpDown());
			this->Label2 = (gcnew System::Windows::Forms::Label());
			this->nmEX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tpCircle = (gcnew System::Windows::Forms::TabPage());
			this->nmCR = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->nmCY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->nmCX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tpElSpectre = (gcnew System::Windows::Forms::TabPage());
			this->nmSESY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->nmSESX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->nmSERY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->nmSERX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->nmSEY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->nmSEX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tpElCircle = (gcnew System::Windows::Forms::TabPage());
			this->nmSCSCR = (gcnew System::Windows::Forms::NumericUpDown());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->nmSCR = (gcnew System::Windows::Forms::NumericUpDown());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->nmSCY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->nmSCX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->btnDrawColor = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->btnClearColor = (gcnew System::Windows::Forms::Button());
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->lbTime = (gcnew System::Windows::Forms::Label());
			this->pbDraw = (gcnew System::Windows::Forms::PictureBox());
			this->cdEllipse = (gcnew System::Windows::Forms::ColorDialog());
			this->cbMethod = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl1->SuspendLayout();
			this->tpEllipse->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmERY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmERX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmEY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmEX))->BeginInit();
			this->tpCircle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCX))->BeginInit();
			this->tpElSpectre->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSESY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSESX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSERY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSERX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSEY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSEX))->BeginInit();
			this->tpElCircle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCSCR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbDraw))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tpEllipse);
			this->tabControl1->Controls->Add(this->tpCircle);
			this->tabControl1->Controls->Add(this->tpElSpectre);
			this->tabControl1->Controls->Add(this->tpElCircle);
			this->tabControl1->Location = System::Drawing::Point(538, 16);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(476, 160);
			this->tabControl1->TabIndex = 0;
			// 
			// tpEllipse
			// 
			this->tpEllipse->Controls->Add(this->nmERY);
			this->tpEllipse->Controls->Add(this->label4);
			this->tpEllipse->Controls->Add(this->nmERX);
			this->tpEllipse->Controls->Add(this->label3);
			this->tpEllipse->Controls->Add(this->nmEY);
			this->tpEllipse->Controls->Add(this->Label2);
			this->tpEllipse->Controls->Add(this->nmEX);
			this->tpEllipse->Controls->Add(this->label1);
			this->tpEllipse->Location = System::Drawing::Point(4, 22);
			this->tpEllipse->Name = L"tpEllipse";
			this->tpEllipse->Padding = System::Windows::Forms::Padding(3);
			this->tpEllipse->Size = System::Drawing::Size(468, 134);
			this->tpEllipse->TabIndex = 0;
			this->tpEllipse->Text = L"Эллипс";
			this->tpEllipse->UseVisualStyleBackColor = true;
			// 
			// nmERY
			// 
			this->nmERY->Location = System::Drawing::Point(292, 34);
			this->nmERY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmERY->Name = L"nmERY";
			this->nmERY->Size = System::Drawing::Size(120, 20);
			this->nmERY->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(218, 34);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Радиус по Y";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// nmERX
			// 
			this->nmERX->Location = System::Drawing::Point(84, 34);
			this->nmERX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmERX->Name = L"nmERX";
			this->nmERX->Size = System::Drawing::Size(120, 20);
			this->nmERX->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Радиус по X";
			// 
			// nmEY
			// 
			this->nmEY->Location = System::Drawing::Point(173, 7);
			this->nmEY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmEY->Name = L"nmEY";
			this->nmEY->Size = System::Drawing::Size(120, 20);
			this->nmEY->TabIndex = 3;
			// 
			// Label2
			// 
			this->Label2->AutoSize = true;
			this->Label2->Location = System::Drawing::Point(153, 9);
			this->Label2->Name = L"Label2";
			this->Label2->Size = System::Drawing::Size(14, 13);
			this->Label2->TabIndex = 2;
			this->Label2->Text = L"Y";
			// 
			// nmEX
			// 
			this->nmEX->Location = System::Drawing::Point(27, 7);
			this->nmEX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmEX->Name = L"nmEX";
			this->nmEX->Size = System::Drawing::Size(120, 20);
			this->nmEX->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X";
			// 
			// tpCircle
			// 
			this->tpCircle->Controls->Add(this->nmCR);
			this->tpCircle->Controls->Add(this->label7);
			this->tpCircle->Controls->Add(this->nmCY);
			this->tpCircle->Controls->Add(this->label6);
			this->tpCircle->Controls->Add(this->nmCX);
			this->tpCircle->Controls->Add(this->label5);
			this->tpCircle->Location = System::Drawing::Point(4, 22);
			this->tpCircle->Name = L"tpCircle";
			this->tpCircle->Padding = System::Windows::Forms::Padding(3);
			this->tpCircle->Size = System::Drawing::Size(468, 134);
			this->tpCircle->TabIndex = 1;
			this->tpCircle->Text = L"Окружность";
			this->tpCircle->UseVisualStyleBackColor = true;
			// 
			// nmCR
			// 
			this->nmCR->Location = System::Drawing::Point(52, 33);
			this->nmCR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmCR->Name = L"nmCR";
			this->nmCR->Size = System::Drawing::Size(120, 20);
			this->nmCR->TabIndex = 5;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 35);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 13);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Радиус";
			// 
			// nmCY
			// 
			this->nmCY->Location = System::Drawing::Point(173, 3);
			this->nmCY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmCY->Name = L"nmCY";
			this->nmCY->Size = System::Drawing::Size(120, 20);
			this->nmCY->TabIndex = 3;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(153, 6);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Y";
			// 
			// nmCX
			// 
			this->nmCX->Location = System::Drawing::Point(26, 3);
			this->nmCX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmCX->Name = L"nmCX";
			this->nmCX->Size = System::Drawing::Size(120, 20);
			this->nmCX->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 6);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"X";
			// 
			// tpElSpectre
			// 
			this->tpElSpectre->Controls->Add(this->nmSESY);
			this->tpElSpectre->Controls->Add(this->label13);
			this->tpElSpectre->Controls->Add(this->nmSESX);
			this->tpElSpectre->Controls->Add(this->label12);
			this->tpElSpectre->Controls->Add(this->nmSERY);
			this->tpElSpectre->Controls->Add(this->label11);
			this->tpElSpectre->Controls->Add(this->nmSERX);
			this->tpElSpectre->Controls->Add(this->label10);
			this->tpElSpectre->Controls->Add(this->nmSEY);
			this->tpElSpectre->Controls->Add(this->label9);
			this->tpElSpectre->Controls->Add(this->nmSEX);
			this->tpElSpectre->Controls->Add(this->label8);
			this->tpElSpectre->Location = System::Drawing::Point(4, 22);
			this->tpElSpectre->Name = L"tpElSpectre";
			this->tpElSpectre->Size = System::Drawing::Size(468, 134);
			this->tpElSpectre->TabIndex = 2;
			this->tpElSpectre->Text = L"Спектр эллипсов";
			this->tpElSpectre->UseVisualStyleBackColor = true;
			// 
			// nmSESY
			// 
			this->nmSESY->Location = System::Drawing::Point(348, 53);
			this->nmSESY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSESY->Name = L"nmSESY";
			this->nmSESY->Size = System::Drawing::Size(120, 20);
			this->nmSESY->TabIndex = 11;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(288, 51);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(52, 13);
			this->label13->TabIndex = 10;
			this->label13->Text = L"Шаг по Y";
			// 
			// nmSESX
			// 
			this->nmSESX->Location = System::Drawing::Point(111, 44);
			this->nmSESX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSESX->Name = L"nmSESX";
			this->nmSESX->Size = System::Drawing::Size(120, 20);
			this->nmSESX->TabIndex = 9;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(7, 46);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(52, 13);
			this->label12->TabIndex = 8;
			this->label12->Text = L"Шаг по X";
			// 
			// nmSERY
			// 
			this->nmSERY->Location = System::Drawing::Point(345, 29);
			this->nmSERY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSERY->Name = L"nmSERY";
			this->nmSERY->Size = System::Drawing::Size(120, 20);
			this->nmSERY->TabIndex = 7;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(239, 29);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(101, 13);
			this->label11->TabIndex = 6;
			this->label11->Text = L"Макс. Радиус по Y";
			// 
			// nmSERX
			// 
			this->nmSERX->Location = System::Drawing::Point(113, 25);
			this->nmSERX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSERX->Name = L"nmSERX";
			this->nmSERX->Size = System::Drawing::Size(120, 20);
			this->nmSERX->TabIndex = 5;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 29);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(101, 13);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Макс. Радиус по X";
			// 
			// nmSEY
			// 
			this->nmSEY->Location = System::Drawing::Point(173, 4);
			this->nmSEY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSEY->Name = L"nmSEY";
			this->nmSEY->Size = System::Drawing::Size(120, 20);
			this->nmSEY->TabIndex = 3;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(152, 4);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(14, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Y";
			// 
			// nmSEX
			// 
			this->nmSEX->Location = System::Drawing::Point(25, 0);
			this->nmSEX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSEX->Name = L"nmSEX";
			this->nmSEX->Size = System::Drawing::Size(120, 20);
			this->nmSEX->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(4, 4);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(14, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"X";
			// 
			// tpElCircle
			// 
			this->tpElCircle->Controls->Add(this->nmSCSCR);
			this->tpElCircle->Controls->Add(this->label17);
			this->tpElCircle->Controls->Add(this->nmSCR);
			this->tpElCircle->Controls->Add(this->label16);
			this->tpElCircle->Controls->Add(this->nmSCY);
			this->tpElCircle->Controls->Add(this->label15);
			this->tpElCircle->Controls->Add(this->nmSCX);
			this->tpElCircle->Controls->Add(this->label14);
			this->tpElCircle->Location = System::Drawing::Point(4, 22);
			this->tpElCircle->Name = L"tpElCircle";
			this->tpElCircle->Size = System::Drawing::Size(468, 134);
			this->tpElCircle->TabIndex = 3;
			this->tpElCircle->Text = L"Спектр окружностей";
			this->tpElCircle->UseVisualStyleBackColor = true;
			// 
			// nmSCSCR
			// 
			this->nmSCSCR->Location = System::Drawing::Point(85, 63);
			this->nmSCSCR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSCSCR->Name = L"nmSCSCR";
			this->nmSCSCR->Size = System::Drawing::Size(120, 20);
			this->nmSCSCR->TabIndex = 7;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(7, 63);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(71, 13);
			this->label17->TabIndex = 6;
			this->label17->Text = L"Шаг радиуса";
			// 
			// nmSCR
			// 
			this->nmSCR->Location = System::Drawing::Point(57, 31);
			this->nmSCR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSCR->Name = L"nmSCR";
			this->nmSCR->Size = System::Drawing::Size(120, 20);
			this->nmSCR->TabIndex = 5;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(7, 31);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(43, 13);
			this->label16->TabIndex = 4;
			this->label16->Text = L"Радиус";
			// 
			// nmSCY
			// 
			this->nmSCY->Location = System::Drawing::Point(171, 4);
			this->nmSCY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSCY->Name = L"nmSCY";
			this->nmSCY->Size = System::Drawing::Size(120, 20);
			this->nmSCY->TabIndex = 3;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(150, 6);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(14, 13);
			this->label15->TabIndex = 2;
			this->label15->Text = L"Y";
			// 
			// nmSCX
			// 
			this->nmSCX->Location = System::Drawing::Point(24, 4);
			this->nmSCX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->nmSCX->Name = L"nmSCX";
			this->nmSCX->Size = System::Drawing::Size(120, 20);
			this->nmSCX->TabIndex = 1;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(4, 4);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(14, 13);
			this->label14->TabIndex = 0;
			this->label14->Text = L"X";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(539, 189);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(92, 13);
			this->label18->TabIndex = 1;
			this->label18->Text = L"Цвет рисования:";
			// 
			// btnDrawColor
			// 
			this->btnDrawColor->BackColor = System::Drawing::Color::Black;
			this->btnDrawColor->Location = System::Drawing::Point(635, 184);
			this->btnDrawColor->Name = L"btnDrawColor";
			this->btnDrawColor->Size = System::Drawing::Size(75, 23);
			this->btnDrawColor->TabIndex = 2;
			this->btnDrawColor->UseVisualStyleBackColor = false;
			this->btnDrawColor->Click += gcnew System::EventHandler(this, &Form1::btnDrawColor_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(542, 215);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(64, 13);
			this->label19->TabIndex = 3;
			this->label19->Text = L"Цвет фона:";
			// 
			// btnClearColor
			// 
			this->btnClearColor->BackColor = System::Drawing::Color::White;
			this->btnClearColor->Location = System::Drawing::Point(635, 215);
			this->btnClearColor->Name = L"btnClearColor";
			this->btnClearColor->Size = System::Drawing::Size(75, 23);
			this->btnClearColor->TabIndex = 4;
			this->btnClearColor->UseVisualStyleBackColor = false;
			this->btnClearColor->Click += gcnew System::EventHandler(this, &Form1::btnClearColor_Click);
			// 
			// btnDraw
			// 
			this->btnDraw->Location = System::Drawing::Point(635, 245);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(84, 23);
			this->btnDraw->TabIndex = 5;
			this->btnDraw->Text = L"Нарисовать";
			this->btnDraw->UseVisualStyleBackColor = true;
			this->btnDraw->Click += gcnew System::EventHandler(this, &Form1::btnDraw_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(635, 275);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 6;
			this->btnClear->Text = L"Очистить";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(543, 311);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(151, 13);
			this->label20->TabIndex = 7;
			this->label20->Text = L"Время последней операции:";
			// 
			// lbTime
			// 
			this->lbTime->AutoSize = true;
			this->lbTime->Location = System::Drawing::Point(709, 311);
			this->lbTime->Name = L"lbTime";
			this->lbTime->Size = System::Drawing::Size(0, 13);
			this->lbTime->TabIndex = 8;
			// 
			// pbDraw
			// 
			this->pbDraw->Location = System::Drawing::Point(13, 12);
			this->pbDraw->Name = L"pbDraw";
			this->pbDraw->Size = System::Drawing::Size(500, 500);
			this->pbDraw->TabIndex = 9;
			this->pbDraw->TabStop = false;
			// 
			// cbMethod
			// 
			this->cbMethod->FormattingEnabled = true;
			this->cbMethod->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Ур-е в декартовой СК", L"Ур-е в параметрической форме", 
				L"Алгоритм средней точки", L"Алгоритм Брезенхема", L"Библиотечная функция"});
			this->cbMethod->Location = System::Drawing::Point(725, 247);
			this->cbMethod->Name = L"cbMethod";
			this->cbMethod->Size = System::Drawing::Size(200, 21);
			this->cbMethod->TabIndex = 10;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1014, 519);
			this->Controls->Add(this->cbMethod);
			this->Controls->Add(this->pbDraw);
			this->Controls->Add(this->lbTime);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnDraw);
			this->Controls->Add(this->btnClearColor);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->btnDrawColor);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Lab4";
			this->tabControl1->ResumeLayout(false);
			this->tpEllipse->ResumeLayout(false);
			this->tpEllipse->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmERY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmERX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmEY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmEX))->EndInit();
			this->tpCircle->ResumeLayout(false);
			this->tpCircle->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCX))->EndInit();
			this->tpElSpectre->ResumeLayout(false);
			this->tpElSpectre->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSESY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSESX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSERY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSERX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSEY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSEX))->EndInit();
			this->tpElCircle->ResumeLayout(false);
			this->tpElCircle->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCSCR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmSCX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbDraw))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnDrawColor_Click(System::Object^  sender, System::EventArgs^  e) {
				 cdEllipse->Color = btnDrawColor->BackColor;
				 cdEllipse->ShowDialog();
				 drPen->Color = cdEllipse->Color;
				 brUse->Color = cdEllipse->Color;

				 btnDrawColor->ForeColor = cdEllipse->Color;
				 btnDrawColor->BackColor = cdEllipse->Color;
			 }
private: System::Void btnClearColor_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 cdEllipse->Color = btnClearColor->BackColor;
				 cdEllipse->ShowDialog();

				 brClear->Color = cdEllipse->Color;
				 btnClearColor->ForeColor = cdEllipse->Color;
				 btnClearColor->BackColor = cdEllipse->Color;
		 }
private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
			buffer->Graphics->FillRectangle(brClear, pbDraw->ClientRectangle);
            buffer->Render (currGraph);

			lbTime->Text = "";
		 }
private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e) {


			 typedef double (*TDrawFunc)(Point center, int radx, int rady, BufferedGraphics^ buffer, SolidBrush^ brush, Graphics^ graph);

			 TDrawFunc funcs[] = {&Equation, &Parametric, &MiddlePoint, &Brezenham, &LibFunc};

			int choice = cbMethod->SelectedIndex;
			if (choice == -1)
				return;

			TDrawFunc curr = funcs[cbMethod->SelectedIndex];

			double res = 0;

			int maxX, maxY, stepX, stepY;
			switch (tabControl1->SelectedIndex)
			{
			case 0:
				{
					Point center ((int) nmEX->Value, (int) nmEY->Value);
					int radx = (int) nmERX->Value, rady = (int) nmERY->Value;

					double res = curr (center, radx, rady, buffer, brUse, currGraph);
					break;
				}
			case 1:
				{
					Point center ((int) nmCX->Value, (int) nmCY->Value);
					int rad = (int) nmCR->Value;

					double res = curr (center, rad, rad, buffer, brUse, currGraph);
					break;
				}
			case 2:
				{
					Point center ((int) nmSEX->Value, (int) nmSEY->Value);
					maxX = (int) nmSERX->Value; maxY = (int) nmSERY->Value;
					stepX = (int) nmSESX->Value; stepY = (int) nmSESY->Value;


					for (int currX = stepX, currY = stepY; (currX <= maxX) && (currY <= maxY); currX += stepX, currY += stepY)
						res += curr (center, currX, currY, buffer, brUse, currGraph);

					break;
				}
			case 3:
				{
					Point center ((int) nmSCX->Value, (int) nmSCY->Value);
					int max = (int) nmSCR->Value;
					int step = (int) nmSCSCR->Value;

					for (int currRad = step; currRad <= max; currRad += step)
						res += curr (center, currRad, currRad, buffer, brUse, currGraph);
				}
			}
			lbTime->Text = Double (res).ToString();
		 }
};
}