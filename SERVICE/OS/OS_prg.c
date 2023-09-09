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
 * @note This function should be called after all the tasks are created
 * @note This function should be called after the scheduler is configured
 */
void OS_vStart(void){
    SYSTICK_vInit();                                                /* Initialize the SYSTICK */
    SYSTICK_vTurnOn();                                              /* Turn on the SYSTICK */
    SYSTICK_vSetIntervalPeriodic(TICK_TIME_US, &OS_vScheduler);     /* Set Systick periodically calling the scheduler */
}

/**
 * @brief Create a Task object
 * 
 * @param A_u8Priority       the priority of the task
 * @param A_u16Periodicity   the periodicity of the task
 * @param A_u16FirstDelay    the first delay of the task
 * @param A_Fptr             the function to be called
 */
void OS_vCreateTask(u8 A_u8Priority, u16 A_u16Periodicity, u16 A_u16FirstDelay, u8 A_u8State, void (*A_Fptr)(void)){
    OS_Tasks[A_u8Priority].periodicty = A_u16Periodicity;   
    OS_Tasks[A_u8Priority].firstDelay = A_u16FirstDelay;
    OS_Tasks[A_u8Priority].Fptr = A_Fptr;
}

/**
 * @brief Scheduler Function
 * 
 * @note This Function is called by the SysTick ISR
 * @note The scheduler is configured based on the configuration file
 */
static void OS_vScheduler(void){
    static u8 L_u8OS_Ticks;
    u8 L_u8TaskPriority = 0;

    L_u8OS_Ticks++;

    #if OS_SCHEDULER == PRIORITY_BASED :

    for(L_u8TaskPriority = 0; L_u8TaskPriority < NUMBER_OF_TASKS; L_u8TaskPriority++) {

        /* Check if a task is ready and is created */
        if((OS_Tasks[L_u8TaskPriority].Fptr != ADDRESS_NULL) && (OS_Tasks[L_u8TaskPriority].state == osREADY) ) {

            /* Check if the task periodicity is reached  */
            if(OS_Tasks[L_u8TaskPriority].firstDelay == 0) {
                OS_Tasks[L_u8TaskPriority].Fptr();
                OS_Tasks[L_u8TaskPriority].firstDelay = OS_Tasks[L_u8TaskPriority].periodicty - (TICK_TIME_US/1000);
            }
            else {
                OS_Tasks[L_u8TaskPriority].firstDelay --;
            }

        }
    }

    #endif

}