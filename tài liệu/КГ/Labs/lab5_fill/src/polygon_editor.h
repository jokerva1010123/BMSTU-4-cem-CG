//
//
//
#pragma once

#include "polygonworks.h"
#include "paint.h"
#include <vector>

struct sBufferedPolygon
{
	std::vector<sPoint> points;
	std::vector<int> con;
	~sBufferedPolygon()
	{
		points.clear();
		con.clear();
	}
};


class cPolygonEditor
{
	cEasel *easel;
	tColor clrBack;
	tColor clrFill;
	tColor clrMain;
	static sBufferedPolygon *buf;
	
public:
	cPolygonEditor(PictureBox^ pb)
	{
		easel = new cEasel(pb);
		clrBack = Color::AliceBlue;
		clrFill = Color::Red;
		clrMain = Color::Black;
	}

	void Redraw()
	{
		if (buf)
		{
			std::vector<sPoint>::iterator i;
			for (i = buf->points.begin(); i != buf->points.end(); ++i)
			{
				easel->DrawPoint(&(*i), clrMain);
			}
		}
	}

	void Refresh(Color b, Color f, Color m)
	{
		clrBack = b;
		clrFill = f;
		clrMain = m;
	}
};