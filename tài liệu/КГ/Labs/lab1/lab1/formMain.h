#pragma once
#include "pointworks.h"
#include "listworks.h"
#include "paint.h"

namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; //инпут-оутпут для работы с файлами


	/// <summary>
	/// Summary for formMain
	/// </summary>
	public ref class formMain : public System::Windows::Forms::Form
	{
	public:
		formMain(void)
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
		~formMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;


	private: System::Windows::Forms::Button^  btnCalc;






	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_file;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_file_list2;



	private: System::Windows::Forms::ToolStripMenuItem^  menu_task;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_file_list1;


	private: System::Windows::Forms::OpenFileDialog^  dlgOpen;










	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btnEdit1;
	private: System::Windows::Forms::Button^  btnDelete1;
	private: System::Windows::Forms::DataGridView^  dataTable1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataTable1_Num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataTable1_X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataTable1_Y;
	private: System::Windows::Forms::Button^  btnAdd1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  btnEdit2;
	private: System::Windows::Forms::Button^  btnDelete2;
	private: System::Windows::Forms::DataGridView^  dataTable2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataTable2_Num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataTable2_X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataTable2_Y;
	private: System::Windows::Forms::Button^  btnAdd2;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_file_list1_load;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_file_list1_clear;

	private: System::Windows::Forms::ToolStripMenuItem^  menu_file_list2_load;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_file_list2_clear;

	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Button^  btnDraw;







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
			this->btnCalc = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menu_file = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_file_list1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_file_list1_load = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_file_list1_clear = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_file_list2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_file_list2_load = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_file_list2_clear = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_task = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dlgOpen = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnEdit1 = (gcnew System::Windows::Forms::Button());
			this->btnDelete1 = (gcnew System::Windows::Forms::Button());
			this->dataTable1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataTable1_Num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataTable1_X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataTable1_Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnAdd1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnEdit2 = (gcnew System::Windows::Forms::Button());
			this->btnDelete2 = (gcnew System::Windows::Forms::Button());
			this->dataTable2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataTable2_Num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataTable2_X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataTable2_Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnAdd2 = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::AliceBlue;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(420, 320);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnCalc
			// 
			this->btnCalc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnCalc->Location = System::Drawing::Point(30, 353);
			this->btnCalc->Name = L"btnCalc";
			this->btnCalc->Size = System::Drawing::Size(106, 40);
			this->btnCalc->TabIndex = 5;
			this->btnCalc->Text = L"Решить задачу";
			this->btnCalc->UseVisualStyleBackColor = true;
			this->btnCalc->Click += gcnew System::EventHandler(this, &formMain::btnCalc_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menu_file, this->menu_task});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(766, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menu";
			// 
			// menu_file
			// 
			this->menu_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menu_file_list1, 
				this->menu_file_list2});
			this->menu_file->Name = L"menu_file";
			this->menu_file->Size = System::Drawing::Size(48, 20);
			this->menu_file->Text = L"&Файл";
			// 
			// menu_file_list1
			// 
			this->menu_file_list1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menu_file_list1_load, 
				this->menu_file_list1_clear});
			this->menu_file_list1->Name = L"menu_file_list1";
			this->menu_file_list1->Size = System::Drawing::Size(124, 22);
			this->menu_file_list1->Text = L"Список &1";
			// 
			// menu_file_list1_load
			// 
			this->menu_file_list1_load->Name = L"menu_file_list1_load";
			this->menu_file_list1_load->Size = System::Drawing::Size(128, 22);
			this->menu_file_list1_load->Text = L"&Загрузить";
			this->menu_file_list1_load->Click += gcnew System::EventHandler(this, &formMain::menu_file_list1_load_Click);
			// 
			// menu_file_list1_clear
			// 
			this->menu_file_list1_clear->Name = L"menu_file_list1_clear";
			this->menu_file_list1_clear->Size = System::Drawing::Size(128, 22);
			this->menu_file_list1_clear->Text = L"&Очистить";
			this->menu_file_list1_clear->Click += gcnew System::EventHandler(this, &formMain::menu_file_list1_clear_Click);
			// 
			// menu_file_list2
			// 
			this->menu_file_list2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menu_file_list2_load, 
				this->menu_file_list2_clear});
			this->menu_file_list2->Name = L"menu_file_list2";
			this->menu_file_list2->Size = System::Drawing::Size(124, 22);
			this->menu_file_list2->Text = L"Список &2";
			// 
			// menu_file_list2_load
			// 
			this->menu_file_list2_load->Name = L"menu_file_list2_load";
			this->menu_file_list2_load->Size = System::Drawing::Size(128, 22);
			this->menu_file_list2_load->Text = L"&Загрузить";
			this->menu_file_list2_load->Click += gcnew System::EventHandler(this, &formMain::menu_file_list2_load_Click);
			// 
			// menu_file_list2_clear
			// 
			this->menu_file_list2_clear->Name = L"menu_file_list2_clear";
			this->menu_file_list2_clear->Size = System::Drawing::Size(128, 22);
			this->menu_file_list2_clear->Text = L"&Очистить";
			this->menu_file_list2_clear->Click += gcnew System::EventHandler(this, &formMain::menu_file_list2_clear_Click);
			// 
			// menu_task
			// 
			this->menu_task->Name = L"menu_task";
			this->menu_task->Size = System::Drawing::Size(65, 20);
			this->menu_task->Text = L"Условие";
			this->menu_task->Click += gcnew System::EventHandler(this, &formMain::menu_task_Click);
			// 
			// dlgOpen
			// 
			this->dlgOpen->Filter = L"Points sets(*.set;*.txt)|*.set;*.txt|All files (*.*)|*.*";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnEdit1);
			this->groupBox1->Controls->Add(this->btnDelete1);
			this->groupBox1->Controls->Add(this->dataTable1);
			this->groupBox1->Controls->Add(this->btnAdd1);
			this->groupBox1->Location = System::Drawing::Point(438, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(155, 366);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Список 1";
			// 
			// btnEdit1
			// 
			this->btnEdit1->Location = System::Drawing::Point(41, 336);
			this->btnEdit1->Name = L"btnEdit1";
			this->btnEdit1->Size = System::Drawing::Size(70, 23);
			this->btnEdit1->TabIndex = 14;
			this->btnEdit1->Text = L"Изменить";
			this->btnEdit1->UseVisualStyleBackColor = true;
			this->btnEdit1->Click += gcnew System::EventHandler(this, &formMain::btnEdit1_Click);
			// 
			// btnDelete1
			// 
			this->btnDelete1->Location = System::Drawing::Point(80, 307);
			this->btnDelete1->Name = L"btnDelete1";
			this->btnDelete1->Size = System::Drawing::Size(69, 23);
			this->btnDelete1->TabIndex = 13;
			this->btnDelete1->Text = L"Удалить";
			this->btnDelete1->UseVisualStyleBackColor = true;
			this->btnDelete1->Click += gcnew System::EventHandler(this, &formMain::btnDelete1_Click);
			// 
			// dataTable1
			// 
			this->dataTable1->AllowUserToAddRows = false;
			this->dataTable1->AllowUserToDeleteRows = false;
			this->dataTable1->AllowUserToResizeColumns = false;
			this->dataTable1->AllowUserToResizeRows = false;
			this->dataTable1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataTable1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dataTable1_Num, 
				this->dataTable1_X, this->dataTable1_Y});
			this->dataTable1->EnableHeadersVisualStyles = false;
			this->dataTable1->Location = System::Drawing::Point(6, 19);
			this->dataTable1->MultiSelect = false;
			this->dataTable1->Name = L"dataTable1";
			this->dataTable1->ReadOnly = true;
			this->dataTable1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataTable1->RowHeadersVisible = false;
			this->dataTable1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataTable1->ShowEditingIcon = false;
			this->dataTable1->Size = System::Drawing::Size(143, 282);
			this->dataTable1->TabIndex = 12;
			// 
			// dataTable1_Num
			// 
			this->dataTable1_Num->Frozen = true;
			this->dataTable1_Num->HeaderText = L"#";
			this->dataTable1_Num->Name = L"dataTable1_Num";
			this->dataTable1_Num->ReadOnly = true;
			this->dataTable1_Num->Width = 23;
			// 
			// dataTable1_X
			// 
			this->dataTable1_X->Frozen = true;
			this->dataTable1_X->HeaderText = L"X";
			this->dataTable1_X->Name = L"dataTable1_X";
			this->dataTable1_X->ReadOnly = true;
			this->dataTable1_X->Width = 60;
			// 
			// dataTable1_Y
			// 
			this->dataTable1_Y->Frozen = true;
			this->dataTable1_Y->HeaderText = L"Y";
			this->dataTable1_Y->Name = L"dataTable1_Y";
			this->dataTable1_Y->ReadOnly = true;
			this->dataTable1_Y->Width = 60;
			// 
			// btnAdd1
			// 
			this->btnAdd1->Location = System::Drawing::Point(6, 307);
			this->btnAdd1->Name = L"btnAdd1";
			this->btnAdd1->Size = System::Drawing::Size(69, 23);
			this->btnAdd1->TabIndex = 11;
			this->btnAdd1->Text = L"Добавить";
			this->btnAdd1->UseVisualStyleBackColor = true;
			this->btnAdd1->Click += gcnew System::EventHandler(this, &formMain::btnAdd1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btnEdit2);
			this->groupBox2->Controls->Add(this->btnDelete2);
			this->groupBox2->Controls->Add(this->dataTable2);
			this->groupBox2->Controls->Add(this->btnAdd2);
			this->groupBox2->Location = System::Drawing::Point(599, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(155, 366);
			this->groupBox2->TabIndex = 17;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Список 2";
			// 
			// btnEdit2
			// 
			this->btnEdit2->Location = System::Drawing::Point(41, 336);
			this->btnEdit2->Name = L"btnEdit2";
			this->btnEdit2->Size = System::Drawing::Size(70, 23);
			this->btnEdit2->TabIndex = 18;
			this->btnEdit2->Text = L"Изменить";
			this->btnEdit2->UseVisualStyleBackColor = true;
			this->btnEdit2->Click += gcnew System::EventHandler(this, &formMain::btnEdit2_Click);
			// 
			// btnDelete2
			// 
			this->btnDelete2->Location = System::Drawing::Point(80, 307);
			this->btnDelete2->Name = L"btnDelete2";
			this->btnDelete2->Size = System::Drawing::Size(69, 23);
			this->btnDelete2->TabIndex = 17;
			this->btnDelete2->Text = L"Удалить";
			this->btnDelete2->UseVisualStyleBackColor = true;
			this->btnDelete2->Click += gcnew System::EventHandler(this, &formMain::btnDelete2_Click);
			// 
			// dataTable2
			// 
			this->dataTable2->AllowUserToAddRows = false;
			this->dataTable2->AllowUserToDeleteRows = false;
			this->dataTable2->AllowUserToResizeColumns = false;
			this->dataTable2->AllowUserToResizeRows = false;
			this->dataTable2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataTable2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dataTable2_Num, 
				this->dataTable2_X, this->dataTable2_Y});
			this->dataTable2->EnableHeadersVisualStyles = false;
			this->dataTable2->Location = System::Drawing::Point(6, 19);
			this->dataTable2->MultiSelect = false;
			this->dataTable2->Name = L"dataTable2";
			this->dataTable2->ReadOnly = true;
			this->dataTable2->RowHeadersVisible = false;
			this->dataTable2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataTable2->ShowEditingIcon = false;
			this->dataTable2->Size = System::Drawing::Size(143, 282);
			this->dataTable2->TabIndex = 16;
			// 
			// dataTable2_Num
			// 
			this->dataTable2_Num->Frozen = true;
			this->dataTable2_Num->HeaderText = L"#";
			this->dataTable2_Num->Name = L"dataTable2_Num";
			this->dataTable2_Num->ReadOnly = true;
			this->dataTable2_Num->Width = 23;
			// 
			// dataTable2_X
			// 
			this->dataTable2_X->Frozen = true;
			this->dataTable2_X->HeaderText = L"X";
			this->dataTable2_X->Name = L"dataTable2_X";
			this->dataTable2_X->ReadOnly = true;
			this->dataTable2_X->Width = 60;
			// 
			// dataTable2_Y
			// 
			this->dataTable2_Y->Frozen = true;
			this->dataTable2_Y->HeaderText = L"Y";
			this->dataTable2_Y->Name = L"dataTable2_Y";
			this->dataTable2_Y->ReadOnly = true;
			this->dataTable2_Y->Width = 60;
			// 
			// btnAdd2
			// 
			this->btnAdd2->Location = System::Drawing::Point(6, 307);
			this->btnAdd2->Name = L"btnAdd2";
			this->btnAdd2->Size = System::Drawing::Size(69, 23);
			this->btnAdd2->TabIndex = 15;
			this->btnAdd2->Text = L"Добавить";
			this->btnAdd2->UseVisualStyleBackColor = true;
			this->btnAdd2->Click += gcnew System::EventHandler(this, &formMain::btnAdd2_Click);
			// 
			// btnClear
			// 
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnClear->Location = System::Drawing::Point(289, 352);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(88, 40);
			this->btnClear->TabIndex = 18;
			this->btnClear->Text = L"Очистить холст";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &formMain::btnClear_Click);
			// 
			// btnDraw
			// 
			this->btnDraw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnDraw->Location = System::Drawing::Point(195, 352);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(88, 40);
			this->btnDraw->TabIndex = 19;
			this->btnDraw->Text = L"Отрисовать точки";
			this->btnDraw->UseVisualStyleBackColor = true;
			this->btnDraw->Click += gcnew System::EventHandler(this, &formMain::btnDraw_Click);
			// 
			// formMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 405);
			this->Controls->Add(this->btnDraw);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnCalc);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"formMain";
			this->Text = L"[КГ] ЛР №1";
			this->Load += gcnew System::EventHandler(this, &formMain::formMain_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		pointlist *List1, *List2; //списки точек для таблиц
		canvasstruct *Easel; //мольберт на котором рисовать, холст+размеры


//загрузочка формочки
private: System::Void formMain_Load(System::Object^  sender, System::EventArgs^  e);

//условие
private: System::Void menu_task_Click(System::Object^  sender, System::EventArgs^  e);

//список1: загрузка, очистка, отрисовка; добавить, удалить, изменить
private: System::Void menu_file_list1_load_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void menu_file_list1_clear_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void btnAdd1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnDelete1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnEdit1_Click(System::Object^  sender, System::EventArgs^  e);


//список2: загрузка, очистка, отрисовка; добавить, удалить, изменить
private: System::Void menu_file_list2_load_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void menu_file_list2_clear_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void btnAdd2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnDelete2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnEdit2_Click(System::Object^  sender, System::EventArgs^  e);


private: System::Void btnCalc_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e);
};
}

