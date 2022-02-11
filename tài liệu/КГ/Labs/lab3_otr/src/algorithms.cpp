//
//		��������������� �������������� - ��� � ���������
//
#include "stdafx.h"

#include "algorithms.h"
#include "paint.h"
//#include <time.h>

//��������� ����������� �������
void DrawDefault(Graphics^ canvas, int x1, int y1, int x2, int y2, Color drawcolor)
{
	Pen^ drawpen = gcnew Pen(drawcolor,1);

	canvas->DrawLine(drawpen,x1,y1,x2,y2);

	delete drawpen;
}

//��������� ���
void DrawCDA(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor)
{
	/*
	������
	���� ��, ��, ��, ��
	�������� ������� �� �������������: ���� ����������� �� ��������� ����� � ������� �� �����
	x_���=x_�,   y_���=y_�
	dx=x_k-x_n,dy=y_k-y_n
	���� |dx|>|dy|, �� l=|dx| ����� l=|dy|
	dx=dx/l,dy=dy/l
	���������� ������� (���� �� i=1 �� l+1)
		������������ ����� E(xt),E(yt)
		���������� ��������� ��������� ����� x_�������=x_���+dx,y_���=y_���+dy
	�����
	*/

	//���� ������� �����������, �� ������������ ������ ���� �����
	if (x2 == x1 && y2 == y1)
	{
		//������������ ������ ������� ������ ������� �������
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		double xt=(double)x1, yt=(double)y1; //������� ����������
		double dx=x2-x1, dy=y2-y1; //���������� ���������
		int l=MAX(ABS(dx), ABS(dy)); //���������� "��������"
		dx /= l; dy /= l;
		for (int i=1; i<=l+1; i++)
		{
			//������������ ������ ������� ������ ������� �������
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
				bm->SetPixel((int)(xt+0.5), (int)(yt+0.5), drawcolor);
			xt += dx; yt += dy;
		}
	}

}

//��������� �����������
void DrawBrezenhem(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor)
{
	/*
	������
	���� ��, ��, ��, ��
	�������� ������� �� �������������: ���� ����������� �� ��������� ����� ��,�� � ������� �� �����
	x_���=x_�,   y_���=y_�
	dx=x_k-x_n,dy=y_k-y_n
	Sx=sign(dx), sy=sign(dy)
	Dx=|dx|, dy=|dy|
	���� dx>dy �� �����=0, ����� �����=1 {t=dy; dy=dx; dx=t}
	m=dy/dx. //������� ���� �������
	���� ���������� ������� (�� i=1 to dx+1)
		������������ ����� (xt,yt)
		���� (e>=0) {
			���� (�����=0) {yt=yt+sy}
			����� {xt=xt+sx};
			e=e-1
		}
		����� {
			���� (�����=0) {xt=xt+sx}
			����� {�t=�t+sy};
			e=e+m
		}
	�����
	*/

	//���� ������� �����������, �� ������������ ������ ���� �����
	if (x2 == x1 && y2 == y1)
	{
		//������������ ������ ������� ������ ������� �������
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		int dx=x2-x1, dy=y2-y1; //���������� ���������
		int sx = SIGN(dx), sy = SIGN(dy); //��� �� X � �� Y
		dx = ABS(dx); dy = ABS(dy); //������������ ����������
		//System::Windows::Forms::MessageBox::Show(String::Format("{0}",sx));
		double m = (double)dy/dx; //������� ���� ������� //(����) ����������!! ����� �� �������� (���)��/(���)�� =0 ��� ��<��!!

		bool swap; //���� ������
		if (m <= 1)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
			m = 1/m;
		}

		double e = m-0.5; //������
		int xt=x1, yt=y1; //������� ����������

		//� ����� ����������� ������
		for (int i=1; i<=dx+1; i++)
		{
			//������������ ������ ������� ������ ������� �������
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
				bm->SetPixel(xt,yt,drawcolor);

			if (e>=0)
			{
				if (swap)
					xt += sx;
				else
				{
					yt += sy;
				}
				e = e-1;
			}
			if (e<0)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
			}
			e = e+m;
			
		}
	}
}

