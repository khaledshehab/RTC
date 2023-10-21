/*
 * USART_Private.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_USART_PRIVATE_H_
#define MCAL_USART_PRIVATE_H_

#define USART_DATA_SIZE_5BIT  0
#define USART_DATA_SIZE_6BIT  1
#define USART_DATA_SIZE_7BIT  2
#define USART_DATA_SIZE_8BIT  3
#define USART_DATA_SIZE_9BIT  7

#define USART_ASYNCHRONOUS    0
#define USART_SYNCHRONOUS     1

#define USART_ONE_STOP_BIT    0
#define USART_TWO_STOP_BIT    1

#define USART_NO_PARITY_BIT   0
#define USART_EVEN_PARITY_BIT 2
#define USART_ODD_PARITY_BIT  3

#define USART_BAUD_RATE_2400  207
#define USART_BAUD_RATE_4800  103
#define USART_BAUD_RATE_9600  51
#define USART_BAUD_RATE_14400 34

/* in case synchronous */
#define USART_SETUP_RISING    2
#define USART_SETUP_FALLING   4

#define UDR    *((volatile uint8*) 0x2C)
#define UCSRA  *((volatile uint8*) 0x2B)
#define UCSRB  *((volatile uint8*) 0x2A)
#define UCSRC  *((volatile uint8*) 0x40)
#define UBRRH  *((volatile uint8*) 0x40)
#define UBRRL  *((volatile uint8*) 0x29)

#endif /* MCAL_USART_USART_PRIVATE_H_ */
