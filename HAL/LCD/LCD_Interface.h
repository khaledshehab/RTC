/*
 * LCD_Interface.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendChar(uint8 u8IndexCpy, uint8 u8CharCpy);
void LCD_voidSendCommand(uint8 u8IndexCpy, uint8 u8CommandCpy);

void LCD_voidInit(void);


void LCD_voidClrScr(uint8 u8IndexCpy);

void LCD_voidSendNumber(uint8 u8IndexCpy,uint32 u32NumberCpy );

void LCD_voidDisplayHex(uint8 u8IndexCpy,uint16 u16HexNumberCpy );
void LCD_voidMoveCourser(uint8 u8IndexCpy,uint8 u8RowCPy,uint8 u8ColmCpy);

void LCD_voidSendString(uint8 u8IndexCpy, uint8* pau8CharCpy);

#endif
