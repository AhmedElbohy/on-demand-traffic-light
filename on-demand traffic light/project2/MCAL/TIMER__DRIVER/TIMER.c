/*
* <<<<<<<<<<<<<<<<<< TIMER.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#include "TIMER.h"


void TIMER0_INIT(TIMER0_MODE mode,TIMER0_CLK_MODE scaler,OC0_MODE OC0mode)
{
	switch(mode)
	{
		case TIMER0_Normal_Mode :
		CLR_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);
		break;
		case TIMER0_PhaseCorrect_Mode :
		SET_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);
		break;
		case TIMER0_CTC_Mode :
		CLR_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);
		break;
		case TIMER0_FastPWM_Mode :
		SET_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);
		break;
	}
	
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
	TCCR0_REG |= scaler;
	
	switch(OC0mode)
	{
		case OC0_DISCONNECTED :
		CLR_BIT(TCCR0_REG,COM00);
		CLR_BIT(TCCR0_REG,COM01);
		break;
		case OC0_TOGGLE :
		SET_BIT(TCCR0_REG,COM00);
		CLR_BIT(TCCR0_REG,COM01);
		break;
		case OC0_NON_INVERTING :
		CLR_BIT(TCCR0_REG,COM00);
		SET_BIT(TCCR0_REG,COM01);
		break;
		case OC0_INVERTING :
		SET_BIT(TCCR0_REG,COM00);
		SET_BIT(TCCR0_REG,COM01);
		break;
	}
	
}

void TIMER0_OV_Interrupt_ENABLE(void)
{
	SET_BIT(TIMSK_REG,TOIE0);
}

void TIMER0_OV_Interrupt_DISABLE(void)
{
	CLR_BIT(TIMSK_REG,TOIE0);
}

void TIMER0_OC_Interrupt_ENABLE(void)
{
	SET_BIT(TIMSK_REG,OCIE0);
}

void TIMER0_OC_Interrupt_DISABLE(void)
{
	CLR_BIT(TIMSK_REG,OCIE0);
}

void TIMER_0_set_init_value(uint16 val)
{
	TCNT0_REG = val;
}

void TIMER0_Stop(void){
	TCCR0_REG = 0x00;
}

void TIMER0_delay_5s(void)
{
	
	/*i use prescaler 1024 so tick time is 1.024ms
	so number of overflows =20
	intial value 273 */
	
	
	TIMER_0_set_init_value(273);
	TIMER0_INIT(TIMER0_Normal_Mode,TIMER0_Prescaler_1024,OC0_DISCONNECTED);
	uint16 OV_counter=0;
	while(OV_counter < 20){
		while(GET_BIT(TIFR_REG,TOV0)==0);
		SET_BIT(TIFR_REG,TOV0);
		OV_counter++;
	}
	OV_counter = 0;
	TIMER0_Stop();
}

void TIMER0_delay_1s(void)
{
	/*i use prescaler 1024 so tick time is 1.024ms
	so number of overflows =4
	intial value 47 */
	
	
	TIMER_0_set_init_value(47);
	TIMER0_INIT(TIMER0_Normal_Mode,TIMER0_Prescaler_1024,OC0_DISCONNECTED);
	uint16 OV_counter=0;
	while(OV_counter < 4){
		while(GET_BIT(TIFR_REG,TOV0)==0);
		SET_BIT(TIFR_REG,TOV0);
		OV_counter++;
	}
	OV_counter = 0;
	TIMER0_Stop();
}

void TIMER0_delay_250ms(void)
{
	/*i use prescaler 1024 so tick time is 1.024ms
	so number of overflows =1
	intial value 12 */
	
	
	TIMER_0_set_init_value(12);
	TIMER0_INIT(TIMER0_Normal_Mode,TIMER0_Prescaler_1024,OC0_DISCONNECTED);
	uint16 OV_counter=0;
	while(OV_counter < 1){
		while(GET_BIT(TIFR_REG,TOV0)==0);
		SET_BIT(TIFR_REG,TOV0);
		OV_counter++;
	}
	OV_counter = 0;
	TIMER0_Stop();
}









/******************* Test TIMER Driver *******************/

/*int main(void)
{
	LED_INIT(PORTA,PIN0);
	LED_ON(PORTA,PIN0);
	TIMER0_delay_1s();
	while (1)
	{
		LED_TOGGLE(PORTA,PIN0);
		TIMER0_delay_250ms();
	}
	
}*/


/******************************************************/



