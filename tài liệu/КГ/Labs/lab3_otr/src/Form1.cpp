//
//		кнопочна€ реализаци€
//
#include "stdafx.h"

#include "Form1.h"
#include "paint.h"
#include "alg_call.h"

using namespace src;

//инициализаци€
System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	Easel = new canvasstruct;
	Easel->canvas = pictureBox1->CreateGraphics(); //инициализируем холст на пикчурбоксе
	Easel->width = pictureBox1->Width;
	Easel->height = pictureBox1->Height;
	ClearCanvas(Easel,Color::AliceBlue);
	cmbMethods->SelectedIndex = 0;
	nmrX1->Maximum = Easel->width/2;
	nmrX1->Minimum = -Easel->width/2;
	nmrY1->Maximum = Easel->height/2;
	nmrY1->Minimum = -Easel->height/2;
	nmrX2->Maximum = nmrX1->Maximum;
	nmrX2->Minimum = nmrX1->Minimum;
	nmrY2->Maximum = nmrY1->Maximum;
	nmrY2->Minimum = nmrY1->Minimum;
}

//выбор цвета

//ручка
System::Void Form1::pctColorMain_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (colorDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		return;
	pctColorMain->BackColor = colorDialog1->Color;
}
//фон
System::Void Form1::pctColorBack_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (colorDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		return;
	pctColorBack->BackColor = colorDialog1->Color;
	//если отрисовываем фоном - то помен€ем перо тоже
	if (!pctColorMain->Enabled)
		pctColorMain->BackColor = colorDialog1->Color;
}

//использовать цвет фона
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

//кнопки

//принудительна€ очистка
System::Void Form1::btnClear_Click(System::Object^  sender, System::EventArgs^  e)
{
	ClearCanvas(Easel, pctColorBack->BackColor);
}

//отрезок из точки ј в точку Ѕ
System::Void Form1::btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
{
	SelectMethod(Easel,
		Convert::ToInt32(nmrX1->Value), Convert::ToInt32(nmrY1->Value),
		Convert::ToInt32(nmrX2->Value), Convert::ToInt32(nmrY2->Value),
		pctColorMain->BackColor,pctColorBack->BackColor, cmbMethods->SelectedIndex);
}

//спектр отрезков вокруг точки ј
System::Void Form1::btnSpectre_Click(System::Object^  sender, System::EventArgs^  e)
{
	//выбираем метод и отрисовываем спектр отрезков из точки
	SpectreMethod(Easel,
		Convert::ToInt32(nmrX1->Value), Convert::ToInt32(nmrY1->Value),
		Convert::ToInt32(nmrSpectreStep->Value), Convert::ToInt32(nmrRadius->Value),
		pctColorMain->BackColor,pctColorBack->BackColor, cmbMethods->SelectedIndex);
}

//измерение скорости алгоритма
System::Void Form1::btnCalc_Click(System::Object^  sender, System::EventArgs^  e)
{
	double timepass = CalcMethod(Easel,
		Convert::ToInt32(nmrX1->Value), Convert::ToInt32(nmrY1->Value),
		Convert::ToInt32(nmrX2->Value), Convert::ToInt32(nmrY2->Value),
		pctColorMain->BackColor,pctColorBack->BackColor, cmbMethods->SelectedIndex);
	MessageBox::Show(String::Format("ћетод #{0} зан€л ~{1:0.000000} секунд", cmbMethods->SelectedIndex, timepass));
}


//выбор точек щелчком мыши
System::Void Form1::pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int x = e->X - pictureBox1->Width/2;
	int y = -e->Y + pictureBox1->Height/2;
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		nmrX1->Text = String::Format("{0}", x);
		nmrY1->Text = String::Format("{0}", y);
	}
	if (e->Button == System::Windows::Forms::MouseButtons::Right)
	{
		nmrX2->Text = String::Format("{0}",x);
		nmrY2->Text = String::Format("{0}",y);
	}
}