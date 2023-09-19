/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: DMA  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 SEP 2023	 	**************/
/*********************************************************/


/*  LIB  Inclusion  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*  MCAL Inclusion  */
#include "DMA_int.h"
#include "DMA_pri.h"
#include "DMA_cfg.h"
#include "DMA_reg.h"

/*  Global variables */
static ptr_func_t G_DMA_ISR = ADDRESS_NULL;


/**
 * @brief API to initialize the DMA channel based on the selected configuration
 * 
 * @param dmaCfg struct object of type DMA_CFG_t
 */
void DMA_vInit( DMA_CFG_t * dmaCfg ){
    /*  MEM2MEM mode                */
    if( dmaCfg->direction == DMA_DIR_MEMORY_TO_MEMORY ){
        SET_BIT( DMA1->channel[dmaCfg->channel].CCR, MEM2MEM );
    }
    else{
        CLR_BIT( DMA1->channel[dmaCfg->channel].CCR, MEM2MEM );

        /*  Data transfer direction: MEM2PER or PER2MEM */
        DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->direction << DIR);
    }

    /*  Peripheral increment mode   */
    DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->peripheralIncrement << PINC);

    /*  Memory increment mode       */
    DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->memoryIncrement << MINC);

    /*  Circular mode               */
    DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->circularMode << CIRC);

    /*  Peripheral size             */
    DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->peripheralSize << PSIZE);

    /*  Memory size                 */
    DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->memorySize << MSIZE);

    /*  Channel priority level      */
    DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->priority << PL);

    /* Interrupts states            */
    DMA1->channel[dmaCfg->channel].CCR |= (dmaCfg->halfTransferInterrupt     << HTIE)
                                        | (dmaCfg->transferCompleteInterrupt << TCIE)
                                        | (dmaCfg->transferErrorInterrupt    << TEIE);
}



/**
 * @brief API to start the DMA transaction
 * 
 * @param dmaCfg                    struct object of type DMA_CFG_t
 * @param A_pu32SourceAddress       pointer to the source address
 * @param A_pu32DestinationAddress  pointer to the destination address
 * @param A_u16BlockLength          length of the block to be transferred up to 65535 byte
 */
void DMA_vStartTransaction(DMA_CFG_t * dmaCfg, u32 * A_pu32SourceAddress, u32 * A_pu32DestinationAddress, u16 A_u16BlockLength){
    /* Disable the DMA channel to reload new data   */
    CLR_BIT( DMA1->channel[dmaCfg->channel].CCR, EN );

    /* Load the source and distantion addresses     */
    if(dmaCfg->direction == DMA_DIR_MEMORY_TO_PERIPHERAL) {
        DMA1->channel[dmaCfg->channel].CMAR = A_pu32SourceAddress;
        DMA1->channel[dmaCfg->channel].CPAR = A_pu32DestinationAddress;
    } else if (dmaCfg->direction == DMA_DIR_PERIPHERAL_TO_MEMORY)
    {
        DMA1->channel[dmaCfg->channel].CPAR = A_pu32SourceAddress;
        DMA1->channel[dmaCfg->channel].CMAR = A_pu32DestinationAddress;
    } else {    /* MEM2MEM: Peripheral means source and Memory means destination */
        DMA1->channel[dmaCfg->channel].CPAR = A_pu32SourceAddress;
        DMA1->channel[dmaCfg->channel].CMAR = A_pu32DestinationAddress;
    }

    /* Define the block size for the transaction */
    DMA1->channel[dmaCfg->channel].CNDTR = A_u16BlockLength;

    /* Enable the channel to start the transaction */
    SET_BIT( DMA1->channel[dmaCfg->channel].CCR, EN );
}




/**
 * @brief API to set the callback function
 * 
 * @param callBack pointer to the callback function
 */
void DMA_vSetCallBack(ptr_func_t callBack){
    G_DMA_ISR = callBack;
}


void DMA1_Channel1_IRQHandler(){
    if(G_DMA_ISR != ADDRESS_NULL) {
        G_DMA_ISR();
    }
}