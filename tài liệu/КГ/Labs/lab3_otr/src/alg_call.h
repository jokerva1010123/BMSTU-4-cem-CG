#pragma once

#include "paint.h"
#define _USE_MATH_DEFINES //����� ������� � M_PI(nkie Pie)

//������������ ������ ����� ����� ������� �����-���� �������
void SelectMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor, int method);

//�������� ����� ��� ��������� �������
double CalcMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor, int method);

//�������� ����� � ������������ ������ �������� �� �����
void SpectreMethod(canvasstruct *Easel, int x1, int y1, int angle, int radius, Color maincolor, Color backcolor, int method);