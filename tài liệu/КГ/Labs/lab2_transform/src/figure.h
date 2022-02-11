#pragma once

#include <math.h>

//структура точки
struct sPoint
{
	double x,y;
};

//класс фигуры состоящей из множества точек
class cFigure
{
public:
	int size; //количество точек
	sPoint *points; //сами точки

	//выделяет память под n точек
	cFigure(int n);
	~cFigure();
	cFigure(const cFigure &from) //конструктор копирования
	{
		this->size = from.size;
		this->points = new sPoint [size];
		for (int i=0; i<size; i++)
			this->points[i] = from.points[i];
	}

	//смещает фигуру
	void Shift(double dx, double dy);

	//масштабирует фигуру
	void Scale(sPoint *c, double sx, double sy);

	//вращает фигуру
	void Rotate(sPoint *c, double ang);


	//точки будут образовывать окружность
	void InitializeCircle(double a, double b, double r);

	//точки будут образовывать параболу
	void InitializeParabola(double c, double d);
};

