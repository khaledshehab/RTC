/*
 * ADC_Interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Khaled Shehab
 */

#ifndef  MCAL_ADC_INTERFACE_H_
#define  MCAL_ADC_INTERFACE_H_

/* inilize the mode single or free rrunning , mbit or 10 bit and prescaler and Vref */
void ADC_voidInit(void);

void ADC_voidEnable(void);

void ADC_voidDisable(void);

void ADC_voidEnableInterrupt(void);

void ADC_voidDisableInterrupt(void);

void ADC_voidSetCallback(pf pfCallbackCpy);

void ADC_voidStartConversion(uint8 u8ChannelNbCpy);

void ADC_voidChangeMode(uint8 u8ModeCpy);

 /* read the vlaue from ADC polling method*/
uint16 ADC_u16ReadSync(uint8 u8ChannelNbCpy);
/* read the vlaue from ADC Interrupt method*/
uint16 ADC_u16ReadAsync(void);



#endif

