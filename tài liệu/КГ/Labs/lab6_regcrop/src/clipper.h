#pragma once

#include "geometry.h"


//отсечение отрезка по прямоугольнику методом средней точки
sLine* ClipMiddle(sLine &line, cRect *rect);