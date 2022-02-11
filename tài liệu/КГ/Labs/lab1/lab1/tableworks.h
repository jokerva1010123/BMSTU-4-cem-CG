#pragma once

#include "listworks.h"

using namespace System;
using namespace System::Windows::Forms;



//формирует табличное представление списка
void MatchTable(DataGridView^ table, pointlist *list);

//добавляет запись в таблицу
void AddRecordToTable(pointlist *data, DataGridView^ table, int num);