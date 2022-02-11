#pragma once

struct sPoint
{
	double x;
	double y;
	sPoint()
	{
		x = y = 0;
	}
	sPoint(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	sPoint& operator = (const sPoint &orig)
	{
		x = orig.x;
		y = orig.y;
		return *this;
	}
	sPoint friend operator + (const sPoint &A, const sPoint &B)
	{
		sPoint C(A.x + B.x, A.y + B.y);
		return C;
	}
	sPoint friend operator / (const sPoint &A, const double d)
	{
		sPoint C(A.x / d, A.y / d);
		return C;
	}
	sPoint friend operator - (const sPoint &A, sPoint &B)
	{
		sPoint C(A.x - B.x, A.y - B.y);
		return C;
	}
#define EPS 1e-2
	bool friend operator == (const sPoint &A, sPoint &B)
	{
		return (A.x == B.x && A.y == B.y);
	}
	bool friend operator != (const sPoint &A, sPoint &B)
	{
		return (A.x != B.x || A.y != B.y);
	}
#undef EPS
};

struct sLine
{
	//int x1,y1, x2,y2;
	sPoint A, B;
	sLine()
	{
	}
	sLine(double x1, double y1, double x2, double y2) : A(x1,y1), B(x2,y2)
	{
		/*this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;*/
	}
};

//прямоуг для отсекателя
class cRect
{
public:
	cRect()
	{
		l = r = u = d = 0;
	}

	//задать левый верхний угол
	void SetA(int x, int y)
	{
		l = x;
		u = y;
	}
	//задать нижний правый угол
	void SetB(int x, int y)
	{
		if (x < l+1)
			x = l+1;
		if (y < u+1)
			y = u+1;

		r = x;
		d = y;
	}

	//получить размеры
	int GetWidth()
	{
		return r - l;
	}
	int GetHeight()
	{
		return d - u;
	}

	//получить координаты
	int left() {return l;}
	int right() {return r;}
	int down() {return d;}
	int up() {return u;}
private:
	int l, r, u, d;
};