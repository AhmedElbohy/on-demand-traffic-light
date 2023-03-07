/*
* <<<<<<<<<<<<<<<<<< EXTI.C >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#include "EXTI.h"

/*************Pointer to functions to be assigned to ISR***************/
static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;

void EXTI_EnableGlobal()
{
	SET_BIT(SREG_REG,GIE);
}

void EXTI_DisableGlobal()
{
	CLR_BIT(SREG_REG,GIE);
}

void EXTI_ENABLE(EXTI_ID interrupt)
{
	switch(interrupt)
	{
		case EX_INT0 : SET_BIT(GICR_REG,INT0);break;
		case EX_INT1 : SET_BIT(GICR_REG,INT1);break;
		case EX_INT2 : SET_BIT(GICR_REG,INT2);break;
	}
}

void EXTI_DISABLE(EXTI_ID interrupt)
{
	switch(interrupt)
	{
		case EX_INT0 : CLR_BIT(GICR_REG,INT0);break;
		case EX_INT1 : CLR_BIT(GICR_REG,INT1);break;
		case EX_INT2 : CLR_BIT(GICR_REG,INT2);break;
	}
}

void EXTI_TriggerEdge(EXTI_ID interrupt,TriggerEdge_Type TriggerType)
{
	switch(interrupt)
	{
		case EX_INT0 : 
		switch(TriggerType)
		{
			case LOW_LEVEL :
			CLR_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
			break;
			case LOGIC_CHANGE :
			SET_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			case RISING_EDGE :
			SET_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
		}break;
		case EX_INT1 :
		switch(TriggerType)
		{
			case LOW_LEVEL :
			CLR_BIT(MCUCR_REG,ISC10);
			CLR_BIT(MCUCR_REG,ISC11);
			break;
			case LOGIC_CHANGE :
			SET_BIT(MCUCR_REG,ISC10);
			CLR_BIT(MCUCR_REG,ISC11);
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;
			case RISING_EDGE :
			SET_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;
		}break;
		case EX_INT2 : 
		switch(TriggerType)
		{
			case FALLING_EDGE :
			CLR_BIT(MCUCSR_REG,ISC2);
			break;
			case RISING_EDGE :
			SET_BIT(MCUCSR_REG,ISC2);
			break;
			default : SET_BIT(MCUCSR_REG,ISC2);break;
		}break;
	}
}


/*************Call Back function***************/
void EXI_SetCallBack(EXTI_ID Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt){
		case EX_INT0: INT0_Fptr=LocalPtr; break;
		case EX_INT1: INT1_Fptr=LocalPtr; break;
		case EX_INT2: INT2_Fptr=LocalPtr; break;
	}
}

/*************ISR functions***************/

/*ISR(INT0_VEC)
{
	if (INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}
}*/
ISR(INT1_VEC)
{
	if (INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}
ISR(INT2_VEC)
{
	if (INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}
}








/******************* Test INTERRUPT Driver *******************/

/*int main(void)
{
	EXTI_EnableGlobal();
	EXTI_ENABLE(EX_INT0);
	EXTI_TriggerEdge(EX_INT0,RISING_EDGE);
	while (1)
	{
	}
	
}

ISR(INT0_VEC)
{
	if(BUTTON_READ(PORTD,PIN2)==Pressed)
	{
		LED_INIT(PORTA,PIN0);
		LED_ON(PORTA,PIN0);
	}
}*/

/******************************************************/