#pragma once

#include "pointworks.h"


//создаёт точку из координат вводимых в окно; возвращает Null если создание не прошло
realpoint* CreatePointForm();

namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

;

	/// <summary>
	/// Summary for formAdd
	/// </summary>
	public ref class formAdd : public System::Windows::Forms::Form
	{
	public:
		formAdd(void)
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
		~formAdd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnAdd;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox1;
	public: System::Windows::Forms::TextBox^  txtX; //публичные, чтобы можно было вытащить значения и передать в функцию
	private: System::Windows::Forms::GroupBox^  groupBox2;
	public: System::Windows::Forms::TextBox^  txtY;
	private: System::Windows::Forms::Button^  btnCancel;


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
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnAdd
			// 
			this->btnAdd->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnAdd->Location = System::Drawing::Point(24, 63);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(70, 23);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"ОК";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &formAdd::btnAdd_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtX);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(82, 45);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"X:";
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(6, 19);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(70, 20);
			this->txtX->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txtY);
			this->groupBox2->Location = System::Drawing::Point(118, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(82, 45);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Y:";
			// 
			// txtY
			// 
			this->txtY->Location = System::Drawing::Point(6, 19);
			this->txtY->Name = L"txtY";
			this->txtY->Size = System::Drawing::Size(70, 20);
			this->txtY->TabIndex = 1;
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(118, 63);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(70, 23);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->Text = L"Отменить";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// formAdd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(212, 98);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnAdd);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"formAdd";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Координаты:";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e);
};
}
