#pragma once

//#include <vcclr.h>
#include <gcroot.h>

using namespace System;
using namespace System::Drawing;


struct canvasstruct
{
	gcroot<Graphics^> canvas;
	int width;
	int height;
};

//������� �����, ������������ �����
void ClearCanvas(canvasstruct *Easel, Color clearcolor);