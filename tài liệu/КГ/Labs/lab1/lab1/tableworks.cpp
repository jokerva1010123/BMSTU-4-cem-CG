#include <stdafx.h>

//������ � ����������, ����-�����

#include "tableworks.h"
#include "listworks.h"

//using namespace lab1;



//��������� � ������� ������� � ���������� ������
void AddRecordToTable(pointlist *data, DataGridView^ table, int num)
{
	table->Rows->Insert(num,
		String::Format("{0}",data->id),
		String::Format("{0:0.0###}",data->point->x),
		String::Format("{0:0.0###}",data->point->y));
}

//��������� ��������� ������������� ������
void MatchTable(DataGridView^ table, pointlist *list)
{
	table->Rows->Clear();

	if (!list)
		return;

	pointlist *ptr = list;


	//��������� ������� ������
	int pos=0;
	while (ptr)
	{
		AddRecordToTable(ptr,table,pos++);
		ptr = ptr->next;
	}
}

/*void MatchTable(DataGridView^ table, pointlist *list)
{
	//���� ������ ������ ������, �� ������� ���������
	if (!list)
	{
		table->Rows->Clear();
		return;
	}

	pointlist *ptr = list;


	//���� �� � ������ �� ����, �� ���������, �� ����� �� ����-������ ��������
	//�������� � ������ ���� ������ ������������
	int pos=0;
	while (ptr)
	{
		Int32 ListNum = ptr->id;
		Int32 TableNum = Convert::ToInt32(table->Rows[pos]->Cells[0]->Value);
		if (TableNum != ListNum)
		{
			AddRecordToTable(ptr,table,pos+1);
			ptr = ptr->next;
			continue;
		}
		pos++; 

		ptr = ptr->next;
	}
}*/