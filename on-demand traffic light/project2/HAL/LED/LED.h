/*
* <<<<<<<<<<<<<<<<<< LED.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/


#ifndef LED_H_
#define LED_H_

#include "../../LIB/REGISTERS.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO_DRIVER/DIO.h"

void LED_INIT(PORT_ID PortNumber,PIN_ID PinNumber);

void LED_ON(PORT_ID PortNumber,PIN_ID PinNumber);

void LED_OFF(PORT_ID PortNumber,PIN_ID PinNumber);

void LED_TOGGLE(PORT_ID PortNumber,PIN_ID PinNumber);

void LED_INIT_Port(PORT_ID PortNumber);

void LED_ON_Port(PORT_ID PortNumber);

void LED_OFF_Port(PORT_ID PortNumber);

void LED_TOGGLE_Port(PORT_ID PortNumber);

#endif