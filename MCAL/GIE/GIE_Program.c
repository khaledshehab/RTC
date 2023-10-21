/*
 * GIE_Program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Khaled Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"


void GIE_voidEnable(void)
{
	SET_BIT(SREG,INTERRUPT_PIN);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,INTERRUPT_PIN);
}
