/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: DMA  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 SEP 2023	 	**************/
/*********************************************************/

#ifndef DMA_INT_H
#define DMA_INT_H

typedef enum{
    DMA_CHANNEL_1,
    DMA_CHANNEL_2,
    DMA_CHANNEL_3,
    DMA_CHANNEL_4,
    DMA_CHANNEL_5,
    DMA_CHANNEL_6,
    DMA_CHANNEL_7
}DMA_CHANNEL_t;

typedef enum{
    DMA_DIR_PERIPHERAL_TO_MEMORY,
    DMA_DIR_MEMORY_TO_PERIPHERAL,
    DMA_DIR_MEMORY_TO_MEMORY
}DMA_DIR_t;

typedef enum{
    DMA_CIRCULAR_MODE_DISABLE,
    DMA_CIRCULAR_MODE_ENABLE
}DMA_CIRCULAR_MODE_t;

typedef enum{
    DMA_PERIPHERAL_INCREMENT_DISABLE,
    DMA_PERIPHERAL_INCREMENT_ENABLE
}DMA_PERIPHERAL_INCREMENT_t;


typedef enum{
    DMA_MEMORY_INCREMENT_DISABLE,
    DMA_MEMORY_INCREMENT_ENABLE
}DMA_MEMORY_INCREMENT_t;

typedef enum{
    DMA_PERIPHERAL_SIZE_8BITS,
    DMA_PERIPHERAL_SIZE_16BITS,
    DMA_PERIPHERAL_SIZE_32BITS
}DMA_PERIPHERAL_SIZE_t;

typedef enum{
    DMA_MEMORY_SIZE_8BITS,
    DMA_MEMORY_SIZE_16BITS,
    DMA_MEMORY_SIZE_32BITS
}DMA_MEMORY_SIZE_t;

typedef enum{
    DMA_PRIORITY_LOW,
    DMA_PRIORITY_MEDIUM,
    DMA_PRIORITY_HIGH,
    DMA_PRIORITY_VERY_HIGH
}DMA_PRIORITY_t;

typedef enum{
    DMA_INTERRUPT_DISABLE,
    DMA_INTERRUPT_ENABLE
}DMA_INTERRUPT_t;

typedef struct {
    DMA_CHANNEL_t                 channel;
    DMA_DIR_t                     direction;
    DMA_CIRCULAR_MODE_t           circularMode;
    DMA_PERIPHERAL_INCREMENT_t    peripheralIncrement;
    DMA_MEMORY_INCREMENT_t        memoryIncrement;
    DMA_PERIPHERAL_SIZE_t         peripheralSize;
    DMA_MEMORY_SIZE_t             memorySize;
    DMA_PRIORITY_t                priority;
    DMA_INTERRUPT_t               transferErrorInterrupt;
    DMA_INTERRUPT_t               halfTransferInterrupt;
    DMA_INTERRUPT_t               transferCompleteInterrupt;
}DMA_CFG_t;


/**
 * @brief API to initialize the DMA channel based on the selected configuration
 * 
 * @param dmaCfg struct object of type DMA_CFG_t
 */
void DMA_vInit( DMA_CFG_t* dmaCfg );

/**
 * @brief API to start the DMA transaction
 * 
 * @param dmaCfg struct object of type DMA_CFG_t
 * @param A_pu32SourceAddress pointer to the source address
 * @param A_pu32DestinationAddress pointer to the destination address
 * @param A_u16BlockLength length of the block to be transferred
 */
void DMA_vStartTransaction(DMA_CFG_t* dmaCfg, u32 * A_pu32SourceAddress, u32 * A_pu32DestinationAddress, u16 A_u16BlockLength);

/**
 * @brief API to set the callback function
 * 
 * @param callBack pointer to the callback function
 */
void DMA_vSetCallBack(ptr_func_t callBack);

void DMA_vDisable(DMA_CFG_t* dmaCfg);

#endif // DMA_INT_H