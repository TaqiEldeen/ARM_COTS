/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: 				 	**************/
/***********		Component: 				**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 Apr 2023		 	**************/
/*********************************************************/

/*          LIB Inclusion           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*          MCAL Inclusion          */
#include "UART_int.h"

/*          Module Inclusion           */
#include "ESP_pri.h"
#include "ESP_cfg.h"
#include "ESP_int.h"


/**********************************************************************************************************
 * Description : Interface Function to initialize the ESP WIFI module based on the configuration
 * Outputs     : Error state
 * Inputs      : void
 * NOTES	   : from UART data sheet do not set global interrupts before calling initialize
 ***********************************************************************************************************/
void ESP_vInit(void) {
    /* Initialize the UART */
    UART_vInit();
}

/**********************************************************************************************************
 * Description : Interface Function to Configure the ESP WIFI module
 * Outputs     : void
 * Inputs      : void
 * NOTES	   : Use it to configure the ESP WIFI one time only before release
 ***********************************************************************************************************/
void ESP_vOneTimeConfig(void) {
    /* Configure the Mode of ESP */
    UART_vSendString(ESP_MODE, ESP_UART_ID);
    //_delay_ms(1);   /* Delay to make sure the command is sent */

    /* Connect to target AP */
    UART_vSendString(ESP_AP_CONNECT_CMD, ESP_UART_ID);
    UART_vSendString(ESP_STATION_SSID, ESP_UART_ID);
    UART_vSendByte(',', ESP_UART_ID);
    UART_vSendString(ESP_STATION_PASSWORD, ESP_UART_ID);
    //_delay_ms(1);   /* Delay to make sure the command is sent */
}

/**********************************************************************************************************
 * Description : Interface Function to send a command to the ESP WIFI module
 * Outputs     : void
 * Inputs      : A_pu8Json : JSON string to send, A_u8Length : length of the JSON string
 * NOTES	   : from UART data sheet do not set global interrupts before calling initialize
 ***********************************************************************************************************/
void ESP_vMakeApiReq(u8 *A_pu8Json, u8 A_u8Length) {
    char L_u8Length[4];

    /* Convert the length to string */
    snprintf(L_u8Length, 4, "%d", A_u8Length);

    //UART_vSendStringSync("AT+CIPSTART=\"TCP\","ESP_HTTP_HOST","ESP_HTTP_PORT);
    _delay_ms(5);   /* Delay to make sure the command is sent */

    /*  Prepare API Call  */
    UART_vSendStringSync("AT+CIPSEND=");

    /* Send the JSON: HTTP Header */
    // UART_vSendStringSync(
    //     "POST /api/device/updateStatus HTTP/1.1\r\n"    /* HTTP request */
    //     "Host: 127.0.0.1:5000\r\n"                      /* Host address */
    //     "Content-Type: application/json\r\n"            /* JSON format */
    //     "Content-Length: "L_u8Length"\r\n"              /* Length of the JSON */
    //     "Connection: close\r\n"                         /* Close the connection after sending the request */
    //     "\r\n"                                          /* End of the HTTP request */
    // );

    /* Send the JSON: HTTP Data */
    UART_vSendStringSync(A_pu8Json);

    _delay_ms(50);   /* Delay to make sure the command is sent */
}

/**********************************************************************************************************
 * Description : Interface Function to send a command to the ESP WIFI module
 * Outputs     : void
 * Inputs      : pu8Command : pointer to the command to be sent, u8Length : length of the Data
 * NOTES	   : from UART data sheet do not set global interrupts before calling initialize
 ***********************************************************************************************************/
void ESP_vSendDataWithLength(u8 *pu8Data, u8 u8Length) {

}
