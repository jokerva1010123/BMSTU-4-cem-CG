//
//		��������������� ����� ����������, ��� ��������� � ���������
//
#include "stdafx.h"

#include "alg_call.h"
#include "algorithms.h"
#include "ticker.h"
#include <math.h>


//�������� ����� ��� ���������
void SelectMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor, int method)
{
	//��������� ������ ��������� � ����� ���������
	x1 += Easel->width/2;
	x2 += Easel->width/2;
	y1 = -y1 + Easel->height/2;
	y2 = -y2 + Easel->height/2;

	//�������� ��������� �������� - ��� �������� � ������, � �� � ��������
	if (method == 0)
	{
		DrawDefault(Easel->canvas, x1,y1,x2,y2,maincolor);
		return;
	}


	Bitmap^ bm = gcnew Bitmap(Easel->width, Easel->height, Easel->canvas); //������� ������ ������� �������
	
	switch (method)
	{
		case 1: // ���
			{
				DrawCDA(bm,x1,y1,x2,y2,maincolor);
				break;
			}
		case 2: //��������� ��������������
			{
				DrawBrezenhem(bm,x1,y1,x2,y2,maincolor);
				break;
			}
		case 3: //��������� �������������
			{
				DrawBrezenhemInt(bm,x1,y1,x2,y2,maincolor);
				break;
			}
		case 4: //��������� ������������
			{
				DrawBrezenhemSoft(bm,x1,y1,x2,y2,maincolor,backcolor);
				//DrawBrezenhemSoft(bm,x2,y2-1,x1,y1-1,maincolor,backcolor);
				break;
			}
	}
	Easel->canvas->DrawImageUnscaled(bm,0,0); //��������������� ������������ ���� ���������� �������, �� �������, ������� �������
	delete bm;
}


//�������� ����� ��� ��������� �������
double CalcMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor, int method)
{
	//��������� ������ ��������� � ����� ���������
	x1 += Easel->width/2;
	x2 += Easel->width/2;
	y1 = -y1 + Easel->height/2;
	y2 = -y2 + Easel->height/2;
	
	Bitmap^ bm = gcnew Bitmap(Easel->width, Easel->height, Easel->canvas); //������� ������ ������� �������
	//������ ������������ ��� �� �����! ������ ������ �������� �������� ������!

	//clock_t start = clock(); //�������� �����
	FrequencyTimer *ticker = new FrequencyTimer(1000000); //������� ������ �� �������������
	ticker->Start();
	//System::Windows::Forms::MessageBox::Show(String::Format("{0}",start));
#define NMAX 10 //��� ������� ������������, �� ����� �������� ��������� ���
	switch (method)
	{
	case 0:
		{
			for (int i=0; i<NMAX; i++)
				DrawDefault(Easel->canvas, x1,y1,x2,y2,maincolor);
			break;
		}
	case 1: // ���
		{
			for (int i=0; i<NMAX; i++)
				DrawCDA(bm,x1,y1,x2,y2,maincolor);
			break;
		}
	case 2: //��������� ��������������
		{
			for (int i=0; i<NMAX; i++)
				DrawBrezenhem(bm,x1,y1,x2,y2,maincolor);
			break;
		}
	case 3: //��������� �������������
		{
			for (int i=0; i<NMAX; i++)
				DrawBrezenhemInt(bm,x1,y1,x2,y2,maincolor);
			break;
		}
	case 4: //��������� ������������
		{
			for (int i=0; i<NMAX; i++)
				DrawBrezenhemSoft(bm,x1,y1,x2,y2,maincolor,backcolor);
			break;
		}
	}
	/*clock_t end = clock();
	double res = end - start;
	res /= (NMAX * CLOCKS_PER_SEC);*/

	ticker->Stop(); //������������� ������
	double res = ticker->GetTime();
	res /= NMAX;
	delete ticker;
	return res;
}


//�������� ����� � ������������ ������ �������� �� �����
void SpectreMethod(canvasstruct *Easel, int x1, int y1, int angle, int radius, Color maincolor, Color backcolor, int method)
{
	//��������� ������ ��������� � ����� ���������
	x1 += Easel->width/2;
	y1 = -y1 + Easel->height/2;
	int x2=0,y2=0; //���������� ����� "����" �������

	//�������� ��������� �������� - ��� �������� � ������, � �� � ��������
	if (method == 0)
	{
		for (double i = 0; i<360; i += angle)
		{
			x2 = x1 + radius*cos(i/180*M_PI);
			y2 = y1 - radius*sin(i/180*M_PI);
			DrawDefault(Easel->canvas, x1,y1,x2,y2,maincolor);
		}
		return;
	}


	Bitmap^ bm = gcnew Bitmap(Easel->width, Easel->height, Easel->canvas); //������� ������ ������� �������

	for (double i = 0; i<360; i += angle)
	{
		x2 = x1 + radius*cos(i/180*M_PI);
		y2 = y1 - radius*sin(i/180*M_PI);

		switch (method)
		{
		case 1: // ���
			{
				DrawCDA(bm,x1,y1,x2,y2,maincolor);
				break;
			}
		case 2: //��������� ��������������
			{
				DrawBrezenhem(bm,x1,y1,x2,y2,maincolor);
				break;
			}
		case 3: //��������� �������������
			{
				DrawBrezenhemInt(bm,x1,y1,x2,y2,maincolor);
				break;
			}
		case 4: //��������� ������������
			{
				DrawBrezenhemSoft(bm,x1,y1,x2,y2,maincolor,backcolor);
				break;
			}
		}
	}
	Easel->canvas->DrawImageUnscaled(bm,0,0); //��������������� ������������ ���� ���������� �������, �� �������, ������� �������
	delete bm;
}