#pragma once

#include <gcroot.h>


using namespace System;
using namespace System::Drawing;


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

};

//красит указанный пиксель
void SetPixel(Bitmap^ bm, int x, int y, Color clr);