/*
* <<<<<<<<<<<<<<<<<< TIMER.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/ 

#ifndef TIMER_H_
#define TIMER_H_

#include "../../LIB/REGISTERS.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

/******************* TIMER TYPES ************************/

typedef enum
{
	TIMER0_Normal_Mode,
	TIMER0_PhaseCorrect_Mode,
	TIMER0_CTC_Mode,
	TIMER0_FastPWM_Mode
}TIMER0_MODE;

typedef enum
{
	OC0_DISCONNECTED,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING
}OC0_MODE;

typedef enum
{
	TIMER0_NoClock,
	TIMER0_Prescaler_1,
	TIMER0_Prescaler_8,
	TIMER0_Prescaler_64,
	TIMER0_Prescaler_256,
	TIMER0_Prescaler_1024,
	TIMER0_EXT_FallingEdge,
	TIMER0_EXT_RisingEdge
}TIMER0_CLK_MODE;


/******************* DIO FUNCTIONS ************************/

void TIMER0_INIT(TIMER0_MODE mode,TIMER0_CLK_MODE scaler,OC0_MODE OC0mode);

void TIMER0_OV_Interrupt_ENABLE(void);

void TIMER0_OV_Interrupt_DISABLE(void);

void TIMER0_OC_Interrupt_ENABLE(void);

void TIMER0_OC_Interrupt_DISABLE(void);

void TIMER0_Stop(void);

void TIMER_0_set_init_value(uint16 val);

void TIMER0_delay_5s(void);

void TIMER0_delay_1s(void);

void TIMER0_delay_250ms(void);

#endif