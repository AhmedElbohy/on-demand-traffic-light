/*
* <<<<<<<<<<<<<<<<<< DIO.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#ifndef DIO_H_
#define DIO_H_

#include "../../LIB/REGISTERS.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

/******************* DIO TYPES ************************/

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}PORT_ID;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PIN_ID;

typedef enum
{
	INPUT,
	OUTPUT
}DDR_DIRECTION;

typedef enum
{
	LOW,
	HIGH
}DIO_VALUE;

/******************* DIO FUNCTIONS ************************/
void DIO_SetPortDirection_v(PORT_ID PortNumber,DDR_DIRECTION Direction);

void DIO_SetPortValue_v(PORT_ID PortNumber,DIO_VALUE value);

void DIO_TogglePort_v(PORT_ID PortNumber);

void DIO_SetPinDirection_v(PORT_ID PortNumber,PIN_ID PinNumber,DDR_DIRECTION Direction);

void DIO_SetPinValue_v(PORT_ID PortNumber,PIN_ID PinNumber,DIO_VALUE value);

DIO_VALUE DIO_GetPinValue_int(PORT_ID PortNumber,PIN_ID PinNumber);

void DIO_TogglePin_v(PORT_ID PortNumber,PIN_ID PinNumber);

#endif