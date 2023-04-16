/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: NVIC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 APRIL 2023	 	**************/
/*********************************************************/

#ifndef NVIC_REG_H_
#define NVIC_REG_H_

#define NVIC_BASE_ADDRESS		0xE000E100

/*      Interrupt set-enable registers       */
#define NVIC_ISER0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x000))      
#define NVIC_ISER1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x004))   

/*      Interrupt clear-enable registers     */
#define NVIC_ICER0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x084))

/*      Interrupt set-pending registers      */
#define NVIC_ISPR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x104))

/*      Interrupt clear-pending registers    */
#define NVIC_ICPR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x184))

/*      Interrupt active bit registers       */
#define NVIC_IABR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x204))

/*      Interrupt priority registers         */
#define NVIC_IPR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x300))
#define NVIC_IPR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x304))
#define NVIC_IPR2				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x308))
#define NVIC_IPR3				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x30C))
#define NVIC_IPR4				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x310))
#define NVIC_IPR5				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x314))
#define NVIC_IPR6				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x318))
#define NVIC_IPR7				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x31C))
#define NVIC_IPR8				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x320))
#define NVIC_IPR9				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x324))
#define NVIC_IPR10				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x328))
#define NVIC_IPR11				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x32C))
#define NVIC_IPR12				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x330))
#define NVIC_IPR13				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x334))
#define NVIC_IPR14				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x338))
#define NVIC_IPR15				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x33C))
#define NVIC_IPR16				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x340))
#define NVIC_IPR17				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x344))
#define NVIC_IPR18				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x348))
#define NVIC_IPR19				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x34C))
#define NVIC_IPR20				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x350))
#define NVIC_IPR21				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x354))
#define NVIC_IPR22				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x358))
#define NVIC_IPR23				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x35C))
#define NVIC_IPR24				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x360))
#define NVIC_IPR25				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x364))
#define NVIC_IPR26				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x368))
#define NVIC_IPR27				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x36C))
#define NVIC_IPR28				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x370))
#define NVIC_IPR29				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x374))
#define NVIC_IPR30				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x378))
#define NVIC_IPR31				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x37C))
#define NVIC_IPR32				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x380))
#define NVIC_IPR33				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x384))
#define NVIC_IPR34				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x388))
#define NVIC_IPR35				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x38C))
#define NVIC_IPR36				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x390))
#define NVIC_IPR37				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x394))
#define NVIC_IPR38				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x398))
#define NVIC_IPR39				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x39C))
#define NVIC_IPR40				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3A0))
#define NVIC_IPR41				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3A4))
#define NVIC_IPR42				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3A8))
#define NVIC_IPR43				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3AC))
#define NVIC_IPR44				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3B0))
#define NVIC_IPR45				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3B4))
#define NVIC_IPR46				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3B8))
#define NVIC_IPR47				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3BC))
#define NVIC_IPR48				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3C0))
#define NVIC_IPR49				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3C4))
#define NVIC_IPR50				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3C8))
#define NVIC_IPR51				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3CC))
#define NVIC_IPR52				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3D0))
#define NVIC_IPR53				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3D4))
#define NVIC_IPR54				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3D8))
#define NVIC_IPR55				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3DC))
#define NVIC_IPR56				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3E0))
#define NVIC_IPR57				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3E4))
#define NVIC_IPR58				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3E8))
#define NVIC_IPR59				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3EC))
#define NVIC_IPR60				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3F0))
#define NVIC_IPR61				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3F4))
#define NVIC_IPR62				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3F8))
#define NVIC_IPR63				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x3FC))

#define NVIC_STIR				*((volatile u32*)(NVIC_BASE_ADDRESS + 0xE00))


#endif /* NVIC_REG_H_ */