/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: IR     		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 SEP 2023	 	**************/
/*********************************************************/
#ifndef IR_INT_H_
#define IR_INT_H_


#define IR_MUTE				0b01001001
#define IR_REPEAT			0b01101001
#define IR_OFF				0b01111001
#define IR_PHOTO			0b00000101
#define IR_MUSIC			0b00001001
#define IR_MOVIE			0b00001101
#define IR_STOP				0b00010001
#define IR_UP				0b00010101
#define IR_PAUSE_RESUME		0b00011001
#define IR_LEFT				0b00011101
#define IR_ENTER			0b00100001
#define IR_RIGHT			0b00100101
#define IR_SETUP			0b00101001
#define IR_DOWN				0b01101101
#define IR_MODE				0b01111101
#define IR_VOL_UP			0b00110001
#define IR_REWIND			0b00110101
#define IR_RESTART			0b00111001
#define IR_VOL_DOWN			0b00000001
#define IR_FORWARD			0b00111101
#define IR_END				0b01100101
#define IR_NOT_PRESSED		0b11111111

/**
 * @brief This function is responsible for initializing the IR module
 * 
 * @note 1- intialize the timer module  (GPT)
 *       2- intialize the EXTI0 module
 * 
 */
void IR_vInit(void);

/**
 * @brief This function is responsible for getting the pressed KEY
 * 
 * @note It returns the MACROS defined
 */
u8 IR_u8GetKey(void);

/**
 * @brief This function is responsible for getting the IR frame
 * 
 * @param pu8Data pointer to the data
 */
void IR_vGetFrame(u8 *pu8Data);

/**
 * @brief This function is responsible for setting the callback function
 * 
 * @param cbf pointer to the callback function
 */
void IR_vRegisterCBF(ptr_func_Iu8_Ov cbf);













#endif  /* IR_INT_H_ */
