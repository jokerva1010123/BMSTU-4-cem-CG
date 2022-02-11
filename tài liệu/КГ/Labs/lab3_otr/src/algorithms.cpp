//
//		Непосредственно алгоритмистика - ЦДА и Брезенхем
//
#include "stdafx.h"

#include "algorithms.h"
#include "paint.h"
//#include <time.h>

//отрисовка стандартным методом
void DrawDefault(Graphics^ canvas, int x1, int y1, int x2, int y2, Color drawcolor)
{
	Pen^ drawpen = gcnew Pen(drawcolor,1);

	canvas->DrawLine(drawpen,x1,y1,x2,y2);

	delete drawpen;
}

//отрисовка ЦДА
void DrawCDA(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor)
{
	/*
	Начало
	Ввод хн, ун, хк, ук
	Проверка отрезка на вырожденность: если вырожденный то высветить точку и переход на конец
	x_тек=x_н,   y_тек=y_к
	dx=x_k-x_n,dy=y_k-y_n
	Если |dx|>|dy|, то l=|dx| иначе l=|dy|
	dx=dx/l,dy=dy/l
	Построение отрезка (цикл по i=1 до l+1)
		Высвечивание точки E(xt),E(yt)
		Вычисление координат следующей точки x_текущая=x_тек+dx,y_тек=y_тек+dy
	Конец
	*/

	//если отрезок вырожденный, то отрисовываем только одну точку
	if (x2 == x1 && y2 == y1)
	{
		//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		double xt=(double)x1, yt=(double)y1; //текущие координаты
		double dx=x2-x1, dy=y2-y1; //приращение координат
		int l=MAX(ABS(dx), ABS(dy)); //количество "итераций"
		dx /= l; dy /= l;
		for (int i=1; i<=l+1; i++)
		{
			//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
				bm->SetPixel((int)(xt+0.5), (int)(yt+0.5), drawcolor);
			xt += dx; yt += dy;
		}
	}

}

//отрисовка Брезенхемом
void DrawBrezenhem(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor)
{
	/*
	Начало
	Ввод хн, ун, хк, ук
	Проверка отрезка на вырожденность: если вырожденный то высветить точку хн,ун и переход на конец
	x_тек=x_н,   y_тек=y_к
	dx=x_k-x_n,dy=y_k-y_n
	Sx=sign(dx), sy=sign(dy)
	Dx=|dx|, dy=|dy|
	Если dx>dy то обмен=0, иначе обмен=1 {t=dy; dy=dx; dx=t}
	m=dy/dx. //тангенс угла наклона
	Цикл построения отрезка (по i=1 to dx+1)
		Высвечивание точки (xt,yt)
		Если (e>=0) {
			если (обмен=0) {yt=yt+sy}
			иначе {xt=xt+sx};
			e=e-1
		}
		иначе {
			если (обмен=0) {xt=xt+sx}
			иначе {уt=уt+sy};
			e=e+m
		}
	Конец
	*/

	//если отрезок вырожденный, то отрисовываем только одну точку
	if (x2 == x1 && y2 == y1)
	{
		//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		int dx=x2-x1, dy=y2-y1; //приращение координат
		int sx = SIGN(dx), sy = SIGN(dy); //шаг по X и по Y
		dx = ABS(dx); dy = ABS(dy); //абсолютируем приращения
		//System::Windows::Forms::MessageBox::Show(String::Format("{0}",sx));
		double m = (double)dy/dx; //тангенс угла наклона //(дабл) ОБЯЗАТЕЛЕН!! иначе он расценит (инт)ду/(инт)дх =0 при ду<дх!!

		bool swap; //флаг обмена
		if (m <= 1)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
			m = 1/m;
		}

		double e = m-0.5; //ошибка
		int xt=x1, yt=y1; //текущие координаты

		//в цикле анализируем ошибку
		for (int i=1; i<=dx+1; i++)
		{
			//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
				bm->SetPixel(xt,yt,drawcolor);

			if (e>=0)
			{
				if (swap)
					xt += sx;
				else
				{
					yt += sy;
				}
				e = e-1;
			}
			if (e<0)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
			}
			e = e+m;
			
		}
	}
}

