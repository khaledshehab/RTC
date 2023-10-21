/*****************************************************************/
/* Author  : Khaled Shehab                                       */
/* SWC     : SPI                                                 */
/* Version : 1.0                                                 */
/* Date    : 21 Aug 2023                                         */
/*****************************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_DATA_MSB  0
#define SPI_DATA_LSB  1

#define SPI_SLAVE   0
#define SPI_MASTER  1

#define SPI_CLK_IDLE_LOW   0
#define SPI_CLK_IDLE_HIGH  1



#define SPCR *((volatile uint8*) 0x2D)
#define SPSR *((volatile uint8*) 0x2E)
#define SPDR *((volatile uint8*) 0x2F)

#endif
