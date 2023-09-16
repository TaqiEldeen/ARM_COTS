/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: GPT  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 15 SEP 2023	 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPT_pri.h"
#include "GPT_cfg.h"
#include "GPT_reg.h"
#include "GPT_int.h"


/**
 * @brief Global Variable to Hold the CallBack Functions for each timer
 * 
 */
ptr_func_t GPT_CallBack[GPT_TIMER_COUNT] = {ADDRESS_NULL};

/**
 * @brief Global Variable to Hold the state of the timer in Async mode
 * 
 */
static u8 isSingleInterval[GPT_TIMER_COUNT] = {FALSE};



/**
 * @brief  function used to intialize the timer object based on the selected configuration 
 * 
 * @param timer struct object of type TIM_CFG_t 
 */
void GPT_vInit(TIM_CFG_t *timer){
    switch(timer->timerId) {
        case TIM2_ID:
        {
            /* Apply counting mode */
            if(timer->countMode == TIM_DOWN_COUNTING){
                SET_BIT(TIM2->TIMx_CR1, DIR);
            } else {
                CLR_BIT(TIM2->TIMx_CR1, DIR);
            } 

            /* Only overflow/underflow generates an update INT */
            SET_BIT(TIM2->TIMx_CR1, URS);

            /* Enable UEV event generation */
            CLR_BIT(TIM2->TIMx_CR1, UDIS);

            /* Update interrupt status */
            if(timer->updateIntEnable == 1 ) {
                SET_BIT(TIM2->TIMx_DIER, UIE);
            } else {
                CLR_BIT(TIM2->TIMx_DIER, UIE);
            } 

            /* trigger interrupt status */
            if(timer->triggerEventIntEnable == 1) {
                SET_BIT(TIM2->TIMx_DIER, TIE);
            } else {
                CLR_BIT(TIM2->TIMx_DIER, TIE);
            }

            /* Apply the AutoReload value */
            TIM2->TIMx_ARR = timer->autoReloadVal;

            /* Apply the prescaler value */
            TIM2->TIMx_PSC = timer->prescalerVal;

            break;
        } 
        case TIM3_ID:
        {
            /* Apply counting mode */
            if(timer->countMode == TIM_DOWN_COUNTING){
                SET_BIT(TIM3->TIMx_CR1, DIR);
            } else {
                CLR_BIT(TIM3->TIMx_CR1, DIR);
            }

            /* Only overflow/underflow generates an update INT */
            SET_BIT(TIM3->TIMx_CR1, URS);

            /* Enable UEV event generation */
            CLR_BIT(TIM3->TIMx_CR1, UDIS);

            /* Update interrupt status */
            if(timer->updateIntEnable == 1 ) {
                SET_BIT(TIM3->TIMx_DIER, UIE);
            } else {
                CLR_BIT(TIM3->TIMx_DIER, UIE);
            }

            /* trigger interrupt status */
            if(timer->triggerEventIntEnable == 1) {
                SET_BIT(TIM3->TIMx_DIER, TIE);
            } else {
                CLR_BIT(TIM3->TIMx_DIER, TIE);
            }

            /* Apply the AutoReload value */
            TIM3->TIMx_ARR = timer->autoReloadVal;

            /* Apply the prescaler value */
            TIM3->TIMx_PSC = timer->prescalerVal;

            break;
        } 
        case TIM4_ID:
        {
            /* Apply counting mode */
            if(timer->countMode == TIM_DOWN_COUNTING){
                SET_BIT(TIM4->TIMx_CR1, DIR);
            } else {
                CLR_BIT(TIM4->TIMx_CR1, DIR);
            }

            /* Only overflow/underflow generates an update INT */
            SET_BIT(TIM4->TIMx_CR1, URS);

            /* Enable UEV event generation */
            CLR_BIT(TIM4->TIMx_CR1, UDIS);

            /* Update interrupt status */
            if(timer->updateIntEnable == 1 ) {
                SET_BIT(TIM4->TIMx_DIER, UIE);
            } else {
                CLR_BIT(TIM4->TIMx_DIER, UIE);
            }

            /* trigger interrupt status */
            if(timer->triggerEventIntEnable == 1) {
                SET_BIT(TIM4->TIMx_DIER, TIE);
            } else {
                CLR_BIT(TIM4->TIMx_DIER, TIE);
            }

            /* Apply the AutoReload value */
            TIM4->TIMx_ARR = timer->autoReloadVal;

            /* Apply the prescaler value */
            TIM4->TIMx_PSC = timer->prescalerVal;

            break;
        } 
        case TIM5_ID:
        {
            /* Apply counting mode */
            if(timer->countMode == TIM_DOWN_COUNTING){
                SET_BIT(TIM5->TIMx_CR1, DIR);
            } else {
                CLR_BIT(TIM5->TIMx_CR1, DIR);
            }

            /* Only overflow/underflow generates an update INT */
            SET_BIT(TIM5->TIMx_CR1, URS);

            /* Enable UEV event generation */
            CLR_BIT(TIM5->TIMx_CR1, UDIS);

            /* Update interrupt status */
            if(timer->updateIntEnable == 1 ) {
                SET_BIT(TIM5->TIMx_DIER, UIE);
            } else {
                CLR_BIT(TIM5->TIMx_DIER, UIE);
            }

            /* trigger interrupt status */
            if(timer->triggerEventIntEnable == 1) {
                SET_BIT(TIM5->TIMx_DIER, TIE);
            } else {
                CLR_BIT(TIM5->TIMx_DIER, TIE);
            }

            /* Apply the AutoReload value */
            TIM5->TIMx_ARR = timer->autoReloadVal;

            /* Apply the prescaler value */
            TIM5->TIMx_PSC = timer->prescalerVal;

            break;
        }
         
        default:
            break;
    }
}

