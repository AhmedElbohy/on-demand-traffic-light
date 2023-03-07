/*
* <<<<<<<<<<<<<<<<<< DIO.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#include "DIO.h"

void DIO_SetPortDirection_v(PORT_ID PortNumber,DDR_DIRECTION Direction)
{
	if(Direction == OUTPUT)
	{
		switch(PortNumber)
		{
			case PORTA : SET_PORT(DDRA_REG);break;
			case PORTB : SET_PORT(DDRB_REG);break;
			case PORTC : SET_PORT(DDRC_REG);break;
			case PORTD : SET_PORT(DDRD_REG);break;
		}
	}
	else if(Direction == INPUT)
	{
		switch(PortNumber)
		{
			case PORTA : CLR_PORT(DDRA_REG);break;
			case PORTB : CLR_PORT(DDRB_REG);break;
			case PORTC : CLR_PORT(DDRC_REG);break;
			case PORTD : CLR_PORT(DDRD_REG);break;
		}
	}
}

void DIO_SetPortValue_v(PORT_ID PortNumber,DIO_VALUE value)
{
	if(value == HIGH)
	{
		switch(PortNumber)
		{
			case PORTA : SET_PORT(PORTA_REG);break;
			case PORTB : SET_PORT(PORTB_REG);break;
			case PORTC : SET_PORT(PORTC_REG);break;
			case PORTD : SET_PORT(PORTD_REG);break;
		}
	}
	else if(value == LOW)
	{
		switch(PortNumber)
		{
			case PORTA : CLR_PORT(PORTA_REG);break;
			case PORTB : CLR_PORT(PORTB_REG);break;
			case PORTC : CLR_PORT(PORTC_REG);break;
			case PORTD : CLR_PORT(PORTD_REG);break;
		}
	}
}

void DIO_TogglePort_v(PORT_ID PortNumber)
{
	switch(PortNumber)
	{
		case PORTA : TOG_PORT(PORTA_REG);break;
		case PORTB : TOG_PORT(PORTB_REG);break;
		case PORTC : TOG_PORT(PORTC_REG);break;
		case PORTD : TOG_PORT(PORTD_REG);break;
	}
}

void DIO_SetPinDirection_v(PORT_ID PortNumber,PIN_ID PinNumber,DDR_DIRECTION Direction)
{
	if(Direction == OUTPUT)
	{
		switch(PortNumber)
		{
			case PORTA : SET_BIT(DDRA_REG,PinNumber);break;
			case PORTB : SET_BIT(DDRB_REG,PinNumber);break;
			case PORTC : SET_BIT(DDRC_REG,PinNumber);break;
			case PORTD : SET_BIT(DDRD_REG,PinNumber);break;
		}
	}
	else if(Direction == INPUT)
	{
		switch(PortNumber)
		{
			case PORTA : CLR_BIT(DDRA_REG,PinNumber);break;
			case PORTB : CLR_BIT(DDRB_REG,PinNumber);break;
			case PORTC : CLR_BIT(DDRC_REG,PinNumber);break;
			case PORTD : CLR_BIT(DDRD_REG,PinNumber);break;
		}
	}
}

void DIO_SetPinValue_v(PORT_ID PortNumber,PIN_ID PinNumber,DIO_VALUE value)
{
	if(value == HIGH)
	{
		switch(PortNumber)
		{
			case PORTA : SET_BIT(PORTA_REG,PinNumber);break;
			case PORTB : SET_BIT(PORTB_REG,PinNumber);break;
			case PORTC : SET_BIT(PORTC_REG,PinNumber);break;
			case PORTD : SET_BIT(PORTD_REG,PinNumber);break;
		}
	}
	else if(value == LOW)
	{
		switch(PortNumber)
		{
			case PORTA : CLR_BIT(PORTA_REG,PinNumber);break;
			case PORTB : CLR_BIT(PORTB_REG,PinNumber);break;
			case PORTC : CLR_BIT(PORTC_REG,PinNumber);break;
			case PORTD : CLR_BIT(PORTD_REG,PinNumber);break;
		}
	}
}

DIO_VALUE DIO_GetPinValue_int(PORT_ID PortNumber,PIN_ID PinNumber)
{
	DIO_VALUE PinValue=0;
	switch(PortNumber)
	{
		case PORTA : PinValue=GET_BIT(PINA_REG,PinNumber);break;
		case PORTB : PinValue=GET_BIT(PINB_REG,PinNumber);break;
		case PORTC : PinValue=GET_BIT(PINC_REG,PinNumber);break;
		case PORTD : PinValue=GET_BIT(PIND_REG,PinNumber);break;
	}
	return PinValue;
}

void DIO_TogglePin_v(PORT_ID PortNumber,PIN_ID PinNumber)
{
	switch(PortNumber)
	{
		case PORTA : TOG_BIT(PORTA_REG,PinNumber);break;
		case PORTB : TOG_BIT(PORTB_REG,PinNumber);break;
		case PORTC : TOG_BIT(PORTC_REG,PinNumber);break;
		case PORTD : TOG_BIT(PORTD_REG,PinNumber);break;
	}
}

