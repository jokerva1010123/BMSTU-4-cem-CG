//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "TickCntr.h"
#include <Math.hpp>
#include <math.h>
#include "Gradient.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformAlg�ircle *formAlg�ircle;
//---------------------------------------------------------------------------
__fastcall TformAlg�ircle::TformAlg�ircle(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
#define drawpixel(X,Y) Image1->Canvas->Pixels[(X)][(Y)] = Image1->Canvas->Pen->Color

void TformAlg�ircle::CanonEllipse(int XC, int YC,
									int A, int B, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	// ����������� ������: ���� ��� ��� �� ���� ������� �����
	if (A==0 || B==0)
	{
		Image1->Canvas->MoveTo(XC-A, YC-B);
		if (A==0)
			Image1->Canvas->LineTo(XC, YC+B+1);
		else
			Image1->Canvas->LineTo(XC+A+1, YC);
	}
	else
	{

		int X=XC, _X=XC;
		int Y=YC+B, _Y=YC-B;
		int X0X=XC+int(double(A)*A/sqrt((double)A*A+(double)B*B)-1e-7);

		while (X<=X0X)
		{
			Image1->Canvas->Pixels[X][Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[_X][Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[X][_Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[_X][_Y] = Image1->Canvas->Pen->Color;
			X++;
			_X--;
			Y = YC+int((double)B/A*sqrt(A*A-(X-XC)*(X-XC))+0.5);
			_Y = 2*YC-Y;
		}


		while (Y>YC)
		{
			Image1->Canvas->Pixels[X][Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[_X][Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[X][_Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[_X][_Y] = Image1->Canvas->Pen->Color;
			Y--;
			_Y++;
			X = XC+int((double)A/B*sqrt(B*B-(Y-YC)*(Y-YC))+0.5);
			_X = 2*XC-X;
		}

		Image1->Canvas->Pixels[X][Y] = Image1->Canvas->Pen->Color;
		Image1->Canvas->Pixels[_X][Y] = Image1->Canvas->Pen->Color;
	}


	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ������ �� ����� "+IntToStr((__int64)t));
	}
}

void TformAlg�ircle::ParamEllipse(int XC, int YC,
									int A, int B, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	if (A==0 || B==0)
	{
		Image1->Canvas->MoveTo(XC-A, YC-B);
		if (A==0)
			Image1->Canvas->LineTo(XC, YC+B+1);
		else
			Image1->Canvas->LineTo(XC+A+1, YC);
	}
	else
	{
		double fi=0;
		double dfi=2.0*Min(double(A)/B,double(B)/A)
		/(3.0*(A+B)-sqrt((3.0*A+B)*(3.0*B+A)));
							// �������� ������� ����������� ��� ����� �������
		int X, Y, _X, _Y;

		while (fi<M_PI_2+dfi/4)
		{
			X = int(A*cos(fi)+0.5);
			Y = int(B*sin(fi)+0.5);
			Image1->Canvas->Pixels[XC+X][YC+Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[XC-X][YC+Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[XC+X][YC-Y] = Image1->Canvas->Pen->Color;
			Image1->Canvas->Pixels[XC-X][YC-Y] = Image1->Canvas->Pen->Color;
			fi += dfi;
		}
	}

	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ������ �� ����� "+IntToStr((__int64)t));
	}
}

void TformAlg�ircle::MidPtEllipse(int XC, int YC,
									int A, int B, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	if (A==0 || B==0)
	{
		Image1->Canvas->MoveTo(XC-A, YC-B);
		if (A==0)
			Image1->Canvas->LineTo(XC, YC+B+1);
		else
			Image1->Canvas->LineTo(XC+A+1, YC);
	}
	else
	{

		int x=0;
		int y=B;
		int A_2 = A*A, B_2 = B*B;

		int xBord = int(double(A_2)/sqrt(double(A_2)+double(B_2))+0.5-1e-7);

		int error = 4*B*(B-A_2)+A_2;

		while (x<=xBord)
		{
			drawpixel(XC+x, YC+y);
			drawpixel(XC+x, YC-y);
			drawpixel(XC-x, YC+y);
			drawpixel(XC-x, YC-y);

			if (error<=0)
			{
				error += B_2*(x++*8 + 4);
			}
			if (error>0)
			{
				error -= A_2*(y-- - 1)*8;
			}
		}

		error = B_2*(4*(x*(x+1)-A_2)+1)+4*A_2*y*y;

		while (y>=0)
		{
			drawpixel(XC+x, YC+y);
			drawpixel(XC+x, YC-y);
			drawpixel(XC-x, YC+y);
			drawpixel(XC-x, YC-y);

			if (error>0)
			{
				error -= A_2*(y--*8 - 4);
			}
			if (error<=0)
			{
				error += B_2*(x++ + 1)*8;
			}
        }
	}

	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ������ �� ����� "+IntToStr((__int64)t));
	}

}

void TformAlg�ircle::BresenhamEllipse(int XC, int YC,
									int A, int B, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	int x = 0;
	int y = B;
	int A_2 = A*A;
	int B_2 = B*B;
	int A_B_2 = A_2+B_2;

	int delta = B_2 - A_2*2*B;
	int error;
	while (y >= 0)
	{
		drawpixel(XC + x, YC + y);
		drawpixel(XC + x, YC - y);
		drawpixel(XC - x, YC + y);
		drawpixel(XC - x, YC - y);

		error = 2 * (delta + A_2*y) - A_2;
		if ((delta < 0) && (error <= 0))
		{
			delta += B_2*(2*++x + 1);
			continue;
		}

		error = 2 * (delta - B_2*x) - B_2;
		if ((delta > 0) && (error > 0))
		{
			delta += A_2*(1 - 2*--y);
			continue;
		}

		delta += 2 * (++x*B_2 - --y*A_2) + A_B_2;
	}

	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ���������� �� ����� "+IntToStr((__int64)t));
	}

}

void TformAlg�ircle::StdEllipse(int XC, int YC,
									int A, int B, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	Image1->Canvas->Ellipse(XC-A, YC-B, XC+A+1, YC+B+1);

	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ������ �� ����� "+IntToStr((__int64)t));
	}
}

void TformAlg�ircle::CanonCircle(int XC, int YC, int R, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}


	// ����������� ������: ���� ��� ��� �� ���� ������� �����
	if (R==0)
	{
		Image1->Canvas->Pixels[XC][YC] = Image1->Canvas->Pen->Color;
	}
	else
	{

		int X=0;
		int Y=R;
		int X0X=int(R*sqrt(0.5)+0.5);

		//ShowMessage("�������� ������, X0X="+IntToStr(X0X));

		while (X<=X0X)
		{

			drawpixel(XC+X, YC+Y);
			drawpixel(XC-X, YC+Y);
			drawpixel(XC+X, YC-Y);
			drawpixel(XC-X, YC-Y);
			drawpixel(XC+Y, YC+X);
			drawpixel(XC-Y, YC+X);
			drawpixel(XC+Y, YC-X);
			drawpixel(XC-Y, YC-X);
			X++;
			Y = int(sqrt(R*R-X*X)+0.5);
		}
	}


	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ���������� �� ����� "+IntToStr((__int64)t));
	}
}

void TformAlg�ircle::ParamCircle(int XC, int YC, int R, bool DoLaunchTimer)
{
    unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	//ShowMessage("�������� ���������");

	if (R==0)
	{
		Image1->Canvas->Pixels[XC][YC] = Image1->Canvas->Pen->Color;
	}
	else
	{
		double fi=0;
		double dfi=1.0/R;
		int X, Y;

		while (fi<M_PI_4+dfi/4)
		{
			X = int(R*cos(fi)+0.5);
			Y = int(R*sin(fi)+0.5);
            drawpixel(XC+X, YC+Y);
			drawpixel(XC-X, YC+Y);
			drawpixel(XC+X, YC-Y);
			drawpixel(XC-X, YC-Y);
			drawpixel(XC+Y, YC+X);
			drawpixel(XC-Y, YC+X);
			drawpixel(XC+Y, YC-X);
			drawpixel(XC-Y, YC-X);
			fi += dfi;
		}

	}
	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ���������� �� ����� "+IntToStr((__int64)t));
	}
}

void TformAlg�ircle::MidPtCircle(int XC, int YC, int R, bool DoLaunchTimer)
{

	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	if (R==0)
	{
		drawpixel(XC,YC);
	}
	else
	{
		int x=0;
		int y=R;
		int xBord = int(R*sqrt(0.5)+0.5);

		int error = (1-4*R);

		while (x<=xBord)
		{
			drawpixel(XC+x, YC+y);
			drawpixel(XC+x, YC-y);
			drawpixel(XC-x, YC+y);
			drawpixel(XC-x, YC-y);
			drawpixel(XC+y, YC+x);
			drawpixel(XC+y, YC-x);
			drawpixel(XC-y, YC+x);
			drawpixel(XC-y, YC-x);

			if (error<=0)
			{
				error += (x++*8 +4);
			}
			if (error>0)
			{
				error -= (y-- -1)*8;
		    }
		}
	}

	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ���������� �� ����� "+IntToStr((__int64)t));
	}

}

