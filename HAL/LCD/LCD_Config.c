/*
 * LCD_Config.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */

#include "LCD_Config.h"

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_Private.h"

lcdconfig lcdarr[MAX_NUM]=
{
		{
				{
					LCD_4_BIT_MODE,LCD_TWO_LINE,LCD_FONT_5X7,LCD_COURSOR_ON,
					LCD_COURSOR_BLINK_OFF,LCD_SHIFT_OFF,LCD_DISPLAY_ON,LCD_LTR
				},


				{           /* RS*/         /* RW*/      /* E*/
						DIO_PIN_NUM_B0 ,DIO_PIN_NUM_B1,DIO_PIN_NUM_B2 ,

						{      /*DB0 */              /*DB0 */
								0,0,0,0,
								DIO_PIN_NUM_B6,DIO_PIN_NUM_B5,
								DIO_PIN_NUM_B4,DIO_PIN_NUM_B3
						}


				}
		}
};

