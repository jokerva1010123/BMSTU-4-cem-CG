#pragma once

//структура точки
struct sPoint
{
	int x; //координаты
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