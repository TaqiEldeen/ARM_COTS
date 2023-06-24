/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: LM			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 20 JUNE 2023	 	**************/
/*********************************************************/
#ifndef LM_INT_H_
#define LM_INT_H_

/**
 * @brief This function initializes the LED matrix
 * 
 */
void LM_vInit();

/**
 * @brief This function displays the given frame on the LED matrix
 * 
 * @param Ptr_u8Frame The frame to be displayed
 */
void LM_vDisplayFrame(u8* Ptr_u8Frame);

/**
 * @brief Sets the FPS for the LED matrix
 * 
 * @param A_u8FPS The FPS needed
 */
void LM_vSetFPS(u8 A_u8FPS);

#endif /* LM_INT_H_ */