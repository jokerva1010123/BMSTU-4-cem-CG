#include <stdafx.h>

#include "paint.h"
#include "listworks.h"
#include "pointworks.h"

using namespace System::Windows::Forms;


#define POINTRADIUS 2	//радиус точки при отрисовке
#define OTSTUP 20		//отступ от краёв холста



canvaspoint* ScalePointToCanvas(realpoint *pt, canvasstruct *easel, bordersstruct *borders)
{
	double scale = 1.0;
	double scaleX, scaleY; //из двух масштабов выберем наименьший
	double MidX = (borders->Right + borders->Left)/2; //середина прямоугольника
	double MidY = (borders->Up + borders->Down)/2;
	double RealHeight = borders->Up - borders->Down; //действительные размеры, по сравнению с размерами холста
	double RealWidth = borders->Right - borders->Left;

	//выбираем наименьший масштаб
	scaleX = (easel->width-OTSTUP*2)/RealWidth;
	scaleY = (easel->height-OTSTUP*2)/RealHeight;
	if ((borders->Up != borders->Down) || (borders->Left != borders->Right))
		scale = MIN(scaleX, scaleY);

	canvaspoint *PointInCanvas = new canvaspoint;
	realpoint *PointInWorld = new realpoint;

	//смещаем точку на координату середины граничного прямоугольника
	PointInWorld->x = pt->x - MidX;
	PointInWorld->y = pt->y - MidY;

	//масштабируем её относительно центра
	PointInWorld->x *= scale;
	PointInWorld->y *= scale;

	//получаем середину холста
	PointInCanvas->x = easel->width/2;
	PointInCanvas->y = easel->height/2;

	//отрисовываем точку относительно неё
	PointInCanvas->x += (int) PointInWorld->x;
	PointInCanvas->y -= (int) PointInWorld->y;

	delete PointInWorld;
	return PointInCanvas;
}


//возвращает граничный прямоугольник точек списка
bordersstruct* GetBorders(pointlist *list)
{
	if (!list)
		return nullptr;

	pointlist *ptr = list; //указатель, которым будем пробегаться по списку
	bordersstruct* borders = new bordersstruct;
	double Left = ptr->point->x;
	double Right = ptr->point->x;
	double Up = ptr->point->y;
	double Down = ptr->point->y;

	//определяем прямоугольник граничных координат, в которых лежат точки списка
	while (ptr)
	{
		if (ptr->point->x < Left)
			Left = ptr->point->x;
		if (ptr->point->x > Right)
			Right = ptr->point->x;
		if (ptr->point->y < Down)
			Down = ptr->point->y;
		if (ptr->point->y > Up)
			Up = ptr->point->y;
		ptr = ptr->next;
	}

	borders->Left = Left;
	borders->Right = Right;
	borders->Up = Up;
	borders->Down = Down;
	return borders;
}
//возвращает "общий" граничный прямоугольник из двух
bordersstruct* SumBorders(bordersstruct* borders1, bordersstruct* borders2)
{
	bordersstruct *summary;
	if (borders1) //определяем границы, исходя из "доступности" списков
		summary = borders1;
	if (borders2)
		summary = borders2;
	if (borders1 && borders2)
	{
		summary = new bordersstruct;
		summary->Left = MIN(borders1->Left, borders2->Left);
		summary->Down = MIN(borders1->Down, borders2->Down);
		summary->Up = MAX(borders1->Up, borders2->Up);
		summary->Right = MAX(borders1->Right, borders2->Right);
	}
	return summary;
}


//рисует точку на холсте
void DrawPoint(Graphics^ canvas, canvaspoint *point, Drawing::Color drawcolor)
{	
	//MessageBox::Show(String::Format("{0}, {1}",point->x, point->y));
	Pen^ drawpen = gcnew Pen(Color::Black, 1); //чёрная обводка
	SolidBrush^ drawbrush = gcnew SolidBrush(drawcolor); //цветная заливка
	Rectangle rect = Rectangle(point->x-POINTRADIUS, point->y-POINTRADIUS, POINTRADIUS*2, POINTRADIUS*2); //прямоугольнки заливки
	canvas->FillEllipse(drawbrush,rect);
	canvas->DrawEllipse(drawpen,rect);

	delete rect;
	delete drawbrush;
	delete drawpen;
}

//отрисовываем на мольберте с заданным размером точки из списка
void DrawPointsList(canvasstruct *easel, pointlist *list, bordersstruct* borders, Color drawcolor)
{
	if (!list) //если чего-то не хватает, то ничего и не рисуем
		return;

	
	//проходимся по списку и отрисовываем все точки
	canvaspoint *PointInCanvas;
	pointlist *ptr = list;
	while (ptr)
	{
		PointInCanvas = ScalePointToCanvas(ptr->point, easel, borders);
		DrawPoint(easel->canvas,PointInCanvas,drawcolor);
		// Create string to draw.
		String^ drawString = String::Format("{0}",ptr->id);
		// Create font and brush.
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",10 );
		SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
		// Draw string to screen.
		easel->canvas->DrawString( drawString, drawFont, drawBrush, (float) PointInCanvas->x, (float) PointInCanvas->y );
		ptr = ptr->next;
		delete PointInCanvas;
		delete drawString, drawFont, drawBrush;
	}
}

