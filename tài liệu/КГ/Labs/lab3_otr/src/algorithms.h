#pragma once

#include "paint.h"

//
//		��������������� �������������� - ��� � ���������
//
#include "stdafx.h"

#include "paint.h"
//#include <time.h>
//#include <gcroot.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define SIGN(x) ( (x) < 0 ? (-1) : ((x)==0 ? 0 : (1)) )
#define ABS(x) ( (x) < 0 ? (x)*(-1) : (x) )

//��������� ����������� �������
void DrawDefault(Graphics^ canvas, int x1, int y1, int x2, int y2, Color drawcolor);

//��������� ���
void DrawCDA(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor);

//��������� �����������
void DrawBrezenhem(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor);

//��������� ����� �����������
void DrawBrezenhemInt(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor);

//��������� ����������� �� ������������
void DrawBrezenhemSoft(Bitmap^ bm, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor);