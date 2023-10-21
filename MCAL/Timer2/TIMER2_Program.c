/*
 * TIMER2_Program.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Khaled Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER2_Config.h"
#include "TIMER2_Private.h"
#include "TIMER2_Interface.h"

pf TIM2_pfOVFCallBack;
pf TIM2_pfCompareCallBack;

void TIM2_voidInit(void)
{
	/* Select timer mode */
#if TIM2_MODE == TIM2_NORMAL
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#elif TIM2_MODE == TIM2_CTC
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#elif TIM2_MODE == TIM2_FAST_PWM
	SET_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#elif TIM2_MODE == TIM2_PHASE_PWM
	SET_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#else
	/* set normal as default */
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#endif

	/* select wave form on OC2 pin */
#if TIM2_WAVE == TIM2_TOG_OC2
	SET_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);

#elif TIM2_WAVE == TIM2_SET_OC2
	SET_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#elif TIM2_WAVE == TIM2_CLR_OC2
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#elif TIM2_WAVE == TIM2_FAST_INVERT_OC2
	SET_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#elif TIM2_WAVE == TIM2_FAST_NONINVERT_OC2
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#elif TIM2_WAVE == TIM2_PHASE_INVERT_OC2
	SET_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#elif TIM2_WAVE == TIM2_PHASE_NONINVERT_OC2
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#else
	CLR_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);

#endif
}
void TIM2_voidEnable(uint8 u8PreScaler)
{
	TCCR2 &=0b11111000;
	TCCR2 |= (u8PreScaler & 0b00000111); //& 0b00000111 --> to prevent last 5 bits of TCCR2 Reg
}
void TIM2_voidDisable(void)
{
	TCCR2 &=0b11111000;
}
void TIM2_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK,6);
}
void TIM2_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK,6);
}
void TIM2_voidEnableCompareInt(void)
{
	SET_BIT(TIMSK,7);
}
void TIM2_voidDisableCompareInt(void)
{
	CLR_BIT(TIMSK,7);
}
void TIM2_voidSetCallBackOvfInt(pf pfOvfCallBack)
{
	TIM2_pfOVFCallBack = pfOvfCallBack;
}
void TIM2_voidSetCallBackCompareInt(pf pfCompareCallBack)
{
	TIM2_pfCompareCallBack = pfCompareCallBack;
}
void TIM2_voidSetTCNTValue(uint8 u8TcntReg)
{
	TCNT2 = u8TcntReg;
}
void TIM2_voidSetOCRValue(uint8 u8OcrReg)
{
	OCR2 = u8OcrReg;
}
uint8 Tim2_u8ReadTcntReg(void)
{
	return TCNT2;
}

uint8 Tim2_u8ReadOcrReg(void)
{
	return OCR2;
}

void TIM2_voidEnableOutputClk(void)
{
	SET_BIT(ASSR,3);
}


void TIM2_voidChangeMode(uint8 u8Mode)
{
	if (u8Mode == TIM2_NORMAL_MODE)
	{
		CLR_BIT(TCCR2,6);
		CLR_BIT(TCCR2,3);
	}

	else if (u8Mode == TIM2_CTC_MODE)
	{
		CLR_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);
	}

	else if (u8Mode == TIM2_FAST_PWM_MODE)
	{
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);
	}

	else if (u8Mode == TIM2_PHASE_PWM_MODE)
	{
		SET_BIT(TCCR2,6);
		CLR_BIT(TCCR2,3);
	}
	else
	{
		/* Nothing */
	}
}

/* Overflow ISR */

void __vector_5 (void)  __attribute__ ((signal,used));
void __vector_5 (void)
{
	TIM2_pfOVFCallBack();
}

/* Compare ISR */

void __vector_4 (void)  __attribute__((signal,used));
void __vector_4(void)
{
	TIM2_pfCompareCallBack();
}
