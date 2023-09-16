/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: IR     		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 SEP 2023	 	**************/
/*********************************************************/
#ifndef IR_PRI_H
#define IR_PRI_H

/**
 * @brief This macro is responsible for setting the timer prescaler to get 1us tick time
 * 
 */
#define IR_TIMER_PRESCALER    1

/**
 * @brief For Logic one it must be 2250US but we will check if it is greater than 2000US for making sure
 * 
 */
#define IR_LOGIC_ONE_US      2000

/**
 * @brief For Logic ZERO it must be 1125US but we will check if it is greater than 1000US for making sure
 * 
 */
#define IR_LOGIC_ZERO_US     1000

/**
 * @brief For START it must be 13.5ms but we will check if it is greater than 13000US for making sure
 * 
 */
#define IR_START_US          13000

/**
 * @brief For START it must be 9ms + 2.25ms but we will check if it is greater than 10000US for making sure
 *
 */
#define IR_REPEAT_US		 10000


/**
 * @brief 
 * 
*/
typedef enum {
    IR_START,
    IR_IDLE,
	IR_ADR_FIELD,
	IR_ADR_INV_FIELD,
	IR_CMD_FIELD,
	IR_CMD_INV_FIELD,
	IR_REPEAT_STATE
}IR_STATE_t;

/**
 * @brief 
 * 
 */
static void IR_vHandler(void);




#endif /* IR_PRI_H */