void TformAlg�ircle::BresenhamCircle(int XC, int YC, int R, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	int x = 0;
	int y = R;
	int delta = 1 - 2 * R;
	int error;
	while (y >= 0)
	{
		drawpixel(XC + x, YC + y);
		drawpixel(XC + x, YC - y);
		drawpixel(XC - x, YC + y);
		drawpixel(XC - x, YC - y);

		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
		{
			delta += (2 * ++x + 1);
			continue;
		}

		error = 2 * (delta - x) - 1;
		if ((delta > 0) && (error > 0))
		{
			delta += (1 - 2 * --y);
			continue;
		}

		delta += 2 * (++x - --y + 1);
	}

	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ���������� �� ����� "+IntToStr((__int64)t));
	}

}

void TformAlg�ircle::StdCircle(int XC, int YC, int R, bool DoLaunchTimer)
{
	unsigned __int64 t;

	if (DoLaunchTimer)
	{
		t = tick();
	}

	Image1->Canvas->Ellipse(XC-R, YC-R, XC+R+1, YC+R+1);

	if (DoLaunchTimer)
	{
		t = tick()-t;
		ShowMessage("�������� ���������� �� ����� "+IntToStr((__int64)t));
	}
}

//----------------------------------------------------------------------------

void __fastcall TformAlg�ircle::btnDrawEllipseClick(TObject *Sender)
{
	unsigned __int64 t;

	int XC, YC, A, B;

	XC = StrToInt(edtXC->Text);
	YC = StrToInt(edtYC->Text);
	A = StrToInt(edtXAxis->Text);
	if (!chbEqAxis->Checked)
	{
		B = StrToInt(edtYAxis->Text);
	}

	if (!chbEqAxis->Checked)
	{
		switch (rgrChooseAlg->ItemIndex)
		{
			case 4:  // ����������� ��������
				StdEllipse(XC, YC, A, B, chbSetTimer->Checked);
				break;
			case 0:  // �������� ���������� ������������� ���������
				CanonEllipse(XC, YC, A, B, chbSetTimer->Checked);
				break;
			case 1:  // �������� ���������� ���������������� ����������
				ParamEllipse(XC, YC, A, B, chbSetTimer->Checked);
				break;
			case 2:   // �������� ������� �����
				MidPtEllipse(XC, YC, A, B, chbSetTimer->Checked);
				break;
			case 3:   // �������� ����������
				BresenhamEllipse(XC, YC, A, B, chbSetTimer->Checked);
				break;
		}
	}
	else
	{
        switch (rgrChooseAlg->ItemIndex)
		{
			case 4:  // ����������� ��������
				StdCircle(XC, YC, A, chbSetTimer->Checked);
				break;
			case 0:  // �������� ���������� ������������� ���������
				CanonCircle(XC, YC, A, chbSetTimer->Checked);
				break;
			case 1:  // �������� ���������� ���������������� ����������
				ParamCircle(XC, YC, A, chbSetTimer->Checked);
				break;
			case 2:   // �������� ������� �����
				MidPtCircle(XC, YC, A, chbSetTimer->Checked);
				break;
			case 3:   // �������� ����������
				BresenhamCircle(XC, YC, A, chbSetTimer->Checked);
				break;
		}
    }

}
//---------------------------------------------------------------------------
void __fastcall TformAlg�ircle::FormCreate(TObject *Sender)
{
	Image1->Canvas->Pen->Width = 1;
	Image1->Canvas->Brush->Style = bsSolid;
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->Rectangle(-2,-2,Image1->Width+1, Image1->Height+1);
	Image1->Canvas->Brush->Style = bsClear;
}
//---------------------------------------------------------------------------
void __fastcall TformAlg�ircle::btnClearCanvasClick(TObject *Sender)
{
	Image1->Canvas->Brush->Style = bsSolid;
	Image1->Canvas->Rectangle(-2,-2,Image1->Width+1, Image1->Height+1);
	Image1->Canvas->Brush->Style = bsClear;
}
//---------------------------------------------------------------------------
void __fastcall TformAlg�ircle::btnBuildSunClick(TObject *Sender)
{
	int step = StrToInt(edtAngleStep->Text);
	int dA = StrToInt(edtRSun->Text);
	int A = StrToInt(edtXSun->Text);

	int B;
	if (!chbEqAxis->Checked)
	{
		B = StrToInt(edtYSun->Text);
	}


	const int XC = Image1->Width>>1;
	const int YC = Image1->Height>>1;

	if (chbEqAxis->Checked)
	{
		do
		{
			switch (rgrChooseAlg->ItemIndex)
			{
				case 4:  // ����������� ��������
					StdCircle(XC, YC, A, false);
					break;
				case 0:  // �������� ���������� ������������� ���������
					CanonCircle(XC, YC, A, false);
					break;
				case 1:  // �������� ���������� ���������������� ����������
					ParamCircle(XC, YC, A, false);
					break;
				case 2:   // �������� ������� �����
					MidPtCircle(XC, YC, A, false);
					break;
				case 3:   // �������� ����������
					BresenhamCircle(XC, YC, A, false);
					break;
			}
			A-=dA;
			step--;
		}
		while (A>=0 && step);
	}
	else
		do
		{
			switch (rgrChooseAlg->ItemIndex)
			{
				case 4:  // ����������� ��������
					StdEllipse(XC, YC, A, B, false);
					break;
				case 0:  // �������� ���������� ������������� ���������
					CanonEllipse(XC, YC, A, B, false);
					break;
				case 1:  // �������� ���������� ���������������� ����������
					ParamEllipse(XC, YC, A, B, false);
					break;
				case 2:   // �������� ������� �����
					MidPtEllipse(XC, YC, A, B, false);
					break;
				case 3:   // �������� ����������
					BresenhamEllipse(XC, YC, A, B, false);
					break;
			}
			A -= dA;
			B = B*A/(A+dA);
			step--;
		}
		while (A>=0 && step);

}
//---------------------------------------------------------------------------
void __fastcall TformAlg�ircle::clbBgndColorChange(TObject *Sender)
{
	Image1->Canvas->Brush->Color = clbBgndColor->Selected;
}
//---------------------------------------------------------------------------
void __fastcall TformAlg�ircle::clbLineColorChange(TObject *Sender)
{
	Image1->Canvas->Pen->Color = clbLineColor->Selected;
}
//---------------------------------------------------------------------------
void __fastcall TformAlg�ircle::edtXAxisChange(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

void __fastcall TformAlg�ircle::edtYAxisChange(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

void __fastcall TformAlg�ircle::chbEqAxisClick(TObject *Sender)
{
	edtYAxis->Enabled = !chbEqAxis->Checked;
    edtYSun->Enabled = !chbEqAxis->Checked;
}
//---------------------------------------------------------------------------

