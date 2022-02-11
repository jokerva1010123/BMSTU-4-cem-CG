//---------------------------------------------------------------------------

#pragma hdrstop

#include "TickCntr.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


unsigned __int64 tick(void)
{
	_asm rdtsc

}
