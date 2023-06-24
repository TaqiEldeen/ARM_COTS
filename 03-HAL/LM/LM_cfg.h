/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: LM			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 20 JUNE 2023	 	**************/
/*********************************************************/
#ifndef LM_CFG_H_
#define LM_CFG_H_

/**
 * @brief The ports to which the ROW and Coloumn pins are connected
 * 
 */
#define LM_ROW_PORT		PORTA_ID
#define LM_COL_PORT		PORTB_ID

/**
 * @brief Put the size of your LED matrix
 * 
 */
#define LM_COL_NUM      8
#define LM_ROW_NUM      8


/**
 * @brief This is used to define the ROW pins
 * 
 * @note  Assumes that this LED matrix is 8x8
 */
#define LM_ROW0         PIN0_ID
#define LM_ROW1         PIN1_ID
#define LM_ROW2         PIN2_ID
#define LM_ROW3         PIN3_ID
#define LM_ROW4         PIN4_ID
#define LM_ROW5         PIN5_ID
#define LM_ROW6         PIN6_ID
#define LM_ROW7         PIN7_ID


/**
 * @brief This is used to define the COL pins
 * 
 * @note  Assumes that this LED matrix is 8x8
 */
#define LM_COL0         PIN0_ID
#define LM_COL1         PIN1_ID
#define LM_COL2         PIN2_ID
#define LM_COL3         PIN5_ID
#define LM_COL4         PIN6_ID
#define LM_COL5         PIN7_ID
#define LM_COL6         PIN8_ID
#define LM_COL7         PIN9_ID

/**
 * @brief The frequency of the LED matrix
 * 
 * @note This is used to calculate the time of each frame
 * 
 */
#define LM_FREQ 50

#endif /* LM_CFG_H_ */