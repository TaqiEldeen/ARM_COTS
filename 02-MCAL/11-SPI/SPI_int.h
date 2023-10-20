/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 24 SEP 2023	 	**************/
/*********************************************************/

#ifndef SPI_INT_H
#define SPI_INT_H

/**
 * @brief   This function is used to initialize the SPI peripheral
 * 
 */
void SPI_vInit(void);

/**
 * @brief   This function is used to send a byte of data
 * 
 * @param   A_u8Data: The data to be sent
 */
void SPI_vSendByte(u8 A_u8SlavePort, u8 A_u8SlavePin, u8 A_u8Data);

/**
 * @brief   This function is used to receive a byte of data
 * 
 * @return  u8: The received data
 */
u8 SPI_u8ReceiveByte(u8 A_u8SlavePort, u8 A_u8SlavePin);

/**
 * @brief   This function is used to send a string of data
 * 
 * @param   A_u8Data: The String to be sent
 */
void SPI_vSendString(u8 A_u8SlavePort, u8 A_u8SlavePin, u8* A_u8Data);

/**
 * @brief   This function is used to receive a string of data
 * 
 * @param   A_u8Data: The received stgring
 */
void SPI_vReceiveString(u8 A_u8SlavePort, u8 A_u8SlavePin, u8* A_u8Data);

/**
 * @brief   This function is used to send and receive a byte of data
 * 
 * @param   A_u8Data: The data to be sent
 * @return  u8: The received data
 */
u8 SPI_u8TransmitReceive(u8 A_u8Data);

#endif  /* SPI_INT_H */