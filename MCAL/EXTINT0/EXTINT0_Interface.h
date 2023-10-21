/*
 * EXTINT0_Interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_EXTINT0_EXTINT0_INTERFACE_H_
#define MCAL_EXTINT0_EXTINT0_INTERFACE_H_

#define EXTINTO_LOW_LEVEL     0
#define EXTINTO_ON_CHANGE     1
#define EXTINTO_FALLING_EDGE  2
#define EXTINTO_RISING_EDGE   3

void EXTINTO_voidEnable(void);
void EXTINTO_voidDisable(void);
void EXTINT0_voidInit(void);

void EXTINT0_voidChangeSense(uint8 u8SenseStateCpy);
void EXTINT0_voidSetCallBack(pf pfCallBack);

#endif /* MCAL_EXTINT0_EXTINT0_INTERFACE_H_ */
