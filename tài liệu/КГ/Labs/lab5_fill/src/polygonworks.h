#pragma once

//��������� �����
struct sPoint
{
	int x; //����������
	int y;
	sPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

struct sPolygon
{
	sPoint *points;
	int *con;
	int num;
};