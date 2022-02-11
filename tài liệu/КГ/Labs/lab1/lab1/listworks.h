#pragma once

#include "pointworks.h"

//������ �� �������� ��� ��������

//������ �����
struct pointlist
{
	realpoint* point;
	int id;
	pointlist *next;
};




//�������� ������ ����� �� ����������� �����
pointlist *LoadListFromFile(pointlist *list, String^ filename);

//��������� ���� �� ������������
bool CheckFile(String^ filename);



//������� "������" �� �����
pointlist* FormRecord(realpoint* from);

//��������� ������ � ������
pointlist* AddRecordToList(pointlist *record, pointlist *list);

//������� ������ � ������� �� ������
pointlist* RemoveRecord(int num, pointlist *list);

//������� ������ �� ������ � ������
pointlist* FindRecord(int num, pointlist *list);

//������ ����� ������ � ������� � ������
pointlist* CopyRecord(int num, pointlist *list);

//������� ���������� ��������� � ������
int CountElements(pointlist *list);