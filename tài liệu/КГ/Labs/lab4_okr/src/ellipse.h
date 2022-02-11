#pragma once

#include "paint.h"

namespace Ellipse
{
	using namespace System::Drawing;

	//�������� ����� ��� ���������
	void SelectMethod(cEasel *easel, int x, int y, int A, int B, Color maincolor, int method);

	//�������� ����� � ������������ ������ �������� �� �����
	void SpectreMethod(cEasel *easel, int x, int y, int delta, int num, int startA, int startB, Color maincolor, int method);

}