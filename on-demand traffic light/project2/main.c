/*
 * <<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: AHMED ELBOHY
 *
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "APP/APP.h"


/**/int main(void)
{
	APP_INIT();
	while (1)
	{
		APP_Start();
	}
	
}
