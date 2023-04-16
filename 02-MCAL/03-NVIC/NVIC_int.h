/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: NVIC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 APRIL 2023	 	**************/
/*********************************************************/

#ifndef NVIC_INT_H_
#define NVIC_INT_H_

/**********************************************************************************************************
 * Description : Interface Function to Enable Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vEnableInterrupt(u8 A_u8IntNumber);

/**********************************************************************************************************
 * Description : Interface Function to Disable Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vDisableInterrupt(u8 A_u8IntNumber);

/**********************************************************************************************************
 * Description : Interface Function to Set Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vSetPendingInterrupt(u8 A_u8IntNumber);

/**********************************************************************************************************
 * Description : Interface Function to Clear Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vClearPendingInterrupt(u8 A_u8IntNumber);

/**********************************************************************************************************
 * Description : Interface Function to Get Active Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetActiveInterrupt(u8 A_u8IntNumber);



#endif /* NVIC_INT_H_ */