//
//		Алгоритмы отрисовки окружности
//

#include "stdafx.h"

#include "circle.h"
#include <math.h>

namespace Circle
{
	//			АЛГОРИТМЫ ОТРИСОВКИ

	//отрисовка стандартным методом
	void DrawDefault(Graphics ^canvas, int cx, int cy, int radius, Color drawcolor)
	{
		Pen^ drawpen = gcnew Pen(drawcolor, 1); //чёрная обводка
		Rectangle rect = Rectangle(cx-radius, cy-radius, radius*2, radius*2); //контурный прямоугольник

		canvas->DrawEllipse(drawpen,rect);

		delete rect;
		delete drawpen;
	}

	//отрисовка средней точкой
	void DrawMid(Bitmap^ bm, int cx, int cy, int radius, Color drawcolor)
	{
		DEBUGPRINT("кружок, средний");
	}
	
	//отрисовка параметрическим уравнением
	void DrawParam(Bitmap^ bm, int cx, int cy, int radius, Color drawcolor)
	{
		const int L = (int) (M_PI*radius/2 +0.5); //длина четверти окружности
		int x,y;
		for (int t = 0; t <= L; t ++)
		{
			x = (int) (radius*cos(t/(double)radius) + 0.5);
			y = (int) (radius*sin(t/(double)radius) + 0.5);
			//отрисовываем четыре симметричных пикселя
			SetPixel(bm, cx+x, cy+y, drawcolor);
			SetPixel(bm, cx+x, cy-y, drawcolor);
			SetPixel(bm, cx-x, cy+y, drawcolor);
			SetPixel(bm, cx-x, cy-y, drawcolor);
		}
	}

	//отрисовка каноническим уравнением
	void DrawCanon(Bitmap^ bm, int cx, int cy, int radius, Color drawcolor)
	{
		for (int x = 0; x <= radius; x++)
		{
			int y = (int) (sqrt((double)radius*radius - x*x) + 0.5);
			//отрисовываем четыре симметричных пикселя
			SetPixel(bm, cx+x, cy+y, drawcolor);
			SetPixel(bm, cx+x, cy-y, drawcolor);
			SetPixel(bm, cx-x, cy+y, drawcolor);
			SetPixel(bm, cx-x, cy-y, drawcolor);
		}
	}

	//отрисовка брезенхемом
	void DrawBrezenhem(Bitmap^ bm, int cx, int cy, int radius, Color drawcolor)
	{
		int x=0, y=radius; //начальный пиксель
		int d = 2 - 2*radius; //значение D(x,y)  при (0,R)
		int b = 0;
		//D(x,y) = (x+1)^2 + (y-1)^2 - R^2, "ошибка"

		do
		{
			//отрисовываем четыре симметричных пикселя
			SetPixel(bm, cx+x, cy+y, drawcolor);
			SetPixel(bm, cx+x, cy-y, drawcolor);
			SetPixel(bm, cx-x, cy+y, drawcolor);
			SetPixel(bm, cx-x, cy-y, drawcolor);

			if (y <= 0)
				break;

			
			//определяем сдвиг:
			if (d < 0) //пиксель лежит вне окружности
			{
				b = 2*d + 2*y - 1;
				x += 1;

				if (b <= 0)
				{
					d = d + 2*x + 1;
				}
				else
				{
					y -= 1;
					d = d + 2*x - 2*y + 2;
				}
				continue;
			}
			if (d > 0) //пиксель лежит внутри окружности
			{
				b = 2*d - 2*x - 1;
				y -= 1;

				if (b > 0)
				{
					d = d - 2*y + 1;
				}
				else
				{
					x += 1;
					d = d + 2*x - 2*y + 2;
				}
				continue;
			}
			if (d == 0.0) //пиксель лежит на окружности
			{
				x += 1;
				y -= 1;
				d = d + 2*x - 2*y + 2;
			}
		}
		while (true);
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//			ВЫБОР АЛГОРИТМА

	
	//	Простая отрисовка
	void SelectMethod(cEasel *easel, int x, int y, int radius, Color maincolor, int method)
	{
		//переносим начало координат в центр мольберта
		x += easel->width/2;
		y = -y + easel->height/2;

		//нативная отрисовка отдельно - она работает с канвас, а не с битмапом
		if (method == 0)
		{
			DrawDefault(easel->canvas, x,y, radius, maincolor);
			return;
		}

		Bitmap^ bm = gcnew Bitmap(easel->width, easel->height, easel->canvas); //создаем битмап который красить

		switch (method)
		{
		case 1: //средняя точка
			{
				DrawMid(bm, x,y, radius, maincolor);
				break;
			}
		case 2: //каноническое уравнение
			{
				DrawCanon(bm, x,y, radius, maincolor);
				break;
			}
		case 3: //параметрическое уравнение
			{
				DrawParam(bm, x,y, radius, maincolor);
				break;
			}
		case 4: //Брезенхем
			{
				DrawBrezenhem(bm, x,y, radius, maincolor);
				break;
			}
		}
		easel->canvas->DrawImageUnscaled(bm,0,0); //непосредственно отрисовываем само содержимое битмапа, на канвасе, чёртовы матрёшки
		delete bm;
	}


	//	Отрисовка спектра
	void SpectreMethod(cEasel *easel, int x, int y, int delta, int num, int startR, Color maincolor, int method)
	{
		//переносим начало координат в центр мольберта
		x += easel->width/2;
		y = -y + easel->height/2;
		/*int x2=0,y2=0; //координаты конца "луча" спектра

		//нативная отрисовка отдельно - она работает с канвас, а не с битмапом
		if (method == 0)
		{
			for (double i = 0; i<360; i += angle)
			{
				x2 = x1 + radius*cos(i/180*M_PI);
				y2 = y1 - radius*sin(i/180*M_PI);
				DrawDefault(Easel->canvas, x1,y1,x2,y2,maincolor);
			}
			return;
		}

		*/
		Bitmap^ bm = gcnew Bitmap(easel->width, easel->height, easel->canvas); //создаем битмап который красить

		for (int r = from; r <= to; r += delta)
		{
			switch (method)
			{
			case 1: //средняя точка
				{
					DrawMid(bm, x,y, r, maincolor);
					break;
				}
			case 2: //каноническое уравнение
				{
					//DrawBrezenhem(bm,x1,y1,x2,y2,maincolor);
					break;
				}
			case 3: //параметрическое уравнение
				{
					//DrawBrezenhemInt(bm,x1,y1,x2,y2,maincolor);
					break;
				}
			case 4: //Брезенхем
				{
					//Circle::DrawBrezenhemSoft(bm,x1,y1,x2,y2,maincolor,backcolor);
					break;
				}
			}
		}
		easel->canvas->DrawImageUnscaled(bm,0,0); //непосредственно отрисовываем само содержимое битмапа, на канвасе, чёртовы матрёшки
		delete bm;
	}
}