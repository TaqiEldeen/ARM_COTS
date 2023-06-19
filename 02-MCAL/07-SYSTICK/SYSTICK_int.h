/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/
#ifndef SYSTICK_INT_H
#define SYSTICK_INT_H

/**
 * @brief Interface Function to Initialize the SYSTICK
 * 
 * @note This Function Must be called before any other function in this module
 *       Initialize the SYSTICK with the configured values in the configuration file
 * 
 */
void SYSTICK_vInit(void);

/**
 * @brief Interface Function to Set the Reload Value
 * 
 * @param A_u32Ticks 
 */
void SYSTICK_vSetReload(u32 A_u32Ticks);

/**
 * @brief Interface Function to get the Elapsed Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetElapsedTicks(void);

/**
 * @brief Interface Function to Get the Remaining Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetRemainingTicks(void);

/**
 * @brief Interface Function to Turn off the SYSTICK
 * 
 */
void SYSTICK_vTurnOff(void);

/**
 * @brief Interface Function to Turn on the SYSTICK
 * 
 */
void SYSTICK_vTurnOn(void);

/**
 * @brief Interface Function to Set the CallBack Function
 * 
 * @param A_ptr_func 
 */
void SYSTICK_vSetCallBack(ptr_func_t A_ptr_func);

#endif // SYSTICK_INT_H