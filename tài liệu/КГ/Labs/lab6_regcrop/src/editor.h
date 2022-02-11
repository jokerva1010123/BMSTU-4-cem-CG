//
//
//
#pragma once

#include "geometry.h"
#include "paint.h"
#include "clipper.h"
#include <vector>


typedef gcroot<DataGridView^> tGrid;


//редактор
class cEditor
{
	cEasel *easel;		//холст
	tGrid grid;			//таблица с отрезками
	tColor clrClip;		//цвет отсекателя
	tColor clrLine;		//цвет отрезка
	tColor clrResult;	//цвет результата

public:
	std::vector<sLine> lines;	//список отрезков
	int linesNum;
	cRect *clip; //отсекатель
	
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



	//отрисовать содержимое
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

	//обновить цвета
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


	//начать отрисовку отсекателя
	void StartClip(int x, int y)
	{
		if (!clip)
			clip = new cRect;
		clip->SetA(x,y);
	}
	//продолжить/закончить  отрисовку отсекателя
	void EndClip(int x, int y)
	{
		clip->SetB(x,y);
		Redraw();
	}


	//начать отрисовку отрезка
	void StartLine(int x, int y)
	{
		AddLine(x,y, x,y);
	}
	//продолжить/закончить отрисовку отрезка
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
			SHOW_ERROR("Не задан ни один отрезок!");
			return;
		}
		if (!clip)
		{
			SHOW_ERROR("Не задан отсекатель!");
			return;
		}

		easel->Clear(); //почистим холст
		easel->DrawRectangle(clip, clrClip); //отрисуем отсекатель
		sLine *l;
		for (unsigned i=0; i<lines.size(); i++)
		{
			easel->DrawLine(&lines[i], clrLine); //отрисуем отрезок
			l = ClipMiddle(lines[i], clip);
			if (l)
			{
				easel->DrawLine(l, clrResult); //отрисуем его отсеченную часть
				delete l;
			}
		}
	}
};