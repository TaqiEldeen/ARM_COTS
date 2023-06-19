/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 17 APRIL 2023	 	**************/
/*********************************************************/

/*      LIB Inclusion       */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*      Module Inclusion      */
#include "EXTI_pri.h"
#include "EXTI_int.h"
#include "EXTI_cfg.h"

static ptr_func_t EXTI_Callback[16] = {ADDRESS_NULL};

/**********************************************************************************************************
 * Description : Interface Function to Intialize the EXTI
 * Outputs     : void
 * Inputs      : void
 * NOTES       : To Enable the EXTI, you have to use the EXTI_vEnable function
 ***********************************************************************************************************/
void EXTI_vInit(u8 A_u8Line, u8 A_u8SenseControl) {
    EXTI_vSetSenseControl( A_u8Line, A_u8SenseControl );
}

/**********************************************************************************************************
 * Description : Interface Function to Enable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vEnable(u8 A_u8Line) {
    SET_BIT(EXTI->IMR, A_u8Line);
}

/**********************************************************************************************************
 * Description : Interface Function to Disable the EXTI
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vDisable(u8 A_u8Line){
    CLR_BIT(EXTI->IMR, A_u8Line);
}

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Sense Control
 * Outputs     : void
 * Inputs      : line number, sense control
 * NOTES       : To Enable the EXTI, you have to use the EXTI_vEnable function
 ***********************************************************************************************************/
void EXTI_vSetSenseControl(u8 A_u8Line, u8 A_u8SenseControl){
    switch(A_u8SenseControl){
        case EXTI_SENSE_CONTROL_RISING_EDGE:    SET_BIT(EXTI->RTSR, A_u8Line);  break;
        case EXTI_SENSE_CONTROL_FALLING_EDGE:   SET_BIT(EXTI->FTSR, A_u8Line);  break;
        case EXTI_SENSE_CONTROL_BOTH_EDGES:     SET_BIT(EXTI->RTSR, A_u8Line);  SET_BIT(EXTI->FTSR, A_u8Line);  break;
        default:
            break;
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Set the EXTI Callback
 * Outputs     : void
 * Inputs      : pointer to function, line number
 ***********************************************************************************************************/
void EXTI_vSetCallback(u8 A_u8Line, ptr_func_t A_ptrFunc) {
    EXTI_Callback[A_u8Line] = A_ptrFunc;
}

/**********************************************************************************************************
 * Description : Interface Function to Clear the EXTI Pending Flag
 * Outputs     : void
 * Inputs      : line number
 ***********************************************************************************************************/
void EXTI_vSwTrigger(u8 A_u8Line) {
    SET_BIT(EXTI->SWIER, A_u8Line);
}

void EXTI0_IRQHandler(void) {
    EXTI_Callback[0]();
    SET_BIT(EXTI->PR, 0);
}

void EXTI1_IRQHandler(void) {
    EXTI_Callback[1]();
    SET_BIT(EXTI->PR, 1);
}

void EXTI2_IRQHandler(void) {
    EXTI_Callback[2]();
    SET_BIT(EXTI->PR, 2);
}

void EXTI3_IRQHandler(void) {
    EXTI_Callback[3]();
    SET_BIT(EXTI->PR, 3);
}

void EXTI4_IRQHandler(void) {
    EXTI_Callback[4]();
    SET_BIT(EXTI->PR, 4);
}

void EXTI9_5_IRQHandler(void) {
    if (GET_BIT(EXTI->PR, 5)) {
        EXTI_Callback[5]();
        SET_BIT(EXTI->PR, 5);
    }
    if (GET_BIT(EXTI->PR, 6)) {
        EXTI_Callback[6]();
        SET_BIT(EXTI->PR, 6);
    }
    if (GET_BIT(EXTI->PR, 7)) {
        EXTI_Callback[7]();
        SET_BIT(EXTI->PR, 7);
    }
    if (GET_BIT(EXTI->PR, 8)) {
        EXTI_Callback[8]();
        SET_BIT(EXTI->PR, 8);
    }
    if (GET_BIT(EXTI->PR, 9)) {
        EXTI_Callback[9]();
        SET_BIT(EXTI->PR, 9);
    }
}

void EXTI15_10_IRQHandler(void) {
    if (GET_BIT(EXTI->PR, 10)) {
        EXTI_Callback[10]();
        SET_BIT(EXTI->PR, 10);
    }
    if (GET_BIT(EXTI->PR, 11)) {
        EXTI_Callback[11]();
        SET_BIT(EXTI->PR, 11);
    }
    if (GET_BIT(EXTI->PR, 12)) {
        EXTI_Callback[12]();
        SET_BIT(EXTI->PR, 12);
    }
    if (GET_BIT(EXTI->PR, 13)) {
        EXTI_Callback[13]();
        SET_BIT(EXTI->PR, 13);
    }
    if (GET_BIT(EXTI->PR, 14)) {
        EXTI_Callback[14]();
        SET_BIT(EXTI->PR, 14);
    }
    if (GET_BIT(EXTI->PR, 15)) {
        EXTI_Callback[15]();
        SET_BIT(EXTI->PR, 15);
    }
}

