/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: GPT  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 15 SEP 2023	 	**************/
/*********************************************************/

#ifndef GPT_INT_H
#define GPT_INT_H

/**
 * @brief enum used for identifying the timer being used
 * 
 */
typedef enum {
    TIM2_ID,
    TIM3_ID,
    TIM4_ID,
    TIM5_ID,
    GPT_TIMER_COUNT
}GPT_ID;

/**
 * @brief enum for selecting the counting mode
 * 
 */
typedef enum {
    TIM_UP_COUNTING,
    TIM_DOWN_COUNTING,
    TIM_CENTER_ALIGNED
}GPT_CNT_MODE;

/**
 * @brief enum for selecting the operation mode for the timers
 * 
 */
typedef enum {
    TIM_IC_MODE,
    TIM_NORMAL_MODE,
    TIM_OC_MODE
}GPT_OPERATION_MODE;

/**
 * @brief struct for making timer object for configuring the timers
 * 
 */
typedef struct {
    GPT_ID       timerId;
    GPT_CNT_MODE countMode;
    u8           updateIntEnable;           /* counter overflow/underflow, counter initialization (by software or internal/external trigger: 0 --> Disable, 1 --> Enable*/
    u8           triggerEventIntEnable;     /* counter start, stop, initialization or count by internal/external trigger: 0 --> Disable, 1 --> Enable*/
    u8           ICIntEnable;               /* Input capture:  0 --> Disable, 1 --> Enable */
    u8           OCIntEnable;               /* Output compare: 0 --> Disable, 1 --> Enable */
    u16          prescalerVal;              /* 0 --> 2^16 */
    u16          autoReloadVal;             /* 0 --> 2^16 */
} TIM_CFG_t;

/**
 * @brief  function used to intialize the timer object based on the selected configuration 
 * 
 * @param timer struct object of type TIM_CFG_t 
 * 
 * @note Only normal mode is supported for now
 */
void GPT_vInit(TIM_CFG_t *timer);

/**
 * @brief Enable the timer 
 * 
 * @param A_u8TimerID timer id 
 */
void GPT_vEnable(u8 A_u8TimerID);

/**
 * @brief Disable the timer 
 * 
 * @param A_u8TimerID timer id 
 */
void GPT_vDisable(u8 A_u8TimerID);

/**
 * @brief 
 * 
 * @param A_u8TimerID 
 * @return u16 
 */
u16 GPT_u16GetRemainingTicks(TIM_CFG_t* timer);

/**
 * @brief 
 * 
 * @param A_u8TimerId 
 * @return u16 
 */
u16 GPT_u16GetElapsedTicks(TIM_CFG_t* timer);

/**
 * @brief 
 * 
 * @param A_u8TimerId 
 * @param A_u32Ticks 
 * @param A_ptr_func 
 */
void GPT_vSetIntervalSingle(u8 A_u8TimerId, u32 A_u32Ticks, ptr_func_t A_ptr_func);

/**
 * @brief 
 * 
 * @param A_u8TimerId 
 * @param A_u32Ticks 
 * @param A_ptr_func 
 */
void GPT_vSetIntervalPeriodic(u8 A_u8TimerId, u32 A_u32Ticks, ptr_func_t A_ptr_func);

/**
 * @brief 
 * 
 * @param A_u8TimerId 
 * @param A_u32Ticks 
 */
void GPT_vSetBusyWait(u8 A_u8TimerId, u32 A_u32Ticks);

#endif  /* GPT_INT_H */
