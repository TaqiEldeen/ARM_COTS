/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: SERVICE			**************/
/***********		Component: DELAY		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 25 JUNE 2023	 	**************/
/*********************************************************/

/*      LIB Inclusion       */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*      MCAL Inclusion      */
#include "SYSTICK_int.h"

/*      MODULE Inclusion        */
#include "DELAY_pri.h"
#include "DELAY_cfg.h"
#include "DELAY_int.h"

/*      GLOBAL Variables        */
static f32 G_f32AHB_Period = 0.0;

void DELAY_vInit( u8 A_u8AHB_FreqMhz ){
    /* Set the Period of AHB */
    G_f32AHB_Period = 1.0 / A_u8AHB_FreqMhz ; 

    /* Init the timer: Here i used Systick for now */
    SYSTICK_vInit();
}

void DELAY_vSetDelayBusyWait( u32 A_u32DelayMs ){
    u32 L_u32TicksNeeded = 0;

    /* Calculate the needed ticks */
    L_u32TicksNeeded = (f32) A_u32DelayMs  / ( G_f32AHB_Period * 1000 ) ;

    /* Start the busy waiting */
    SYSTICK_vSetBusyWait( L_u32TicksNeeded );
}

void DELAY_vSetDelayAsync( u32 A_u32DelayMs, ptr_func_t Ptr_Func ){
    u32 L_u32TicksNeeded = 0;

    /* Calculate the needed ticks */
    L_u32TicksNeeded = (f32) A_u32DelayMs  / ( G_f32AHB_Period * 1000 ) ;

    SYSTICK_vSetIntervalPeriodic (L_u32TicksNeeded, Ptr_Func);
}