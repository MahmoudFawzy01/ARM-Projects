#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/******************************************************************************************/
/******************************************************************************************/
/********************************* RCC clock interface ************************************/
/******************************************************************************************/
/******************************************************************************************/

/*
 * Function : init
 * Description : this function used to add the clock configration of RCC peripheral
 * Inputs: void
 * Output: void
 * */
void RCC_voidProcessorClockInit(void);

/*
 * Function : RCC_voidEnableClock
 * Description : this function used to enable the peripheral by enable its clock.
 * Inputs:
 * - copy_u8Bus: the bus options: RCC_AHB_BUS/RCC_APB1_BUS/RCC_APB2_BUS
 * - copy_u8Peripheral : it's the peripherals connected to the buses.
 * you can fined the options of buses and it's peripherals at this file.
 * Output: void
 * */
void RCC_voidEnableClock(u8 copy_u8Bus,u8 copy_u8Peripheral);

/*
 * Function : RCC_voidDisableClock
 * Description : this function used to disable the peripheral by enable its clock.
 * Inputs:
 * - copy_u8Bus: the bus options: RCC_AHB_BUS/RCC_APB1_BUS/RCC_APB2_BUS
 * - copy_u8Peripheral : it's the peripherals connected to the buses.
 * you can fined the options of buses and it's peripherals at this file.
 * Output: void
 * */
void RCC_voidDisableClock(u8 copy_u8Bus,u8 copy_u8Peripheral);

/******************************************************************************************/
/********************************* AHB BUS and its peripherals ****************************/
/******************************************************************************************/
#define RCC_AHB_BUS 	0	/*AHB BUS*/

#define RCC_AHB_ETHMACRXEN	16  /*Ethernet MAC RX clock enable*/
#define RCC_AHB_ETHMACTXEN	15	/*Ethernet MAC TX clock enable*/
#define RCC_AHB_ETHMACEN	14	/*Ethernet MAC clock enable*/
#define RCC_AHB_OTGFSEN		12	/*USB OTG FS clock enable*/
#define RCC_AHB_CRCEN		6	/*CRC clock enable*/
#define RCC_AHB_FLITFEN		4	/*FLITF clock enable*/
#define RCC_AHB_SRAMEN		2	/*SRAM interface clock enable*/
#define RCC_AHB_DMA2EN		1	/*DMA2 clock enable*/
#define RCC_AHB_DMA1EN		0	/*DMA1 clock enable*/

/******************************************************************************************/
/********************************* APB2 BUS and its peripherals ***************************/
/******************************************************************************************/
#define RCC_APB2_BUS	2	/*APB2 BUS*/

#define RCC_APB2_USART1EN	14  	/*USART1 clock enable*/
#define RCC_APB2_SPI1EN		12		/*SPI 1 clock enable*/
#define RCC_APB2_TIM1EN		11		/*TIM1 Timer clock enable*/
#define RCC_APB2_ADC2EN		10		/*ADC 2 interface clock enable*/
#define RCC_APB2_ADC1EN		9		/*ADC 1 interface clock enable*/
#define RCC_APB2_IOPCEN		4		/*I/O port C clock enable*/
#define RCC_APB2_IOPBEN		3		/*I/O port B clock enable*/
#define RCC_APB2_IOPAEN		2		/*I/O port A clock enable*/
#define RCC_APB2_AFIOEN		0		/*Alternate function I/O clock enable*/
/******************************************************************************************/
/********************************* APB1 BUS and its peripherals ***************************/
/******************************************************************************************/
#define RCC_APB1_BUS  	1	/*APB1 BUS*/

#define RCC_APB1_DACEN		29     /*DAC interface clock enable*/
#define RCC_APB1_PWREN		28	   /*Power interface clock enable*/
#define RCC_APB1_BKPEN		27	   /*Backup interface clock enable*/
#define RCC_APB1_CAN2EN		26	   /*CAN2 clock enable*/
#define RCC_APB1_CAN1EN		25	   /*CAN1 clock enable*/
#define RCC_APB1_I2C2EN		22	   /*I2C 2 clock enable*/
#define RCC_APB1_I2C1EN		21	   /*I2C 1 clock enable*/
#define RCC_APB1_UART5EN		20	   /*USART 5 clock enable*/
#define RCC_APB1_UART4EN		19	   /*USART 4 clock enable*/
#define RCC_APB1_USART3EN	18	   /*USART 3 clock enable*/
#define RCC_APB1_USART2EN	17	   /*USART 2 clock enable*/
#define RCC_APB1_SPI3EN		15	   /*SPI 3 clock enable*/
#define RCC_APB1_SPI2EN		14	   /*SPI 2 clock enable*/
#define RCC_APB1_WWDGEN		11	   /*Window watch dog clock enable*/
#define RCC_APB1_TIM7EN		5	   /*Timer 7 clock enable*/
#define RCC_APB1_TIM6EN		4	   /*Timer 6 clock enable*/
#define RCC_APB1_TIM5EN		3	   /*Timer 5 clock enable*/
#define RCC_APB1_TIM4EN		2	   /*Timer 4 clock enable*/
#define RCC_APB1_TIM3EN		1	   /*Timer 3 clock enable*/
#define RCC_APB1_TIM2EN		0	   /*Timer 2 clock enable*/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
#define RCC_PLL_RDY_UNLOCKED	0	/*PLL clock ready flag unlocked*/
#define RCC_PLL_RDY_LOCKED		1	/*PLL clock ready flag locked*/

#define RCC_HSE_RDY_NOT_READY	0	/*External high-speed clock ready flag not ready*/
#define RCC_HSE_RDY_READY		1	/*External high-speed clock ready flag	ready*/

#define RCC_HSI_RDY_NOT_READY	0	/*Internal high-speed clock ready flag not ready*/
#define RCC_HSI_RDY_READY		1	/*Internal high-speed clock ready flag ready*/

#define RCC_SWS_HSI				0	/*System clock switch status HSI oscillator used as system clock*/
#define RCC_SWS_HSE				1	/*System clock switch status HSE oscillator used as system clock*/
#define RCC_SWS_PLL				2	/*System clock switch status PLL oscillator used as system clock*/




#endif
