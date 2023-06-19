/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: 				 	**************/
/***********		Component: 				**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 Apr 2023		 	**************/
/*********************************************************/

#ifndef HAL_ESP_ESP_CFG_H_
#define HAL_ESP_ESP_CFG_H_

#define ESP_UART_ID     UART2_ID

/*
* ESP_MODE
* Options:
* 1- STATION_MODE
* 2- SOFTAP_MODE
* 3- STATIONAP_MODE
*/
#define ESP_MODE STATION_MODE

/*
* ESP_STATION_SSID
* Options:
* Enter the SSID of the network you want to connect to
*/
#define ESP_STATION_SSID "TaqiEldeen"

/*
* ESP_STATION_PASSWORD
* Options:
* Enter the password of the network you want to connect to
*/
#define ESP_STATION_PASSWORD "123456789"


/**
 * @brief HTTP API Configuration
 */
#define ESP_HTTP_API            "/api/device/updateStatus"
#define ESP_HTTP_HOST           "127.0.0.1"
#define ESP_HTTP_PORT           5000UL
#define ESP_HTTP_CONTENT_TYPE   "application/json"



#endif /* HAL_ESP_ESP_CFG_H_ */
