/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: IR     		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 SEP 2023	 	**************/
/*********************************************************/
#ifndef IR_CFG_H
#define IR_CFG_H

/**
 * @brief This macro is responsible for setting the timer ID
 * 
 */
#define IR_TIMER_ID TIM2_ID

/**
 * @brief   This macro is responsible for setting the timer RCC ID 
 * 
 * @warning This is based on macros defined in RCC_int.h
 * 
 */
#define IR_TIMER_RCC TIM2

/**
 * @brief This macro is responsible for setting the EXTI ID
 * 
 */
#define IR_EXTI_ID EXTI_0


/**
 * @brief This macro is responsible for setting the EXTI RCC ID
 * 
 * @warning This is based on macros defined in RCC_int.h
 * 
 */
#define IR_EXTI_RCC IOPA

/**
 * @brief This macro is responsible for setting the NVIC ID
 * 
 * @warning This is based on macros defined in NVIC_int.h
 * 
 */
#define IR_EXTI_NVIC NVIC_EXTI0

#define IR_EXTI_PORT_ID     PORTA_ID
#define IR_EXTI_PIN         PIN0_ID

#endif /* IR_CFG_H */
