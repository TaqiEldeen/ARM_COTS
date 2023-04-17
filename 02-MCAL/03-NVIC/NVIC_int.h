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
u8 NVIC_vEnableInterrupt(u8 A_u8IntId );

/**********************************************************************************************************
 * Description : Interface Function to Disable Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_vDisableInterrupt(u8 A_u8IntId);

/**********************************************************************************************************
 * Description : Interface Function to Set Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vSetPendingInterrupt(u8 A_u8IntI);

/**********************************************************************************************************
 * Description : Interface Function to Clear Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vClearPendingInterrupt(u8 A_u8IntId );

/**********************************************************************************************************
 * Description : Interface Function to Get Active Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetActiveInterrupt(u8 A_u8IntId );

/**********************************************************************************************************
 * Description : Interface Function to Set Priority of Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number, Priority, Group Priority
 * NOTES       : This Function adaptes to the Priority Grouping chosen in the configuration file
 ***********************************************************************************************************/
void NVIC_vSetPriority(u8 A_u8IntI, u8 A_u8SubPriority, u8 A_u8GroupPriority);

/**********************************************************************************************************
 * Description : Interface Function to Get Priority of Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetPriority(u8 A_u8IntId);


#endif /* NVIC_INT_H_ */