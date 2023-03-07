/*
* <<<<<<<<<<<<<<<<<< BUTTON.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#include "BUTTON.h"

void BUTTON_INIT(PORT_ID PortNumber,PIN_ID PinNumber)
{
	DIO_SetPinDirection_v(PortNumber,PinNumber,INPUT);
}

BUTTON_STATE BUTTON_READ(PORT_ID PortNumber,PIN_ID PinNumber)
{
	uint8 ButtonState=0;
	ButtonState=DIO_GetPinValue_int(PortNumber,PinNumber);
	return ButtonState;
}










/******************* Test BUTTON Driver *******************/

/*int main(void)
{
	LED_INIT(PORTA,PIN0);
	BUTTON_INIT(PORTD,PIN2);
	while (1)
	{
		if(BUTTON_READ(PORTD,PIN2)==Pressed)
		{
			LED_ON(PORTA,PIN0);
		}
	}
}*/


/******************************************************/