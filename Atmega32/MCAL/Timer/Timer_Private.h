

#ifndef MCAL_TIMERS_TIMER0_PRIVATE_H_
#define MCAL_TIMERS_TIMER0_PRIVATE_H_

/*************************TIMER0*************************/
/* Timer 0 */
#define TCNT0   (*(volatile u8*)0x52)
#define TCCR0   (*(volatile u8*)0x53)
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TIFR    (*(volatile u8*)0x58)
#define TIMSK   (*(volatile u8*)0x59)
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define TWCR    (*(volatile u8*)0x56)
#define SPMCR   (*(volatile u8*)0x57)
#define OCR0    (*(volatile u8*)0x5C)

/********* Timer 1 *****/
#define TCCR1A			(* ((volatile u8 *)(0x4F)))

#define COM1A1 		7
#define COM1A0 		6
#define COM1B1 		5
#define COM1B0 		4
#define FOC1A 		3
#define FOC1B 		2
#define WGM11 		1
#define WGM10		0

#define TCCR1B			(* ((volatile u8 *)(0x4E)))
#define ICNC1 		7
#define ICES1 		6
#define WGM13 		4
#define WGM12 		3
#define CS12 		2
#define CS11 		1
#define CS10		0

#define TCNT1			(* ((volatile u16 *)(0x4C)))

#define OCR1A			(* ((volatile u16 *)(0x4A)))

#define OCR1B			(* ((volatile u16 *)(0x48)))

#define ICR1			(* ((volatile u16 *)(0x46)))
/****************************** Timer 2 ********************************/

// timer 2 control reg
#define TCCR2   *((volatile u8*)0x45)
#define WGM20   6
#define WGM21   3
#define COM21   5
#define COM20   4
#define CS22    2
#define CS21    1
#define CS20    0
// timer 2 reg
#define TCNT2   *((volatile u8*)0x44)

// output compare reg
#define OCR2    *((volatile u8*)0x43)

// asyn status reg
#define ASSR    *((volatile u8*)0x42)
#define EXCLK   7
#define AS2     3

// special func i\o reg
#define SFIOR   *((volatile u8*)0x50)
#define PUD     2
#define ACME    1


#endif /* MCAL_TIMERS_TIMER_PRIVATE_H_ */
