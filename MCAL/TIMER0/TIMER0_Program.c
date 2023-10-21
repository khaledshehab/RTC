/*
 * TIMER0_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Khaled Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_Config.h"
#include "TIMER0_Private.h"
#include "TIMER0_Interface.h"

pf TIM0_pfOVFCallBack;
pf TIM0_pfCompareCallBack;

void TIM0_voidInit(void)
{
	/* Select timer mode */
#if TIM0_MODE == TIM0_NORMAL
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#elif TIM0_MODE == TIM0_CTC
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#elif TIM0_MODE == TIM0_FAST_PWM
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#elif TIM0_MODE == TIM0_PHASE_PWM
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#else
	/* set normal as default */
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#endif

	/* select wave form on OC0 pin */
#if TIM0_WAVE == TIM0_TOG_OC0
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);

#elif TIM0_WAVE == TIM0_SET_OC0
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIM0_WAVE == TIM0_CLR_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIM0_WAVE == TIM0_FAST_INVERT_OC0
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIM0_WAVE == TIM0_FAST_NONINVERT_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIM0_WAVE == TIM0_PHASE_INVERT_OC0
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIM0_WAVE == TIM0_PHASE_NONINVERT_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#else
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);

#endif
}
void TIM0_voidEnable(uint8 u8PreScaler)
{
	TCCR0 &=0b11111000;
	TCCR0 |= (u8PreScaler & 0b00000111); //& 0b00000111 --> to prevent last 5 bits of TCCR0 Reg
}
void TIM0_voidDisable(void)
{
	TCCR0 &=0b11111000;
}
void TIM0_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK,0);
}
void TIM0_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK,0);
}
void TIM0_voidEnableCompareInt(void)
{
	SET_BIT(TIMSK,1);
}
void TIM0_voidDisableCompareInt(void)
{
	CLR_BIT(TIMSK,1);
}
void TIM0_voidSetCallBackOvfInt(pf pfOvfCallBack)
{
	TIM0_pfOVFCallBack = pfOvfCallBack;
}
void TIM0_voidSetCallBackCompareInt(pf pfCompareCallBack)
{
	TIM0_pfCompareCallBack = pfCompareCallBack;
}
void TIM0_voidSetTCNTValue(uint8 u8TcntReg)
{
	TCNT0 = u8TcntReg;
}
void TIM0_voidSetOCRValue(uint8 u8OcrReg)
{
	OCR0 = u8OcrReg;
}
uint8 Tim0_u8ReadTcntReg(void)
{
	return TCNT0;
}

uint8 Tim0_u8ReadOcrReg(void)
{
	return OCR0;
}

void TIM0_voidChangeMode(uint8 u8Mode)
{
	if (u8Mode == TIM0_NORMAL_MODE)
	{CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);}

	else if (u8Mode == TIM0_CTC_MODE)
	{CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);}

	else if (u8Mode == TIM0_FAST_PWM_MODE)
	{SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);}

	else if (u8Mode == TIM0_PHASE_PWM_MODE)
	{SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);}
	else
	{
		/* Nothing */
	}
}

/* Overflow ISR */

void __vector_11 (void)  __attribute__ ((signal,used));
void __vector_11 (void)
{
	TIM0_pfOVFCallBack();
}

/* Compare ISR */

void __vector_10 (void)  __attribute__ ((signal,used));
void __vector_10 (void)
{
	TIM0_pfCompareCallBack();
}
