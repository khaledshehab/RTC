/*
 * TIMER0_Private.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_PRIVATE_H_

#define TIM0_NORMAL    0
#define TIM0_CTC       1
#define TIM0_FAST_PWM  2
#define TIM0_PHASE_PWM 3

/* non pwm mode */
#define TIM0_TOG_OC0   0
#define TIM0_SET_OC0   1
#define TIM0_CLR_OC0   2
/* pwm mode */
#define TIM0_FAST_INVERT_OC0        3
#define TIM0_FAST_NONINVERT_OC0     4

#define TIM0_PHASE_INVERT_OC0       5
#define TIM0_PHASE_NONINVERT_OC0    6

#define TIM0_DISCONNECT             7

#define TCCR0     *((volatile uint8*) 0x53)
#define TCNT0     *((volatile uint8*) 0x52)
#define OCR0      *((volatile uint8*) 0x5C)
#define TIMSK     *((volatile uint8*) 0x59)
#define TIFR      *((volatile uint8*) 0x58)

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
