/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 24 SEP 2023	 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "SPI_pri.h"
#include "SPI_int.h"
#include "SPI_cfg.h"
#include "SPI_reg.h"


/**
 * @brief   This function is used to initialize the SPI peripheral
 * 
 */
void SPI_vInit(void){
    /* Apply the configuration */
    SPI1->CR1 |=  (BI_DIRECTION_MODE    << BIDIMODE )
                | (BI_DIRECTION_OUTPUT  << BIDIOE   )
                | (RECEIVE_ONLY         << RXONLY   )
                | (USE_CRC              << CRCEN    )
                | (DATA_FRAME           << DFF      )
                | (USE_SSM              << SSM      )
                | (SSI_VAL              << SSI      )
                | (DATA_ORDER           << LSBFIRST )
                | (BAUD_RATE            << BR       )
                | (SPI_MODE             << MSTR     )
                | (CLOCK_POL            << CPOL     )
                | (CLOCK_PHA            << CPHA     )   ;
    
    SPI1->CR2 |= (SS_OUTPUT_EN << SSOE);

    /* Enable the SPI */
    SET_BIT( SPI1->CR1, SPE );
}
 
/**
 * @brief   This function is used to send a byte of data using busy wait
 * 
 * @param   A_u8SlavePort: The port of the slave
 * @param   A_u8SlavePin: The pin of the slave
 * 
 * @param   A_u8Data: The data to be sent
 */
void SPI_vSendByte(u8 A_u8SlavePort, u8 A_u8SlavePin, u8 A_u8Data){
    /* Activate the slave */
    DIO_vSetPinVal(A_u8SlavePort, A_u8SlavePin, VAL_LOW);

    /* Send The Data */
    SPI1->DR = A_u8Data;

    /* Wait until the transmission is complete */
    while( GET_BIT( SPI1->SR, BSY ) == 1 );

    /* Deactivate the slave */
    DIO_vSetPinVal(A_u8SlavePort, A_u8SlavePin, VAL_HIGH);
}

/**
 * @brief   This function is used to receive a byte of data
 * 
 * @param   A_u8SlavePort: The port of the slave
 * @param   A_u8SlavePin: The pin of the slave
 * 
 * @return  u8: The received data
 */
u8 SPI_u8ReceiveByte(u8 A_u8SlavePort, u8 A_u8SlavePin){

}

/**
 * @brief   This function is used to send a string of data using busy wait
 * 
 * @param   A_u8Data: The String to be sent
 * @param   A_u8SlavePort: The port of the slave
 * @param   A_u8SlavePin: The pin of the slave
 * 
 * @note    The string must be terminated by '\0'
 */
void SPI_vSendString(u8 A_u8SlavePort, u8 A_u8SlavePin, u8* A_u8Data){
    /* Activate the slave */
    DIO_vSetPinVal(A_u8SlavePort, A_u8SlavePin, VAL_LOW);


    /* Send The String */
    while (A_u8Data != '\0')
    {
        SPI1->DR = *A_u8Data;
        A_u8Data++;
        /* Wait until the transmission is complete */
        while( GET_BIT( SPI1->SR, BSY ) == 1 );
    }

    /* Deactivate the slave */
    DIO_vSetPinVal(A_u8SlavePort, A_u8SlavePin, VAL_HIGH);
}

/**
 * @brief   This function is used to receive a string of data
 * 
 * @param   A_u8Data: The received stgring
 * @param   A_u8SlavePort: The port of the slave
 * @param   A_u8SlavePin: The pin of the slave
 * 
 * @note    The string must be terminated by '\0'
 */
void SPI_vReceiveString(u8 A_u8SlavePort, u8 A_u8SlavePin, u8* A_u8Data){
    /* Activate the slave */
    DIO_vSetPinVal(A_u8SlavePort, A_u8SlavePin, VAL_LOW);

    /* Receive The String */
    do 
    {
        *A_u8Data = SPI1->DR;
        A_u8Data++;

        /* Wait until the transmission is complete */
        while( GET_BIT( SPI1->SR, BSY ) == 1 );

    } while (*A_u8Data != '\0');

    /* Deactivate the slave */
    DIO_vSetPinVal(A_u8SlavePort, A_u8SlavePin, VAL_HIGH);
}

/**
 * @brief   This function is used to send and receive a byte of data
 * 
 * @param   A_u8Data: The data to be sent
 * @return  u8: The received data
 */
u8 SPI_u8TransmitReceive(u8 A_u8Data){
    /* Wait until the transmission  buffer is empty */
    while( GET_BIT( SPI1->SR, TXE ) == 0 );

    /* Send The Data */
    SPI1->DR = A_u8Data;

    /* Wait until the receive buffer is full */
    while( GET_BIT( SPI1->SR, RXNE ) == 0 );

    /* Return the received data */
    return SPI1->DR;
}
