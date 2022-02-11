//
//		Реализация событий формочки
//

#include "stdafx.h"
#include "Form1.h"

#include "paint.h"
#include "ellipse.h"
#include "circle.h"

using namespace src;
using namespace System;



cEasel *easel; //мольберт для рисования

//загрузка формы
System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	easel = new cEasel(pictureBox1);
	cmbMethods->SelectedIndex = 0;
	nmrX->Maximum = easel->width/2;
	nmrX->Minimum = -easel->width/2;
	nmrY->Maximum = easel->height/2;
	nmrY->Minimum = -easel->height/2;
}

//установка центра на холсте
System::Void Form1::pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	int x = e->X - pictureBox1->Width/2;
	int y = -e->Y + pictureBox1->Height/2;
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		nmrX->Text = String::Format("{0}", x);
		nmrY->Text = String::Format("{0}", y);
	}
}

//выбор цветов
System::Void Form1::pctColorMain_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (colorDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		return;
	pctColorMain->BackColor = colorDialog1->Color;
}
System::Void Form1::pctColorBack_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (colorDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		return;
	pctColorBack->BackColor = colorDialog1->Color;
	//если отрисовываем фоном - то поменяем перо тоже
	if (!pctColorMain->Enabled)
		pctColorMain->BackColor = colorDialog1->Color;
}

//проверка на использование цвета фона
System::Void Form1::chkDrawBack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (chkDrawBack->Checked)
	{
		pctColorMain->Enabled = false;
		pctColorMain->BackColor = pctColorBack->BackColor;
	}
	else
	{
		pctColorMain->Enabled = true;
	}
}

//очистка
System::Void Form1::btnClear_Click(System::Object^  sender, System::EventArgs^  e)
{
	easel->Clear();
}

//отрисовка
System::Void Form1::btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (rdbCircle->Checked)
		Circle::SelectMethod(easel,
			Convert::ToInt32(nmrX->Value), Convert::ToInt32(nmrY->Value),
			Convert::ToInt32(nmrRadius->Value),
			pctColorMain->BackColor, cmbMethods->SelectedIndex
		);
	else
		Ellipse::SelectMethod(easel,
			Convert::ToInt32(nmrX->Value), Convert::ToInt32(nmrY->Value),
			Convert::ToInt32(nmrAxisX->Value), Convert::ToInt32(nmrAxisY->Value),
			pctColorMain->BackColor, cmbMethods->SelectedIndex
		);
}

//отрисовка спектром
System::Void Form1::btnSpectre_Click(System::Object^  sender, System::EventArgs^  e)
{
	//выбираем метод и отрисовываем спектр отрезков из точки
	if (rdbCircle->Checked)
	{
		Circle::SpectreMethod(easel,(Int32)nmrX->Value, (Int32)nmrY->Value, (Int32)nmrSpectreStep, (Int32)nmrAxisX->Value,);
	}
	else
	{
		Ellipse::SpectreMethod(easel, (Int32)nmrX->Value, (Int32)nmrY->Value, (Int32)nmrSpectreStep,
			(Int32)nmrAxisX->Value, (Int32)nmrAxisY->Value, pctColorMain->BackColor, cmbMethods->SelectedIndex);
	}
}

//расчёт времени
System::Void Form1::btnCalc_Click(System::Object^  sender, System::EventArgs^  e)
{
}