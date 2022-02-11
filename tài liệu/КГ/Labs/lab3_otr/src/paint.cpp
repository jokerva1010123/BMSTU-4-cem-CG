//
//		Рисовач на формочке
//
#include <stdafx.h>

#include "paint.h"

using namespace System::Windows::Forms;


//очищает холст, отрисовывает сетку
void ClearCanvas(canvasstruct *Easel, Color clearcolor)
{
	Easel->canvas->Clear(clearcolor);
	Pen^ drawpen = gcnew Pen(Color::Aquamarine, 1);
	Easel->canvas->DrawLine(drawpen, Easel->width/2, 0, Easel->width/2, Easel->height);
	Easel->canvas->DrawLine(drawpen, 0, Easel->height/2, Easel->width, Easel->height/2);
	delete drawpen;
}
