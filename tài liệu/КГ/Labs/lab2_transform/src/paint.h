#pragma once

#include <gcroot.h>
#include "figure.h"


using namespace System;
using namespace System::Drawing;

#define POINTRADIUS 3 //������ �����-������

//����� ������ � ����� ��� � ��� �������
class cEasel
{
public:
	int width; //������� ������
	int height;
	gcroot<Graphics^> canvas; //�����
	gcroot<Color> backcolor; //��� ����

	//�������������� ����� �� �����������
	cEasel(Windows::Forms::PictureBox^ pb);
	~cEasel();

	//������� �����, ������������ �����
	void Clear();

	//������ ������ ����� ������������
	void DrawLine(double fromx, double fromy, double tox, double toy, Color clr, float w=1);

	//������ ������ ����� �������
	void DrawLine(sPoint &pt1, sPoint &pt2, Color clr, float w=1);


	//������ ������
	void DrawCircle(cFigure *fig, Color clr);
	void DrawParabola(cFigure *fig, Color clr);
	void DrawPoint(sPoint *point, Color clr);
};