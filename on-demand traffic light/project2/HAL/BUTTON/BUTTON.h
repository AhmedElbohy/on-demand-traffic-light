/*
* <<<<<<<<<<<<<<<<<< BUTTON.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../LIB/REGISTERS.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO_DRIVER/DIO.h"

typedef enum
{
	NotPressed,
	Pressed
}BUTTON_STATE;

void BUTTON_INIT(PORT_ID PortNumber,PIN_ID PinNumber);

BUTTON_STATE BUTTON_READ(PORT_ID PortNumber,PIN_ID PinNumber);


#endif