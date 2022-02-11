#pragma once

#include "paint.h"

namespace Circle
{
	using namespace System::Drawing;

	//выбираем метод для отрисовки
	void SelectMethod(cEasel *easel, int x, int y, int radius, Color maincolor, int method);

	//выбираем метод и отрисовываем спектр отрезков из точки
	void SpectreMethod(cEasel *easel, int x, int y, int delta, int num, int startR, Color maincolor, int method);

}