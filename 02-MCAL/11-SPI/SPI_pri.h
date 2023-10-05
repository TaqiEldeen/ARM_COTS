/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 24 SEP 2023	 	**************/
/*********************************************************/

#ifndef SPI_PRI_H
#define SPI_PRI_H


#define ENABLE      1
#define DISABLE     0


#define RECEIVE_ONLY        0
#define TRANSMIT_ONLY       1
#define NULL                0


#define FULL_DUPLEX         0
#define OUTPUT_DISABLED     1


#define EIGHT_BIT           0
#define SIXTEEN_BIT         1


#define MSB_FIRST           0
#define LSB_FIRST           1


#define DIV_2               0
#define DIV_4               1
#define DIV_8               2
#define DIV_16              3
#define DIV_32              4
#define DIV_64              5
#define DIV_128             6
#define DIV_256             7


#define MASTER_MODE         0
#define SLAVE_MODE          1


#define IDLE_LOW            0
#define IDLE_HIGH           1


#define SAMPLE_LEADING      0
#define SAMPLE_TRAILING     1


#endif /* SPI_PRI_H */