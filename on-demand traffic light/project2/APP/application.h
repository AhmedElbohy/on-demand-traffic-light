/*
* <<<<<<<<<<<<<<<<<< application.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../HAL/LED/LED.h"

void App_Init(PORT_ID Leds_Port);

void Flaching(PORT_ID Leds_Port);

void Shift_Left(PORT_ID Leds_Port);

void Shift_Right(PORT_ID Leds_Port);

void Converging(PORT_ID Leds_Port);

void Diverging(PORT_ID Leds_Port);

void Pingpong(PORT_ID Leds_Port);

void Snake(PORT_ID Leds_Port);

void Converging_Diverging(PORT_ID Leds_Port);

#endif /* APPLICATION_H_ */