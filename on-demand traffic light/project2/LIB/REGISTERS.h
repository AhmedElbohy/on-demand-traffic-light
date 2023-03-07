/*
* <<<<<<<<<<<<<<<<<< DIO_REG.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*  Author: AHMED ELBOHY
*
*/


#ifndef DIO_REG_H_
#define DIO_REG_H_

/******************* DIO REGISTERS ************************/

//PORTA REGISTERS
#define PORTA_REG (*((volatile uint8*)0x3B))
#define DDRA_REG  (*((volatile uint8*)0x3A))
#define PINA_REG  (*((volatile uint8*)0x39))

//PORTB REGISTERS
#define PORTB_REG (*((volatile uint8*)0x38))
#define DDRB_REG  (*((volatile uint8*)0x37))
#define PINB_REG  (*((volatile uint8*)0x36))

//PORTC REGISTERS
#define PORTC_REG (*((volatile uint8*)0x35))
#define DDRC_REG  (*((volatile uint8*)0x34))
#define PINC_REG  (*((volatile uint8*)0x33))

//PORTD REGISTERS
#define PORTD_REG (*((volatile uint8*)0x32))
#define DDRD_REG  (*((volatile uint8*)0x31))
#define PIND_REG  (*((volatile uint8*)0x30))

/******************* INTERRUPT REGISTERS ************************/

//General Interrupt Control Register 
#define GICR_REG   (*((volatile uint8*)0x5B))
#define INT0 6         //ENABLE INT0
#define INT1 7         //ENABLE INT1
#define INT2 5         //ENABLE INT2

//General Interrupt Flag Register			   
#define GIFR_REG   (*((volatile uint8*)0x5A))
#define INTF0 6
#define INTF1 7
#define INTF2 5

//MCU Control Register (ISC00,ISC01 for INT0) (ISC10,ISC11 for INT1)
#define MCUCR_REG  (*((volatile uint8*)0x55))
#define ISC00 0 
#define ISC01 1
#define ISC10 2
#define ISC11 3

//MCU Control and Status Register (ISC2 for INT2)
#define MCUCSR_REG (*((volatile uint8*)0x54))
#define ISC2 6

//Status Register
#define SREG_REG (*(volatile unsigned char*)0x5F)
#define GIE 7         //Global interrupt Enable

/*<<<<<<<<<<<<<<INTERRUPT Vector Table>>>>>>>>>>>>>>>>*/
//External Interrupt Request 0
#define INT0_VEC __vector_1
//External Interrupt Request 1
#define INT1_VEC __vector_2
//External Interrupt Request 2
#define INT2_VEC __vector_3
//Timer/Counter2 Compare Match
#define TIMER2_COMP_VEC __vector_4
//Timer/Counter2 Overflow
#define TIMER2_OVF_VEC __vector_5
//Timer/Counter1 Capture Event
#define TIMER1_CAPT_VEC __vector_6
//Timer/Counter1 Compare Match A
#define TIMER1_COMPA_VEC __vector_7
//Timer/Counter1 Compare Match B
#define TIMER1_COMPB_VEC __vector_8
//Timer/Counter1 Overflow
#define TIMER1_OVF_VEC __vector_9
//Timer/Counter0 Compare Match
#define  TIMER0_COMP_VEC __vector_10
//Timer/Counter0 Overflow
#define TIMER0_OVF_VEC __vector_11
//Serial Transfer Complete
#define SPI_STC_VEC __vector_12
//USART, Rx Complete
#define USART_RXC_VEC __vector_13
//USART Data Register Empty
#define USART_UDRE_VEC __vector_14
//USART, Tx Complete
#define USART_TXC_VEC __vector_15
//ADC Conversion Complete
#define ADC_VEC __vector_16
//EEPROM Ready
#define EE_RDY_VEC __vector_17
//Analog Comparator
#define ANA_COMP_VEC __vector_18
//Two-wire Serial Interface
#define TWI_VEC __vector_19
//Store Program Memory Ready
#define SPM_RDY_VEC __vector_20

/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)

#define ISR_NOBLOCK __attribute__((interrupt))

#define ISR(vector,...) \
void vector(void) __attribute__((signal))__VA_ARGS__ ; \
void vector(void)

/******************* TIMERS REGISTERS ************************/

/*********TIMER0**********/
#define OCR0_REG  (*((volatile uint8*)0x5C))
#define TIMSK_REG (*((volatile uint8*)0x59))
#define TOIE0 0
#define OCIE0 1

#define TIFR_REG  (*((volatile uint8*)0x58))
#define TOV0  0
#define OCF0  1

#define SPMCR_REG (*((volatile uint8*)0x57))
#define TWCR_REG  (*((volatile uint8*)0x56))
//TCCR0
#define TCCR0_REG (*((volatile uint8*)0x53)) 
#define FOC0   7
#define WGM00  6
#define COM01  5
#define COM00  4
#define WGM01  3
#define CS02   2
#define CS01   1
#define CS00   0

#define TCNT0_REG (*((volatile uint8*)0x52))

/*********TIMER1**********/
#define OSCCAL_REG (*((volatile uint8*)0x51))
#define SFIOR_REG (*((volatile uint8*)0x50))
//TCCR1A
#define TCCR1A_REG (*((volatile uint8*)0x4F))
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0
//TCCR1B
#define TCCR1B_REG (*((volatile uint8*)0x4E))
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12  2
#define CS11  1
#define CS10  0

#define TCNT1H_REG (*((volatile uint8*)0x4D))
#define TCNT1L_REG (*((volatile uint8*)0x4C))
#define OCR1AH_REG (*((volatile uint8*)0x4B))
#define OCR1AL_REG (*((volatile uint8*)0x4A))
#define OCR1BH_REG (*((volatile uint8*)0x49))
#define OCR1BL_REG (*((volatile uint8*)0x48))
#define ICR1H_REG (*((volatile uint8*)0x47))
#define ICR1L_REG (*((volatile uint8*)0x46))

/*********TIMER2**********/
//TCCR2
#define TCCR2_REG (*((volatile uint8*)0x45))
#define FOC2  7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22  2
#define CS21  1
#define CS20  0

#define TCNT2_REG (*((volatile uint8*)0x44))
#define OCR2_REG  (*((volatile uint8*)0x43))
//ASSR
#define ASSR_REG  (*((volatile uint8*)0x43))
#define AS2     3
#define TCN2UB	2
#define OCR2UB	1
#define TCR2UB	0


#endif