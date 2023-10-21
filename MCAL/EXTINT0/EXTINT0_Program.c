/*
 * EXTINT0_Program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Khaled Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTINT0_Interface.h"
#include "EXTINT0_Private.h"
#include "EXTINT0_Config.h"

pf EXTINT0_pfCall;

void EXTINTO_voidEnable(void)
{
	SET_BIT(GICR,6);
}

void EXTINTO_voidDisable(void)
{
	CLR_BIT(GICR,6);
}

void EXTINT0_voidInit(void)
{
#if EXTINT0_SENSE_MODE == EXTINTO_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXTINT0_SENSE_MODE == EXTINTO_ON_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXTINT0_SENSE_MODE == EXTINTO_FALLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif EXTINT0_SENSE_MODE == EXTINTO_RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#else //default as Falling edge
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif
}

void EXTINT0_voidChangeSense(uint8 u8SenseStateCpy)
{
	switch(u8SenseStateCpy)
	{
	case EXTINTO_LOW_LEVEL:
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case EXTINTO_ON_CHANGE:
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case EXTINTO_FALLING_EDGE:
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	case EXTINTO_RISING_EDGE:
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	default:  //default as Falling edge
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	}
}

void EXTINT0_voidSetCallBack(pf pfCallBack)
{
	EXTINT0_pfCall =pfCallBack;
}

void __vector_1(void)  __attribute__ ((signal,used)); //for optimize

void __vector_1(void)
{
	EXTINT0_pfCall();
}

