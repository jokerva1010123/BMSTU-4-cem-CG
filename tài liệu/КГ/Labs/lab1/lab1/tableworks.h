#pragma once

#include "listworks.h"

using namespace System;
using namespace System::Windows::Forms;



//��������� ��������� ������������� ������
void MatchTable(DataGridView^ table, pointlist *list);

//��������� ������ � �������
void AddRecordToTable(pointlist *data, DataGridView^ table, int num);