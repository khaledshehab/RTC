/*
 * LCD_Program.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */


#include "util/delay.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"


void LCD_voidInit(void)
{
	uint8 u8CntLoc;
	uint8 u8commnad=0;
	for (u8CntLoc =0  ; u8CntLoc <MAX_NUM ; u8CntLoc++)
	{
		/*inilize 8 bit */
		if(lcdarr[u8CntLoc].lcdswconfig.u8mode ==LCD_8_BIT_MODE)
		{
			/*step 1*/
			_delay_ms(30);

			u8commnad=0b00110000 |lcdarr[u8CntLoc].lcdswconfig.u8font <<2
					|lcdarr[u8CntLoc].lcdswconfig.u8line<<3 ;
			/* send command */
			voidWriteCmd(u8CntLoc,u8commnad);
			/*more than 39 micro*/
			_delay_ms(1);
			u8commnad=0b00001000 |lcdarr[u8CntLoc].lcdswconfig.u8display<<2 |
									lcdarr[u8CntLoc].lcdswconfig.u8coursorstate<<1 |
									lcdarr[u8CntLoc].lcdswconfig.u8coursorblink<<0 ;

			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);
			voidWriteCmd(u8CntLoc,0x01);
			_delay_ms(3);
			u8commnad=0b00000100 | lcdarr[u8CntLoc].lcdswconfig.u8direction<<1 |

								lcdarr[u8CntLoc].lcdswconfig.u8shift<<0;


			voidWriteCmd(u8CntLoc,u8commnad);
			/*extra delay*/
			_delay_ms(3);


		}
		else
		{
			/*step 1*/
			_delay_ms(30);
			voidWriteCmd(u8CntLoc,0b00100000);

			voidWriteCmd(u8CntLoc,0b00100000);

			u8commnad=0b00000000 |lcdarr[u8CntLoc].lcdswconfig.u8line<<7 |
			lcdarr[u8CntLoc].lcdswconfig.u8font <<6 ;

			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);

			voidWriteCmd(u8CntLoc,0b00000000);

			u8commnad=0b10000000 |lcdarr[u8CntLoc].lcdswconfig.u8display<<6|
			lcdarr[u8CntLoc].lcdswconfig.u8coursorstate<<5 |
			lcdarr[u8CntLoc].lcdswconfig.u8coursorblink<<4 ;
			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);
			voidWriteCmd(u8CntLoc,0b00000000);
			voidWriteCmd(u8CntLoc,0b00010000);
			_delay_ms(3);
			voidWriteCmd(u8CntLoc,0b00000000);

			u8commnad= 0b01000000 | lcdarr[u8CntLoc].lcdswconfig.u8direction<<5 |
					   lcdarr[u8CntLoc].lcdswconfig.u8shift<<4 ;


			voidWriteCmd(u8CntLoc,u8commnad);
			/*extra delay*/
			_delay_ms(3);



		}


	}



}


static void voidWriteCmd(uint8 u8Index , uint8 u8CmdCPy)
 {

	/*RS   0*/
	DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8RS , DIO_LOW);

	/*help*/
	LCDHelp(u8Index,u8CmdCPy);

 }

static void  LCDHelp(uint8 u8Index , uint8 u8dataCmdCPy)
	{
		uint8 u8CntLoc=0;
		/*set to write to lCD */
		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8RW , DIO_LOW);

		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8E , DIO_HIGH);

		if (lcdarr[u8Index].lcdswconfig.u8mode==LCD_8_BIT_MODE)
		{
			for (u8CntLoc =0 ;u8CntLoc<8;u8CntLoc++)
			{
				DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.au8data[u8CntLoc],GET_BIT(u8dataCmdCPy,u8CntLoc));
			}

		}

		else
		{
			for (u8CntLoc =4 ;u8CntLoc<8;u8CntLoc++)
			{
				DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.au8data[u8CntLoc],GET_BIT(u8dataCmdCPy,u8CntLoc));
			}
		}
			/* latch */
		_delay_ms(10);
		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8E , DIO_LOW);
		/*extra delay*/
		_delay_ms(10);
	}

void LCD_voidSendChar(uint8 u8IndexCpy, uint8 u8CharCpy)

{
	/*RS  1*/
	DIO_enuWritePin(lcdarr[u8IndexCpy].lcdhwconfig.u8RS , DIO_HIGH);


	if (lcdarr[u8IndexCpy].lcdswconfig.u8mode==LCD_8_BIT_MODE)
	{
		LCDHelp(u8IndexCpy,u8CharCpy);
		_delay_ms(1);

	}
	else
	{
		LCDHelp(u8IndexCpy,u8CharCpy);
		_delay_ms(1);
		LCDHelp(u8IndexCpy,u8CharCpy<<4);
		_delay_ms(1);

	}

	}



void LCD_voidSendCommand(uint8 u8IndexCpy, uint8 u8CommandCpy)
{
	if (lcdarr[u8IndexCpy].lcdswconfig.u8mode==LCD_8_BIT_MODE)
		{
			voidWriteCmd(u8IndexCpy,u8CommandCpy);
			_delay_ms(1);

		}
		else
		{
			voidWriteCmd(u8IndexCpy,u8CommandCpy);
			_delay_ms(1);
			voidWriteCmd(u8IndexCpy,u8CommandCpy<<4);
			_delay_ms(1);
		}

}



void LCD_voidSendString(uint8 u8IndexCpy, uint8* pau8CharCpy)
{
	uint8 u8CntLoc=0;
	while(pau8CharCpy[u8CntLoc]!= '\0')
			{
				LCD_voidSendChar(u8IndexCpy,pau8CharCpy[u8CntLoc])	;
				u8CntLoc++;
			}
}

void LCD_voidClrScr(uint8 u8IndexCpy)
	{
		LCD_voidSendCommand(u8IndexCpy,0x01);
	}

void LCD_voidSendNumber(uint8 u8IndexCpy,uint32 u32NumberCpy )
{
	uint8 i=0, Num[10]={'\0'};
	do
	{
		Num[i] = (u32NumberCpy%10);
		u32NumberCpy /= 10;
		i++;
	}while(u32NumberCpy != 0);
	i=10;
	while(i != 0)
	{
		i--;
		if(Num[i] != '\0')
		{
			for(int j=i;i>0;i--)
			{
				LCD_voidSendChar(u8IndexCpy,Num[i]+'0');
			}
			break;
		}
	}
	LCD_voidSendChar(u8IndexCpy,Num[0]+'0');
}


void LCD_voidDisplayHex(uint8 u8IndexCpy,uint16 u16HexNumberCpy )
{}
void LCD_voidMoveCourser(uint8 u8IndexCpy,uint8 u8RowCPy,uint8 u8ColmCpy)
{
	uint8 u8commnad=0;
	DIO_enuWritePin(lcdarr[u8IndexCpy].lcdhwconfig.u8RS,DIO_LOW);
	if(u8RowCPy == 1)
	{
		u8commnad = LCD_FIRST_POS_IN_L1 + u8ColmCpy -1;
		LCD_voidSendCommand(u8IndexCpy,u8commnad);
	}
	else if(u8RowCPy == 2)
	{
		u8commnad = LCD_FIRST_POS_IN_L2 + u8ColmCpy -1;
		LCD_voidSendCommand(u8IndexCpy,u8commnad);
	}
	else
	{
		/* NOTHING */
	}
}

