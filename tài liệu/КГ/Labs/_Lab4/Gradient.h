//---------------------------------------------------------------------------

#ifndef GradientH
#define GradientH

#include <Graphics.hpp>
//---------------------------------------------------------------------------
typedef union
{
	TColor Color;
	struct
	{
		unsigned char Red;
		unsigned char Green;
		unsigned char Blue;
		unsigned char Mode;
	} Segm;
}TSegmentedColor;

TSegmentedColor GetIntensiveColor(TSegmentedColor, TSegmentedColor, double);

#endif
