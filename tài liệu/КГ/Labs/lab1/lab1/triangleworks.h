#pragma once

#include "pointworks.h"
#include "listworks.h"

//������ ���������� �����, ������ ������ ��������� �� ���
struct triangle
{
	realpoint *A;
	realpoint *B;
	realpoint *C;
	double AB;
	double BC;
	double AC;
};

//��������� � �������
struct resultstruct
{
	pointlist *list1; //����� ������� ������������
	pointlist *list2; //����� ������� ������������
	double angle; //���� ����� ������ ����� ����������� ����������, � ���������
	int code; //��� ������. 0 - �� ������, 1 - ��� ������������ � �1 �����������, 2 - ��� ������������ � �2 �����������
};

//�������� ����������� �� ��� �����
triangle* FormTriangle(realpoint *p1, realpoint *p2, realpoint *p3);

//�������� ���������� ����� ����������� ����������
realpoint* BissCross(triangle *T);

//�� ������� 1 � 2 ������� ��� ������������ �����, ����� ������, ���������� �����
//����� ����������� �� ����������, ������������ ���������� ���� � ���� �������
resultstruct* Solve(pointlist *list1, pointlist *list2);