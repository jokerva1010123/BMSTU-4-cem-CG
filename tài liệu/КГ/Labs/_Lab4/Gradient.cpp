//---------------------------------------------------------------------------


#pragma hdrstop

#include "Gradient.h"

//---------------------------------------------------------------------------
TSegmentedColor GetIntensiveColor(TSegmentedColor BaseColor,
									TSegmentedColor BgrdColor,
									double Intensity)
{    // Intensity от 0 до 1
	BaseColor.Segm.Red += Intensity*(BgrdColor.Segm.Red-BaseColor.Segm.Red);
	BaseColor.Segm.Green += Intensity*(BgrdColor.Segm.Green-BaseColor.Segm.Green);
	BaseColor.Segm.Blue += Intensity*(BgrdColor.Segm.Blue-BaseColor.Segm.Blue);
	return BaseColor;
}




#pragma package(smart_init)
