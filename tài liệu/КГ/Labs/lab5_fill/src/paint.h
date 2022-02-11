#pragma once

#include "polygonworks.h"

#include <gcroot.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


typedef gcroot<Graphics^> tCanvas;
typedef gcroot<Color> tColor;
#define POINTRADIUS 3


//����� ������ � ����� ��� � ��� �������
class cEasel
{
public:
	int width; //������� ������
	int height;
	tCanvas canvas; //�����
	tColor backcolor;	//���� ����
	tColor maincolor;	//���� �����
	tColor fillcolor;	//���� �������

	//�������������� ����� �� �����������
	cEasel(PictureBox^ pb);
	~cEasel();

	//������� �����
	void Clear();

	//������ ������ ����� ������������
	void DrawLine(int fromx, int fromy, int tox, int toy, Color clr, float w=1.0);
	void DrawLine(sPoint *from, sPoint *to, Color clr, float w=1.0);

	//������ �����
	void DrawPoint(int cx, int cy, Color clr)
	{
		SolidBrush^ drawbrush = gcnew SolidBrush(clr); //������� �������
		Pen^ drawpen = gcnew Pen(Color::Black);
		Drawing::Rectangle rect(cx-POINTRADIUS, cy-POINTRADIUS, POINTRADIUS*2, POINTRADIUS*2); //������������� �������

		canvas->FillEllipse(drawbrush,rect);
		canvas->DrawEllipse(drawpen,rect);
		//DrawCircle(cx,cy, Color::Black, POINTRADIUS-1, 1);

		delete drawbrush, drawpen;
	}
	void DrawPoint(sPoint *pt, Color clr)
	{
		DrawPoint(pt->x, pt->y, clr);
	}
};