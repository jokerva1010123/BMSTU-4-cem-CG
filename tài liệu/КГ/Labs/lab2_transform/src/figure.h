#pragma once

#include <math.h>

//��������� �����
struct sPoint
{
	double x,y;
};

//����� ������ ��������� �� ��������� �����
class cFigure
{
public:
	int size; //���������� �����
	sPoint *points; //���� �����

	//�������� ������ ��� n �����
	cFigure(int n);
	~cFigure();
	cFigure(const cFigure &from) //����������� �����������
	{
		this->size = from.size;
		this->points = new sPoint [size];
		for (int i=0; i<size; i++)
			this->points[i] = from.points[i];
	}

	//������� ������
	void Shift(double dx, double dy);

	//������������ ������
	void Scale(sPoint *c, double sx, double sy);

	//������� ������
	void Rotate(sPoint *c, double ang);


	//����� ����� ������������ ����������
	void InitializeCircle(double a, double b, double r);

	//����� ����� ������������ ��������
	void InitializeParabola(double c, double d);
};

