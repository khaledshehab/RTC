/*
 * ADC_Private.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Khaled Shehab
 */

#ifndef  MCAL_ADC_PRIVATE_H_
#define  MCAL_ADC_PRIVATE_H_


#define ADC_8BIT             0
#define ADC_10BIT            1


#define ADC_AREF             0
#define ADC_AVCC_REF         1
#define ADC_2_56_REF         3


#define ADC_PRESCALLER_2     1
#define ADC_PRESCALLER_4     2
#define ADC_PRESCALLER_8     3
#define ADC_PRESCALLER_16    4
#define ADC_PRESCALLER_32    5
#define ADC_PRESCALLER_64    6
#define ADC_PRESCALLER_128   7

#define ADC_SGL_MODE         9

#define ADCSRA  *((volatile uint8 * ) 0x26 )
#define ADCMUX  *((volatile uint8 * ) 0x27 )
#define ADCH    *((volatile uint8 * ) 0x25 )
#define ADCL    *((volatile uint8 * ) 0x24)
#define SFIOR   *((volatile uint8 * ) 0x50 )





#endif




