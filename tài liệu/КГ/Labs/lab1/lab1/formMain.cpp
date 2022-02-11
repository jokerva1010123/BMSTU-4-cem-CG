#include "StdAfx.h"
#include "formMain.h"
#include "formAdd.h"
#include "tableworks.h"
#include "triangleworks.h"
#include "pointworks.h"
#include "listworks.h"
#include "paint.h"

using namespace lab1;

//���������������� ��������!
System::Void formMain::formMain_Load(System::Object^  sender, System::EventArgs^  e)
{
	List1 = nullptr; //�������������� ������ ��������
	List2 = nullptr;
	
	Easel = new canvasstruct;
	Easel->canvas = pictureBox1->CreateGraphics(); //�������������� ����� �� �����������
	Easel->width = pictureBox1->Width;
	Easel->height = pictureBox1->Height;
}

//���������� �������!
System::Void formMain::btnCalc_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool err=false;
	String^ errormessage;
	if (!err && !List1)
	{
		err = true;
		errormessage = String::Format("������ �1 �� ���������!");
	}
	if (!err && !List2)
	{
		err = true;
		errormessage = String::Format("������ �2 �� ���������!");
	}
	
	if (!err && CountElements(List1)<3)
	{
		err = true;
		errormessage = String::Format("� ������ �1 ������������ �����!");
	}
	if (!err && CountElements(List2)<3)
	{
		err = true;
		errormessage = String::Format("� ������ �2 ������������ �����!");
	}

	if (err)
	{
		MessageBox::Show(errormessage, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}


	resultstruct *result = Solve(List1, List2);
	if (result->code == 1)
	{
		MessageBox::Show("��� ������������ � ������ �1 �����������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (result->code == 2)
	{
		MessageBox::Show("��� ������������ � ������ �2 �����������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (result->code == 3)
	{
		MessageBox::Show("����� ����������� ���������� ���������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	//DrawTwoLists(Easel, result->list1, result->list2, Color::Green, Color::Red);
	DrawResult(Easel, result);
	MessageBox::Show(
		String::Format("����������� �1 �������� �� ������: {0}, {1}, {2}\n", result->list1->id, result->list1->next->id, result->list1->next->next->id)+
		String::Format("����������� �2 �������� �� ������: {0}, {1}, {2}\n", result->list2->id, result->list2->next->id, result->list2->next->next->id)+
		String::Format("���� ����� ���� Y � ������ ����� ����� ����������� ����������: {0:0.0##}�",result->angle/PI*180),
		"���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	delete errormessage;
}

//���������� �����!
System::Void formMain::btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
{
	DrawTwoLists(Easel, List1, List2, Color::Green, Color::Red);
}

//�������� �����!
System::Void formMain::btnClear_Click(System::Object^  sender, System::EventArgs^  e)
{
	Easel->canvas->Clear(Color::AliceBlue);
}


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//		������� ������ ����
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//������1 - ��������
System::Void formMain::menu_file_list1_load_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgOpen->FileName = "";

	//���� ������������ ������� ����� �� ������ � �� ������
	if (dlgOpen->ShowDialog() != Windows::Forms::DialogResult::OK)
		return;

	StreamReader^ MyReader;
	try //�������� ������� ����
	{
		MyReader = gcnew StreamReader(dlgOpen->FileName);
	}
	catch (IO::FileNotFoundException^ error) //���� ���� �� ������
	{
		MessageBox::Show(error->Message + "\n���� �� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	MyReader->Close();
	delete MyReader;

	//���� ���� �������� �����
	if (!CheckFile(dlgOpen->FileName))
	{
		MessageBox::Show("���� �������� ������������ ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	List1 = LoadListFromFile(List1,dlgOpen->FileName);

	MatchTable(dataTable1, List1);
}

//������1 - �������
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

//������2 - ��������
System::Void formMain::menu_file_list2_load_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgOpen->FileName = "";

	//���� ������������ ������� ����� �� ������ � �� ������
	if (dlgOpen->ShowDialog() != Windows::Forms::DialogResult::OK)
		return;

	StreamReader^ MyReader;
	try //�������� ������� ����
	{
		MyReader = gcnew StreamReader(dlgOpen->FileName);
	}
	catch (IO::FileNotFoundException^ error) //���� ���� �� ������
	{
		MessageBox::Show(error->Message + "\n���� �� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	MyReader->Close();
	delete MyReader;

	//���� ���� �������� �����
	if (!CheckFile(dlgOpen->FileName))
	{
		MessageBox::Show("���� �������� ������������ ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	List2 = LoadListFromFile(List2,dlgOpen->FileName);

	MatchTable(dataTable2, List2);
}

//������2 - �������
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



//�������
System::Void formMain::menu_task_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("\
�� ��������� ���� ��� ��������� �����. ����� ���� ������������� \
(������ ������� �� ����� ������� ���������, ������ � �� ����� �������) \
�����, ��� ������, ����������� ����� ����������� ����������, \
�������� ����������� ���� � ���� �������", "������� �35");
}



//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//		������� ������ ������1
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//��������
System::Void formMain::btnAdd1_Click(System::Object^  sender, System::EventArgs^  e)
{
	realpoint *point = CreatePointForm(); //������ ����� � ������� ��������
	if (point)
	{		
		pointlist *data = FormRecord(point); //�������� ������� ������ �� ������ �����
		List1 = AddRecordToList(data, List1); //��������� ��� � ������ ���������
		MatchTable(dataTable1,List1); //��������� �������
	}
}

//�������
System::Void formMain::btnDelete1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List1)
		return;

	int pos = dataTable1->CurrentRow->Index; //����� ������� ������� �������
	int num = Convert::ToInt32(dataTable1->CurrentRow->Cells[0]->Value); //����� � ���� ����� � ������

	System::Windows::Forms::DialogResult result;
	String^ message = String::Format("������� ����� #{0}?", num);
	result = MessageBox::Show(message, "�������������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if ( result == ::DialogResult::Yes )
	{
		dataTable1->Rows->Remove(dataTable1->Rows[pos]);
		List1 = RemoveRecord(num,List1);
	}
	delete message;
}

//��������
System::Void formMain::btnEdit1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List1)
		return;

	realpoint *newpoint = CreatePointForm(); //������� ������ ����� ����������
	if (newpoint)
	{		
		int pos = dataTable1->CurrentRow->Index; //������� ����� �� �������
		int num = Convert::ToInt32(dataTable1->CurrentRow->Cells[0]->Value); //� �� ������
		dataTable1->Rows->Remove(dataTable1->Rows[pos]);
		List1 = RemoveRecord(num,List1);
		pointlist *newdata = FormRecord(newpoint); //�������� �����
		List1 = AddRecordToList(newdata, List1); //��������� � � ������
		MatchTable(dataTable1,List1); //������
	}
}



//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//		������� ������ ������2
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//��������
System::Void formMain::btnAdd2_Click(System::Object^  sender, System::EventArgs^  e)
{
	realpoint *point = CreatePointForm(); //������ ����� � ������� ��������
	if (point)
	{		
		pointlist *data = FormRecord(point); //�������� ������� ������ �� ������ �����
		List2 = AddRecordToList(data, List2); //��������� ��� � ������ ���������
		MatchTable(dataTable2,List2); //��������� �������
	}
}

//�������
System::Void formMain::btnDelete2_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!List2)
		return;

	int pos = dataTable2->CurrentRow->Index; //����� ������� ������� �������
	int num = Convert::ToInt32(dataTable2->CurrentRow->Cells[0]->Value); //����� � ���� ����� � ������

	System::Windows::Forms::DialogResult result;
	String^ message = String::Format("������� ����� #{0}?", num);
	result = MessageBox::Show(message, "�������������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
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

	realpoint *newpoint = CreatePointForm(); //������� ������ ����� ����������
	if (newpoint)
	{		
		int pos = dataTable2->CurrentRow->Index; //������� ����� �� �������
		int num = Convert::ToInt32(dataTable2->CurrentRow->Cells[0]->Value); //� �� ������
		dataTable2->Rows->Remove(dataTable2->Rows[pos]);
		List2 = RemoveRecord(num,List2);
		pointlist *newdata = FormRecord(newpoint); //�������� �����
		List2 = AddRecordToList(newdata, List2); //��������� � � ������
		MatchTable(dataTable2,List2); //������
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
		MessageBox::Show(String::Format("�{0} X:{1:0.0##} Y:{2:0.0##}", ptr->id, ptr->point->x, ptr->point->y));
		ptr = ptr->next;
	}
}*/