/*
* <<<<<<<<<<<<<<<<<< BIT_MATH.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(PORT_ID,PIN_ID)   (PORT_ID)|=(1<<PIN_ID)
#define CLR_BIT(PORT_ID,PIN_ID)   (PORT_ID)&=(~(1<<PIN_ID))
#define TOG_BIT(PORT_ID,PIN_ID)   (PORT_ID)^=(1<<PIN_ID)
#define GET_BIT(PORT_ID,PIN_ID)   ((PORT_ID>>PIN_ID)&0x01)

#define SET_PORT(PORT_ID)   (PORT_ID)|=0xFF
#define CLR_PORT(PORT_ID)   (PORT_ID)&=0x00
#define TOG_PORT(PORT_ID)   (PORT_ID)^=0xFF
#define GET_PORT(PORT_ID)   (PORT_ID)&0xFF

#endif /* BIT_MATH_H_ */