//отрисовка целым Брезенхемом
void DrawBrezenhemInt(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor)
{
	//если отрезок вырожденный, то отрисовываем только одну точку
	if (x2 == x1 && y2 == y1)
	{
		//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		int dx=x2-x1, dy=y2-y1; //приращение координат
		int sx = SIGN(dx), sy = SIGN(dy); //шаг по X и по Y
		dx = ABS(dx); dy = ABS(dy); //абсолютируем приращения
		
		bool swap; //флаг обмена
		if (dy <= dx)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
		}

		int _E = 2*dy - dx; //ошибка
		int xt=x1, yt=y1; //текущие координаты

		//в цикле анализируем ошибку
		for (int i=1; i<=dx+1; i++)
		{
			//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
			{
				bm->SetPixel(xt,yt,drawcolor);
			}
			
			if (_E>=0)
			{
				if (swap)
					xt += sx;
				else
				{
					yt += sy;
				}
				_E = _E - 2*dx;
			}
			if (_E<0)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
			}
			_E = _E + 2*dy;			
		}
	}
}

//отрисовка Брезенхемом со сглаживанием
void DrawBrezenhemSoft(Bitmap^ bm, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor)
{
	/*
	1.Ввод исходных данных Xн,Yн,Xк,Yк (координаты концов отрезка), I - количество уровней интенсивности.
	2.проверка вырожденности отрезка. Если отрезок вырожден, то высвечивание отдельного пиксела и переход к п.13.
	3.Вычисление приращений dX=Xк-Xн и dY=Yк-Yн.
	4.Вычисление шага изменения каждой координаты: SX=sign(dX),  SY=sign(dY).
	5.Вычисление модулей приращения координат: dX=!dX!,    dY=!dY!.
	6.Вычисление модуля тангенса угла наклона m=dY/dX.
	7.Анализ вычисленного значения m и обмен местами dX и dY при m>1:
	если m>1, то выполнить
		p=dX;	dX=dY;   dY=p; m=1/m; fl=1;
	если m<1, то
		fl=0.
	8.Инициализация начального значения ошибки f=I/2.
	9.Инициализация начальных значений координат текущего пиксела:
	X=Xн,   Y=Yн.
	10.Вычисление скорректированного значения тангенса угла наклона m=mI и коэффициента W=I-m.
	11.Высвечивание пиксела	с координатами (X,Y) интенсивностью E(f).
	12.Цикл от i=1 до i=dX с шагом 1:
		Если f<W, то
			если fl=0, то
				X=X+SX;
			если fl=1, то
				Y=Y+SY;
		f=f+m.
		Если f>W, то X=X+SX, Y=Y+SY, f=f-W.
		Высвечивание пиксела с координатами (X,Y) интенсивностью E(f).
	13.Конец.

	*/
	if (x2 == x1 && y2 == y1)
	{
		//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,maincolor);
	}
	else
	{
		int dx=x2-x1, dy=y2-y1; //приращение координат
		int sx = SIGN(dx), sy = SIGN(dy); //шаг по X и по Y
		dx = ABS(dx); dy = ABS(dy); //абсолютируем приращения
		//System::Windows::Forms::MessageBox::Show(String::Format("{0}",sx));
		double m = (double)dy/dx; //тангенс угла наклона
		bool swap; //флаг обмена
		if (m <= 1)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
			m = 1/m;
		}
#define I 256 //количество уровней интенсивности
		double e = I/2; //ошибка
		int xt=x1, yt=y1; //текущие координаты
		m *= I; //корректируем тангенс
		double W = I - m; //коэффициент

		//в цикле анализируем ошибку
		for (int i=1; i<=dx; i++)
		{
			int r,g,b; //ргб-составляющие цвета для закраски
			double C = e/I;
			//if (C>0.5) C = 0.5; //корректируем "прозрачность", чтобы перекрашиваться не в абсолютный ноль, а просто в бледный цвет
			r = maincolor.R + C*(backcolor.R - maincolor.R);
			g = maincolor.G + C*(backcolor.G - maincolor.G);
			b = maincolor.B + C*(backcolor.B - maincolor.B);
			Color drawcolor = Color::FromArgb(255,r,g,b);
			//обрабатываем ТОЛЬКО пиксели внутри массива битмапа
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
			{
				bm->SetPixel(xt,yt,drawcolor);
			}

			if (e <= W)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
				e = e+m;
			}
			else
			{
				xt += sx;
				yt += sy;
				e = e-W;
			}
		}
	}
}