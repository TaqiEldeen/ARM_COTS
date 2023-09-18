/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: DMA  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 SEP 2023	 	**************/
/*********************************************************/

#ifndef DMA_REG_H
#define DMA_REG_H

#define DMA1_BASE_ADDRESS 0x40020000

/**
 * @brief DMA Channel Registers
 * 
 */
typedef struct {
    u32 CCR;
    u32 CNDTR;
    u32 CPAR;
    u32 CMAR;
    u32 Reserved;
}DMA_CHANNEL_t;

/**
 * @brief DMA Registers
 * 
 */
typedef struct{
    u32 ISR;
    u32 IFCR;
    DMA_CHANNEL_t channel[7];
}DMA_t;

#define DMA1 ((volatile DMA_t*) DMA1_BASE_ADDRESS)

/*      DMA_ISR             */
#define GIF1    0
#define TCIF1   1
#define HTIF1   2
#define TEIF1   3


/*      DMA_IFCR bits       */
#define CGIF1   0
#define CTCIF1  1
#define CHTIF1  2
#define CTEIF1  3


/*      DMA_CCR bits        */
#define EN      0
#define TCIE    1
#define HTIE    2
#define TEIE    3
#define DIR     4
#define CIRC    5
#define PINC    6
#define MINC    7
#define PSIZE   8
#define MSIZE   10
#define PL      12
#define MEM2MEM 14



#endif // DMA_REG_H 