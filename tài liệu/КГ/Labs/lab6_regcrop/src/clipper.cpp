//
//		Обрезание отрезка прямоугольником
//
#include "stdafx.h"

#include "geometry.h"
#include "clipper.h"
#include <math.h>

//возвращает true, если точка видима
bool CheckPoint(sPoint &pt, cRect *r)
{
	if (pt.x < r->left() || pt.x > r->right())
		return false;
	if (pt.y < r->up() || pt.y > r->down())
		return false;
	return true;
}

//возвращает true если отрезок гарантированно невидим
bool IsInvis(sPoint &A, sPoint &B, cRect *r)
{
	if (A.y < r->up()  &&  B.y < r->up()) //выше
		return true;
	if (A.y > r->down()  &&  B.y > r->down()) //ниже
		return true;
	if (A.x < r->left()  &&  B.x < r->left()) //левее
		return true;
	if (A.x > r->right()  &&  B.x > r->right()) //правее
		return true;
	return false;
}

//получение "кода внешности" точки
char PointCode(sPoint &pt, cRect *r)
{
	char code = 0;				//==границе - внутри
	if (pt.y < r->up())			//выше
		code = code | 0x0008;	//	1000
	if (pt.y > r->down())		//ниже
		code = code | 0x0004;	//	0100
	if (pt.x > r->right())		//правее
		code = code | 0x0002;	//	0010
	if (pt.x < r->left())		//левее
		code = code | 0x0001;	//	0001
	return code;
}

inline double sqr(double x)
{
	return x*x;
}
//возвращает расстояние между точками
double Dist(sPoint &A, sPoint &B)
{
	return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

//отсечение отрезка по прямоугольнику методом средней точки
sLine* ClipMiddle(sLine &line, cRect *rect)
{	
//	static double EPS  =  1.0;
#define EPS 0.1
	/*
	1. ввод исходных данных Хл, Хпр, Ун, Ув, Р1, Р2
	2. вычисление кодов концов отрезка, Т1 и Т2
	3. вычисление сумм кодов концов С1 и С2
	4. проверка отрезка на полную видимость, С1=0 и С2=0; если видимый - высвечиваем и заканчиваем
	5. если не полностьювидимый - проверка на невидимость; если невидимый - заканчиваем
	если же частично видимый - пошло-поехало
	6. запоминание Р1 (Т=Р1)
	7. определить номер искомой точки пересечения i=1
	8. если i>2, то анализируем полученный отрезок на невидимость (произведение кодов концов, если равно нулю - то видим)
		9. Если S2=0, то
				Res[i] = P2;
				i+=1
				Р1 = P2; P2 = T
		10. если S2 != 0 , то ищется точка пересечения:
			10.1. если |P1-P2|>E то
				sPoint P_mid = (Р1+Р2)/2
				sPoint P_t = P1
				P1 = Р_mid
				определение невидимости Р1Р2, предварительно вычислить код Р1
				если Р1Р2 невидим, то
					Р1 = P_t (вернуть Р1 на прежнее место)
					P2 = Р_mid
				(иначе работа продолжается с Р1Р2)
			Иначе, если же |P1-P2|<=E, то
				if (pointsNum == 1)
					res->A = P2;
				else
					res->B = P2;
				P1 = P2
				P2 = T
				pointsNum += 1
			переход к 8.
	*/


	//если отрезок гарантированно невидимый, то уведомляем об этом
	if (IsInvis(line.A, line.B, rect))
		return nullptr;

	sLine *res;
	sPoint P1 = line.A, P2 = line.B;

	res = new sLine;
	//если отрезок гарантированно видимый, то возвращаем его
	//if (CheckPoint(P1, rect) && CheckPoint(P2, rect))
	if (!PointCode(P1, rect) && !PointCode(P1, rect))
	{
		res->A = P1;
		res->B = P2;
		return res;
	}

	sPoint T = P1; //буфер
	int pointsNum = 1; //номер рассматриваемой точки
	while (pointsNum < 3/* && P1 != P2*/)
	{
		if (PointCode(P2, rect) == 0) //если точка Р2 оказалась внутри прямоугла, то запоминаем её
		{
			if (pointsNum == 1)
				res->A = P2;
			else
				res->B = P2;
			pointsNum += 1;
			P1 = P2;
			P2 = T;
		}
		else //если не оказалась, то ищем точку пересечения
		{
			if (Dist(P1,P2) > EPS) //не сжались в точку, можно продолжать половинное деление
			{
				sPoint P_mid = (P1+P2)/2; //средняя точка
				sPoint P_t = P1; //ещё один буфер
				P1 = P_mid;
				if (IsInvis(P1, P2, rect))
				{
					P1 = P_t;
					P2 = P_mid;
				}
			}
			else //сжались - заносим точку в результат
			{
				if (pointsNum == 1)
					res->A = P2;
				else
					res->B = P2;
				P1 = P2;
				P2 = T;
				pointsNum += 1;
			}
		}
	}
	return res;
}