#pragma once

using namespace System;
#define PI 3.141592

//точка
struct realpoint
{
	double x,y;
};
//вектор с длиной
struct vector
{
	double x,y;
	double len;
};

//возвращает рассто€ние между двум€ точками
double Distance(realpoint *A, realpoint *B);

//возвращает вектор из двух точек, заодно вычисл€€ длину оного
vector* FormVector(realpoint *A, realpoint *B);

//возвращает точку по двум  ќ––≈ “Ќџћ строкам
realpoint *FormPoint(String^ strx, String^ stry);

//возвращает угол между двум€ векторами в радианах
double VectorsAngle (vector *V1, vector *v2);