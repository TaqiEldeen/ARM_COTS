/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef UART_INT_H
#define UART_INT_H

typedef enum {
    UART1_ID,
    UART2_ID,
    UART3_ID
}UART_ENUM;

void UART_vInit(void);
void UART_vSendByte(u8 A_u8Data, UART_ENUM A_u8UART_ID);
void UART_vSendString(u8 *A_u8Data, UART_ENUM A_u8UART_ID);
u8 UART_u8ReceiveByte(UART_ENUM A_u8UART_ID);
void UART_vReceiveString(u8 *A_u8Data, UART_ENUM A_u8UART_ID);


#endif /* UART_INT_H */