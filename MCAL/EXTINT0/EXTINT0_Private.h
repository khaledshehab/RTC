/*
 * EXTINT0_Private.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_EXTINT0_EXTINT0_PRIVATE_H_
#define MCAL_EXTINT0_EXTINT0_PRIVATE_H_

#define MCUCR *((volatile uint8 *) 0x55)
#define GICR  *((volatile uint8 *) 0x5B)
#define GIFR  *((volatile uint8 *) 0x5A)



#endif /* MCAL_EXTINT0_EXTINT0_PRIVATE_H_ */
