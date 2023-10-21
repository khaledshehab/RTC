/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */


#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/SSD/SSD_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/Keypad/Keypad_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/TIMER2/TIMER2_Interface.h"
#include <util/delay.h>

uint8 u8Key=0xff;
uint8 hours=0,minutes=0,seconds=0;

void Hours(void)
{
	uint8 flag=0;
	LCD_voidClrScr(0);
	LCD_voidSendString(0,"hours=--");
	LCD_voidMoveCourser(0,1,7);
	while(1)
	{
		u8Key = KPD_u8GetPressedKey();
		if(u8Key != 0xff)
		{
			if(u8Key <= '2' && flag == 0 && (u8Key != '/' && u8Key != '*' && u8Key != '+' && u8Key != '-'))
			{
				hours = (u8Key-'0');
				LCD_voidSendChar(0,u8Key);
				flag=1;
			}
			else if(u8Key <= '9' && flag == 1 && (u8Key != '/' && u8Key != '*' && u8Key != '+' && u8Key != '-'))
			{
				LCD_voidSendChar(0,u8Key);
				if(hours == 2)
				{
					if(u8Key <= '3')
					{
						hours = (hours*10) + (u8Key-'0');
						break;
					}
					else
					{
						LCD_voidClrScr(0);
						LCD_voidSendString(0,"No hours > 24");
						_delay_ms(500);
						LCD_voidClrScr(0);
						LCD_voidSendString(0,"hours=--");
						LCD_voidMoveCourser(0,1,7);
						flag=0;
					}
				}
				else
				{
					hours = (hours*10) + (u8Key-'0');
					break;
				}
			}
			else
			{
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"No hours > 24");
				_delay_ms(500);
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"hours=--");
				LCD_voidMoveCourser(0,1,7);
				flag=0;
			}
		}
		else
		{
			/* Nothing */
		}
	}
	Minutes();
}

void Minutes(void)
{
	uint8 flag=0;
	LCD_voidClrScr(0);
	LCD_voidSendString(0,"minutes=--");
	LCD_voidMoveCourser(0,1,9);
	while(1)
	{
		u8Key = KPD_u8GetPressedKey();
		if(u8Key != 0xff)
		{
			if(u8Key <= '5' && flag == 0 && (u8Key != '/' && u8Key != '*' && u8Key != '+' && u8Key != '-'))
			{
				minutes = (u8Key-'0');
				LCD_voidSendChar(0,u8Key);
				flag=1;
			}
			else if(u8Key <= '9' && flag == 1 && (u8Key != '/' && u8Key != '*' && u8Key != '+' && u8Key != '-'))
			{
				LCD_voidSendChar(0,u8Key);
				minutes = (minutes*10) + (u8Key - '0');
				break;
			}
			else
			{
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"No minutes > 60");
				_delay_ms(500);
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"minutes=--");
				LCD_voidMoveCourser(0,1,9);
				flag=0;
			}
		}
		else
		{
			/* Nothing */
		}
	}
	Seconds();
}

void Seconds(void)
{
	uint8 flag=0;
	LCD_voidClrScr(0);
	LCD_voidSendString(0,"seconds=--");
	LCD_voidMoveCourser(0,1,9);
	while(1)
	{
		u8Key = KPD_u8GetPressedKey();
		if(u8Key != 0xff)
		{
			if(u8Key <= '5' && flag == 0 && (u8Key != '/' && u8Key != '*' && u8Key != '+' && u8Key != '-'))
			{
				seconds = (u8Key-'0');
				LCD_voidSendChar(0,u8Key);
				flag=1;
			}
			else if(u8Key <= '9' && flag == 1 && (u8Key != '/' && u8Key != '*' && u8Key != '+' && u8Key != '-'))
			{
				LCD_voidSendChar(0,u8Key);
				seconds = (seconds*10) + (u8Key - '0');
				break;
			}
			else
			{
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"No seconds > 60");
				_delay_ms(500);
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"seconds=--");
				LCD_voidMoveCourser(0,1,9);
				flag=0;
			}
		}
		else
		{
			/* Nothing */
		}
	}
	SEV_enuDisable(0);
	SEV_enuDisable(1);
	SEV_enuDisable(2);
	SEV_enuDisable(3);
	SEV_enuDisable(4);
	SEV_enuDisable(5);

	display();
}

void ISR(void)
{
	if(seconds<59)
	{
		seconds++;
	}
	else
	{
		if(minutes<59)
		{
			minutes++;
			seconds=0;
		}
		else
		{
			if(hours<23)
			{
				hours++;
				minutes=0;
				seconds=0;
			}
			else
			{
				hours=0;
				minutes=0;
				seconds=0;
			}
		}
	}
}

void display(void)
{
	TIM2_voidInit();
	TIM2_voidEnableOutputClk();
	TIM2_voidEnable(5);
	TIM2_voidEnableOvfInt();
	LCD_voidClrScr(0);
	LCD_voidSendString(0,"RTC Started...");
	TIM2_voidSetCallBackOvfInt(ISR);
	while(1)
	{
		SEV_enuDisplay(0,(hours/10));
		SEV_enuEnable(0);
		_delay_ms(3);
		SEV_enuDisable(0);
		SEV_enuDisplay(1,(hours%10));
		SEV_enuEnable(1);
		_delay_ms(3);
		SEV_enuDisable(1);
		SEV_enuDisplay(2,(minutes/10));
		SEV_enuEnable(2);
		_delay_ms(3);
		SEV_enuDisable(2);
		SEV_enuDisplay(3,(minutes%10));
		SEV_enuEnable(3);
		_delay_ms(3);
		SEV_enuDisable(3);
		SEV_enuDisplay(4,(seconds/10));
		SEV_enuEnable(4);
		_delay_ms(3);
		SEV_enuDisable(4);
		SEV_enuDisplay(5,(seconds%10));
		SEV_enuEnable(5);
		_delay_ms(3);
		SEV_enuDisable(5);
	}
}

int main (void)
{

	DIO_voidInit();
	LCD_voidInit();
	KPD_voidInit();
	GIE_voidEnable();
	LCD_voidClrScr(0);
	LCD_voidSendString(0,"Press 1 to");
	LCD_voidMoveCourser(0,2,1);
	LCD_voidSendString(0,"set clock");
	while(1)
	{
		u8Key = KPD_u8GetPressedKey();
		if(u8Key != 0xff)
		{
			if(u8Key == '1')
			{
				Hours();
			}
			else
			{
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"Wrong choice");
				_delay_ms(500);
				LCD_voidClrScr(0);
				LCD_voidSendString(0,"Press 1 to");
				LCD_voidMoveCourser(0,2,1);
				LCD_voidSendString(0,"set clock");
			}
		}
		else
		{
			/* Nothing */
		}
	}
}

