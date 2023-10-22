/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 24 SEP 2023	 	**************/
/*********************************************************/

#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/**
 * @brief  Bidirectional data mode enable
 * 
 * Used if wanting only one line ( Bi-direction ) Half-Duplex
 * 
 * 
 * Options:
 * 1- ENABLE
 * 2- DISABLE
 * 
 */
#define BI_DIRECTION_MODE    DISABLE 

/**
 * @brief  Output enable in bidirectional mode
 * 
 * Used if enabled the BI_DIRECTION_MODE
 * 
 * Options:
 * 1- RECEIVE_ONLY
 * 2- TRANSMIT_ONLY
 * 3- NULL          
 */
#define BI_DIRECTION_OUTPUT          NULL

/**
 * @brief This bit combined with the BIDImode bit selects the direction of transfer in 2-line 
 *        unidirectional mode. This bit is also useful in a multislave system in which this particular 
 *        slave is not accessed
 * 
 * Options:
 * 1- FULL_DUPLEX
 * 2- OUTPUT_DISABLED
 */
#define RECEIVE_ONLY    FULL_DUPLEX

/**
 * @brief Hardware CRC calculation enable
 * 
 * Used if wanting an error checking in SPI
 * 
 * Options:
 * 1- ENABLE
 * 2- DISABLE
 * 
 */
#define USE_CRC     DISABLE


/**
 * @brief Data frame format
 * 
 * Used to define the length of the data frame
 * 
 * Options:
 * 1- EIGHT_BIT
 * 2- SIXTEEN_BIT
 * 
 */
#define DATA_FRAME      EIGHT_BIT

/**
 * @brief Software slave management
 * 
 * Control the NSS by software ( Automatically )
 * 
 * Options:
 * 1- ENABLE
 * 2- DISABLE
 * 
 */
#define USE_SSM     ENABLE

/**
 * @brief   Internal slave select
 * 
 * Used to select the master or slave
 * 
 * Options:
 * 1- 1
 * 2- 0
 * 
 */
#define SSI_VAL     1

/**
 * @brief   Slave select output enable
 * 
 * Used to enable the slave select pin
 * 
 * Options:
 * 1- ENABLE
 * 2- DISABLE
 * 
 */
#define SS_OUTPUT_EN   DISABLE

/**
 * @brief Used to send MSB first or LSB first
 * 
 * Options:
 * 1- MSB_FIRST
 * 2- LSB_FIRST
 * 
 */
#define DATA_ORDER  MSB_FIRST

/**
 * @brief   Baud rate control
 * 
 * Options:
 * 
 * 1- DIV_2
 * 2- DIV_4
 * 3- DIV_8
 * 4- DIV_16
 * 5- DIV_32
 * 6- DIV_64
 * 7- DIV_128
 * 8- DIV_256
 * 
 */
#define BAUD_RATE   DIV_8

/**
 * @brief    Master selection
 * 
 * Options:
 * 1- MASTER_MODE
 * 2- SLAVE_MODE 
 * 
 */
#define SPI_MODE    MASTER_MODE

/**
 * @brief 
 * 
 * Options:
 * 1- IDLE_LOW
 * 2- IDLE_HIGH
 * 
 */
#define CLOCK_POL   IDLE_LOW

/**
 * @brief 
 * 
 * Options:
 * 1- SAMPLE_LEADING        (CAPTURE)
 * 2- SAMPLE_TRAILING
 * 
 */
#define CLOCK_PHA   SAMPLE_LEADING

/**
 * @brief Interrupt modes
 * 
 * Options:
 * 1- ENABLE
 * 2- DISABLE
 * 
 */
#define TX_BUFFER_EMPTY_INT         DISABLE
#define RX_BUFFER_NOT_EMPTY_INT     DISABLE
#define ERR_INT                     DISABLE


#endif  /* SPI_CFG_H_ */
