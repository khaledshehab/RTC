/*
 * TIMER0_Interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Khaled Shehab
 */

#ifndef MCAL_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_INTERFACE_H_

#define TIM0_NORMAL_MODE     1
#define TIM0_CTC_MODE        2
#define TIM0_FAST_PWM_MODE   3
#define TIM0_PHASE_PWM_MODE  4


#define TIM0_PRESCALER_1              1
#define TIM0_PRESCALER_8              2
#define TIM0_PRESCALER_64             3
#define TIM0_PRESCALER_256            4
#define TIM0_PRESCALER_1024           5
#define TIM0_PRESCALER_ExtT0_Falling  6
#define TIM0_PRESCALER_ExtT0_Rising   7

void TIM0_voidInit(void);
void TIM0_voidEnable(uint8 u8PreScaler);
void TIM0_voidDisable(void);
void TIM0_voidEnableOvfInt(void);
void TIM0_voidDisableOvfInt(void);
void TIM0_voidEnableCompareInt(void);
void TIM0_voidDisableCompareInt(void);
void TIM0_voidSetCallBackOvfInt(pf pfOvfCallBack);
void TIM0_voidSetCallBackCompareInt(pf pfCompareCallBack);
void TIM0_voidSetTCNTValue(uint8 u8TcntReg);
void TIM0_voidSetOCRValue(uint8 u8OcrReg);
uint8 Tim0_u8ReadTcntReg(void);
uint8 Tim0_u8ReadOcrReg(void);
void TIM0_voidChangeMode(uint8 u8Mode);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
