/*
 * SSD_Program.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SSD_Config.h"
#include "SSD_Interface.h"
#include "SSD_Private.h"




tenuErrorStatus SEV_enuDisplay(uint8 u8SevIndexCpy, uint8 u8NumCpy)
{

	tenuErrorStatus enuReturnLoc =EOK;
	uint8 au8cathode[10] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	if (u8NumCpy<10)
	{
		if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_CATHODE)
		{
			SEV_HexToBin(u8SevIndexCpy,au8cathode[u8NumCpy]);
		}
		else if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_ANODE)
		{
			SEV_HexToBin(u8SevIndexCpy,~au8cathode[u8NumCpy]);
		}
		else
		{
			enuReturnLoc=ENOK;
		}
	}
	else
	{
		enuReturnLoc=PARAMRETER_OUT_RANGE;
	}
	return enuReturnLoc;


}


static void SEV_HexToBin(uint8 u8SevIndexCpy,uint8 u8HexCpy ) // 0b0111111  num 0
{
	uint8 au8BinValuesLoc[7];
	uint8 u8CounterLoc;
	for (u8CounterLoc=0; u8CounterLoc<7;u8CounterLoc++)
	{
		au8BinValuesLoc[u8CounterLoc]=GET_BIT(u8HexCpy,u8CounterLoc);
	}
	DIO_enuWriteGroup(SEV_ConfigSet[u8SevIndexCpy].au8SevCon,au8BinValuesLoc,7);

}

tenuErrorStatus SEV_enuEnable(uint8 u8SevIndexCpy)
{

	tenuErrorStatus enuReturnLoc =EOK;
	if (u8SevIndexCpy < SEV_MAX_NUM)
	{
		if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_CATHODE)
		{
			DIO_enuWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,DIO_LOW);
		}
		else if  (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_ANODE)
		{
			DIO_enuWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,DIO_HIGH);
		}
		else
		{
			enuReturnLoc=ENOK;

		}
	}
	else
	{
		enuReturnLoc =PARAMRETER_OUT_RANGE;
	}

	return enuReturnLoc;
}
tenuErrorStatus SEV_enuDisable(uint8 u8SevIndexCpy)
{
	tenuErrorStatus enuReturnLoc =EOK;
		if (u8SevIndexCpy < SEV_MAX_NUM)
		{
			if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_CATHODE)
			{
				DIO_enuWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,DIO_HIGH);
			}
			else if  (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_ANODE)
			{
				DIO_enuWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,DIO_LOW);
			}
			else
			{
				enuReturnLoc=ENOK;

			}
		}
		else
		{
			enuReturnLoc =PARAMRETER_OUT_RANGE;
		}

		return enuReturnLoc;
}


