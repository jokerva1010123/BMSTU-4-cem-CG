#include <stdafx.h>

//Работа с точками, векторами, и всем что с ними связано

#include "pointworks.h"
#include <math.h>


//возвращает расстояние между двумя точками
double Distance(realpoint *A, realpoint *B)
{
	return sqrt((B->x - A->x)*(B->x - A->x) + (B->y - A->y)*(B->y - A->y));
}


//возвращает вектор AB из двух точек А и В, заодно вычисляя длину оного
vector* FormVector(realpoint *A, realpoint *B)
{
	vector *V = new vector;
	V->x = B->x - A->x;
	V->y = B->y - A->y;
	V->len = Distance(A,B);

	return V;
}


//возвращает точку по двум КОРРЕКТНЫМ строкам
realpoint* FormPoint(String^ strx, String^ stry)
{
	//ввод верный - "возвращаем" точку
	realpoint *NewPoint = new realpoint;
	NewPoint->x = Convert::ToDouble(strx);
	NewPoint->y = Convert::ToDouble(stry);
	return NewPoint;
}


//скалярное и векторное произведения
double MultScal(vector *Vec1, vector *Vec2)
{
	return (Vec1->x * Vec2->x) + (Vec1->y * Vec2->y);
}
double MultVec(vector *Vec1, vector *Vec2)
{
	return (Vec1->x * Vec2->y) - (Vec1->y * Vec2->x);
}


//возвращают синус и косинус угла между векторами
double VectorsCos(vector *V1, vector *V2)
{
	double CosA = MultScal(V1,V2) / (V1->len * V2->len);
	return CosA;
}
double VectorsSin(vector *V1, vector *V2)
{
	double SinA = MultVec(V1,V2) / (V1->len * V2->len);
	return SinA;
}


//возвращает угол между двумя векторами в радианах
double VectorsAngle (vector *V1, vector *V2)
{
	double SinA = VectorsSin(V1,V2);
	double CosA = VectorsCos(V1,V2);
	/*System::Windows::Forms::MessageBox::Show(
		String::Format("V1={0:0.000}:{1:0.000}, Len={2:0.000}\n", V1->x, V1->y, V1->len)+
		String::Format("V2={0:0.000}:{1:0.000}, Len={2:0.000}\n", V2->x, V2->y, V2->len)+
		String::Format("Sin={0:0.000}, Cos={1:0.000}", SinA,CosA)
		);*/
	double Angle = fabs(asin(SinA));
	/*if (CosA < 0)
		Angle += PI/2;*/
	return Angle;
}