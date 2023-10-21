/*
 * WDT_Program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Khaled Shehab
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_Interface.h"
#include "WDT_Private.h"

void WTD_voidEnable(void)
{
	WDTCR |= (1<<3);
}

void WTD_voidDisable(void)
{
	WDTCR |= (1<<3) | (1<<4);  //0b00011000
	WDTCR = 0x00; //a logic 0 to WDE
}

void WTD_u8Sleep(uint8 u8SleepTime)
{
	WDTCR &= 0b11111000;
	WDTCR |= u8SleepTime;
}
