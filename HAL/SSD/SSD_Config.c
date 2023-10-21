/*
 * SSD_Config.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SSD_Config.h"
#include "SSD_Private.h"



tstrSevenSegConfig SEV_ConfigSet[SEV_MAX_NUM]=
{
		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						/* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C0,

				COMMON_ANODE   //20
		},


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						/* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C1,

				COMMON_ANODE
		},

		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						/* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C2,

				COMMON_ANODE
		},


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						/* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C3,

				COMMON_ANODE
		},

		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						/* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C4,

				COMMON_ANODE
		},


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						/* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C5,

				COMMON_ANODE
		}
};
