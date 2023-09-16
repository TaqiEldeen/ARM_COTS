/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: IR     		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 SEP 2023	 	**************/
/*********************************************************/

/* LIB Inclusion */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Inclusion */
#include "GPT_int.h"
#include "EXTI_int.h"
#include "RCC_int.h"
#include "NVIC_int.h"
#include "AFIO_int.h"
#include "DIO_int.h"

/* Module Inclusion */
#include "IR_int.h"
#include "IR_pri.h"
#include "IR_cfg.h"

/* Global variables */

/**
 * @brief This variable is responsible for holding the callback function after Knowing the IR Key
 * 
 */
ptr_func_t IR_cbf = ADDRESS_NULL;

/**
 * @brief 
 * 
 */
volatile TIM_CFG_t TIM_cfg;


/**
 * @brief Array that will hold the frame 8-bit address + 8-bit command(Key)
 * 
 */
static volatile
u8 G_u8AdrField;

static volatile
u8 G_u8CmdField;

static volatile
u8 G_u8NewKey;

/**
 * @brief This function is responsible for initializing the IR module
 * 
 * @note 1- intialize the timer module  (GPT)
 *       2- intialize the EXTI0 module
 *       3- Enable the NVIC for the EXTI0
 *       4- Enable RCC for the GPT & EXTI
 */
void IR_vInit(void){
    /* RCC for The GPT & EXTI & AFIO */
    RCC_vEnableClk(RCC_APB1, IR_TIMER_RCC);
    RCC_vEnableClk(RCC_APB2, IR_EXTI_RCC);
    RCC_vEnableClk(RCC_APB2, AFIO);

    /* Initialize the timer module */
    TIM_cfg.autoReloadVal = 0xFFFE;
    TIM_cfg.countMode     = TIM_UP_COUNTING;
    TIM_cfg.prescalerVal  = IR_TIMER_PRESCALER;
    TIM_cfg.timerId       = IR_TIMER_ID;
    GPT_vInit(&TIM_cfg);

    /* Enable NVIC for EXTI */
    NVIC_vEnableInterrupt(IR_EXTI_NVIC);

    /* Initialize the EXTI0 module */
    AFIO_vSetEXTICfg(IR_EXTI_ID, IR_EXTI_PORT_ID);
    DIO_vSetPinMode(IR_EXTI_PORT_ID, IR_EXTI_PIN, INPUT_FLOATING);
    EXTI_vInit( IR_EXTI_ID, EXTI_SENSE_CONTROL_FALLING_EDGE );
    EXTI_vEnable( IR_EXTI_ID );
    EXTI_vSetCallback(IR_EXTI_ID, &IR_vHandler);

    GPT_vEnable(TIM_cfg.timerId);
}

/**
 * @brief This function is responsible for getting the pressed KEY
 * 
 * @note It returns the MACROS defined
 */
u8 IR_u8GetKey(void) {
    u8 L_u8PressedKey = IR_NOT_PRESSED;

    /* If new press happened*/
    if(G_u8NewKey) {
    	L_u8PressedKey = G_u8CmdField;
    	G_u8NewKey = 0;
    }

    return L_u8PressedKey;
}

/**
 * @brief This function is responsible for getting the IR frame
 * 
 * @param pu8Data pointer to the data
 */
void IR_vGetFrame(u8 *pu8Data){

}

/**
 * @brief This function is responsible for setting the callback function
 * 
 * @param cbf pointer to the callback function
 */
void IR_vRegisterCBF(ptr_func_Iu8_Ov cbf){
    IR_cbf = cbf;
}


static void IR_vHandler(void){
    static volatile u16 L_u16TimeStamp;
    static volatile u16 L_u16PrevTimeStamp;
    static volatile IR_STATE_t L_eState = IR_IDLE;
    static volatile u8 L_u8Indexer;

    u16 L_u16CurrentField = 0;

    L_u16TimeStamp = GPT_u16GetElapsedTicks( &TIM_cfg );

    /* If prevTimeStamp > current: Therefore ovf happened */
    if(L_u16PrevTimeStamp > L_u16TimeStamp) {
        L_u16CurrentField = TIM_cfg.autoReloadVal - L_u16PrevTimeStamp + L_u16TimeStamp;
    } else {
        L_u16CurrentField = L_u16TimeStamp - L_u16PrevTimeStamp;
    }

    /* Check current field */
    if(L_u16CurrentField > IR_START_US) {
        L_eState = IR_START;
        L_u16TimeStamp = 0;
        GPT_vResetTimer(TIM_cfg.timerId);
    } else if(L_u16CurrentField > IR_REPEAT_US) {
    	L_eState = IR_REPEAT_STATE;
    } else if(L_u16CurrentField > IR_LOGIC_ONE_US) {
        L_u16CurrentField = 1;
    } else if(L_u16CurrentField > IR_LOGIC_ZERO_US) {
        L_u16CurrentField = 0;
    } else {
        /* ERROR */
    }

    switch(L_eState) {
		case IR_START: 			L_eState = IR_ADR_FIELD;	break;
		case IR_ADR_FIELD:
		{
			if(L_u16CurrentField == 1) {
				SET_BIT(G_u8AdrField, L_u8Indexer++);
			} else {
				CLR_BIT(G_u8AdrField, L_u8Indexer++);
			}

			if(L_u8Indexer == 7){
				L_eState = IR_ADR_INV_FIELD;
				L_u8Indexer = 0;
			}

			break;
		}
		case IR_ADR_INV_FIELD:
		{
			L_u8Indexer++;
			if(L_u8Indexer == 7) {
				L_eState = IR_CMD_FIELD;
				L_u8Indexer = 0;
			}
			break;
		}
		case IR_CMD_FIELD:
		{
			if(L_u16CurrentField == 1) {
				SET_BIT(G_u8CmdField, L_u8Indexer++);
			} else {
				CLR_BIT(G_u8CmdField, L_u8Indexer++);
			}
			if(L_u8Indexer == 7){
				L_eState = IR_CMD_INV_FIELD;
				L_u8Indexer = 0;
			}
			break;
		}
		case IR_CMD_INV_FIELD:
		{
			L_u8Indexer++;
			if(L_u8Indexer == 7) {
				L_eState = IR_IDLE;
				G_u8NewKey = 1;			/* A new key is pressed */
				L_u8Indexer = 0;
			}
			break;
		}

		default: 	break;
    }

    L_u16PrevTimeStamp = L_u16TimeStamp;
}
