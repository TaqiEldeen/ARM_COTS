/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/

/*  LIB Inclusion   */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*  Module Inclusion   */
#include "SYSTICK_pri.h"
#include "SYSTICK_cfg.h"
#include "SYSTICK_int.h"
#include "SYSTICK_reg.h"

/**
 * @brief Global Variable to Hold the CallBack Function
 * 
 */
static ptr_func_t SYSTICK_CallBack = ADDRESS_NULL;

/**
 * @brief Interface Function to Initialize the SYSTICK
 * 
 */
void SYSTICK_vInit(void) {
    SYSTICK-> CTRL = 0;                       /* Clear CTRL */
    SYSTICK-> LOAD = SYSTICK_RELOAD_VALUE;    /* Set the maximum value */   
    SYSTICK-> VAL  = 0;                       /* Clear the current value */
    SYSTICK-> CTRL |= (SYSTICK_ENABLE << ENABLE)              /* Enable the counter */
                    | (SYSTICK_INTERRUPT << TICKINT)          /* Enable the interrupt */
                    | (SYSTICK_CLKSOURCE << CLKSOURCE);       /* Select the clock source */
}

/**
 * @brief Interface Function to Turn on the SYSTICK
 * 
 */
void SYSTICK_vTurnOn(void) {
    SET_BIT(SYSTICK-> CTRL, ENABLE);
}

/**
 * @brief  Interface Function to Turn off the SYSTICK
 * 
 */
void SYSTICK_vTurnOff(void) {
    CLR_BIT(SYSTICK-> CTRL, ENABLE);
}

/**
 * @brief Interface Function to Set the Reload Value
 * 
 * @param A_u32Ticks 
 */
void SYSTICK_vSetReload(u32 A_u32Ticks){
    SYSTICK-> LOAD = A_u32Ticks;
}

/**
 * @brief Interface Function to Get the Elapsed Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetElapsedTicks(void) {
    return ( (SYSTICK->LOAD) - (SYSTICK-> VAL) );
}

/**
 * @brief Interface Function to Get the Remaining Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetRemainingTicks(void) {
    return (SYSTICK-> VAL);
}

/**
 * @brief Interface Function to Set the CallBack Function
 * 
 * @param A_ptr_func 
 */
void SYSTICK_vSetCallBack(ptr_func_t A_ptr_func){
    SYSTICK_CallBack = A_ptr_func;
}

/**
 * @brief ISR Function to Handle the SYSTICK Interrupt
 * 
 * @return ptr_func_t 
 */
void SysTick_Handler(void) {
    if (SYSTICK_CallBack != ADDRESS_NULL) {
        SYSTICK_CallBack();
    } else {
        /*  Do Nothing  */
    }
}