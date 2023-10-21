/*
 * DIO_Interface.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#define DIO_LOW     0
#define DIO_HIGH    1

#define DIO_ACTIVATE_PULLUP     1
#define DIO_DEACTIVATE_PULLUP   0

#define DIO_PIN_NUM_A0   0
#define DIO_PIN_NUM_A1   1
#define DIO_PIN_NUM_A2   2
#define DIO_PIN_NUM_A3   3
#define DIO_PIN_NUM_A4   4
#define DIO_PIN_NUM_A5   5
#define DIO_PIN_NUM_A6   6
#define DIO_PIN_NUM_A7   7

#define DIO_PIN_NUM_B0   8
#define DIO_PIN_NUM_B1   9
#define DIO_PIN_NUM_B2   10
#define DIO_PIN_NUM_B3   11
#define DIO_PIN_NUM_B4   12
#define DIO_PIN_NUM_B5   13
#define DIO_PIN_NUM_B6   14
#define DIO_PIN_NUM_B7   15

#define DIO_PIN_NUM_C0   16
#define DIO_PIN_NUM_C1   17
#define DIO_PIN_NUM_C2   18
#define DIO_PIN_NUM_C3   19
#define DIO_PIN_NUM_C4   20
#define DIO_PIN_NUM_C5   21
#define DIO_PIN_NUM_C6   22
#define DIO_PIN_NUM_C7   23

#define DIO_PIN_NUM_D0   24
#define DIO_PIN_NUM_D1   25
#define DIO_PIN_NUM_D2   26
#define DIO_PIN_NUM_D3   27
#define DIO_PIN_NUM_D4   28
#define DIO_PIN_NUM_D5   29
#define DIO_PIN_NUM_D6   30
#define DIO_PIN_NUM_D7   31

void DIO_voidInit(void);
tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy, uint8 u8PinValueCpy);
tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy, uint8* pu8PinValue);
tenuErrorStatus DIO_enuWriteGroup(uint8* pau8PinNumCpy, uint8* pau8PinValueCpy,uint8 u8SizeCpy);
tenuErrorStatus DIO_enuStatePullup(uint8 u8PinNumCpy, uint8 u8StateCpy);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
