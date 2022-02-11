#pragma once

#include "listworks.h"
#include "triangleworks.h"
//#include <vcclr.h>
#include <gcroot.h>

using namespace System;
using namespace System::Drawing;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

struct canvaspoint
{
	int x;
	int y;
};

struct canvasstruct
{
	gcroot<Graphics^> canvas;
	int width;
	int height;
};

struct bordersstruct
{
	double	Left,
			Right,
			Down,
			Up;
};

//������ ����� � ������������ �����
//void DrawPoint(Graphics^ canvas, canvaspoint *point, Drawing::Color pcolor);

//������������ �� ��������� ��� ����� �� ������, � ������ ��������
//����� 0.0;0.0 ����� ���������� � ������
void DrawPointsList(canvasstruct *easel, pointlist *list, bordersstruct* borders, Color drawcolor);

//���������� ��������� ������������� ����� ������
bordersstruct* GetBorders(pointlist *list);

//������������ ��� ������ ����� �� ����� ���������
void DrawTwoLists(canvasstruct *easel, pointlist *list1, pointlist *list2, Color list1color, Color list2color);

//������������ ��������� ����������
void DrawResult(canvasstruct *easel, resultstruct *res);