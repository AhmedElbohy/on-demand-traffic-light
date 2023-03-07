/*
 * <<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: AHMED ELBOHY
 *
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "APP/application.h"


/**/int main(void)
{
	App_Init(PORTA);
	while (1)
	{
		//Flaching(PORTA);
		//Shift_Left(PORTA);
		//Shift_Right(PORTA);
		//Converging(PORTA);
		//Diverging(PORTA);
		//Pingpong(PORTA);
		//Snake(PORTA);
		Converging_Diverging(PORTA);
	}
	
}