/**
 * @brief Enable the timer 
 * 
 * @param A_u8TimerID timer id 
 */
void GPT_vEnable(u8 A_u8TimerID){
    switch (A_u8TimerID)
    {
        case TIM2_ID:   SET_BIT(TIM2->TIMx_CR1, CEN);   break;
        case TIM3_ID:   SET_BIT(TIM3->TIMx_CR1, CEN);   break;
        case TIM4_ID:   SET_BIT(TIM4->TIMx_CR1, CEN);   break;
        case TIM5_ID:   SET_BIT(TIM5->TIMx_CR1, CEN);   break;
    default:
        break;
    }
}

/**
 * @brief Disable the timer 
 * 
 * @param A_u8TimerID timer id 
 */
void GPT_vDisable(u8 A_u8TimerID){
    switch (A_u8TimerID)
    {
        case TIM2_ID:   CLR_BIT(TIM2->TIMx_CR1, CEN);   break;
        case TIM3_ID:   CLR_BIT(TIM3->TIMx_CR1, CEN);   break;
        case TIM4_ID:   CLR_BIT(TIM4->TIMx_CR1, CEN);   break;
        case TIM5_ID:   CLR_BIT(TIM5->TIMx_CR1, CEN);   break;
    default:
        break;
    }
}

/**
 * @brief   function used to get the remaining ticks of the timer
 * 
 * @param timer struct object of type TIM_CFG_t 
 * @return u16  the remaining ticks
 */
u16 GPT_u16GetRemainingTicks(TIM_CFG_t* timer){
    u16 L_u16Remaning = 0;

    switch (timer->timerId)
    {
        case TIM2_ID:
        {
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Remaning = timer->autoReloadVal - TIM2->TIMx_CNT;
            } else {
                L_u16Remaning = TIM2->TIMx_CNT;
            }
            break;
        }   

        case TIM3_ID:   
        {            
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Remaning = timer->autoReloadVal - TIM3->TIMx_CNT;
            } else {
                L_u16Remaning = TIM3->TIMx_CNT;
            }
            break;
        }

        case TIM4_ID:   
        {
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Remaning = timer->autoReloadVal - TIM4->TIMx_CNT;
            } else {
                L_u16Remaning = TIM4->TIMx_CNT;
            }
            break;
        }

        case TIM5_ID: 
        {
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Remaning = timer->autoReloadVal - TIM5->TIMx_CNT;
            } else {
                L_u16Remaning = TIM5->TIMx_CNT;
            }
            break;
        }
        default:    /* Error */     break;
    }

    return L_u16Remaning;
}

