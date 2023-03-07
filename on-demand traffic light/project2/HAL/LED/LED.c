/*
* <<<<<<<<<<<<<<<<<< LED.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/


#include "LED.h"

void LED_INIT(PORT_ID PortNumber,PIN_ID PinNumber)
{
	DIO_SetPinDirection_v(PortNumber,PinNumber,OUTPUT);
}

void LED_ON(PORT_ID PortNumber,PIN_ID PinNumber)
{
	DIO_SetPinValue_v(PortNumber,PinNumber,HIGH);
}

void LED_OFF(PORT_ID PortNumber,PIN_ID PinNumber)
{
	DIO_SetPinValue_v(PortNumber,PinNumber,LOW);
}

void LED_TOGGLE(PORT_ID PortNumber,PIN_ID PinNumber)
{
	DIO_TogglePin_v(PortNumber,PinNumber);
}

void LED_INIT_Port(PORT_ID PortNumber)
{
	DIO_SetPortDirection_v(PortNumber,OUTPUT);
}

void LED_ON_Port(PORT_ID PortNumber)
{
	DIO_SetPortValue_v(PortNumber,HIGH);
}

void LED_OFF_Port(PORT_ID PortNumber)
{
	DIO_SetPortValue_v(PortNumber,LOW);
}

void LED_TOGGLE_Port(PORT_ID PortNumber)
{
	DIO_TogglePort_v(PortNumber);
}






