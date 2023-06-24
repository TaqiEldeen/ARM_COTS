/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: LM			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 20 JUNE 2023	 	**************/
/*********************************************************/

/****           LIB inclusion           ****/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/****           MCAL inclusion            ****/
#include "DIO_int.h"
#include "SYSTICK_int.h"

/****           Module inclusion            ****/
#include "LM_pri.h"
#include "LM_cfg.h"
#include "LM_int.h"

static u8 G_u8RowPins[8];
static u8 G_u8ColPins[8];

/**
 * @brief This function initializes the LED matrix
 * 
 * @param obj The user defined LED matrix 
 */
void LM_vInit(){
    /* Init Systick*/
    SYSTICK_vInit();

    /* Pin mode for LED matrix colomn */
    DIO_vSetPinMode(LM_COL_PORT, LM_COL0, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_COL_PORT, LM_COL1, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_COL_PORT, LM_COL2, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_COL_PORT, LM_COL3, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_COL_PORT, LM_COL4, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_COL_PORT, LM_COL5, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_COL_PORT, LM_COL6, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_COL_PORT, LM_COL7, OUTPUT_2MHZ_AFPP);

    /* Initially OFF */
    DIO_vSetPinVal(LM_COL_PORT, LM_COL0, VAL_HIGH);
    DIO_vSetPinVal(LM_COL_PORT, LM_COL1, VAL_HIGH);
    DIO_vSetPinVal(LM_COL_PORT, LM_COL2, VAL_HIGH);
    DIO_vSetPinVal(LM_COL_PORT, LM_COL3, VAL_HIGH);
    DIO_vSetPinVal(LM_COL_PORT, LM_COL4, VAL_HIGH);
    DIO_vSetPinVal(LM_COL_PORT, LM_COL5, VAL_HIGH);
    DIO_vSetPinVal(LM_COL_PORT, LM_COL6, VAL_HIGH);
    DIO_vSetPinVal(LM_COL_PORT, LM_COL7, VAL_HIGH);

    /* Pin mode for LED matrix Row */
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW0, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW1, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW2, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW3, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW4, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW5, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW6, OUTPUT_2MHZ_AFPP);
    DIO_vSetPinMode(LM_ROW_PORT, LM_ROW7, OUTPUT_2MHZ_AFPP);

    G_u8ColPins[0] = LM_COL0;
    G_u8ColPins[1] = LM_COL1;
    G_u8ColPins[2] = LM_COL2;
    G_u8ColPins[3] = LM_COL3;
    G_u8ColPins[4] = LM_COL4;
    G_u8ColPins[5] = LM_COL5;
    G_u8ColPins[6] = LM_COL6;
    G_u8ColPins[7] = LM_COL7;

    G_u8RowPins[0] = LM_ROW0;
    G_u8RowPins[1] = LM_ROW1;
    G_u8RowPins[2] = LM_ROW2;
    G_u8RowPins[3] = LM_ROW3;
    G_u8RowPins[4] = LM_ROW4;
    G_u8RowPins[5] = LM_ROW5;
    G_u8RowPins[6] = LM_ROW6;
    G_u8RowPins[7] = LM_ROW7;
}

/**
 * @brief This function displays the given frame on the LED matrix
 * 
 * @param Ptr_u8Frame The frame to be displayed
 * (3, 3, 3, 255, 255, 3, 3, 3)
 */
void LM_vDisplayFrame(u8* Ptr_u8Frame){
    for(u8 col = 0; col < LM_COL_NUM; col++) {
        /* Enable the corresponding rows */
        LM_vSetRows(Ptr_u8Frame[col]);

        /* Enable the current Column */
        DIO_vSetPinVal(LM_COL_PORT, G_u8ColPins[col], VAL_LOW);

        SYSTICK_vSetBusyWait(2500);  /* 2.5 ms */

        /* Disable the current Column */
        DIO_vSetPinVal(LM_COL_PORT, G_u8ColPins[col], VAL_HIGH);
    }
}

/**
 * @brief Private function to set the rows of the LED matrix
 * 
 * @param A_u8RowsVal The values of the rows
 */
static void LM_vSetRows( u8 A_u8RowsVal ) {
    for(u8 row = 0; row < LM_ROW_NUM; row++) {
        DIO_vSetPinVal(LM_ROW_PORT, G_u8RowPins[row], GET_BIT(A_u8RowsVal, row));
    }
}

/**
 * @brief Sets the FPS for the LED matrix
 * 
 * @param A_u8FPS The FPS needed
 */
void LM_vSetFPS(u8 A_u8FPS){
    
}