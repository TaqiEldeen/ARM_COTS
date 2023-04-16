/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: NVIC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 APRIL 2023	 	**************/
/*********************************************************/

/*          LIB inclusion           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*          Module inclusion        */
#include "NVIC_priv.h"
#include "NVIC_int.h"
#include "NVIC_reg.h"
#include "NVIC_cfg.h"

/**********************************************************************************************************
 * Description : Interface Function to Enable Interrupts in NVIC
 * Outputs     : Error State
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_vEnableInterrupt(u8 A_u8IntNumber) {
    u8 L_u8ErrorState = 0;
    if (A_u8IntNumber <= 31) {
        NVIC_ISER0 = (1 << A_u8IntNumber);  /* Writing 0 has no effect */
    } else if (A_u8IntNumber <= 59) {
        A_u8IntNumber -= 32;
        NVIC_ISER1 = (1 << A_u8IntNumber); 
    } else {
        /* Return Error */
        L_u8ErrorState = 1;
    }
    return L_u8ErrorState;
}

/**********************************************************************************************************
 * Description : Interface Function to Disable Interrupts in NVIC
 * Outputs     : Error State
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_vDisableInterrupt(u8 A_u8IntNumber){
    u8 L_u8ErrorState = 0;
    if (A_u8IntNumber <= 31) {
        NVIC_ICER0 = (1 << A_u8IntNumber);
    } else if (A_u8IntNumber <= 59) {
        A_u8IntNumber -= 32;
        NVIC_ICER1 = (1 << A_u8IntNumber);
    } else {
        /* Return Error */
        L_u8ErrorState = 1;
    }
    return L_u8ErrorState;
}

/**********************************************************************************************************
 * Description : Interface Function to Set Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vSetPendingInterrupt(u8 A_u8IntNumber) {
    if (A_u8IntNumber <= 31) {
        NVIC_ISPR0 = (1 << A_u8IntNumber);
    } else if (A_u8IntNumber <= 59) {
        A_u8IntNumber -= 32;
        NVIC_ISPR1 = (1 << A_u8IntNumber);
    } else {
        /* Return Error */
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Clear Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vClearPendingInterrupt(u8 A_u8IntNumber) {
    if (A_u8IntNumber <= 31) {
        NVIC_ICPR0 = (1 << A_u8IntNumber);
    } else if (A_u8IntNumber <= 59) {
        A_u8IntNumber -= 32;
        NVIC_ICPR1 = (1 << A_u8IntNumber);
    } else {
        /* Return Error */
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Get Active Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetActiveInterrupt(u8 A_u8IntNumber) {
    u8 L_u8ActiveState = 0;
    if (A_u8IntNumber <= 31) {
        L_u8ActiveState = GET_BIT(NVIC_IABR0, A_u8IntNumber);
    } else if (A_u8IntNumber <= 59) {
        A_u8IntNumber -= 32;
        L_u8ActiveState = GET_BIT(NVIC_IABR1, A_u8IntNumber);
    } else {
        /* Return Error */
    }
    return L_u8ActiveState;
}
