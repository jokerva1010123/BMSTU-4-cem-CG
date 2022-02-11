#pragma once

#include <gcroot.h>
#include "figure.h"


using namespace System;
using namespace System::Drawing;

#define POINTRADIUS 3 //радиус точки-центра

//класс холста и всего что с ним связано
class cEasel
{
public:
	int width; //размеры холста
	int height;
	gcroot<Graphics^> canvas; //холст
	gcroot<Color> backcolor; //его цвет

	//инициализирует холст из пикчурбокса
	cEasel(Windows::Forms::PictureBox^ pb);
	~cEasel();

	//очищает холст, отрисовывает сетку
	void Clear();

	//рисует прямую между координатами
	void DrawLine(double fromx, double fromy, double tox, double toy, Color clr, float w=1);

	//рисует прямую между точками
	void DrawLine(sPoint &pt1, sPoint &pt2, Color clr, float w=1);


	//рисует фигуры
	void DrawCircle(cFigure *fig, Color clr);
	void DrawParabola(cFigure *fig, Color clr);
	void DrawPoint(sPoint *point, Color clr);
};