#include "stdafx.h"

#include "frequency_timer.h"

#define _USE_MATH_DEFINES

#include <cmath>

static FrequencyTimer timer;

static inline int round (double x) {return ceil (x - 0.5);};

static inline void DrawPoint (double x, double y, BufferedGraphics^ buffer, SolidBrush^ brush)
{
	buffer->Graphics->FillRectangle(brush, round (x), round (y) , 1, 1);
}

double LibFunc (Point center, int radx, int rady, BufferedGraphics^ buffer, SolidBrush^ brush, Graphics^ graph)
{
	Pen^ drPen = gcnew Pen (brush->Color);

	timer.SetMeasurementUnit (1000000);
	timer.Reset();
	timer.Start();
	buffer->Graphics->DrawEllipse (drPen, center.X - radx, center.Y - rady, 2 * radx, 2 * rady);
	timer.Stop();

	buffer->Render (graph);
	return timer.GetTime();
}

double Equation (Point center, int radx, int rady, BufferedGraphics^ buffer, SolidBrush^ brush, Graphics^ graph)
{
	timer.SetMeasurementUnit (1000000);
	timer.Reset();
    timer.Start();

    double a = radx, b = rady;
    double a2 = a * a, b2 = b * b;
    double border = a * a * sqrt (a2 + b2);
    double xt = 0, yt = b;
	if (a >= b)
	{
		double step = 1 / a;
		for (; xt < a; xt += step)
		{
			yt = sqrt (a2 * b2 - xt * xt * b2) / a;
		    DrawPoint(center.X + xt, center.Y + yt, buffer, brush);
			DrawPoint(center.X - xt, center.Y + yt, buffer, brush);
			DrawPoint(center.X + xt, center.Y - yt, buffer, brush);
			DrawPoint(center.X - xt, center.Y - yt, buffer, brush);
		}
	}
	else
	{
		double step = 1 / b;
		for (; yt > 0; yt -= step)
		{
			xt = sqrt (a2 * b2 - yt * yt * a2) / b;
			DrawPoint(center.X + xt, center.Y + yt, buffer, brush);
			DrawPoint(center.X - xt, center.Y + yt, buffer, brush);
			DrawPoint(center.X + xt, center.Y - yt, buffer, brush);
			DrawPoint(center.X - xt, center.Y - yt, buffer, brush);
		}
	}
     timer.Stop();

     buffer->Render(graph);
     return timer.GetTime();
}

double Parametric (Point center, int radx, int rady, BufferedGraphics^ buffer, SolidBrush^ brush, Graphics^ graph)
{
	timer.SetMeasurementUnit (1000000);
	timer.Reset();
    timer.Start();

    double a = radx, b = rady;
    double xt = 0;
    double yt = 0;
    double d = 1.0 / max (a, b);
    for (double t = M_PI / 2.0; t >= 0; t -= d)
    {
		xt = a * cos(t);
        yt = b * sin(t);
		DrawPoint(center.X + xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X + xt, center.Y - yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y - yt, buffer, brush);
    }
    timer.Stop();
    buffer->Render(graph);

    return timer.GetTime();
}

double MiddlePoint (Point center, int radx, int rady, BufferedGraphics^ buffer, SolidBrush^ brush, Graphics^ graph)
{
	timer.SetMeasurementUnit (1000000);
	timer.Reset();
    timer.Start();

    double a = radx;
    double b = rady;
    double ab2 = a * a * b * b,
                 a2 = a * a,
                 b2 = b * b;
    double xt = 0;
    double yt = b;
    double delta = b2 + a2 * (yt - 0.5) * (yt - 0.5) - ab2;
    double border = a2 / sqrt (b2 + a2);
    while (xt <= border)
     {
                //delta = b2 * (xt + 1) * (xt + 1) + a2 * (yt - 0.5) * (yt - 0.5) - ab2;
		DrawPoint(center.X + xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X + xt, center.Y - yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y - yt, buffer, brush);
        xt += 1;

        if (delta > 0)
        {        
			yt -= 1;
            delta += a2 * (-2 * yt);

        }
        delta += b2 * (2 * xt + 1);

      }
      delta += 0.75 * (a2 - b2) - (b2 * xt + a2 * yt);
      while (yt >= 0)
      {
                //delta = b2 * (xt + 0.5) * (xt + 0.5) + a2 * (yt - 1) * (yt - 1) - ab2;
		DrawPoint(center.X + xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X + xt, center.Y - yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y - yt, buffer, brush);

        yt -= 1;
        if (delta < 0)
        {        
			xt += 1;
            delta += b2 * (2 * xt);       
        }
	    delta += a2 * (-2 * yt + 1);
       }
       timer.Stop();

       buffer->Render(graph);
       return timer.GetTime();
}

double Brezenham (Point center, int radx, int rady, BufferedGraphics^ buffer, SolidBrush^ brush, Graphics^ graph)
{
	timer.SetMeasurementUnit (1000000);
	timer.Reset();
    timer.Start();

    double a = radx;
    double b = rady;
    double ab2 = a * a * b * b,
                 a2 = a * a,
                 b2 = b * b;
    double xt = 0;
    double yt = b;
    double delta = b2 + (b - 1) * (b - 1) * a2 - ab2,
                   delta1 = b2 + b2 * a2 - ab2,
                   delta2 = (b - 1) * (b - 1) * a2 - ab2;
    bool stepGorizontal, stepVertical;
    double d;
    while (yt >= 0)
    {
        DrawPoint(center.X + xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y + yt, buffer, brush);
		DrawPoint(center.X + xt, center.Y - yt, buffer, brush);
		DrawPoint(center.X - xt, center.Y - yt, buffer, brush);
        stepGorizontal = false;
        stepVertical = false;
        if (delta < 0)
        {
           xt += 1;
           stepGorizontal = true;
           if (abs (delta1) - abs (delta2) > 0)
			{
				yt -= 1;
                stepVertical = true;
            }
        }
			else
            if (delta > 0)
            {
				yt -= 1;
                stepVertical = true;
                if (-abs(delta2) + abs(delta) < 0)
                {
					xt += 1;
                    stepGorizontal = true;
                }
            }
            else
				if (delta == 0)
                {
					xt += 1;
                    yt -= 1;
                    stepVertical = true;
                    stepGorizontal = true;
                }
                if (stepGorizontal == true)
                {
                    d = b2 * (2 * xt + 1);
                    delta += d;
                    delta1 += d;
                    delta2 += d - 2 * b2;
                }
                if (stepVertical == true)
                {
                    d = a2 * (-2 * yt + 1);
                    delta += d;
                    delta1 += d - 2 * a2;
                    delta2 += d;
                }
            }
            timer.Stop();
            buffer->Render(graph);

            return timer.GetTime();
        }