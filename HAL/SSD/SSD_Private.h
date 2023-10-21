/*
 * SSD_Private.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled Shehab
 */




#ifndef SSD_PRIVATE_H
#define SSD_PRIVATE_H

#define  COMMON_ANODE       10
#define  COMMON_CATHODE     20


typedef struct
{
    uint8 au8SevCon[7];
    uint8 u8common;
    uint8 u8ConMode;
}tstrSevenSegConfig;

static void SEV_HexToBin(uint8 u8SevIndexCpy,uint8 u8HexCpy );
extern tstrSevenSegConfig SEV_ConfigSet[SEV_MAX_NUM];


#endif


