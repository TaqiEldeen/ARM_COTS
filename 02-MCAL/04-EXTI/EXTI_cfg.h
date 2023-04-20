/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 17 APRIL 2023	 	**************/
/*********************************************************/

#ifndef EXTI_CFG_H
#define EXTI_CFG_H

/*
*   EXTI_SENSE_CONTROL
*   Options:
*   1- EXTI_SENSE_CONTROL_RISING_EDGE
*   2- EXTI_SENSE_CONTROL_FALLING_EDGE
*   3- EXTI_SENSE_CONTROL_BOTH_EDGES  
*/
#define EXTI_SENSE_CONTROL_LINE0	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE1	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE2	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE3	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE4	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE5	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE6	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE7	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE8	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE9	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE10	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE11	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE12	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE13	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE14	EXTI_SENSE_CONTROL_RISING_EDGE
#define EXTI_SENSE_CONTROL_LINE15	EXTI_SENSE_CONTROL_RISING_EDGE

/*
*   EXTI_LINE0_PIN
*   Options:
*   Choose the pin that will be used as EXTI_LINEX
*/
#define EXTI_LINE0_PIN        PIN0_ID
#define EXTI_LINE1_PIN        PIN1_ID
#define EXTI_LINE2_PIN        PIN2_ID
#define EXTI_LINE3_PIN        PIN3_ID
#define EXTI_LINE4_PIN        PIN4_ID
#define EXTI_LINE5_PIN        PIN5_ID
#define EXTI_LINE6_PIN        PIN6_ID
#define EXTI_LINE7_PIN        PIN7_ID
#define EXTI_LINE8_PIN        PIN8_ID
#define EXTI_LINE9_PIN        PIN9_ID
#define EXTI_LINE10_PIN       PIN10_ID
#define EXTI_LINE11_PIN       PIN11_ID
#define EXTI_LINE12_PIN       PIN12_ID
#define EXTI_LINE13_PIN       PIN13_ID
#define EXTI_LINE14_PIN       PIN14_ID
#define EXTI_LINE15_PIN       PIN15_ID

#endif /* EXTI_CFG_H */