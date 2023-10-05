/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 24 SEP 2023	 	**************/
/*********************************************************/

#ifndef SPI_REG_H
#define SPI_REG_H


#define SPI1_BASE_ADDRESS 0x40013000

typedef struct {
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;

#define SPI1 ((volatile SPI_t*)SPI1_BASE_ADDRESS)

/*   SPI_CR1 bits    */
#define BIDIMODE    15
#define BIDIOE      14
#define CRCEN       13
#define CRCNEXT     12
#define DFF         11
#define RXONLY      10
#define SSM         9
#define SSI         8
#define LSBFIRST    7
#define SPE         6
#define BR          3
#define MSTR        2
#define CPOL        1
#define CPHA        0

/*   SPI_CR2 bits    */
#define TXEIE       7
#define RXNEIE      6
#define ERRIE       5
#define SSOE        2
#define TXDMAEN     1
#define RXDMAEN     0

/*   SPI_SR bits    */
#define BSY         7
#define OVR         6
#define MODF        5
#define CRCERR      4
#define UDR         3
#define CHSIDE      2
#define TXE         1
#define RXNE        0

#endif  /* SPI_REG_H */