#pragma once

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

	//�������������� ����� �� �����������
	cEasel(PictureBox^ pb)
	{
		canvas = pb->CreateGraphics();
		width = pb->Width;
		height = pb->Height;
		backcolor = pb->BackColor;
		Clear();
	}
	~cEasel()
	{
		delete canvas;
	}

	//������� �����
	void Clear()
	{
		canvas->Clear(backcolor);
	}

	//������ ������ ����� ������������
	void DrawLine(double fromx, double fromy, double tox, double toy, Color clr, float w=1.0)
	{
		int x1 = (int) (fromx + 0.5);
		int y1 = (int) (fromy + 0.5);
		int x2 = (int) (tox + 0.5);
		int y2 = (int) (toy + 0.5);
		Pen^ drawpen = gcnew Pen(clr,w);
		canvas->DrawLine(drawpen, x1, y1, x2, y2);
		delete drawpen;
	}
	void DrawLine(sPoint *from, sPoint *to, Color clr, float w=1.0)
	{
		DrawLine(from->x, from->y, to->x, to->y, clr, w);
	}
	void DrawLine(sLine *line, Color clr, float w=1.0)
	{
		DrawLine(&line->A, &line->B, clr, w);
	}

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
		int x = (int) (pt->x + 0.5);
		int y = (int) (pt->y + 0.5);
		DrawPoint(x, y, clr);
	}

	//������ �������������
	void DrawRectangle(cRect *r, Color clr)
	{
		Drawing::Rectangle rect(r->left(), r->up(), r->GetWidth(), r->GetHeight());
		Pen^ drawpen = gcnew Pen(clr);
		canvas->DrawRectangle(drawpen, rect);
	}
};