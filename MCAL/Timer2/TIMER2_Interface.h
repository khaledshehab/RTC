/*
 * TIMER2_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_TIMER2_INTERFACE_H_
#define MCAL_TIMER2_INTERFACE_H_

#define TIM2_NORMAL_MODE     1
#define TIM2_CTC_MODE        2
#define TIM2_FAST_PWM_MODE   3
#define TIM2_PHASE_PWM_MODE  4


#define TIM2_PRESCALER_1              1
#define TIM2_PRESCALER_8              2
#define TIM2_PRESCALER_32             3
#define TIM2_PRESCALER_64             4
#define TIM2_PRESCALER_128            5
#define TIM2_PRESCALER_256            6
#define TIM2_PRESCALER_1024           7

void TIM2_voidInit(void);
void TIM2_voidEnable(uint8 u8PreScaler);
void TIM2_voidDisable(void);
void TIM2_voidEnableOvfInt(void);
void TIM2_voidDisableOvfInt(void);
void TIM2_voidEnableCompareInt(void);
void TIM2_voidDisableCompareInt(void);
void TIM2_voidSetCallBackOvfInt(pf pfOvfCallBack);
void TIM2_voidSetCallBackCompareInt(pf pfCompareCallBack);
void TIM2_voidSetTCNTValue(uint8 u8TcntReg);
void TIM2_voidSetOCRValue(uint8 u8OcrReg);
void TIM2_voidEnableOutputClk(void);
uint8 Tim2_u8ReadTcntReg(void);
uint8 Tim2_u8ReadOcrReg(void);
void TIM2_voidChangeMode(uint8 u8Mode);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
