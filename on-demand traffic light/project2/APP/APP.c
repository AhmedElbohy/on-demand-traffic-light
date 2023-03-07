/*
* <<<<<<<<<<<<<<<<<< APP.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/
#include "APP.h"

uint8 i=0;

Normal_mode()
{
	LED_ON(LED_CARS_PORT,LED_GreenCars_PIN);
	TIMER0_delay_5s();
	LED_OFF(LED_CARS_PORT,LED_GreenCars_PIN);
	i=0;
	while(i<20)
	{
		LED_TOGGLE(LED_CARS_PORT,LED_YellowCars_PIN);
		TIMER0_delay_250ms();
		i++;
	}
	i=0;
	LED_ON(LED_CARS_PORT,LED_RedCars_PIN);
	TIMER0_delay_5s();
	LED_OFF(LED_CARS_PORT,LED_RedCars_PIN);
	while(i<20)
	{
		LED_TOGGLE(LED_CARS_PORT,LED_YellowCars_PIN);
		TIMER0_delay_250ms();
		i++;
	}
}


Pedestrian_mode()
{
	if(DIO_GetPinValue_int(LED_CARS_PORT,LED_RedCars_PIN)==HIGH)
	{
		LED_OFF(LED_CARS_PORT,LED_GreenCars_PIN);
		LED_ON(LED_CARS_PORT,LED_RedCars_PIN);
		LED_ON(LED_PEDESTRIAN_PORT,LED_GreenPedestrian_PIN);
		TIMER0_delay_5s();
		LED_OFF(LED_CARS_PORT,LED_RedCars_PIN);
	}
	else if((DIO_GetPinValue_int(LED_CARS_PORT,LED_GreenCars_PIN)==HIGH)||(DIO_GetPinValue_int(LED_CARS_PORT,LED_YellowCars_PIN)==HIGH))
	{
		LED_OFF(LED_CARS_PORT,LED_YellowCars_PIN);
		LED_ON(LED_PEDESTRIAN_PORT,LED_RedPedestrian_PIN);
		TIMER0_delay_250ms();
		i=0;
		while(i<20)
		{
			LED_OFF(LED_CARS_PORT,LED_GreenCars_PIN);
			LED_TOGGLE(LED_CARS_PORT,LED_YellowCars_PIN);
			LED_TOGGLE(LED_PEDESTRIAN_PORT,LED_YellowPedestrian_PIN);
			TIMER0_delay_250ms();
			i++;
		}
		LED_OFF(LED_PEDESTRIAN_PORT,LED_RedPedestrian_PIN);
		LED_ON(LED_CARS_PORT,LED_RedCars_PIN);
		LED_ON(LED_PEDESTRIAN_PORT,LED_GreenPedestrian_PIN);
		TIMER0_delay_5s();
		LED_OFF(LED_CARS_PORT,LED_RedCars_PIN);
	}
	i=0;
	while(i<20)
	{
		LED_TOGGLE(LED_CARS_PORT,LED_YellowCars_PIN);
		LED_TOGGLE(LED_PEDESTRIAN_PORT,LED_YellowPedestrian_PIN);
		TIMER0_delay_250ms();
		i++;
	}
	LED_OFF(LED_PEDESTRIAN_PORT,LED_GreenPedestrian_PIN);
	LED_ON(LED_CARS_PORT,LED_GreenCars_PIN);
	LED_ON(LED_PEDESTRIAN_PORT,LED_RedPedestrian_PIN);
	TIMER0_delay_5s();
	LED_OFF(LED_PEDESTRIAN_PORT,LED_RedPedestrian_PIN);
}
void APP_INIT()
{
	LED_INIT(LED_CARS_PORT,LED_GreenCars_PIN);
	LED_INIT(LED_CARS_PORT,LED_YellowCars_PIN);
	LED_INIT(LED_CARS_PORT,LED_RedCars_PIN);
	
	LED_INIT(LED_PEDESTRIAN_PORT,LED_GreenPedestrian_PIN);
	LED_INIT(LED_PEDESTRIAN_PORT,LED_YellowPedestrian_PIN);
	LED_INIT(LED_PEDESTRIAN_PORT,LED_RedPedestrian_PIN);
	
	BUTTON_INIT(BUTTON_PORT,BUTTON_PIN);
	
	TIMER0_INIT(TIMER0_Normal_Mode,TIMER0_Prescaler_1024,OC0_DISCONNECTED);
	
	sei();
	EXTI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXTI_ENABLE(EX_INT0);
	//EXTI_SetCallBack(EX_INT0,Pedestrian_mode);
}

ISR(INT0_VEC)
{
	if (BUTTON_READ(BUTTON_PORT,BUTTON_PIN)==Pressed)
	{
		Pedestrian_mode();
	}
	Normal_mode();
}
void APP_Start()
{
	Normal_mode();
}
