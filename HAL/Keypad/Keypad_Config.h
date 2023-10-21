/*
 * Keypad_Config.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */


#include "../../MCAL/DIO/DIO_interface.h"

#ifndef KYEPAD_CONFIG_H
#define KYEPAD_CONFIG_H



/*output*/
#define KPD_COL0    DIO_PIN_NUM_D4
#define KPD_COL1    DIO_PIN_NUM_D5
#define KPD_COL2    DIO_PIN_NUM_D6
#define KPD_COL3    DIO_PIN_NUM_D7

/*input*/
#define KPD_ROW0    DIO_PIN_NUM_D0
#define KPD_ROW1    DIO_PIN_NUM_D1
#define KPD_ROW2    DIO_PIN_NUM_D2
#define KPD_ROW3    DIO_PIN_NUM_D3


#define KPD_PUTTONS    {\
						{'7' , '8', '9',  '/'},\
						{'4' , '5', '6',  '*'},\
						{'1' , '2','3','-'},\
						{'c', '0','=','+'}\
							}






#endif
