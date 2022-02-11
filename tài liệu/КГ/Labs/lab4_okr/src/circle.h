#pragma once

#include "paint.h"

namespace Circle
{
	using namespace System::Drawing;

	//�������� ����� ��� ���������
	void SelectMethod(cEasel *easel, int x, int y, int radius, Color maincolor, int method);

	//�������� ����� � ������������ ������ �������� �� �����
	void SpectreMethod(cEasel *easel, int x, int y, int delta, int num, int startR, Color maincolor, int method);

}