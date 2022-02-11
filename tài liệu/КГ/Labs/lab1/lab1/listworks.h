#pragma once

#include "pointworks.h"

//Работа со списками как таковыми

//список точек
struct pointlist
{
	realpoint* point;
	int id;
	pointlist *next;
};




//получает список точек из КОРРЕКТНОГО файла
pointlist *LoadListFromFile(pointlist *list, String^ filename);

//проверяет файл на корректность
bool CheckFile(String^ filename);



//создает "запись" из точки
pointlist* FormRecord(realpoint* from);

//добавляет запись в список
pointlist* AddRecordToList(pointlist *record, pointlist *list);

//удаляет запись с номером из списка
pointlist* RemoveRecord(int num, pointlist *list);

//находит запись по номеру в списке
pointlist* FindRecord(int num, pointlist *list);

//создаёт копию записи с номером в списке
pointlist* CopyRecord(int num, pointlist *list);

//считает количество элементов в списке
int CountElements(pointlist *list);