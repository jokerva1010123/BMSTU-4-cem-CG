//
//		��������� ��������� �������
//

#include "stdafx.h"

#include "ellipse.h"
#include <math.h>

namespace Ellipse
{
	//			��������� ���������

	//��������� ����������� �������
	void DrawDefault(Graphics ^canvas, int cx, int cy, int A, int B, Color drawcolor)
	{
		Pen^ drawpen = gcnew Pen(drawcolor, 1); //������ �������
		Rectangle rect = Rectangle(cx-A, cy-B, A*2, B*2); //��������� �������������

		canvas->DrawEllipse(drawpen,rect);

		delete rect;
		delete drawpen;
	}

	//��������� ������� ������
	void DrawMid(Bitmap^ bm, int cx, int cy, int A, int B, Color drawcolor)
	{
		//B2 x2  +  A2 y2  -  A2 B2
		//������ ������: �, �-0.5
		//������ ������: �+0.5, �-0.5

		//DEBUGPRINT("��������, �������");
		int xt = 0;
		int yt = B;
	}

	//��������� ��������������� ����������
	void DrawParam(Bitmap^ bm, int cx, int cy, int A, int B, Color drawcolor)
	{
		const double M = MAX(A,B);
		const int L = (int) (M_PI*M/2 + 0.5); //����� �������� ����������
		int x,y;
		for (int t = 0; t <= L; t ++)
		{
			x = (int) (A*cos(t/M) + 0.5);
			y = (int) (B*sin(t/M) + 0.5);
			//������������ ������ ������������ �������
			SetPixel(bm, cx+x, cy+y, drawcolor);
			SetPixel(bm, cx+x, cy-y, drawcolor);
			SetPixel(bm, cx-x, cy+y, drawcolor);
			SetPixel(bm, cx-x, cy-y, drawcolor);
		}
	}

	//��������� ������������ ����������
	void DrawCanon(Bitmap^ bm, int cx, int cy, int A, int B, Color drawcolor)
	{
		const double dA = (double) A; //����� 1 / 2 ���� 0.5 � �� 0
		for (int x = 0; x <= A; x++)
		{
			int y = (int) (B * sqrt(1.0 - x*x/dA/dA) + 0.5);
			//������������ ������ ������������ �������
			SetPixel(bm, cx+x, cy+y, drawcolor);
			SetPixel(bm, cx+x, cy-y, drawcolor);
			SetPixel(bm, cx-x, cy+y, drawcolor);
			SetPixel(bm, cx-x, cy-y, drawcolor);
		}
	}

	//��������� �����������
	void DrawBrezenhem(Bitmap^ bm, int cx, int cy, int A, int B, Color drawcolor)
	{/*
		int X=0, Y=B;
		A = A * A;
		int d = (int) (B*B/2 - A*B*2 + A/2 + 0.5);
		B = B * B;
		double Beta;
		do
		{
			//������������ ������ ������������ �������
			SetPixel(bm, cx+X, cy+Y, drawcolor);
			SetPixel(bm, cx+X, cy-Y, drawcolor);
			SetPixel(bm, cx-X, cy+Y, drawcolor);
			SetPixel(bm, cx-X, cy-Y, drawcolor);
			if (Y <= 0)
				break;
			
			if (d < 0)
			{
				Beta = 2*d + 2*A*Y - A;
				if (Beta <= 0)
				{
					X += 1;
					d = d + 2*B*X + B;
				}
				else
				{
					X += 1;
					Y -= 1;
					d = d + 2*B*X - 2*A*Y + A + B;
				}
				continue;
			}

			if (d > 0)
			{
				Beta = 2*d - 2*B*X - B;
				if (Beta > 0)
				{
					Y = Y - 1;
					d = d - 2 * A * Y + A;
				}
				else
				{
					X = X + 1;
					Y = Y - 1;
					d = d + 2 * B * X - 2 * A * Y + A + B;
				}
				continue;
			}
			
			X = X + 1;
			Y = Y - 1;
			d = d + 2 * B * X - 2 * A * Y + A + B;
		}
		while (true);*/
		DEBUGPRINT("�������������� ����");
	}
	

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//			����� ���������

	
	//	������� ���������
	void SelectMethod(cEasel *easel, int x, int y, int A, int B, Color maincolor, int method)
	{
		//��������� ������ ��������� � ����� ���������
		x += easel->width/2;
		y = -y + easel->height/2;

		//�������� ��������� �������� - ��� �������� � ������, � �� � ��������
		if (method == 0)
		{
			DrawDefault(easel->canvas, x,y, A,B, maincolor);
			return;
		}

		Bitmap^ bm = gcnew Bitmap(easel->width, easel->height, easel->canvas); //������� ������ ������� �������

		switch (method)
		{
		case 1: //������� �����
			{
				DrawMid(bm, x,y, A, B, maincolor);
				break;
			}
		case 2: //������������ ���������
			{
				DrawCanon(bm, x,y, A, B, maincolor);
				break;
			}
		case 3: //��������������� ���������
			{
				DrawParam(bm, x,y, A, B, maincolor);
				break;
			}
		case 4: //���������
			{
				DrawBrezenhem(bm, x,y, A, B, maincolor);
				break;
			}
		}
		easel->canvas->DrawImageUnscaled(bm,0,0); //��������������� ������������ ���� ���������� �������, �� �������, ������� �������
		delete bm;
	}


	//	��������� �������
	void SpectreMethod(cEasel *easel, int x, int y, int delta, int num, int startA, int startB, Color maincolor, int method)
	{
		//��������� ������ ��������� � ����� ���������
		x = x + easel->width/2;
		y = -y + easel->height/2;

		//�������� ��������� �������� - ��� �������� � ������, � �� � ��������
		if (method == 0)
		{
			for (int i = 0; i<num; i++)
			{
				DrawDefault(easel->canvas, x,y, startA + i*delta, startB + i*delta, maincolor);
			}
			return;
		}

		Bitmap^ bm = gcnew Bitmap(easel->width, easel->height, easel->canvas); //������� ������ ������� �������

		for (int i = 0; i<num; i++)
		{
			//x2 = x1 + radius*cos(i/180*M_PI);
			//y2 = y1 - radius*sin(i/180*M_PI);

			switch (method)
			{
			case 1: //������� �����
				{
					DrawMid(bm, x,y, startA + i*delta, startB + i*delta, maincolor);
					break;
				}
			case 2: //������������ ���������
				{
					DrawCanon(bm, x,y, startA + i*delta, startB + i*delta, maincolor);
					break;
				}
			case 3: //��������������� ���������
				{
					DrawParam(bm, x,y, startA + i*delta, startB + i*delta, maincolor);
					break;
				}
			case 4: //���������
				{
					(bm, x,y, startA + i*delta, startB + i*delta, maincolor);
					break;
				}
			}
		}
		easel->canvas->DrawImageUnscaled(bm,0,0); //��������������� ������������ ���� ���������� �������, �� �������, ������� �������
		delete bm;
	}
}