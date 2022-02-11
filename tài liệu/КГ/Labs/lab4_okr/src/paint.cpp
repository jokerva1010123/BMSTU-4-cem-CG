//
//		Рисовач на формочке
//

#include "stdafx.h"

#include "paint.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


//инициализирует холст из пикчурбокса
cEasel::cEasel(Windows::Forms::PictureBox^ pb)
{
	canvas = pb->CreateGraphics();
	backcolor = pb->BackColor;
	width = pb->Width;
	height = pb->Height;
}
cEasel::~cEasel()
{
	delete canvas;
	delete (Color) backcolor;
}

//очищает холст, отрисовывает сетку
void cEasel::Clear()
{
	canvas->Clear(backcolor);
	int r = ((Color) backcolor).R - 30;
	int g = ((Color) backcolor).G - 30;
	int b = ((Color) backcolor).B - 30;
	if (r<0) r=0; if (g<0) g=0; if (b<0) b=0;
	Pen^ drawpen = gcnew Pen(System::Drawing::Color::FromArgb(r,g,b), 1);
	canvas->DrawLine(drawpen, width/2, 0, width/2, height);
	canvas->DrawLine(drawpen, 0, height/2, width, height/2);
	delete drawpen;
}


//красит указанный пиксель
void SetPixel(Bitmap^ bm, int x, int y, Color clr)
{
	//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
	if ((x < bm->Width) && (x >= 0) && (y < bm->Height) && (y >= 0))
		bm->SetPixel(x, y, clr);
}