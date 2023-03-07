/*
* <<<<<<<<<<<<<<<<<< EXTI.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/

#ifndef EXTI_H_
#define EXTI_H_

#include "../../LIB/REGISTERS.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

/******************* DIO TYPES ************************/

#define NULLPTR ((void*)0)
typedef enum
{
	EX_INT0,
	EX_INT1,
	EX_INT2
}EXTI_ID;

typedef enum
{
	LOW_LEVEL,
	LOGIC_CHANGE,
	RISING_EDGE,
	FALLING_EDGE
}TriggerEdge_Type;

/******************* DIO FUNCTIONS ************************/

void EXTI_EnableGlobal();

void EXTI_DisableGlobal();

void EXTI_ENABLE(EXTI_ID interrupt);

void EXTI_DISABLE(EXTI_ID interrupt);

void EXTI_TriggerEdge(EXTI_ID interrupt,TriggerEdge_Type TriggerType);

void EXTI_SetCallBack(EXTI_ID interrupt,void(*FunctionPtr)(void));

#endif 