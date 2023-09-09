/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: SERVICE			**************/
/***********		Component: OS   		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 09 SEPT 2023	 	**************/
/*********************************************************/

#ifndef OS_INT_H
#define OS_INT_H

#define osREADY     1
#define osWait      0

/**
 * @brief start the OS
 * 
 */
void OS_vStart(void);

/**
 * @brief Create a Task object
 * 
 * @param A_u8Priority       the priority of the task
 * @param A_u16Periodicity   the periodicity of the task
 * @param A_u16FirstDelay    the first delay of the task
 * @param A_u8State          State of the task: osREADY, osWait
 * @param A_Fptr             the function to be called
 */
void OS_vCreateTask(u8 A_u8Priority, u16 A_u16Periodicity, u16 A_u16FirstDelay, u8 A_u8State, void (*A_Fptr)(void));


// void OS_voidSuspendTask(u8 A_u8Priority);
// void OS_voidResumeTask(u8 A_u8Priority);
// void OS_voidDeleteTask(u8 A_u8Priority);


#endif // OS_INT_H