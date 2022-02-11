//
//		Действия над фигурами
//

#include "stdafx.h"
#include <math.h>

#include "figure.h"

//выделяет память под n точек
cFigure::cFigure(int n)
{
	size = n;
	points = new sPoint [n];
}
cFigure::~cFigure()
{
	delete points;
}

//смещает фигуру
void cFigure::Shift(double dx, double dy)
{
	for (int i=0; i<size; i++)
	{
		points[i].x += dx;
		points[i].y += dy;
	}
}

//масштабирует фигуру
void cFigure::Scale(sPoint *c, double sx, double sy)
{
	for (int i=0; i<size; i++)
	{
		points[i].x = c->x + sx*(points[i].x - c->x);
		points[i].y = c->y + sy*(points[i].y - c->y);
	}
}

//вращает фигуру
void cFigure::Rotate(sPoint *c, double ang)
{
	const double phi = ang / 180 * M_PI;
	double nx, ny;
	for (int i=0; i<size; i++)
	{
		//КООРДИНАТЫ ВНАЧАЛЕ ВЫЧИСЛЯЮТСЯ, ПОТОМ УСТАНАВЛИВАЮТСЯ!!! ЗАПОМНИ ЭТО УЖЕ НАКОНЕЦ!
		nx = c->x + (points[i].x - c->x) * cos(phi) + (points[i].y - c->y) * sin(phi);
		ny = c->y - (points[i].x - c->x) * sin(phi) + (points[i].y - c->y) * cos(phi);
		points[i].x = nx; points[i].y = ny;
	}
}

//точки будут образовывать окружность
void cFigure::InitializeCircle(double a, double b, double r)
{
	double delta = 2*M_PI / size;

	for (int i = 0; i < size; i++)
	{
		points[i].x = r * cos(i * delta) +a;
		points[i].y = r * sin(i * delta) +b;
	}
}

//точки будут образовывать параболу
void cFigure::InitializeParabola(double c, double d)
{
	double par_length = 100.0;
	double par_height = sqrt(par_length);
	double ypar = d+par_height;
	double delta = 2*par_height/(size-1);
	for (int i = 0; i < size; i++)
	{
		points[i].y = ypar;
		points[i].x = c + (points[i].y-d)*(points[i].y-d);

		ypar -= delta;
	}
	return;
}