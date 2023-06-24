/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: SERVICE			**************/
/***********		Component: DELAY		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 25 JUNE 2023	 	**************/
/*********************************************************/

#ifndef DELAY_INT_H
#define DELAY_INT_H

/**
 * @brief Init the delay module 
 * 
 * @warning Must put the frequency in MHZ as this EX: A_u8FreqMhz = 8; Means 8 MHZ
 * 
 * @param A_u8AHB_FreqMhz Frequency in MHZ
 */
void DELAY_vInit( u8 A_u8AHB_FreqMhz );

/**
 * @brief Set a delay busy waiting ( Blocking )
 * 
 * @param A_u32DelayMs delay in ms EX: A_u32DelayMs = 1000; Means 1 sec
 */
void DELAY_vSetDelayBusyWait( u32 A_u32DelayMs );

/**
 * @brief Set an Async delay that will be called after the time is up
 * 
 * @param A_u32DelayMs Delay in ms EX: A_u32DelayMs = 1000; Means 1 sec
 * 
 * @param Ptr_Func Function to be called after the time is up
 * 
 * @warning Must first set the callback using the DELAY_vSetCallback( ptr_func_t Ptr_Func )
 */
void DELAY_vSetDelayAsync( u32 A_u32DelayMs, ptr_func_t Ptr_Func );

#endif  /* DELAY_INT_H */