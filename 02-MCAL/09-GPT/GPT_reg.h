/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: GPT  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 15 SEP 2023	 	**************/
/*********************************************************/

#ifndef GPT_REG_H
#define GPT_REG_H

#define TIM2_BASE_ADDRESS   0x40000000 
#define TIM3_BASE_ADDRESS   0x40000400 
#define TIM4_BASE_ADDRESS   0x40000800 
#define TIM5_BASE_ADDRESS   0x40000C00 

typedef struct {
    volatile u32 TIMx_CR1;
    volatile u32 TIMx_CR2;
    volatile u32 TIMx_SMCR;
    volatile u32 TIMx_DIER;
    volatile u32 TIMx_SR;
    volatile u32 TIMx_EGR;
    volatile u32 TIMx_CCMR1;
    volatile u32 TIMx_CCMR2;
    volatile u32 TIMx_CCER;
    volatile u32 TIMx_CNT;
    volatile u32 TIMx_PSC;
    volatile u32 TIMx_ARR;
    volatile u32 TIMx_RCR;      /* For Advanced Control Timer (TIM1) */
    volatile u32 TIMx_CCR[4];
    volatile u32 TIMx_BDTR;     /* For Advanced Control Timer (TIM1)*/
    volatile u32 TIMx_DCR;
    volatile u32 TIMx_DMAR;
}TIM_t;


#define TIM2    ((volatile TIM_t *) TIM2_BASE_ADDRESS)
#define TIM3    ((volatile TIM_t *) TIM3_BASE_ADDRESS)
#define TIM4    ((volatile TIM_t *) TIM4_BASE_ADDRESS)
#define TIM5    ((volatile TIM_t *) TIM5_BASE_ADDRESS)

/* TIMx_CR1 bits */
#define DIR     4
#define URS     2
#define UDIS    1
#define CEN     0

/* TIMx_DIER bits */
#define UIE     0
#define TIE     6

/* TIMx_SR bits */
#define UIF     0
#define TIF     6




#endif  /* GPT_REG_H */