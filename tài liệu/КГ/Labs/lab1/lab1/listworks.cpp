#include <stdafx.h>

#include "pointworks.h"
#include "listworks.h"

using namespace System::IO; //�����-������ ��� ������ � �������


//�������� ������ ����� �� ����������� �����
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

//��������� ���� �� ������������
bool CheckFile(String^ filename)
{
	StreamReader^ Checker = gcnew StreamReader(filename);

	String^ str = Checker->ReadLine();
	if(!str) //���� ���� ����
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


//������� "������" �� �����
pointlist* FormRecord(realpoint* from)
{
	pointlist *data = new pointlist;
	data->id = 0;
	data->point = from;
	data->next = nullptr;

	return data;
}


//��������� ������ � ������
pointlist* AddRecordToList(pointlist *record, pointlist *list)
{
	//���� ������ ����, �� �� "����������������"
	if (list == nullptr)
	{
		record->id = 1; //�������������� �� ���������������� �������� � ����� ������� ����� �1 � �� �0
		list = record;
		return list;
	}

	//���� �� ����� ������ �� ����� �1, �� ��������� ������ � ������
	if (list->id != 1)
	{
		record->next = list;
		record->id = 1;
		list = record;
		return list;
	}

	//���� �� ������ ���������� � 1, �� �����, ���� �������� �����
	int num = 2;
	pointlist *ptr = list;
	while (ptr->next) //�������, ���� �� ����� �� ���������� ��������
	{
		//���� ��������� ������� - �� "���������" � "��������������" �� ������, �� ����� ��������� ������
		if (ptr->next->id - ptr->id > 1)
			break;
		ptr = ptr->next;
		num++;
	}
	//������ ptr ��������� �� �������, ����� �������� ���� �������� ������
	record->next = ptr->next;
	ptr->next = record;
	record->id = num;

	return list;
}


//������� ������ � ������� �� ������
pointlist* RemoveRecord(int num, pointlist *list)
{
	//���� ������ ������ �� � ������� ������
	if (!list)
		return nullptr;

	//���� ����� ������� ������ ������ - ��� � ������
	if (list->id == num)
	{
		pointlist *temp = list;
		list = list->next;
		delete temp->point;
		delete temp;
		return list;
	}

	//� ��������� ������ ���� ��� �������
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


//������� ������ �� ������ � ������
pointlist* FindRecord(int num, pointlist *list)
{
	//���� ������ ������ �� � ������ ������
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

//������ ����� ������ � ������� � ������
pointlist* CopyRecord(int num, pointlist *list)
{
	//���� ������ ������ �� � ���������� ������
	if (!list)
		return nullptr;

	pointlist *ptr = FindRecord(num, list);

	pointlist *copy = new pointlist;
	copy->next = nullptr;
	copy->id = ptr->id;
	copy->point = ptr->point;

	return copy;
}


//������� ���������� ��������� � ������
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