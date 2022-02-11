#include <stdafx.h>

//Работа с треугольниками и всем что с ними связано, решение задачки

#include "triangleworks.h"

bool CheckTriangle(triangle *T)
{
	vector *AB = FormVector(T->A, T->B);
	vector *AC = FormVector(T->A, T->C);
	double angle = VectorsAngle(AB, AC);
	/*System::Windows::Forms::MessageBox::Show("Треугл на координатах:\n"+
		String::Format("A{0:0.000}:{1:0.000}  ;  ", T->A->x, T->A->y)+
		String::Format("B{0:0.000}:{1:0.000}  ;  ", T->B->x, T->B->y)+
		String::Format("C{0:0.000}:{1:0.000}\n", T->C->x, T->C->y)+
		String::Format("Уголь А: {0:0.000}°", angle/PI*180)
		//String::Format("AB={0:0.000}, BC={1:0.000}, AC={2:0.000}\n", tri->AB, tri->BC, tri->AC)
		);*/
	delete AB, AC;
	
	return (angle > 0.0);
}

//образует треугольник из трёх точек
triangle* FormTriangle(realpoint *p1, realpoint *p2, realpoint *p3)
{
	if (!p1 || !p2 || !p3)
		return nullptr;

	triangle *tri = new triangle;
	tri->A = p1;
	tri->B = p2;
	tri->C = p3;
	tri->AB = Distance(tri->A, tri->B);
	tri->AC = Distance(tri->A, tri->C);
	tri->BC = Distance(tri->B, tri->C);
	/*System::Windows::Forms::MessageBox::Show("Треугл на координатах:\n"+
		String::Format("A{0:0.000}:{1:0.000} ; ", tri->A->x, tri->A->y)+
		String::Format("B{0:0.000}:{1:0.000} ; ", tri->B->x, tri->B->y)+
		String::Format("C{0:0.000}:{1:0.000}\n", tri->C->x, tri->C->y)+
		String::Format("AB={0:0.000}, BC={1:0.000}, AC={2:0.000}\n", tri->AB, tri->BC, tri->AC)
		);*/
	return tri;
}

//получает координаты точки пересечения биссектрис
realpoint* BissCross(triangle *T)
{
	if (!T)
		return nullptr;

	realpoint *cross = new realpoint;
	cross->x = (T->A->x * T->BC + T->B->x * T->AC + T->C->x * T->AB) / (T->AB + T->BC + T->AC);
	cross->y = (T->A->y * T->BC + T->B->y * T->AC + T->C->y * T->AB) / (T->AB + T->BC + T->AC);
	return cross;
}



//из списков 1 и 2 находит два треугольника таких, чтобы прямая, проходящая через
//точки пересечения их биссектрис, образовывала наименьший угол с осью ординат
resultstruct* Solve(pointlist *list1, pointlist *list2)
{
	if (!list1 || !list2)
		return nullptr;

	resultstruct *result = new resultstruct;
	result->angle = 0.0;
	result->list1 = nullptr;
	result->list2 = nullptr;
	result->code = 0;

	int Count1 = CountElements(list1); //количество элементов в списках
	int Count2 = CountElements(list2);

	//реализация быдлометодом: 6 вложенных циклов, раз за разом последовательное сравнение треуглов.
	//можно было разбить на отдельные составные части с формированием массивов треуглов, но есть
	//подозрение что тогда потребовалось бы ещё и переделывать их структуру...

	pointlist** PointArr1 = new pointlist* [Count1];
	pointlist** PointArr2 = new pointlist* [Count2];

	//заполняем массивы точек
	pointlist *ptrP = list1;
	for (int i=0; i<Count1; i++)
	{
		PointArr1[i] = ptrP;
		ptrP = ptrP->next;
	}
	ptrP = list2;
	for (int i=0; i<Count2; i++)
	{
		PointArr2[i] = ptrP;
		ptrP = ptrP->next;
	}

	triangle *Tri1, *Tri2; //треуглы, которые будем сравнивать
	int numbers[6]; //массив номеров точек, из которых состоят искомые треуглы
	double minangle = PI; //наименьший угол //любой угол будет меньше pi==3.14
	bool FoundFirst = false;
	bool FoundSecond = false;
	bool FoundBis = false;
	for (int I1=0; I1<Count1-2; I1++)
	{
		for (int J1=I1+1; J1<Count1-1; J1++)
		{
			for (int K1=J1+1; K1<Count1; K1++)
			{
				//собираем треугольник в первом списке
				Tri1 = FormTriangle(PointArr1[I1]->point, PointArr1[J1]->point, PointArr1[K1]->point);
				//проверяем на вырожденность
				if (CheckTriangle(Tri1))
					FoundFirst = true;
				else
					continue;
				for (int I2=0; I2<Count2-2; I2++)
				{
					for (int J2=I2+1; J2<Count2-1; J2++)
					{
						for (int K2=J2+1; K2<Count2; K2++)
						{
							//собираем треугольник во втором списке
							Tri2 = FormTriangle(PointArr2[I2]->point, PointArr2[J2]->point, PointArr2[K2]->point);
							//проверяем на вырожденность
							if (CheckTriangle(Tri2))
								FoundSecond = true;
							else
								continue;
							//получаем точки пересечения биссектрис
							realpoint *cross1 = BissCross(Tri1);
							realpoint *cross2 = BissCross(Tri2);
							//получаем вектор через биссектрисы
							vector *bis = FormVector(cross1, cross2);
							//проверяем бис-вектор на вырожденность
							if (bis->x == 0.0 && bis->y == 0.0)
								continue;
							else
								FoundBis = true;
							//получаем вектор ординат
							vector *ord = new vector;
							ord->x = 0; ord->y = 1; ord->len = 1;
							//получаем угол между ними
							double angle = VectorsAngle(bis, ord);
							//если он меньше минимального - запоминаем, на каких точках он был построен
							if (angle < minangle)
							{
								numbers[0] = PointArr1[I1]->id;
								numbers[1] = PointArr1[J1]->id;
								numbers[2] = PointArr1[K1]->id;
								numbers[3] = PointArr2[I2]->id;
								numbers[4] = PointArr2[J2]->id;
								numbers[5] = PointArr2[K2]->id;
								minangle = angle;
							}

							/*System::Windows::Forms::MessageBox::Show(
								String::Format("Треугл1 на точках: {0}, {1}, {2}\n",PointArr1[I1]->id,PointArr1[J1]->id,PointArr1[K1]->id)+
								String::Format("Треугл2 на точках: {0}, {1}, {2}\n",PointArr2[I2]->id,PointArr2[J2]->id,PointArr2[K2]->id)+
								String::Format("Угол между ними: {0:0.0###}°",angle/PI*180)
								);*/

							delete Tri2;
						}
					}
				}
				delete Tri1;
			}
		}
	}

	//проверяем вырожденности всего
	if (!FoundFirst)
	{
		result->code = 1;
		return result;
	}
	if (!FoundSecond)
	{
		result->code = 2;
		return result;
	}
	if (!FoundBis)
	{
		result->code = 3;
		return result;
	}
	result->list1 = CopyRecord(numbers[0], list1);
	result->list1->next = CopyRecord(numbers[1], list1);
	result->list1->next->next = CopyRecord(numbers[2], list1);
	result->list2 = CopyRecord(numbers[3], list2);
	result->list2->next = CopyRecord(numbers[4], list2);
	result->list2->next->next = CopyRecord(numbers[5], list2);
	result->angle = minangle;
	return result;
}