//��������� ����� �����������
void DrawBrezenhemInt(Bitmap^ bm, int x1, int y1, int x2, int y2, Color drawcolor)
{
	//���� ������� �����������, �� ������������ ������ ���� �����
	if (x2 == x1 && y2 == y1)
	{
		//������������ ������ ������� ������ ������� �������
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		int dx=x2-x1, dy=y2-y1; //���������� ���������
		int sx = SIGN(dx), sy = SIGN(dy); //��� �� X � �� Y
		dx = ABS(dx); dy = ABS(dy); //������������ ����������
		
		bool swap; //���� ������
		if (dy <= dx)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
		}

		int _E = 2*dy - dx; //������
		int xt=x1, yt=y1; //������� ����������

		//� ����� ����������� ������
		for (int i=1; i<=dx+1; i++)
		{
			//������������ ������ ������� ������ ������� �������
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
			{
				bm->SetPixel(xt,yt,drawcolor);
			}
			
			if (_E>=0)
			{
				if (swap)
					xt += sx;
				else
				{
					yt += sy;
				}
				_E = _E - 2*dx;
			}
			if (_E<0)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
			}
			_E = _E + 2*dy;			
		}
	}
}

//��������� ����������� �� ������������
void DrawBrezenhemSoft(Bitmap^ bm, int x1, int y1, int x2, int y2, Color maincolor, Color backcolor)
{
	/*
	1.���� �������� ������ X�,Y�,X�,Y� (���������� ������ �������), I - ���������� ������� �������������.
	2.�������� ������������� �������. ���� ������� ��������, �� ������������ ���������� ������� � ������� � �.13.
	3.���������� ���������� dX=X�-X� � dY=Y�-Y�.
	4.���������� ���� ��������� ������ ����������: SX=sign(dX),  SY=sign(dY).
	5.���������� ������� ���������� ���������: dX=!dX!,    dY=!dY!.
	6.���������� ������ �������� ���� ������� m=dY/dX.
	7.������ ������������ �������� m � ����� ������� dX � dY ��� m>1:
	���� m>1, �� ���������
		p=dX;	dX=dY;   dY=p; m=1/m; fl=1;
	���� m<1, ��
		fl=0.
	8.������������� ���������� �������� ������ f=I/2.
	9.������������� ��������� �������� ��������� �������� �������:
	X=X�,   Y=Y�.
	10.���������� ������������������ �������� �������� ���� ������� m=mI � ������������ W=I-m.
	11.������������ �������	� ������������ (X,Y) �������������� E(f).
	12.���� �� i=1 �� i=dX � ����� 1:
		���� f<W, ��
			���� fl=0, ��
				X=X+SX;
			���� fl=1, ��
				Y=Y+SY;
		f=f+m.
		���� f>W, �� X=X+SX, Y=Y+SY, f=f-W.
		������������ ������� � ������������ (X,Y) �������������� E(f).
	13.�����.

	*/
	if (x2 == x1 && y2 == y1)
	{
		//������������ ������ ������� ������ ������� �������
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,maincolor);
	}
	else
	{
		int dx=x2-x1, dy=y2-y1; //���������� ���������
		int sx = SIGN(dx), sy = SIGN(dy); //��� �� X � �� Y
		dx = ABS(dx); dy = ABS(dy); //������������ ����������
		//System::Windows::Forms::MessageBox::Show(String::Format("{0}",sx));
		double m = (double)dy/dx; //������� ���� �������
		bool swap; //���� ������
		if (m <= 1)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
			m = 1/m;
		}
#define I 256 //���������� ������� �������������
		double e = I/2; //������
		int xt=x1, yt=y1; //������� ����������
		m *= I; //������������ �������
		double W = I - m; //�����������

		//� ����� ����������� ������
		for (int i=1; i<=dx; i++)
		{
			int r,g,b; //���-������������ ����� ��� ��������
			double C = e/I;
			//if (C>0.5) C = 0.5; //������������ "������������", ����� ��������������� �� � ���������� ����, � ������ � ������� ����
			r = maincolor.R + C*(backcolor.R - maincolor.R);
			g = maincolor.G + C*(backcolor.G - maincolor.G);
			b = maincolor.B + C*(backcolor.B - maincolor.B);
			Color drawcolor = Color::FromArgb(255,r,g,b);
			//������������ ������ ������� ������ ������� �������
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
			{
				bm->SetPixel(xt,yt,drawcolor);
			}

			if (e <= W)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
				e = e+m;
			}
			else
			{
				xt += sx;
				yt += sy;
				e = e-W;
			}
		}
	}
}