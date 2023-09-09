/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: SERVICE			**************/
/***********		Component: OS   		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 09 SEPT 2023	 	**************/
/*********************************************************/

#ifndef OS_PRI_H
#define OS_PRI_H

/**
 * @brief This struct is used to define the task
 * 
 */
typedef struct{
    u16 periodicty;
    u16 firstDelay;
    void (*Fptr)(void);
}task_t;

/**
 * @brief Scheduler Function
 * 
 * @note This Function is called by the SysTick ISR
 * @note The scheduler is configured based on the configuration file
 */
static void OS_vScheduler(void);

#endif // OS_PRI_H