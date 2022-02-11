//
//		Рисовач на формочке
//

#include <stdafx.h>

#include "paint.h"


//инициализирует холст из пикчурбокса
cEasel::cEasel(PictureBox^ pb)
{
	canvas = pb->CreateGraphics();
	width = pb->Width;
	height = pb->Height;
	backcolor = pb->BackColor;
	Clear();
}
cEasel::~cEasel()
{
	delete canvas;
}

//очищает холст, отрисовывает сетку
void cEasel::Clear()
{
	canvas->Clear(backcolor);
}

//рисует прямую между координатами
void cEasel::DrawLine(int fromx, int fromy, int tox, int toy, Color clr, float w)
{
	/*
	fromx += width/2;
	fromy = -fromy + height/2;
	tox += width/2;
	toy = -toy + height/2;
	*/
	Pen^ drawpen = gcnew Pen(clr,w);
	canvas->DrawLine(drawpen, fromx, fromy, tox, toy);
	delete drawpen;
}
void cEasel::DrawLine(sPoint *from, sPoint *to, Color clr, float w)
{
	DrawLine(from->x, from->y, to->x, to->y, clr, w);
}