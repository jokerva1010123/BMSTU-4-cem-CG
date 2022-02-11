#include <stdafx.h>

#include "pointworks.h"
#include "listworks.h"

using namespace System::IO; //инпут-оутпут дл€ работы с файлами


//получает список точек из  ќ––≈ “Ќќ√ќ файла
pointlist *LoadListFromFile(pointlist *list, String^ filename)
{
	StreamReader^ Reader = gcnew StreamReader(filename);

	String^ str = Reader->ReadLine();
	String^ coord1;
	String^ coord2;
	double x,y;
	while (str)
	{
		int sep = str->IndexOf(' ');
		coord1 = str->Substring(0,sep);
		coord2 = str->Substring(sep+1,str->Length-sep-1);

		if (Double::TryParse(coord1,CONVERT_NUMBER,x) && Double::TryParse(coord2,CONVERT_NUMBER,y))
		{
			realpoint *NewPoint = new realpoint;
			NewPoint->x = x;
			NewPoint->y = y;
			pointlist *NewElement = FormRecord(NewPoint);
			list = AddRecordToList(NewElement, list);
		}
		delete coord1;
		delete coord2;
		delete str;
		str = Reader->ReadLine();
	}
	Reader->Close();
	return list;
}

//провер€ет файл на корректность
bool CheckFile(String^ filename)
{
	StreamReader^ Checker = gcnew StreamReader(filename);

	String^ str = Checker->ReadLine();
	if(!str) //если файл пуст
		return false;

	double x,y;
	String^ coord1;
	String^ coord2;
	while (str)
	{
		int sep = str->IndexOf(' ');
		if (sep<1 || sep == str->Length-1)
			return false;
		coord1 = str->Substring(0,sep);
		coord2 = str->Substring(sep+1,str->Length-sep-1);

		if (!Double::TryParse(coord1,CONVERT_NUMBER,x) || !Double::TryParse(coord2,CONVERT_NUMBER,y))

		delete coord1;
		delete coord2;
		delete str;
		str = Checker->ReadLine();
	}
	Checker->Close();
	delete Checker;

	return true;
}


//создает "запись" из точки
pointlist* FormRecord(realpoint* from)
{
	pointlist *data = new pointlist;
	data->id = 0;
	data->point = from;
	data->next = nullptr;

	return data;
}


//добавл€ет запись в список
pointlist* AddRecordToList(pointlist *record, pointlist *list)
{
	//если список пуст, то он "инициализируетс€"
	if (list == nullptr)
	{
		record->id = 1; //абстрагируемс€ от программистского мышлени€ и будем считать точки с1 а не с0
		list = record;
		return list;
	}

	//если во главе списка не точка є1, то вставл€ем запись в начало
	if (list->id != 1)
	{
		record->next = list;
		record->id = 1;
		list = record;
		return list;
	}

	//если же список начинаетс€ с 1, то найдЄм, куда вставить точку
	int num = 2;
	pointlist *ptr = list;
	while (ptr->next) //считаем, пока не дойдЄм до последнего элемента
	{
		//если следующий элемент - не "следующий" а "послеследующий" по номеру, то нужно заполнить пробел
		if (ptr->next->id - ptr->id > 1)
			break;
		ptr = ptr->next;
		num++;
	}
	//сейчас ptr указывает на элемент, после которого надо вставить запись
	record->next = ptr->next;
	ptr->next = record;
	record->id = num;

	return list;
}


//удал€ет запись с номером из списка
pointlist* RemoveRecord(int num, pointlist *list)
{
	//если список пустой то и удал€ть нечего
	if (!list)
		return nullptr;

	//если нужно удалить голову списка - так и делаем
	if (list->id == num)
	{
		pointlist *temp = list;
		list = list->next;
		delete temp->point;
		delete temp;
		return list;
	}

	//в противном случае ищем что удалить
	pointlist *ptr = list;
	while (ptr->next)
	{
		pointlist *prev = ptr;
		ptr = ptr->next;
		if (ptr->id == num)
		{
			prev->next = ptr->next;
			delete ptr->point;
			delete ptr;
			return list;
		}
	}
	return list;
}


//находит запись по номеру в списке
pointlist* FindRecord(int num, pointlist *list)
{
	//если список пустой то и искать нечего
	if (!list)
		return nullptr;
	
	pointlist *ptr = list;

	while (ptr)
	{
		if (ptr->id == num)
			break;
		ptr = ptr->next;
	}
	return ptr;
}

//создаЄт копию записи с номером в списке
pointlist* CopyRecord(int num, pointlist *list)
{
	//если список пустой то и копировать нечего
	if (!list)
		return nullptr;

	pointlist *ptr = FindRecord(num, list);

	pointlist *copy = new pointlist;
	copy->next = nullptr;
	copy->id = ptr->id;
	copy->point = ptr->point;

	return copy;
}


//считает количество элементов в списке
int CountElements(pointlist *list)
{
	int count = 0;
	while (list)
	{
		count++;
		list=list->next;
	}
	return count;
}