#pragma once

using namespace System;
#define PI 3.141592

//�����
struct realpoint
{
	double x,y;
};
//������ � ������
struct vector
{
	double x,y;
	double len;
};

//���������� ���������� ����� ����� �������
double Distance(realpoint *A, realpoint *B);

//���������� ������ �� ���� �����, ������ �������� ����� �����
vector* FormVector(realpoint *A, realpoint *B);

//���������� ����� �� ���� ���������� �������
realpoint *FormPoint(String^ strx, String^ stry);

//���������� ���� ����� ����� ��������� � ��������
double VectorsAngle (vector *V1, vector *v2);