/*
* <<<<<<<<<<<<<<<<<< APP.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#ifndef APP_H_
#define APP_H_

#include "../MCAL/DIO_DRIVER/DIO.h"
#include "../MCAL/INTERRUPT_DRIVER/EXTI.h"
#include "../MCAL/TIMER__DRIVER/TIMER.h"
#include "../HAL/BUTTON/BUTTON.h"
#include "../HAL/LED/LED.h"

#define LED_CARS_PORT        PORTA
#define LED_PEDESTRIAN_PORT  PORTB

#define LED_GreenCars_PIN  PIN0
#define LED_YellowCars_PIN PIN1
#define LED_RedCars_PIN    PIN2

#define LED_GreenPedestrian_PIN  PIN5
#define LED_YellowPedestrian_PIN PIN6
#define LED_RedPedestrian_PIN    PIN7

#define BUTTON_PORT  PORTD
#define BUTTON_PIN   PIN2

void Normal_mode();

void Pedestrian_mode();

void APP_INIT();

void APP_Start();

#endif 