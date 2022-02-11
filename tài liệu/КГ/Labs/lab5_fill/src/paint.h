#pragma once

#include "polygonworks.h"

#include <gcroot.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


typedef gcroot<Graphics^> tCanvas;
typedef gcroot<Color> tColor;
#define POINTRADIUS 3


//класс холста и всего что с ним связано
class cEasel
{
public:
	int width; //размеры холста
	int height;
	tCanvas canvas; //холст
	tColor backcolor;	//цвет фона
	tColor maincolor;	//цвет линий
	tColor fillcolor;	//цвет заливки

	//инициализирует холст из пикчурбокса
	cEasel(PictureBox^ pb);
	~cEasel();

	//очищает холст
	void Clear();

	//рисует прямую между координатами
	void DrawLine(int fromx, int fromy, int tox, int toy, Color clr, float w=1.0);
	void DrawLine(sPoint *from, sPoint *to, Color clr, float w=1.0);

	//рисует точку
	void DrawPoint(int cx, int cy, Color clr)
	{
		SolidBrush^ drawbrush = gcnew SolidBrush(clr); //цветная заливка
		Pen^ drawpen = gcnew Pen(Color::Black);
		Drawing::Rectangle rect(cx-POINTRADIUS, cy-POINTRADIUS, POINTRADIUS*2, POINTRADIUS*2); //прямоугольник заливки

		canvas->FillEllipse(drawbrush,rect);
		canvas->DrawEllipse(drawpen,rect);
		//DrawCircle(cx,cy, Color::Black, POINTRADIUS-1, 1);

		delete drawbrush, drawpen;
	}
	void DrawPoint(sPoint *pt, Color clr)
	{
		DrawPoint(pt->x, pt->y, clr);
	}
};