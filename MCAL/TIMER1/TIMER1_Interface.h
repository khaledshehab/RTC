/*
 * TIMER1_Interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Khaled Shehab
 */

#ifndef  MCAL_TIMER1_INTERFACE_H_
#define  MCAL_TIMER1_INTERFACE_H_

#define TIM1_PRESCALER_1              1
#define TIM1_PRESCALER_8              2
#define TIM1_PRESCALER_64             3
#define TIM1_PRESCALER_256            4
#define TIM1_PRESCALER_1024           5
#define TIM1_PRESCALER_ExtT1_Falling  6
#define TIM1_PRESCALER_ExtT1_Rising   7

void TIM1_voidInit(void);
void TIM1_voidEnable(uint8 u8PrescalValCpy);
void TIM1_voidDisable(void);
void TIM1_voidEnableOvfInt(void);
void TIM1_voidDisableOvfInt(void);
void TIM1_voidEnableCmpAInt(void);
void TIM1_voidDisableCmpAInt(void);
void TIM1_voidEnableCmpBInt(void);
void TIM1_voidDisableCmpBInt(void);
void TIM1_voidEnableIcuInt(void);
void TIM1_voidDisableIcuInt(void);
void TIM1_voidSetCallbackOvfInt(pf pfOvfCalbckCpy);
void TIM1_voidSetCallbackCompAInt(pf pfCompACalbckCpy);
void TIM1_voidSetCallbackCompBInt(pf pfCompBCalbckCpy);
void TIM1_voidSetCallbackIcuInt(pf pfIcuCalbckCpy);
void TIM1_voidSetTimerValue(uint16 u16TimValCpy);
void TIM1_voidSetCmpARegValue(uint16 u16CmpAValCpy); //OCR1A
void TIM1_voidSetCmpBRegValue(uint16 u16CmpBValCpy); //OCR1B
void TIM1_voidSetIcuRegValue(uint16 u16IcuValCpy);   //ICR1
uint16 TIM1_u8ReadTimerValue(void);   //TCNT1
uint16 TIM1_u16GetIcuValue (void);


void ICU_voidRisingEdge(void);
void ICU_voidFallenEdge(void);
#endif