/**
 * @brief   function used to get the elapsed ticks of the timer
 * 
 * @param timer struct object of type TIM_CFG_t
 * @return u16  the elapsed ticks
 */
u16 GPT_u16GetElapsedTicks(TIM_CFG_t* timer){
    u16 L_u16Elapsed = 0;

    switch (timer->timerId)
    {
        case TIM2_ID:
        {
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Elapsed = TIM2->TIMx_CNT;
            } else {
                L_u16Elapsed = timer->autoReloadVal - TIM2->TIMx_CNT;
            }
            break;
        }   

        case TIM3_ID:   
        {            
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Elapsed = TIM3->TIMx_CNT;
            } else {
                L_u16Elapsed = timer->autoReloadVal - TIM3->TIMx_CNT;
            }
            break;
        }

        case TIM4_ID:   
        {
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Elapsed = TIM4->TIMx_CNT;
            } else {
                L_u16Elapsed = timer->autoReloadVal - TIM4->TIMx_CNT;
            }
            break;
        }

        case TIM5_ID: 
        {
            if(timer->countMode == TIM_UP_COUNTING) {
                L_u16Elapsed = TIM5->TIMx_CNT;
            } else {
                L_u16Elapsed = timer->autoReloadVal - TIM5->TIMx_CNT;
            }
            break;
        }
        default:    /* Error */     break;
    }

    return L_u16Elapsed;
}

/**
 * @brief   function used to set the interval for only one time 
 * 
 * @param A_u8TimerId 
 * @param A_u32Ticks 
 * @param A_ptr_func 
 */
void GPT_vSetIntervalSingle(u8 A_u8TimerId, u32 A_u32Ticks, ptr_func_t A_ptr_func){

    /* Set timer Async state */
    isSingleInterval[A_u8TimerId] = TRUE;

    /* Apply the CallBack Function */
    GPT_CallBack[A_u8TimerId] = A_ptr_func;

    switch (A_u8TimerId)
    {
        case TIM2_ID:
        {
            /* Apply the AutoReload value */
            TIM2->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM2->TIMx_DIER, UIE);

            break;
        }   

        case TIM3_ID:   
        {            
            /* Apply the AutoReload value */
            TIM3->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM3->TIMx_DIER, UIE);

            break;
        }

        case TIM4_ID:   
        {
            /* Apply the AutoReload value */
            TIM4->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM4->TIMx_DIER, UIE);

            break;
        }

        case TIM5_ID: 
        {
            /* Apply the AutoReload value */
            TIM5->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM5->TIMx_DIER, UIE);

            break;
        }
        default:    /* Error */     break;
    }

    /* Enable the timer */
    GPT_vEnable(A_u8TimerId);

    /* Update generation */
    SET_BIT(TIM2->TIMx_EGR, 0);
}

/**
 * @brief 
 * 
 * @param A_u8TimerId 
 * @param A_u32Ticks 
 * @param A_ptr_func 
 *
 * @note The bus frequency = APB1 x2 so take care
 */
