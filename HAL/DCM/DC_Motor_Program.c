/*
 * DC_Motor_Program.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Khaled Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../DCM/DC_Motor_Config.h"
#include "../DCM/DC_Motor_Interface.h"

void DCM_voidRotateCW(void)
{
	DIO_enuWritePin(DCM_PIN0,DIO_LOW);
	DIO_enuWritePin(DCM_PIN1,DIO_HIGH);
}

void DCM_voidRotateCCW(void)
{
	DIO_enuWritePin(DCM_PIN0,DIO_HIGH);
	DIO_enuWritePin(DCM_PIN1,DIO_LOW);
}

void DCM_voidStop(void)
{
	DIO_enuWritePin(DCM_PIN0,DIO_LOW);
	DIO_enuWritePin(DCM_PIN1,DIO_LOW);
}
