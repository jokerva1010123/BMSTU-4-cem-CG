#pragma once

#include "paint.h"

namespace Ellipse
{
	using namespace System::Drawing;

	//выбираем метод для отрисовки
	void SelectMethod(cEasel *easel, int x, int y, int A, int B, Color maincolor, int method);

	//выбираем метод и отрисовываем спектр отрезков из точки
	void SpectreMethod(cEasel *easel, int x, int y, int delta, int num, int startA, int startB, Color maincolor, int method);

}