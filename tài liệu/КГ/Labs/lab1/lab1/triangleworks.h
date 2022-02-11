#pragma once

#include "pointworks.h"
#include "listworks.h"

//основу составл€ют точки, треугл только указывает на них
struct triangle
{
	realpoint *A;
	realpoint *B;
	realpoint *C;
	double AB;
	double BC;
	double AC;
};

//структура с ответом
struct resultstruct
{
	pointlist *list1; //точки первого треугольника
	pointlist *list2; //точки второго треугольника
	double angle; //угол между пр€мой через пересечени€ биссектрис, и ординатой
	int code; //код ошибки. 0 - всЄ хорошо, 1 - все треугольники в є1 вырожденные, 2 - все треугольники в є2 вырожденные
};

//образует треугольник из трЄх точек
triangle* FormTriangle(realpoint *p1, realpoint *p2, realpoint *p3);

//получает координаты точки пересечени€ биссектрис
realpoint* BissCross(triangle *T);

//из списков 1 и 2 находит два треугольника таких, чтобы пр€ма€, проход€ща€ через
//точки пересечени€ их биссектрис, образовывала наименьший угол с осью ординат
resultstruct* Solve(pointlist *list1, pointlist *list2);