/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: SERVICE			**************/
/***********		Component: OS   		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 09 SEPT 2023	 	**************/
/*********************************************************/


#ifndef OS_CFG_H
#define OS_CFG_H

/**
 * @brief Configure the number of tasks
 * 
 */
#define NUMBER_OF_TASKS 3

/**
 * @brief Configure the tick time in us
 * 
 */
#define TICK_TIME_US 1000

/**
 * Options:
 * 1- PRIORITY_BASED
 * 2- RR        // RoundRobin
 * 3- FCFS      // First Come First Served
 * 
 */
#define OS_SCHEDULER    PRIORITY_BASED
 
#endif // OS_CFG_H