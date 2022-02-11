//
//
//
#pragma once

#include "geometry.h"
#include "paint.h"
#include "clipper.h"
#include <vector>


typedef gcroot<DataGridView^> tGrid;


//��������
class cEditor
{
	cEasel *easel;		//�����
	tGrid grid;			//������� � ���������
	tColor clrClip;		//���� ����������
	tColor clrLine;		//���� �������
	tColor clrResult;	//���� ����������

public:
	std::vector<sLine> lines;	//������ ��������
	int linesNum;
	cRect *clip; //����������
	
	cEditor(PictureBox^ pb, DataGridView^ dgv)
	{
		easel = new cEasel(pb);
		grid = dgv;
		clrClip = Color::Blue;
		clrLine = Color::Black;
		clrResult = Color::Red;
		clip = nullptr;
		linesNum = 0;
	}
	~cEditor()
	{
		if (clip)
			delete clip;
		if (easel)
			delete easel;
		lines.clear();
	}



	//���������� ����������
	void Redraw()
	{
		easel->Clear();
		if (clip)
			easel->DrawRectangle(clip, clrClip);
		
		/*std::vector<sLine>::iterator i;
		for (i = lines.begin(); i != lines.end(); ++i)
		{
			easel->DrawLine(&(*i), clrLine);
		}*/
		for (unsigned i=0; i<lines.size(); i++)
		{
			float w = (i == grid->CurrentRow->Index) ? 2.0f : 1.0f;
			easel->DrawLine(&lines[i], clrLine, w);
		}
	}

	//�������� �����
	void Refresh(Color b, Color c, Color l, Color r)
	{
		easel->backcolor = b;
		clrClip = c;
		clrLine = l;
		clrResult = r;

		Redraw();
	}



	void AddLine(int x1, int y1, int x2, int y2)
	{
		sLine l(x1,y1, x2,y2);
		lines.push_back(l);
		linesNum++;
		grid->Rows->Add(Convert::ToString(x1), Convert::ToString(y1), Convert::ToString(x2), Convert::ToString(y2));
	}
	void RemoveLine()
	{
		//lines.erase(lines[i]);
		if (!grid->CurrentRow)
			return;

		int i = grid->CurrentRow->Index;
		lines.erase(lines.begin() + i);
		grid->Rows->RemoveAt(i);
		linesNum--;
		Redraw();
	}
	void EditLine()
	{
		int i = grid->SelectedCells[0]->RowIndex;
		sLine &l = lines[i];

		l.A.x = Convert::ToInt32(grid->Rows[i]->Cells[0]->Value);
		l.A.y = Convert::ToInt32(grid->Rows[i]->Cells[1]->Value);
		l.B.x = Convert::ToInt32(grid->Rows[i]->Cells[2]->Value);
		l.B.y = Convert::ToInt32(grid->Rows[i]->Cells[3]->Value);

		Redraw();
	}


	//������ ��������� ����������
	void StartClip(int x, int y)
	{
		if (!clip)
			clip = new cRect;
		clip->SetA(x,y);
	}
	//����������/���������  ��������� ����������
	void EndClip(int x, int y)
	{
		clip->SetB(x,y);
		Redraw();
	}


	//������ ��������� �������
	void StartLine(int x, int y)
	{
		AddLine(x,y, x,y);
	}
	//����������/��������� ��������� �������
	void EndLine(int x, int y)
	{
		int i = linesNum-1;
		lines[i].B.x = x;
		lines[i].B.y = y;
		grid->Rows[i]->Cells[2]->Value = Convert::ToString(x);
		grid->Rows[i]->Cells[3]->Value = Convert::ToString(y);
		Redraw();
	}

	void DoClip()
	{
		if (!lines.size())
		{
			SHOW_ERROR("�� ����� �� ���� �������!");
			return;
		}
		if (!clip)
		{
			SHOW_ERROR("�� ����� ����������!");
			return;
		}

		easel->Clear(); //�������� �����
		easel->DrawRectangle(clip, clrClip); //�������� ����������
		sLine *l;
		for (unsigned i=0; i<lines.size(); i++)
		{
			easel->DrawLine(&lines[i], clrLine); //�������� �������
			l = ClipMiddle(lines[i], clip);
			if (l)
			{
				easel->DrawLine(l, clrResult); //�������� ��� ���������� �����
				delete l;
			}
		}
	}
};