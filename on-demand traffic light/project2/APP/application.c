/*
* <<<<<<<<<<<<<<<<<< application.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "application.h"

void App_Init(PORT_ID Leds_Port)
{
	LED_INIT_Port(Leds_Port);
}

void Flaching(PORT_ID Leds_Port)
{
	LED_TOGGLE_Port(Leds_Port);
	_delay_ms(250);
}

void Shift_Left(PORT_ID Leds_Port)
{
	for(uint8 i=7;i>=0;i--)
	{
		LED_ON(Leds_Port,i);
		_delay_ms(250);
		LED_OFF(Leds_Port,i);
	}
}

void Shift_Right(PORT_ID Leds_Port)
{
	for(uint8 i=0;i<8;i++)
	{
		LED_ON(Leds_Port,i);
		_delay_ms(250);
		LED_OFF(Leds_Port,i);
	}
}

void Converging(PORT_ID Leds_Port)
{
	uint8 i=0,j=7;
	while((i<=3),(j>=4))
	{
		LED_ON(Leds_Port,i);
	    LED_ON(Leds_Port,j);
	    _delay_ms(250);
	    LED_OFF(Leds_Port,i);
	    LED_OFF(Leds_Port,j);
		i++;
		j--;
	}
}

void Diverging(PORT_ID Leds_Port)
{
	uint8 i=3,j=4;
	while((i>=0),(j<=7))
	{
		LED_ON(Leds_Port,i);
		LED_ON(Leds_Port,j);
		_delay_ms(250);
		LED_OFF(Leds_Port,i);
		LED_OFF(Leds_Port,j);
		i--;
		j++;
	}
}

void Pingpong(PORT_ID Leds_Port)
{
	uint8 i=0;
	for(i=0;i<8;i++)
	{
		LED_ON(Leds_Port,i);
		_delay_ms(250);
		LED_OFF(Leds_Port,i);
	}
	_delay_ms(100);
	for(i=7;i>=0;i--)
	{
		LED_ON(Leds_Port,i);
		_delay_ms(250);
		LED_OFF(Leds_Port,i);
	}
	_delay_ms(100);
}

void Snake(PORT_ID Leds_Port)
{
	for(uint8 i=0;i<8;i++)
	{
		LED_ON(Leds_Port,i);
		_delay_ms(150);
	}
	LED_OFF_Port(Leds_Port);
	_delay_ms(150);
}

void Converging_Diverging(PORT_ID Leds_Port)
{
	uint8 i=0,j=7;
	while((i<=3),(j>=4))
	{
		LED_ON(Leds_Port,i);
		LED_ON(Leds_Port,j);
		_delay_ms(250);
		LED_OFF(Leds_Port,i);
		LED_OFF(Leds_Port,j);
		i++;
		j--;
	}
	_delay_ms(100);
	while((i>=0),(j<=7))
	{
		LED_ON(Leds_Port,i);
		LED_ON(Leds_Port,j);
		_delay_ms(250);
		LED_OFF(Leds_Port,i);
		LED_OFF(Leds_Port,j);
		i--;
		j++;
	}
	_delay_ms(100);
}