#pragma once

#include "editor.h"
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
	private: System::Windows::Forms::PictureBox^  pctMain;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::PictureBox^  pctColorLine;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pctColorResult;
	private: System::Windows::Forms::PictureBox^  pctColorClip;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  pctColorBack;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ColorDialog^  dlgColor;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rdbDrawLine;
	private: System::Windows::Forms::RadioButton^  rdbDrawClip;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::TextBox^  txtClipLeft;
	private: System::Windows::Forms::TextBox^  txtClipRight;
	private: System::Windows::Forms::TextBox^  txtClipUp;
	private: System::Windows::Forms::TextBox^  txtClipDown;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Button^  btnClip;
	protected: 

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
			this->pctMain = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->pctColorLine = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pctColorResult = (gcnew System::Windows::Forms::PictureBox());
			this->pctColorClip = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pctColorBack = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dlgColor = (gcnew System::Windows::Forms::ColorDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rdbDrawLine = (gcnew System::Windows::Forms::RadioButton());
			this->rdbDrawClip = (gcnew System::Windows::Forms::RadioButton());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtClipLeft = (gcnew System::Windows::Forms::TextBox());
			this->txtClipRight = (gcnew System::Windows::Forms::TextBox());
			this->txtClipUp = (gcnew System::Windows::Forms::TextBox());
			this->txtClipDown = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClip = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctMain))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorLine))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorResult))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorClip))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pctMain
			// 
			this->pctMain->BackColor = System::Drawing::Color::AliceBlue;
			this->pctMain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctMain->Location = System::Drawing::Point(12, 12);
			this->pctMain->Name = L"pctMain";
			this->pctMain->Size = System::Drawing::Size(659, 552);
			this->pctMain->TabIndex = 0;
			this->pctMain->TabStop = false;
			this->pctMain->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pctMain_MouseDown);
			this->pctMain->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pctMain_MouseMove);
			this->pctMain->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pctMain_MouseUp);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->pctColorLine);
			this->groupBox4->Controls->Add(this->label2);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->pctColorResult);
			this->groupBox4->Controls->Add(this->pctColorClip);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->pctColorBack);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(699, 436);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(139, 128);
			this->groupBox4->TabIndex = 15;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Цвета:";
			// 
			// pctColorLine
			// 
			this->pctColorLine->BackColor = System::Drawing::Color::Black;
			this->pctColorLine->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorLine->Location = System::Drawing::Point(6, 19);
			this->pctColorLine->Name = L"pctColorLine";
			this->pctColorLine->Size = System::Drawing::Size(20, 20);
			this->pctColorLine->TabIndex = 9;
			this->pctColorLine->TabStop = false;
			this->pctColorLine->Click += gcnew System::EventHandler(this, &Form1::pct_PickColor);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Цвет результата";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Цвет отсекателя";
			// 
			// pctColorResult
			// 
			this->pctColorResult->BackColor = System::Drawing::Color::Red;
			this->pctColorResult->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorResult->Location = System::Drawing::Point(6, 97);
			this->pctColorResult->Name = L"pctColorResult";
			this->pctColorResult->Size = System::Drawing::Size(20, 20);
			this->pctColorResult->TabIndex = 10;
			this->pctColorResult->TabStop = false;
			this->pctColorResult->Click += gcnew System::EventHandler(this, &Form1::pct_PickColor);
			// 
			// pctColorClip
			// 
			this->pctColorClip->BackColor = System::Drawing::Color::Blue;
			this->pctColorClip->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorClip->Location = System::Drawing::Point(6, 71);
			this->pctColorClip->Name = L"pctColorClip";
			this->pctColorClip->Size = System::Drawing::Size(20, 20);
			this->pctColorClip->TabIndex = 10;
			this->pctColorClip->TabStop = false;
			this->pctColorClip->Click += gcnew System::EventHandler(this, &Form1::pct_PickColor);
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
			this->label5->Size = System::Drawing::Size(76, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Цвет отрезка";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rdbDrawLine);
			this->groupBox1->Controls->Add(this->rdbDrawClip);
			this->groupBox1->Location = System::Drawing::Point(699, 364);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(139, 66);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Рисовать:";
			// 
			// rdbDrawLine
			// 
			this->rdbDrawLine->AutoSize = true;
			this->rdbDrawLine->Location = System::Drawing::Point(6, 42);
			this->rdbDrawLine->Name = L"rdbDrawLine";
			this->rdbDrawLine->Size = System::Drawing::Size(68, 17);
			this->rdbDrawLine->TabIndex = 0;
			this->rdbDrawLine->Text = L"Отрезок";
			this->rdbDrawLine->UseVisualStyleBackColor = true;
			// 
			// rdbDrawClip
			// 
			this->rdbDrawClip->AutoSize = true;
			this->rdbDrawClip->Checked = true;
			this->rdbDrawClip->Location = System::Drawing::Point(6, 19);
			this->rdbDrawClip->Name = L"rdbDrawClip";
			this->rdbDrawClip->Size = System::Drawing::Size(85, 17);
			this->rdbDrawClip->TabIndex = 0;
			this->rdbDrawClip->TabStop = true;
			this->rdbDrawClip->Text = L"Отсекатель";
			this->rdbDrawClip->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column1, 
				this->Column2, this->Column3, this->Column4});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(677, 12);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->DividerHeight = 1;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(183, 251);
			this->dataGridView1->TabIndex = 17;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellClick);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellEndEdit);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"X1";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Y1";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 40;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"X2";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 40;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Y2";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 40;
			// 
			// txtClipLeft
			// 
			this->txtClipLeft->Location = System::Drawing::Point(677, 338);
			this->txtClipLeft->Name = L"txtClipLeft";
			this->txtClipLeft->ReadOnly = true;
			this->txtClipLeft->Size = System::Drawing::Size(40, 20);
			this->txtClipLeft->TabIndex = 18;
			// 
			// txtClipRight
			// 
			this->txtClipRight->Location = System::Drawing::Point(723, 338);
			this->txtClipRight->Name = L"txtClipRight";
			this->txtClipRight->ReadOnly = true;
			this->txtClipRight->Size = System::Drawing::Size(40, 20);
			this->txtClipRight->TabIndex = 18;
			// 
			// txtClipUp
			// 
			this->txtClipUp->Location = System::Drawing::Point(815, 338);
			this->txtClipUp->Name = L"txtClipUp";
			this->txtClipUp->ReadOnly = true;
			this->txtClipUp->Size = System::Drawing::Size(40, 20);
			this->txtClipUp->TabIndex = 18;
			// 
			// txtClipDown
			// 
			this->txtClipDown->Location = System::Drawing::Point(769, 338);
			this->txtClipDown->Name = L"txtClipDown";
			this->txtClipDown->ReadOnly = true;
			this->txtClipDown->Size = System::Drawing::Size(40, 20);
			this->txtClipDown->TabIndex = 18;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(674, 322);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Лев.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(720, 322);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Прав.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(766, 322);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Ниж.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(812, 322);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(34, 13);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Верх.";
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(677, 269);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 20;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);
			// 
			// btnClip
			// 
			this->btnClip->Location = System::Drawing::Point(785, 269);
			this->btnClip->Name = L"btnClip";
			this->btnClip->Size = System::Drawing::Size(75, 23);
			this->btnClip->TabIndex = 20;
			this->btnClip->Text = L"Отсечь";
			this->btnClip->UseVisualStyleBackColor = true;
			this->btnClip->Click += gcnew System::EventHandler(this, &Form1::btnClip_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(872, 576);
			this->Controls->Add(this->btnClip);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtClipDown);
			this->Controls->Add(this->txtClipUp);
			this->Controls->Add(this->txtClipRight);
			this->Controls->Add(this->txtClipLeft);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->pctMain);
			this->Name = L"Form1";
			this->Text = L"[КГ] ЛР №6";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctMain))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorLine))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorResult))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorClip))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#define DR System::Windows::Forms::DialogResult
