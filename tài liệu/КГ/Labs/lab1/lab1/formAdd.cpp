#include "StdAfx.h"
#include "formAdd.h"
#include "pointworks.h"

using namespace lab1;

//создаёт точку из координат вводимых в окно; возвращает Null если создание не прошло

realpoint* CreatePointForm()
{
	formAdd^ Adder = gcnew formAdd;
	realpoint* pt;

	if (Adder->ShowDialog() == DialogResult::OK)
		pt = FormPoint(Adder->txtX->Text, Adder->txtY->Text);
	else
		pt = nullptr;

	return pt;
}



System::Void formAdd::btnAdd_Click(System::Object^  sender, System::EventArgs^  e)
{
	double temp;
	//проверяем на правильность ввода
	if (!Double::TryParse(txtX->Text, CONVERT_NUMBER, temp))
	{
		MessageBox::Show("Некорректно введён X!");
		this->DialogResult = System::Windows::Forms::DialogResult::None;
		return;
	}
	if (!Double::TryParse(txtY->Text, CONVERT_NUMBER, temp))
	{
		MessageBox::Show("Некорректно введён Y!");
		this->DialogResult = System::Windows::Forms::DialogResult::None;
		return;
	}
	//this->Hide();
}
System::Void formAdd::btnCancel_Click(System::Object^  sender, System::EventArgs^  e)
{
	//this->Hide();
}