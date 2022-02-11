#include <stdafx.h>

#include "paint.h"
#include "listworks.h"
#include "pointworks.h"

using namespace System::Windows::Forms;


#define POINTRADIUS 2	//������ ����� ��� ���������
#define OTSTUP 20		//������ �� ���� ������



canvaspoint* ScalePointToCanvas(realpoint *pt, canvasstruct *easel, bordersstruct *borders)
{
	double scale = 1.0;
	double scaleX, scaleY; //�� ���� ��������� ������� ����������
	double MidX = (borders->Right + borders->Left)/2; //�������� ��������������
	double MidY = (borders->Up + borders->Down)/2;
	double RealHeight = borders->Up - borders->Down; //�������������� �������, �� ��������� � ��������� ������
	double RealWidth = borders->Right - borders->Left;

	//�������� ���������� �������
	scaleX = (easel->width-OTSTUP*2)/RealWidth;
	scaleY = (easel->height-OTSTUP*2)/RealHeight;
	if ((borders->Up != borders->Down) || (borders->Left != borders->Right))
		scale = MIN(scaleX, scaleY);

	canvaspoint *PointInCanvas = new canvaspoint;
	realpoint *PointInWorld = new realpoint;

	//������� ����� �� ���������� �������� ���������� ��������������
	PointInWorld->x = pt->x - MidX;
	PointInWorld->y = pt->y - MidY;

	//������������ � ������������ ������
	PointInWorld->x *= scale;
	PointInWorld->y *= scale;

	//�������� �������� ������
	PointInCanvas->x = easel->width/2;
	PointInCanvas->y = easel->height/2;

	//������������ ����� ������������ ��
	PointInCanvas->x += (int) PointInWorld->x;
	PointInCanvas->y -= (int) PointInWorld->y;

	delete PointInWorld;
	return PointInCanvas;
}


//���������� ��������� ������������� ����� ������
bordersstruct* GetBorders(pointlist *list)
{
	if (!list)
		return nullptr;

	pointlist *ptr = list; //���������, ������� ����� ����������� �� ������
	bordersstruct* borders = new bordersstruct;
	double Left = ptr->point->x;
	double Right = ptr->point->x;
	double Up = ptr->point->y;
	double Down = ptr->point->y;

	//���������� ������������� ��������� ���������, � ������� ����� ����� ������
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
//���������� "�����" ��������� ������������� �� ����
bordersstruct* SumBorders(bordersstruct* borders1, bordersstruct* borders2)
{
	bordersstruct *summary;
	if (borders1) //���������� �������, ������ �� "�����������" �������
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


//������ ����� �� ������
void DrawPoint(Graphics^ canvas, canvaspoint *point, Drawing::Color drawcolor)
{	
	//MessageBox::Show(String::Format("{0}, {1}",point->x, point->y));
	Pen^ drawpen = gcnew Pen(Color::Black, 1); //������ �������
	SolidBrush^ drawbrush = gcnew SolidBrush(drawcolor); //������� �������
	Rectangle rect = Rectangle(point->x-POINTRADIUS, point->y-POINTRADIUS, POINTRADIUS*2, POINTRADIUS*2); //������������� �������
	canvas->FillEllipse(drawbrush,rect);
	canvas->DrawEllipse(drawpen,rect);

	delete rect;
	delete drawbrush;
	delete drawpen;
}

//������������ �� ��������� � �������� �������� ����� �� ������
void DrawPointsList(canvasstruct *easel, pointlist *list, bordersstruct* borders, Color drawcolor)
{
	if (!list) //���� ����-�� �� �������, �� ������ � �� ������
		return;

	
	//���������� �� ������ � ������������ ��� �����
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

//������������ ��� ������ ����� �� ����� ���������
void DrawTwoLists(canvasstruct *easel, pointlist *list1, pointlist *list2, Color list1color, Color list2color)
{
	easel->canvas->Clear(Color::AliceBlue); //������� ������������

	if (!list1 && !list2)
		return;

	bordersstruct *borders1, *borders2, *borders; //��������� ��������������
	borders1 = GetBorders(list1);
	borders2 = GetBorders(list2);
	borders = SumBorders(borders1, borders2);

	//������������ ������ ���� �����
	if (list1)
		DrawPointsList(easel, list1, borders, Color::Green);
	if (list2)
		DrawPointsList(easel, list2, borders, Color::Red);

	delete borders, borders1, borders2;
}



//������ ����� �� ������
void DrawLine(Graphics^ canvas, canvaspoint *A, canvaspoint *B, Drawing::Color drawcolor, int width=2)
{	
	Pen^ drawpen = gcnew Pen(drawcolor, (float) width);
	canvas->DrawLine(drawpen,A->x, A->y, B->x, B->y);
	delete drawpen;
}

//������ ����������� �� ������
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


//������������ ��������� ����������
void DrawResult(canvasstruct *easel, resultstruct *res)
{
	//���� �� ����� �� ���������, ����� �� ��� ���� �� ������� ���� � ���� �������
	//����������, ��� ������ �������� ���-������ ������� ��� ��� �������������� �
	bordersstruct *borders1, *borders2, *borders; //��������� ��������������
	borders1 = GetBorders(res->list1);
	borders2 = GetBorders(res->list2);
	borders = SumBorders(borders1, borders2);

	easel->canvas->Clear(Color::AliceBlue); //������� ��� ������������


	realpoint *trA,*trB,*trC,	*tr1Bis,*tr2Bis; //��������� �� ����� �������, ����������
	canvaspoint *Bis1,*Bis2; //"���������" ����� ����������
	canvaspoint *V; //�������, �� ������� ������������ ����� �����������

	//������������ ������ ������
	trA = res->list1->point;
	trB = res->list1->next->point;
	trC = res->list1->next->next->point;
	triangle *T = FormTriangle(trA, trB, trC);
	tr1Bis = BissCross(T);
	DrawTriangle(easel,T,borders,Color::Green);
	//������������ ��� �����������
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
	//������������ ����� ������ �������
	DrawPointsList(easel, res->list1, borders, Color::DarkGreen);
	delete T;

	//������������ ������ ������
	trA = res->list2->point;
	trB = res->list2->next->point;
	trC = res->list2->next->next->point;
	T = FormTriangle(trA, trB, trC);
	tr2Bis = BissCross(T);
	DrawTriangle(easel, T, borders, Color::Red);
	//������������ ��� �����������
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
	//������������ ����� ������ �������
	DrawPointsList(easel, res->list2, borders, Color::DarkRed);
	delete T;


	//������������ ��� Y
	canvaspoint *Y1 = new canvaspoint;
	canvaspoint *Y2 = new canvaspoint;
	Y1->x = Y2->x = (Bis1->x + Bis2->x) / 2;
	Y1->y = 0; Y2->y = easel->height;
	DrawLine(easel->canvas, Y1,Y2, Color::CornflowerBlue);
	delete Y1, Y2;

	//������������ ���� �����������

	//������������ ������ ����� �����������
	DrawLine(easel->canvas, Bis1, Bis2, Color::Blue);
	DrawPoint(easel->canvas, Bis1, Color::DarkBlue);
	DrawPoint(easel->canvas, Bis2, Color::DarkBlue);



	delete borders1, borders2;
	delete tr1Bis, tr2Bis,	Bis1, Bis2;
}