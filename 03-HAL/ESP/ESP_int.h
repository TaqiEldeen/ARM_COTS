/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: 				 	**************/
/***********		Component: 				**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 Apr 2023		 	**************/
/*********************************************************/

#ifndef HAL_ESP_ESP_INT_H_
#define HAL_ESP_ESP_INT_H_

/**********************************************************************************************************
 * Description : Interface Function to initialize the ESP WIFI module based on the configuration
 * Outputs     : void
 * Inputs      : void
 * NOTES	   : from UART data sheet do not set global interrupts before calling initialize
 ***********************************************************************************************************/
void ESP_vInit(void);

/**********************************************************************************************************
 * Description : Interface Function to send a command to the ESP WIFI module
 * Outputs     : void
 * Inputs      : pu8Command : pointer to the command to be sent
 * NOTES	   : from UART data sheet do not set global interrupts before calling initialize
 ***********************************************************************************************************/
void ESP_vSendCommand(u8 *pu8Command);

/**********************************************************************************************************
 * Description : Interface Function to send a command to the ESP WIFI module
 * Outputs     : void
 * Inputs      : pu8Command : pointer to the command to be sent, u8Length : length of the Data
 * NOTES	   : from UART data sheet do not set global interrupts before calling initialize
 ***********************************************************************************************************/
void ESP_vSendDataWithLength(u8 *pu8Data, u8 u8Length);


#endif /* HAL_ESP_ESP_INT_H_ */
