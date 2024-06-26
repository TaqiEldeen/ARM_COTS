/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 17 APRIL 2023	 	**************/
/*********************************************************/
#ifndef EXTI_INT_H
#define EXTI_INT_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_pri.h"
#include "EXTI_reg.h"
#include "EXTI_cfg.h"

/*
 EXTI line 16 is connected to the PVD output
 EXTI line 17 is connected to the RTC Alarm event
 EXTI line 18 is connected to the USB Wakeup event
 EXTI line 19 is connected to the Ethernet Wakeup event (available only in connectivity line devices)
*/

/* Use this as the line needed */
typedef enum
{
    EXTI_0,
    EXTI_1,
    EXTI_2,
    EXTI_3,
    EXTI_4,
    EXTI_5,
    EXTI_6,
    EXTI_7,
    EXTI_8,
    EXTI_9,
    EXTI_10,
    EXTI_11,
    EXTI_12,
    EXTI_13,
    EXTI_14,
    EXTI_15
}EXTI_Line_t;


/**
 * @brief Sense Control for the external interrupt
 * @note  Use this with the EXTI_vSetSenseControl() function
 */
#define EXTI_SENSE_CONTROL_RISING_EDGE      0
#define EXTI_SENSE_CONTROL_FALLING_EDGE     1
#define EXTI_SENSE_CONTROL_BOTH_EDGES       2


/**********************************************************************************************************
 * Description : Interface Function to Intialize the EXTI
 * Outputs     : void
 * Inputs      : void
 * NOTES       : To Enable the EXTI, you have to use the EXTI_vEnable function
 *               Use the AFIO_vSetEXTICfg() function to select the needed pin for a line (EXTI)
 ***********************************************************************************************************/
void EXTI_vInit(u8 A_u8Line, u8 A_u8SenseControl);

/**********************************************************************************************************
 * Description : Interface Function to Enable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vEnable(u8 A_u8Line);

/**********************************************************************************************************
 * Description : Interface Function to Disable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vDisable(u8 A_u8Line);

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Sense Control
 * Outputs     : void
 * Inputs      : line number, sense control
 ***********************************************************************************************************/
void EXTI_vSetSenseControl(u8 A_u8Line, u8 A_u8SenseControl);

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Callback
 * Outputs     : void
 * Inputs      : pointer to function, line number
 ***********************************************************************************************************/
void EXTI_vSetCallback(u8 A_u8Line, ptr_func_t);

/**********************************************************************************************************
 * Description : Interface Function to Clear the EXTI Pending Flag
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vSwTrigger(u8 A_u8Line);

#endif  /* EXTI_INT_H */