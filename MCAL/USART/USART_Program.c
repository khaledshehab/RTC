/*
 * USART_Program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Khaled shehab
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "USART_Config.h"
#include "USART_Interface.h"
#include "USART_Private.h"

void USART_voidInit(void)
{
	uint8 u8TempAloc;
	uint8 u8TempBloc = 0b00011000;
	uint8 u8TempCloc = 0b1000000; //select UCSRC by set bit7

#if USART_DATA_SIZE == USART_DATA_SIZE_5BIT
	CLR_BIT(u8TempCloc,1);
	CLR_BIT(u8TempCloc,2);
	CLR_BIT(u8TempBloc,2);

#elif USART_DATA_SIZE == USART_DATA_SIZE_6BIT
	SET_BIT(u8TempCloc,1);
	CLR_BIT(u8TempCloc,2);
	CLR_BIT(u8TempBloc,2);
#elif USART_DATA_SIZE == USART_DATA_SIZE_7BIT
	CLR_BIT(u8TempCloc,1);
	SET_BIT(u8TempCloc,2);
	CLR_BIT(u8TempBloc,2);
#elif USART_DATA_SIZE == USART_DATA_SIZE_8BIT
	SET_BIT(u8TempCloc,1);
	SET_BIT(u8TempCloc,2);
	CLR_BIT(u8TempBloc,2);
#elif USART_DATA_SIZE == USART_DATA_SIZE_9BIT
	SET_BIT(u8TempCloc,1);
	SET_BIT(u8TempCloc,2);
	SET_BIT(u8TempBloc,2);
#else
	/* default 8Bit size */
	SET_BIT(u8TempCloc,1);
	SET_BIT(u8TempCloc,2);
	CLR_BIT(u8TempBloc,2);
#endif

#if USART_MODE == USART_SYNCHRONOUS
	CLR_BIT(u8TempCloc,6);
#else
	SET_BIT(u8TempCloc,6);
#endif

#if USART_STOP_BIT == USART_ONE_STOP_BIT
	CLR_BIT(u8TempCloc,3);
#else
	SET_BIT(u8TempCloc,3);
#endif

#if USART_PARITY == USART_EVEN_PARITY_BIT
	CLR_BIT(u8TempCloc,4);
	SET_BIT(u8TempCloc,5);
#elif USART_PARITY == USART_ODD_PARITY_BIT
	SET_BIT(u8TempCloc,4);
	SET_BIT(u8TempCloc,5);
#else
	/* NO PARITY */
	CLR_BIT(u8TempCloc,4);
	CLR_BIT(u8TempCloc,5);
#endif

	/* setup --> send at synchronous mode */
#if USART_CLOCK_POLARITY == USART_SETUP_RISING
	CLR_BIT(u8TempCloc,0);
#else
	SET_BIT(u8TempCloc,0);
#endif

	UBRRH = (USART_BAUD_RATE>>8)&0x0f;
	UBRRL = (uint8)USART_BAUD_RATE;
	UCSRB = u8TempBloc;
	UCSRC = u8TempCloc;


}

/*polling*/
void USART_voidSend(uint16 u16Data)
{

	while(GET_BIT(UCSRB,5) == 0);

#if USART_DATA_SIZE == USART_DATA_SIZE_9BIT
	if(GET_BIT(u16Data,8) == 0)
	{
		CLR_BIT(UCSRB,0);
	}
	else
	{
		SET_BIT(UCSRB,0);
	}
#endif
	UDR = u16Data;

}
tenuErrorStatus USART_enuRecieve(uint16* pu16Data)
{
	tenuErrorStatus ErrorState=EOK;
	uint8 u8CheckError=0;
	uint8 u8NineBit;

	while(GET_BIT(UCSRA,7) == 0);
	u8CheckError= UCSRA &0b00011100; //catch errors (FE,DOR,PE)
	if(u8CheckError != 0)
	{
		ErrorState=ENOK;
	}
	else
	{
#if USART_DATA_SIZE == USART_DATA_SIZE_9BIT
	u8NineBit = GET_BIT(UCSRB,1);
	*pu16Data = u8NineBit<<8 | UDR;
#else
	*pu16Data = UDR;
#endif
	}
	return ErrorState;
}

void USART_voidEnableIntRXComp(void)
{
	SET_BIT(UCSRB,7);
}
void USART_voidDisableIntRXComp(void)
{
	CLR_BIT(UCSRB,7);
}

void USART_voidEnableIntTXComp(void)
{
	SET_BIT(UCSRB,6);
}
void USART_voidDisableIntTXComp(void)
{
	CLR_BIT(UCSRB,6);
}

void USART_voidEnableIntTXEmpty(void)
{
	SET_BIT(UCSRB,5);
}
void USART_voidDisableIntTXEmpty(void)
{
	CLR_BIT(UCSRB,5);
}
