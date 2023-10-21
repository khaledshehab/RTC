/*
 * USART_Interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_USART_INTERFACE_H_
#define MCAL_USART_INTERFACE_H_

void USART_voidInit(void); //
void USART_voidSend(uint16 u16Data); //polling
tenuErrorStatus USART_enuRecieve(uint16* pu16Data); //polling

void USART_voidEnableIntRXComp(void); // RX complete
void USART_voidDisableIntRXComp(void);

void USART_voidEnableIntTXComp(void); // TX complete
void USART_voidDisableIntTXComp(void);

void USART_voidEnableIntTXEmpty(void); // TX data reg. empty
void USART_voidDisableIntTXEmpty(void);

#endif /* MCAL_USART_USART_INTERFACE_H_ */
