#pragma once

#include "paint.h"
#define _USE_MATH_DEFINES //воимя доступа к M_PI(nkie Pie)

//отрисовываем прямую между двумя точками каким-либо методом
void SelectMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor, int method);

//выбираем метод для измерения времени
double CalcMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor, int method);

//выбираем метод и отрисовываем спектр отрезков из точки
void SpectreMethod(canvasstruct *Easel, int x1, int y1, int angle, int radius, Color maincolor, Color backcolor, int method);