//
//		Рисовач на формочке
//

#include <stdafx.h>

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
	/*int r = ((Color) backcolor).R - 30;
	int g = ((Color) backcolor).G - 30;
	int b = ((Color) backcolor).B - 30;
	if (r<0) r=0; if (g<0) g=0; if (b<0) b=0;
	Pen^ drawpen = gcnew Pen(System::Drawing::Color::FromArgb(r,g,b), 1);
	canvas->DrawLine(drawpen, width/2, 0, width/2, height);
	canvas->DrawLine(drawpen, 0, height/2, width, height/2);
	delete drawpen;*/
}

//рисует прямую между координатами
void cEasel::DrawLine(double fromx, double fromy, double tox, double toy, Color clr, float w)
{
	Pen^ drawpen = gcnew Pen(clr,w);
	/*int x1 = (int) (fromx + width/2  +0.5);
	int y1 = (int) (height/2 - fromy  +0.5);
	int x2 = (int) (tox + width/2  +0.5);
	int y2 = (int) (height/2 - toy  +0.5);
	canvas->DrawLine(drawpen, x1, y1, x2, y2);*/
	canvas->DrawLine(drawpen, fromx, fromy, tox, toy);
	delete drawpen;
}

//рисует прямую между точками
void cEasel::DrawLine(sPoint &pt1, sPoint &pt2, Color clr, float w)
{
	DrawLine(pt1.x, pt1.y, pt2.x, pt2.y, clr,w);
}



//рисует фигуры
void cEasel::DrawCircle(cFigure *fig, Color clr)
{
	for (int i=0; i < fig->size-1; i++)
	{
		DrawLine(fig->points[i], fig->points[i+1], clr);
	}
	DrawLine(fig->points[0], fig->points[fig->size-1], clr);
}
void cEasel::DrawParabola(cFigure *fig, Color clr)
{
	for (int i=0; i < fig->size-1; i++)
	{
		DrawLine(fig->points[i], fig->points[i+1], clr);
	}
}
void cEasel::DrawPoint(sPoint *point, Color clr)
{
	int cx = (int) (point->x + width/2 +0.5);
	int cy = (int) (-point->y + height/2 +0.5);
	Pen^ drawpen = gcnew Pen(Color::Black, 1); //чёрная обводка
	SolidBrush^ drawbrush = gcnew SolidBrush(clr); //цветная заливка
	Rectangle rect = Rectangle(cx-POINTRADIUS, cy-POINTRADIUS, POINTRADIUS*2, POINTRADIUS*2); //прямоугольнки заливки

	canvas->FillEllipse(drawbrush,rect);
	canvas->DrawEllipse(drawpen,rect);

	delete rect;
	delete drawbrush;
	delete drawpen;
}