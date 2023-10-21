/*
 * STD_TYPES.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled shehab
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

typedef void(*pf)(void);

typedef unsigned char      uint8;
typedef unsigned short int uint16;
typedef unsigned long int  uint32;
typedef signed char        sint8;
typedef signed short int   sint16;
typedef signed long int    sint32;
typedef float              float32;
typedef double             float64;
typedef long double        float128;

typedef enum
{
	EOK,
	ENOK,
	PARAMRETER_OUT_RANGE,
	PARAMETER_NULL_PTR

}tenuErrorStatus;

#define NULL_PTR (void *) 0

#endif /* LIB_STD_TYPES_H_ */