//отрисовывает два списка точек на одном мольберте
void DrawTwoLists(canvasstruct *easel, pointlist *list1, pointlist *list2, Color list1color, Color list2color)
{
	easel->canvas->Clear(Color::AliceBlue); //смываем нарисованное

	if (!list1 && !list2)
		return;

	bordersstruct *borders1, *borders2, *borders; //граничные прямоугольники
	borders1 = GetBorders(list1);
	borders2 = GetBorders(list2);
	borders = SumBorders(borders1, borders2);

	//отрисовываем списки если нужно
	if (list1)
		DrawPointsList(easel, list1, borders, Color::Green);
	if (list2)
		DrawPointsList(easel, list2, borders, Color::Red);

	delete borders, borders1, borders2;
}



//рисует линию на холсте
void DrawLine(Graphics^ canvas, canvaspoint *A, canvaspoint *B, Drawing::Color drawcolor, int width=2)
{	
	Pen^ drawpen = gcnew Pen(drawcolor, (float) width);
	canvas->DrawLine(drawpen,A->x, A->y, B->x, B->y);
	delete drawpen;
}

//рисует треугольник на холсте
void DrawTriangle(canvasstruct *easel, triangle *T, bordersstruct *borders, Drawing::Color drawcolor)
{	
	Pen^ drawpen = gcnew Pen(drawcolor, 2);
	canvaspoint *drA = ScalePointToCanvas(T->A, easel, borders);
	canvaspoint *drB = ScalePointToCanvas(T->B, easel, borders);
	canvaspoint *drC = ScalePointToCanvas(T->C, easel, borders);
	DrawLine(easel->canvas, drA, drB, drawcolor);
	DrawLine(easel->canvas, drA, drC, drawcolor);
	DrawLine(easel->canvas, drC, drB, drawcolor);
	delete drawpen;
}


//отрисовывает результат вычислений
void DrawResult(canvasstruct *easel, resultstruct *res)
{
	//драу ту листс не использую, чтобы по два раза не считать одни и теже границы
	//столяренка, вот только попробуй что-нибудь вякнуть про мою дезоптимизацию ъ
	bordersstruct *borders1, *borders2, *borders; //граничные прямоугольники
	borders1 = GetBorders(res->list1);
	borders2 = GetBorders(res->list2);
	borders = SumBorders(borders1, borders2);

	easel->canvas->Clear(Color::AliceBlue); //смываем уже нарисованное


	realpoint *trA,*trB,*trC,	*tr1Bis,*tr2Bis; //указатели на точки треугла, биссектрис
	canvaspoint *Bis1,*Bis2; //"холстовые" точки биссектрис
	canvaspoint *V; //вершина, из которой отрисовывать линию биссектрисы

	//отрисовываем первый треугл
	trA = res->list1->point;
	trB = res->list1->next->point;
	trC = res->list1->next->next->point;
	triangle *T = FormTriangle(trA, trB, trC);
	tr1Bis = BissCross(T);
	DrawTriangle(easel,T,borders,Color::Green);
	//отрисовываем его биссектрисы
	Bis1 = ScalePointToCanvas(tr1Bis,easel,borders);
	V = ScalePointToCanvas(trA,easel,borders);
	DrawLine(easel->canvas, V,Bis1, Color::Black,1);
	delete V;
	V = ScalePointToCanvas(trB,easel,borders);
	DrawLine(easel->canvas, V,Bis1, Color::Black,1);
	delete V;
	V = ScalePointToCanvas(trC,easel,borders);
	DrawLine(easel->canvas, V,Bis1, Color::Black,1);
	delete V;
	//отрисовываем точки поверх треугла
	DrawPointsList(easel, res->list1, borders, Color::DarkGreen);
	delete T;

	//отрисовываем второй треугл
	trA = res->list2->point;
	trB = res->list2->next->point;
	trC = res->list2->next->next->point;
	T = FormTriangle(trA, trB, trC);
	tr2Bis = BissCross(T);
	DrawTriangle(easel, T, borders, Color::Red);
	//отрисовываем его биссектрисы
	Bis2 = ScalePointToCanvas(tr2Bis,easel,borders);
	V = ScalePointToCanvas(trA,easel,borders);
	DrawLine(easel->canvas, V,Bis2, Color::Black,1);
	delete V;
	V = ScalePointToCanvas(trB,easel,borders);
	DrawLine(easel->canvas, V,Bis2, Color::Black,1);
	delete V;
	V = ScalePointToCanvas(trC,easel,borders);
	DrawLine(easel->canvas, V,Bis2, Color::Black,1);
	delete V;
	//отрисовываем точки поверх треугла
	DrawPointsList(easel, res->list2, borders, Color::DarkRed);
	delete T;


	//отрисовываем ось Y
	canvaspoint *Y1 = new canvaspoint;
	canvaspoint *Y2 = new canvaspoint;
	Y1->x = Y2->x = (Bis1->x + Bis2->x) / 2;
	Y1->y = 0; Y2->y = easel->height;
	DrawLine(easel->canvas, Y1,Y2, Color::CornflowerBlue);
	delete Y1, Y2;

	//отрисовываем сами биссектрисы

	//отрисовываем прямую через биссектрисы
	DrawLine(easel->canvas, Bis1, Bis2, Color::Blue);
	DrawPoint(easel->canvas, Bis1, Color::DarkBlue);
	DrawPoint(easel->canvas, Bis2, Color::DarkBlue);



	delete borders1, borders2;
	delete tr1Bis, tr2Bis,	Bis1, Bis2;
}