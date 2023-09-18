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


/**
 * @brief API to initialize the DMA channel based on the selected configuration
 * 
 * @param dmaCfg struct object of type DMA_CFG_t
 */
void DMA_vInit( DMA_CFG_t * dmaCfg ){

}



/**
 * @brief API to start the DMA transaction
 * 
 * @param dmaCfg struct object of type DMA_CFG_t
 * @param A_pu32SourceAddress pointer to the source address
 * @param A_pu32DestinationAddress pointer to the destination address
 * @param A_u16BlockLength length of the block to be transferred
 */
void DMA_vStartTransaction(DMA_CFG_t * A_dmaCfg, u32 * A_pu32SourceAddress, u32 * A_pu32DestinationAddress, u16 A_u16BlockLength){

}




/**
 * @brief API to set the callback function
 * 
 * @param callBack pointer to the callback function
 */
void DMA_vSetCallBack(ptr_func_t callBack){

}