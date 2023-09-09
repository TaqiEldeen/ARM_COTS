/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: SERVICE			**************/
/***********		Component: OS   		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 09 SEPT 2023	 	**************/
/*********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "OS_pri.h"
#include "OS_cfg.h"
#include "OS_int.h"

#include "SYSTICK_int.h"

/****************************   Global Variables    ****************************/


/**
 * @brief the array of tasks
 * 
 */
static task_t OS_Tasks[NUMBER_OF_TASKS];




/****************************   APIs    ****************************/


/**
 * @brief start the OS
 * 
 */
void OS_vStart(void){

}

/**
 * @brief Create a Task object
 * 
 * @param A_u8Priority       the priority of the task
 * @param A_u16Periodicity   the periodicity of the task
 * @param A_u16FirstDelay    the first delay of the task
 * @param A_Fptr             the function to be called
 */
void OS_vCreateTask(u8 A_u8Priority, u16 A_u16Periodicity, u16 A_u16FirstDelay, void (*A_Fptr)(void)){

}


/**
 * @brief Scheduler Function
 * 
 * @note This Function is called by the SysTick ISR
 * @note The scheduler is configured based on the configuration file
 */
static void OS_vScheduler(void){

}