#pragma once

#include <gcroot.h>


using namespace System;
using namespace System::Drawing;


//����� ������ � ����� ��� � ��� �������
class cEasel
{
public:
	int width; //������� ������
	int height;
	gcroot<Graphics^> canvas; //�����
	gcroot<Color> backcolor; //��� ����

	//�������������� ����� �� �����������
	cEasel(Windows::Forms::PictureBox^ pb);
	~cEasel();

	//������� �����, ������������ �����
	void Clear();

};

//������ ��������� �������
void SetPixel(Bitmap^ bm, int x, int y, Color clr);