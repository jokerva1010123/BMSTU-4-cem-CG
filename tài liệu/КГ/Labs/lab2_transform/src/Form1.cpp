//
//		Реализация событий формочки
//

#include "stdafx.h"
#include <stack>

#include "Form1.h"
#include "paint.h"
#include "figure.h"

using namespace src;
using namespace System;



cEasel *easel; //мольберт для рисования
sPoint *pt = nullptr; //центр трансформации
//int precision=0; //количество точек при инициализации


cFigure *cir = nullptr; //окружность
cFigure *par = nullptr; //парабола
std::stack<cFigure> historyCir, historyPar;

//переотрисовка обеих фигур
void redraw()
{
	if (!easel)
		return;

	easel->Clear();

	if (cir)
		easel->DrawCircle(cir, Color::Black);
	if (par)
		easel->DrawParabola(par, Color::Black);
	if (pt)
		easel->DrawPoint(pt, Color::Red);
}

//занесение обеих фигур в стек
void remember()
{
	historyCir.push(*cir);
	historyPar.push(*par);
}

//извлечение обеих фигур из стека
void recall()
{
	if (historyCir.size() <= 1)
	{
		MessageBox::Show("Нет запомненных итераций.");
		return;
	}
	historyCir.pop();
	historyPar.pop();
	delete cir,par;
	cir = new cFigure(historyCir.top());
	par = new cFigure(historyPar.top());


	redraw();
}

System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	easel = new cEasel(pictureBox1);
	easel->Clear();
}

System::Void Form1::btnInit_Click(System::Object^  sender, System::EventArgs^  e) {
	int precisionC = (Int16) (nmrPrecisionCir->Value);
	int precisionP = (Int16) (nmrPrecisionPar->Value);
	delete cir, par;

	cir = new cFigure(precisionC);
	par = new cFigure((precisionP & 1) ? precisionP : precisionP+1);
	double a,b,c,d,r;
	a = Convert::ToDouble(txtA->Text);
	b = Convert::ToDouble(txtB->Text);
	c = Convert::ToDouble(txtC->Text);
	d = Convert::ToDouble(txtD->Text);
	r = Convert::ToDouble(txtR->Text);
	cir->InitializeCircle(a,b,r);
	par->InitializeParabola(c,d);
	
	//очищаем историю итераций
	while (!historyPar.empty()) historyPar.pop();
	while (!historyCir.empty()) historyCir.pop();

	remember();
	redraw();
}
System::Void Form1::btnBack_Click(System::Object^  sender, System::EventArgs^  e)
{
	recall();
}

System::Void Form1::btnShift_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!cir || !par)
	{
		MessageBox::Show("Фигура не инициализирована!");
		return;
	}

	cir->Shift(Convert::ToDouble(txtDx->Text), Convert::ToDouble(txtDy->Text));
	par->Shift(Convert::ToDouble(txtDx->Text), Convert::ToDouble(txtDy->Text));

	remember();
	redraw();
}
System::Void Form1::btnScale_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!cir || !par)
	{
		MessageBox::Show("Фигура не инициализирована!");
		return;
	}
	if (!pt)
	{
		MessageBox::Show("Не задан центр масштабирования!");
		return;
	}

	cir->Scale(pt, Convert::ToDouble(txtSx->Text), Convert::ToDouble(txtSy->Text));
	par->Scale(pt, Convert::ToDouble(txtSx->Text), Convert::ToDouble(txtSy->Text));

	remember();
	redraw();
}
System::Void Form1::btnRotate_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!cir || !par)
	{
		MessageBox::Show("Фигура не инициализирована!");
		return;
	}
	if (!pt)
	{
		MessageBox::Show("Не задан центр поворота!");
		return;
	}

	cir->Rotate(pt, Convert::ToDouble(txtAng->Text));
	par->Rotate(pt, Convert::ToDouble(txtAng->Text));

	remember();
	redraw();
}


System::Void Form1::pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (!pt)
		pt = new sPoint;
	pt->x = (double) e->X - easel->width/2;
	pt->y = - (double) e->Y + easel->height/2;
	txtCx->Text = String::Format("{0:0.0}", (double) e->X - easel->width/2);
	txtCy->Text = String::Format("{0:0.0}", - (double) e->Y + easel->height/2);
	redraw();
}

System::Void Form1::txt_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!pt)
		pt = new sPoint;
	Double::TryParse(txtCx->Text, CONVERT_NUMBER, pt->x);
	Double::TryParse(txtCy->Text, CONVERT_NUMBER, pt->y);
	redraw();
}