#define MB System::Windows::Forms::MouseButtons

		cEditor *editor;

		//изменение цвета
		System::Void pct_PickColor(System::Object^  sender, System::EventArgs^  e)
		{
			if (dlgColor->ShowDialog() != DR::OK)
				return;

			PictureBox^ p = (PictureBox^) sender;
			p->BackColor = dlgColor->Color;
			editor->Refresh(pctColorBack->BackColor, pctColorClip->BackColor, pctColorLine->BackColor, pctColorResult->BackColor);
		}

		


		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			editor = new cEditor(pctMain, dataGridView1);
		}

		System::Void pctMain_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			if (e->Button == MB::Left)
			{
				if (rdbDrawClip->Checked)
				{
					editor->StartClip(e->X, e->Y);
					txtClipLeft->Text = Convert::ToString(editor->clip->left());
					txtClipUp->Text = Convert::ToString(editor->clip->up());
				}
				if (rdbDrawLine->Checked)
				{
					editor->StartLine(e->X, e->Y);
				}
			}
		}
		System::Void pctMain_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			if (e->Button == MB::Left)
			{
				if (rdbDrawClip->Checked)
				{
					editor->EndClip(e->X, e->Y);
				}
				if (rdbDrawLine->Checked)
				{
					editor->EndLine(e->X, e->Y);
				}
			}
		}
		System::Void pctMain_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			if (e->Button == MB::Left)
			{
				if (rdbDrawClip->Checked)
				{
					editor->EndClip(e->X, e->Y);
					txtClipDown->Text = Convert::ToString(editor->clip->down());
					txtClipRight->Text = Convert::ToString(editor->clip->right());
				}
				if (rdbDrawLine->Checked)
				{
					editor->EndLine(e->X, e->Y);
				}
			}
		}
		System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
		{
			editor->EditLine();
		}
		System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
		{
			editor->Redraw();
		}
		System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e)
		{
			editor->RemoveLine();
		}
		System::Void btnClip_Click(System::Object^  sender, System::EventArgs^  e)
		{
			editor->DoClip();
		}
};
}

