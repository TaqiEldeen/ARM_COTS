/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: ADC  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 22 APRIL 2023	 	**************/
/*********************************************************/

/*          LIB Inclusion           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*          MCAL Inclusion          */
#include "RCC_int.h"

/*        Module Inclusion       */
#include "ADC_pri.h"
#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"


void ADC_vInit(void) {
    ADC1 -> CR2 = 0;    /* Clear CR2 */
    ADC1 -> CR1 = 0;    /* Clear CR1 */

    /* Enable VREFINT Channel */
    ADC1 -> CR2 |= (1<<23); 

    /* Sample Time selection for VREFINT */
    ADC1 -> SMPR1 |= (0b001 << 21);   /* 7.5 cycles */

    /* Regular Channel Sequence Length */
    ADC1 -> SQR1 |= (0b0000 << 20);   /* 1 conversion */

    /* 1st Conversion in regular sequence */
    ADC1 -> SQR3 |= (0b10001 << 0);     /* Channel 17 */

    /* ADC Clock Prescaler */
    RCC_vSetADCPreScaler( ADC_PRESCALER );

    /* Enable ADC */
    ADC1 -> CR2 |= (1 << 0);
}

u16 ADC_u16ReadSync() {
    u16 L_u16Value = 0;

    /* Start Conversion */
    ADC1 -> CR2 |= (1 << 22);

    /* Wait for the conversion to complete */
    while (GET_BIT(ADC1 -> SR, 1) == 0);

    /* Read the value. It clears the Flag also */
    L_u16Value = ADC1 -> DR;

    return L_u16Value;
}