void GPT_vSetIntervalPeriodic(u8 A_u8TimerId, u32 A_u32Ticks, ptr_func_t A_ptr_func){
    /* Set timer Async state */
    isSingleInterval[A_u8TimerId] = FALSE;

    /* Apply the CallBack Function */
    GPT_CallBack[A_u8TimerId] = A_ptr_func;

    switch (A_u8TimerId)
    {
        case TIM2_ID:
        {
            /* Apply the AutoReload value */
            TIM2->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM2->TIMx_DIER, UIE);

            break;
        }   

        case TIM3_ID:   
        {            
            /* Apply the AutoReload value */
            TIM3->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM3->TIMx_DIER, UIE);

            break;
        }

        case TIM4_ID:   
        {
            /* Apply the AutoReload value */
            TIM4->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM4->TIMx_DIER, UIE);

            break;
        }

        case TIM5_ID: 
        {
            /* Apply the AutoReload value */
            TIM5->TIMx_ARR = A_u32Ticks;

            /* Enable the interrupt */
            SET_BIT(TIM5->TIMx_DIER, UIE);

            break;
        }
        default:    /* Error */     break;
    }

    /* Enable the timer */
    GPT_vEnable(A_u8TimerId);
}

/**
 * @brief ISR Function to Handle the TIM2 Interrupt
 * 
 */
void TIM2_IRQHandler() {
	if(GET_BIT(TIM2->TIMx_SR, UIF) == 1) {
	    if (GPT_CallBack[TIM2_ID] != ADDRESS_NULL) {
	        GPT_CallBack[TIM2_ID]();

	        if(isSingleInterval[TIM2_ID]) {
	            isSingleInterval[TIM2_ID] = FALSE;
	            CLR_BIT(TIM2->TIMx_DIER, UIE);          /* Disable the interrupt */
	            GPT_vDisable(TIM2_ID);
	        }
	        else {
	            /*  Do Nothing  */
	        }

	    } else {
	        /*  Do Nothing  */
	    }
	    CLR_BIT(TIM2->TIMx_SR, 0);
	}
}

/**
 * @brief ISR Function to Handle the TIM3 Interrupt
 * 
 */
void TIM3_IRQHandler() {
    if (GET_BIT(TIM3->TIMx_SR, UIF) == 1)
    {
        if (GPT_CallBack[TIM3_ID] != ADDRESS_NULL) {
            GPT_CallBack[TIM3_ID]();

            if(isSingleInterval[TIM3_ID]) {
                isSingleInterval[TIM3_ID] = FALSE;
                CLR_BIT(TIM3->TIMx_DIER, UIE);          /* Disable the interrupt */
                GPT_vDisable(TIM3_ID);
            } 
            else {
                /*  Do Nothing  */
            }
            
        } else {
            /*  Do Nothing  */
        }
        CLR_BIT(TIM4->TIMx_SR, UIF);
    }
}

/**
 * @brief ISR Function to Handle the TIM4 Interrupt
 * 
 */
void TIM4_IRQHandler() {
    if(GET_BIT(TIM4->TIMx_SR, UIF) == 1) {
        if (GPT_CallBack[TIM4_ID] != ADDRESS_NULL) {
            GPT_CallBack[TIM4_ID]();

            if(isSingleInterval[TIM4_ID]) {
                isSingleInterval[TIM4_ID] = FALSE;
                CLR_BIT(TIM4->TIMx_DIER, UIE);          /* Disable the interrupt */
                GPT_vDisable(TIM4_ID);
            } 
            else {
                /*  Do Nothing  */
            }
            
        } else {
            /*  Do Nothing  */
        }
        CLR_BIT(TIM4->TIMx_SR, UIF);
    }
}

/**
 * @brief ISR Function to Handle the TIM5 Interrupt
 * 
 */
void TIM5_IRQHandler() {
    if(GET_BIT(TIM5->TIMx_SR, UIF) == 1) {
        if (GPT_CallBack[TIM5_ID] != ADDRESS_NULL) {
            GPT_CallBack[TIM5_ID]();

            if(isSingleInterval[TIM5_ID]) {
                isSingleInterval[TIM5_ID] = FALSE;
                CLR_BIT(TIM5->TIMx_DIER, UIE);          /* Disable the interrupt */
                GPT_vDisable(TIM5_ID);
            } 
            else {
                /*  Do Nothing  */
            }
            
        } else {
            /*  Do Nothing  */
        }
        CLR_BIT(TIM5->TIMx_SR, UIF);
    }
}
