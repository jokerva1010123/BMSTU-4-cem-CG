#include "StdAfx.h"
#include "formMain.h"
#include "formAdd.h"
#include "tableworks.h"
#include "triangleworks.h"
#include "pointworks.h"
#include "listworks.h"
#include "paint.h"

using namespace lab1;

//инициализировать формочку!
System::Void formMain::formMain_Load(System::Object^  sender, System::EventArgs^  e)
{
	List1 = nullptr; //инициализируем списки пустотой
	List2 = nullptr;
	
	Easel = new canvasstruct;
	Easel->canvas = pictureBox1->CreateGraphics(); //инициализируем холст на пикчурбоксе
	Easel->width = pictureBox1->Width;
	Easel->height = pictureBox1->Height;
}

//рассчитать треуглы!
System::Void formMain::btnCalc_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool err=false;
	String^ errormessage;
	if (!err && !List1)
	{
		err = true;
		errormessage = String::Format("Список №1 не определен!");
	}
	if (!err && !List2)
	{
		err = true;
		errormessage = String::Format("Список №2 не определен!");
	}
	
	if (!err && CountElements(List1)<3)
	{
		err = true;
		errormessage = String::Format("В списке №1 недостаточно точек!");
	}
	if (!err && CountElements(List2)<3)
	{
		err = true;
		errormessage = String::Format("В списке №2 недостаточно точек!");
	}

	if (err)
	{
		MessageBox::Show(errormessage, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}


	resultstruct *result = Solve(List1, List2);
	if (result->code == 1)
	{
		MessageBox::Show("Все треугольники в списке №1 вырожденные.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (result->code == 2)
	{
		MessageBox::Show("Все треугольники в списке №2 вырожденные.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (result->code == 3)
	{
		MessageBox::Show("Точки пересечения биссектрис совпадают.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	//DrawTwoLists(Easel, result->list1, result->list2, Color::Green, Color::Red);
	DrawResult(Easel, result);
	MessageBox::Show(
		String::Format("Треугольник №1 построен на точках: {0}, {1}, {2}\n", result->list1->id, result->list1->next->id, result->list1->next->next->id)+
		String::Format("Треугольник №2 построен на точках: {0}, {1}, {2}\n", result->list2->id, result->list2->next->id, result->list2->next->next->id)+
		String::Format("Угол между осью Y и прямой через точки пересечения биссектрис: {0:0.0##}°",result->angle/PI*180),
		"Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
	delete errormessage;
}

//нарисовать точки!
System::Void formMain::btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
{
	DrawTwoLists(Easel, List1, List2, Color::Green, Color::Red);
}

//очистить холст!
System::Void formMain::btnClear_Click(System::Object^  sender, System::EventArgs^  e)
{
	Easel->canvas->Clear(Color::AliceBlue);
}


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//		нажатие кнопок меню
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//список1 - загрузка
System::Void formMain::menu_file_list1_load_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgOpen->FileName = "";

	//если пользователь отменил выбор то ничего и не делаем
	if (dlgOpen->ShowDialog() != Windows::Forms::DialogResult::OK)
		return;

	StreamReader^ MyReader;
	try //пытаемся открыть файл
	{
		MyReader = gcnew StreamReader(dlgOpen->FileName);
	}
	catch (IO::FileNotFoundException^ error) //если файл не найден
	{
		MessageBox::Show(error->Message + "\nФайл не найден", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	MyReader->Close();
	delete MyReader;

	//если файл содержит мусор
	if (!CheckFile(dlgOpen->FileName))
	{
		MessageBox::Show("Файл содержит некорректные данные", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	List1 = LoadListFromFile(List1,dlgOpen->FileName);

	MatchTable(dataTable1, List1);
}

//список1 - очистка
System::Void formMain::menu_file_list1_clear_Click(System::Object^  sender, System::EventArgs^  e)
{
	pointlist *ptr = List1;
	pointlist *del;
	while (ptr)
	{
		del = ptr;
		ptr = ptr->next;
		delete del->point;
		delete del;
	}
	List1 = nullptr;
	MatchTable(dataTable1, List1);
}

//список2 - загрузка
System::Void formMain::menu_file_list2_load_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgOpen->FileName = "";

	//если пользователь отменил выбор то ничего и не делаем
	if (dlgOpen->ShowDialog() != Windows::Forms::DialogResult::OK)
		return;

	StreamReader^ MyReader;
	try //пытаемся открыть файл
	{
		MyReader = gcnew StreamReader(dlgOpen->FileName);
	}
	catch (IO::FileNotFoundException^ error) //если файл не найден
	{
		MessageBox::Show(error->Message + "\nФайл не найден", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	MyReader->Close();
	delete MyReader;

	//если файл содержит мусор
	if (!CheckFile(dlgOpen->FileName))
	{
		MessageBox::Show("Файл содержит некорректные данные", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	List2 = LoadListFromFile(List2,dlgOpen->FileName);

	MatchTable(dataTable2, List2);
}

//список2 - очистка
System::Void formMain::menu_file_list2_clear_Click(System::Object^  sender, System::EventArgs^  e)
{
	pointlist *ptr = List2;
	pointlist *del;
	while (ptr)
	{
		del = ptr;
		ptr = ptr->next;
		delete del->point;
		delete del;
	}
	List2 = nullptr;
	MatchTable(dataTable2, List2);
}



//условие
System::Void formMain::menu_task_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("\
На плоскости даны два множества точек. Найти пару треугольников \
(первый состоит из точек первого множества, второй – из точек второго) \
таких, что прямая, соединяющая точки пересечения биссектрис, \
образует минимальный угол с осью ординат", "Вариант №35");
}



//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//		нажатие кнопок списка1
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//добавить
System::Void formMain::btnAdd1_Click(System::Object^  sender, System::EventArgs^  e)
{
	realpoint *point = CreatePointForm(); //создаём точку с помощью формочки
	if (point)
	{		
		pointlist *data = FormRecord(point); //образуем элемент списка на основе точки
		List1 = AddRecordToList(data, List1); //добавляем его в первое множество
		MatchTable(dataTable1,List1); //обновляем таблицу
	}
}

//удалить
System::Void formMain::btnDelete1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List1)
		return;

	int pos = dataTable1->CurrentRow->Index; //какой элемент таблицы выделен
	int num = Convert::ToInt32(dataTable1->CurrentRow->Cells[0]->Value); //какой у него номер в списке

	System::Windows::Forms::DialogResult result;
	String^ message = String::Format("Удалить точку #{0}?", num);
	result = MessageBox::Show(message, "Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if ( result == ::DialogResult::Yes )
	{
		dataTable1->Rows->Remove(dataTable1->Rows[pos]);
		List1 = RemoveRecord(num,List1);
	}
	delete message;
}

//изменить
System::Void formMain::btnEdit1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List1)
		return;

	realpoint *newpoint = CreatePointForm(); //требуем ввести новые координаты
	if (newpoint)
	{		
		int pos = dataTable1->CurrentRow->Index; //удаляем точку из таблицы
		int num = Convert::ToInt32(dataTable1->CurrentRow->Cells[0]->Value); //и из списка
		dataTable1->Rows->Remove(dataTable1->Rows[pos]);
		List1 = RemoveRecord(num,List1);
		pointlist *newdata = FormRecord(newpoint); //образуем новую
		List1 = AddRecordToList(newdata, List1); //добавляем её в список
		MatchTable(dataTable1,List1); //профит
	}
}



//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//		нажатие кнопок списка2
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//добавить
System::Void formMain::btnAdd2_Click(System::Object^  sender, System::EventArgs^  e)
{
	realpoint *point = CreatePointForm(); //создаём точку с помощью формочки
	if (point)
	{		
		pointlist *data = FormRecord(point); //образуем элемент списка на основе точки
		List2 = AddRecordToList(data, List2); //добавляем его в первое множество
		MatchTable(dataTable2,List2); //обновляем таблицу
	}
}

//удалить
System::Void formMain::btnDelete2_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List2)
		return;

	int pos = dataTable2->CurrentRow->Index; //какой элемент таблицы выделен
	int num = Convert::ToInt32(dataTable2->CurrentRow->Cells[0]->Value); //какой у него номер в списке

	System::Windows::Forms::DialogResult result;
	String^ message = String::Format("Удалить точку #{0}?", num);
	result = MessageBox::Show(message, "Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if ( result == ::DialogResult::Yes )
	{
		dataTable2->Rows->Remove(dataTable2->Rows[pos]);
		List2 = RemoveRecord(num,List2);
	}
	delete message;
}
System::Void formMain::btnEdit2_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List2)
		return;

	realpoint *newpoint = CreatePointForm(); //требуем ввести новые координаты
	if (newpoint)
	{		
		int pos = dataTable2->CurrentRow->Index; //удаляем точку из таблицы
		int num = Convert::ToInt32(dataTable2->CurrentRow->Cells[0]->Value); //и из списка
		dataTable2->Rows->Remove(dataTable2->Rows[pos]);
		List2 = RemoveRecord(num,List2);
		pointlist *newdata = FormRecord(newpoint); //образуем новую
		List2 = AddRecordToList(newdata, List2); //добавляем её в список
		MatchTable(dataTable2,List2); //профит
	}
}













/*System::Void formMain::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Easel->canvas->Clear(Color::AliceBlue);
	if (!List1)
		return;
	DrawPointsList(Easel,List1,Color::Green);
}

System::Void formMain::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	Easel->canvas->Clear(Color::AliceBlue);
}

System::Void formMain::btnEdit1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List1)
		return;

	pointlist *ptr = List1;
	while(ptr)
	{
		MessageBox::Show(String::Format("№{0} X:{1:0.0##} Y:{2:0.0##}", ptr->id, ptr->point->x, ptr->point->y));
		ptr = ptr->next;
	}
}*/