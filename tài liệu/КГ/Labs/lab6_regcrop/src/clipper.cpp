//
//		��������� ������� ���������������
//
#include "stdafx.h"

#include "geometry.h"
#include "clipper.h"
#include <math.h>

//���������� true, ���� ����� ������
bool CheckPoint(sPoint &pt, cRect *r)
{
	if (pt.x < r->left() || pt.x > r->right())
		return false;
	if (pt.y < r->up() || pt.y > r->down())
		return false;
	return true;
}

//���������� true ���� ������� �������������� �������
bool IsInvis(sPoint &A, sPoint &B, cRect *r)
{
	if (A.y < r->up()  &&  B.y < r->up()) //����
		return true;
	if (A.y > r->down()  &&  B.y > r->down()) //����
		return true;
	if (A.x < r->left()  &&  B.x < r->left()) //�����
		return true;
	if (A.x > r->right()  &&  B.x > r->right()) //������
		return true;
	return false;
}

//��������� "���� ���������" �����
char PointCode(sPoint &pt, cRect *r)
{
	char code = 0;				//==������� - ������
	if (pt.y < r->up())			//����
		code = code | 0x0008;	//	1000
	if (pt.y > r->down())		//����
		code = code | 0x0004;	//	0100
	if (pt.x > r->right())		//������
		code = code | 0x0002;	//	0010
	if (pt.x < r->left())		//�����
		code = code | 0x0001;	//	0001
	return code;
}

inline double sqr(double x)
{
	return x*x;
}
//���������� ���������� ����� �������
double Dist(sPoint &A, sPoint &B)
{
	return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

//��������� ������� �� �������������� ������� ������� �����
sLine* ClipMiddle(sLine &line, cRect *rect)
{	
//	static double EPS  =  1.0;
#define EPS 0.1
	/*
	1. ���� �������� ������ ��, ���, ��, ��, �1, �2
	2. ���������� ����� ������ �������, �1 � �2
	3. ���������� ���� ����� ������ �1 � �2
	4. �������� ������� �� ������ ���������, �1=0 � �2=0; ���� ������� - ����������� � �����������
	5. ���� �� ���������������� - �������� �� �����������; ���� ��������� - �����������
	���� �� �������� ������� - �����-�������
	6. ����������� �1 (�=�1)
	7. ���������� ����� ������� ����� ����������� i=1
	8. ���� i>2, �� ����������� ���������� ������� �� ����������� (������������ ����� ������, ���� ����� ���� - �� �����)
		9. ���� S2=0, ��
				Res[i] = P2;
				i+=1
				�1 = P2; P2 = T
		10. ���� S2 != 0 , �� ������ ����� �����������:
			10.1. ���� |P1-P2|>E ��
				sPoint P_mid = (�1+�2)/2
				sPoint P_t = P1
				P1 = �_mid
				����������� ����������� �1�2, �������������� ��������� ��� �1
				���� �1�2 �������, ��
					�1 = P_t (������� �1 �� ������� �����)
					P2 = �_mid
				(����� ������ ������������ � �1�2)
			�����, ���� �� |P1-P2|<=E, ��
				if (pointsNum == 1)
					res->A = P2;
				else
					res->B = P2;
				P1 = P2
				P2 = T
				pointsNum += 1
			������� � 8.
	*/


	//���� ������� �������������� ���������, �� ���������� �� ����
	if (IsInvis(line.A, line.B, rect))
		return nullptr;

	sLine *res;
	sPoint P1 = line.A, P2 = line.B;

	res = new sLine;
	//���� ������� �������������� �������, �� ���������� ���
	//if (CheckPoint(P1, rect) && CheckPoint(P2, rect))
	if (!PointCode(P1, rect) && !PointCode(P1, rect))
	{
		res->A = P1;
		res->B = P2;
		return res;
	}

	sPoint T = P1; //�����
	int pointsNum = 1; //����� ��������������� �����
	while (pointsNum < 3/* && P1 != P2*/)
	{
		if (PointCode(P2, rect) == 0) //���� ����� �2 ��������� ������ ���������, �� ���������� �
		{
			if (pointsNum == 1)
				res->A = P2;
			else
				res->B = P2;
			pointsNum += 1;
			P1 = P2;
			P2 = T;
		}
		else //���� �� ���������, �� ���� ����� �����������
		{
			if (Dist(P1,P2) > EPS) //�� ������� � �����, ����� ���������� ���������� �������
			{
				sPoint P_mid = (P1+P2)/2; //������� �����
				sPoint P_t = P1; //��� ���� �����
				P1 = P_mid;
				if (IsInvis(P1, P2, rect))
				{
					P1 = P_t;
					P2 = P_mid;
				}
			}
			else //������� - ������� ����� � ���������
			{
				if (pointsNum == 1)
					res->A = P2;
				else
					res->B = P2;
				P1 = P2;
				P2 = T;
				pointsNum += 1;
			}
		}
	}
	return res;
}