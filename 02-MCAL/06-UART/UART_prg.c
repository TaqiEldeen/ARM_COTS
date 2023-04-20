/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

/*          LIB Inclusion           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*          Module Inclusion           */
#include "UART_pri.h"
#include "UART_cfg.h"
#include "UART_int.h"
#include "UART_reg.h"


void UART_vInit(void){
    u16 L_u16Mantissa = 0;
    u8 L_u8Fraction = 0;
    #if UART1_STATE == UART_STATE_ENABLED

        SET_BIT(USART1->CR1, UE); // Enable USART1
        SET_BIT(USART1->CR1, TE); // Enable TX
        SET_BIT(USART1->CR1, RE); // Enable RX

        #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
            SET_BIT(USART1->CR1, M); // 9-bit data
        #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

        #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
            SET_BIT(USART1->CR1, PCE); // Enable parity
        #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
            SET_BIT(USART1->CR1, PCE); // Enable parity
            SET_BIT(USART1->CR1, PS);  // Odd parity
        #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

        #if UART_STOP_BIT == UART_STOP_BIT_2
            SET_BIT(USART1->CR2, 13); // 2 stop bits
            CLR_BIT(USART1->CR2, 12);
        #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

        L_u16Mantissa = (u16)UART1_BAUD_RATE;
        L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

        USART1->BRR = (L_u16Mantissa << 4) | L_u8Fraction;

    #endif /* UART1_STATE == UART_STATE_ENABLED */

    #if UART2_STATE == UART_STATE_ENABLED

        SET_BIT(USART2->CR1, UE); // Enable USART2
        SET_BIT(USART2->CR1, TE); // Enable TX
        SET_BIT(USART2->CR1, RE); // Enable RX

        #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
            SET_BIT(USART2->CR1, M); // 9-bit data
        #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

        #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
            SET_BIT(USART2->CR1, PCE); // Enable parity
        #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
            SET_BIT(USART2->CR1, PCE); // Enable parity
            SET_BIT(USART2->CR1, PS);  // Odd parity
        #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

        #if UART_STOP_BIT == UART_STOP_BIT_2
            SET_BIT(USART2->CR2, 13); // 2 stop bits
            CLR_BIT(USART2->CR2, 12);
        #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

        L_u16Mantissa = (u16)UART1_BAUD_RATE;
        L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

        USART2->BRR = (L_u16Mantissa << 4) | L_u8Fraction;

    #endif /* UART2_STATE == UART_STATE_ENABLED */

    #if UART3_STATE == UART_STATE_ENABLED

        SET_BIT(USART3->CR1, UE); // Enable USART1
        SET_BIT(USART3->CR1, TE); // Enable TX
        SET_BIT(USART3->CR1, RE); // Enable RX

        #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
            SET_BIT(USART3->CR1, M); // 9-bit data
        #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

        #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
            SET_BIT(USART3->CR1, PCE); // Enable parity
        #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
            SET_BIT(USART3->CR1, PCE); // Enable parity
            SET_BIT(USART3->CR1, PS);  // Odd parity
        #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

        #if UART_STOP_BIT == UART_STOP_BIT_2
            SET_BIT(USART3->CR2, 13); // 2 stop bits
            CLR_BIT(USART3->CR2, 12);
        #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

        L_u16Mantissa = (u16)UART1_BAUD_RATE;
        L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

        USART3->BRR = (L_u16Mantissa << 4) | L_u8Fraction;

    #endif /* UART3_STATE == UART_STATE_ENABLED */
}

void UART_vSendByte(u8 A_u8Data, UART_ENUM A_u8UartId){
    switch(A_u8UartId){
        case UART1_ID:
            USART1->DR = A_u8Data;
            while(!GET_BIT(USART1->SR, TC));
            break;
        case UART2_ID:
            USART2->DR = A_u8Data;
            while(!GET_BIT(USART2->SR, TC));
            break;
        case UART3_ID:
            USART3->DR = A_u8Data;
            while(!GET_BIT(USART3->SR, TC));
            break;
        default:
            break;
    }
}

void UART_vSendString(u8 *A_u8Data, UART_ENUM A_u8UartId){
    u8 L_u8Index = 0;
    while(A_u8Data[L_u8Index] != '\0'){
        UART_vSendByte(A_u8Data[L_u8Index], A_u8UartId);
        L_u8Index++;
    }
}

u8 UART_u8ReceiveByte(UART_ENUM A_u8UartId){
    u8 L_u8Data = 0;
    switch(A_u8UartId){
        case UART1_ID:
            while(!GET_BIT(USART1->SR, RXNE));
            L_u8Data = USART1->DR;
            break;
        case UART2_ID:
            while(!GET_BIT(USART2->SR, RXNE));
            L_u8Data = USART2->DR;
            break;
        case UART3_ID:
            while(!GET_BIT(USART3->SR, RXNE));
            L_u8Data = USART3->DR;
            break;
        default:
            break;
    }
    return L_u8Data;
}
void UART_vReceiveString(u8 *A_u8Data, UART_ENUM A_u8UartId){
    u8 L_u8Index = 0;
    A_u8Data[L_u8Index] = UART_u8ReceiveByte(A_u8UartId);
    while(A_u8Data[L_u8Index] != '\r'){
        L_u8Index++;
        A_u8Data[L_u8Index] = UART_u8ReceiveByte(A_u8UartId);
    }
    A_u8Data[L_u8Index] = '\0';
}