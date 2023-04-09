
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_int.h"
#include "DIO_int.h"

int main(){
    /* Enable RCC & Enable PortA clock */
    RCC_vInitSysClk();
    RCC_vEnableClk(RCC_APB2, IOPA);

    DIO_vSetPinMode(PORTA_ID, PIN10_ID, OUTPUT_2MHZ_PP);
    DIO_vSetPinValue(PORTA_ID, PIN10_ID, VAL_HIGH);

    while (1)
    {
        /* code */
    }
    
    return 0;
}