/*
 * RCC_registers.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef RCC_REGISTERS_H_		/*HEADER GUARD*/
#define RCC_REGISTERS_H_		/*HEADER GUARD*/
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_CR 					*((volatile u32*)0x40021000)
#define RCC_CR_PLL_RDY				25
#define RCC_CR_PLLON				24
#define RCC_CR_CSSON				19
#define RCC_CR_HSEBYP				18
#define RCC_CR_HSERDY				17
#define RCC_CR_HSEON				16
#define RCC_CR_HSITRIM0				3
#define RCC_CR_HSIRDY				1
#define RCC_CR_HSION				0
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_CFGR				*((volatile u32*)0x40021004)
/*	Microcontroller clock output	*/
#define RCC_CFGR_MCO_2			26
#define RCC_CFGR_MCO_1			25
#define RCC_CFGR_MCO_0			24
/*	PLL multiplication factor bits	*/
#define RCC_CFGR_PLLMUL_3		21
#define RCC_CFGR_PLLMUL_2		20
#define RCC_CFGR_PLLMUL_1		19
#define RCC_CFGR_PLLMUL_0		18
/*	LSB of division factor by 2	*/
#define RCC_CFGR_PXTPRE			17
/*	PLLSRC bit	*/
#define RCC_CFGR_PLLSRC			16
/*	The System clock switch status bits	*/
#define RCC_CFGR_SWS_0			2
#define RCC_CFGR_SWS_1			3
/*	System clock switch bits	*/
#define RCC_CFGR_SW_0			0
#define RCC_CFGR_SW_1			1
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_CIR					*((volatile u32*)0x40021008)
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_APB2RSTR			*((volatile u32*)0x4002100C)
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_APB1RSTR			*((volatile u32*)0x40021010)
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_AHBENR				*((volatile u32*)0x40021014)

#define RCC_AHBENR_ETHMACRXEN				16  /*	Ethernet MAC RX clock enable	*/
#define RCC_AHBENR_ETHMACTXEN				15	/*	Ethernet MAC TX clock enable	*/
#define RCC_AHBENR_ETHMACEN					14	/*	Ethernet MAC clock enable	*/
#define RCC_AHBENR_OTGFSEN					12	/*	USB OTG FS clock enable	*/
#define RCC_AHBENR_CRCEN					6	/*	CRC clock enable	*/
#define RCC_AHBENR_FLITFEN					4	/*	FLITF clock enable	*/
#define RCC_AHBENR_SRAMEN					2	/*	SRAM interface clock enable	*/
#define RCC_AHBENR_DMA2EN					1	/*	DMA2 clock enable	*/
#define RCC_AHBENR_DMA1EN					0	/*	DMA1 clock enable	*/
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_APB2ENR				*((volatile u32*)0x40021018)

#define RCC_APB2ENR_USART1EN				14  /*	USART1 clock enable	*/
#define RCC_APB2ENR_SPI1EN					12	/*	SPI 1 clock enable	*/
#define RCC_APB2ENR_TIM1EN					11	/*	TIM1 Timer clock enable	*/
#define RCC_APB2ENR_ADC2EN					10	/*	ADC 2 interface clock enable	*/
#define RCC_APB2ENR_ADC1EN					9	/*	ADC 1 interface clock enable	*/
#define RCC_APB2ENR_IOPCEN					4	/*	I/O port C clock enable	*/
#define RCC_APB2ENR_IOPBEN					3	/*	I/O port B clock enable	*/
#define RCC_APB2ENR_IOPAEN					2	/*	I/O port A clock enable	*/
#define RCC_APB2ENR_AFIOEN					0	/*	Alternate function I/O clock enable	*/
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_APB1ENR				*((volatile u32*)0x4002101C)

#define RCC_APB1ENR_DACEN					29  /*	DAC interface clock enable	*/
#define RCC_APB1ENR_PWREN					28	/*	SPI 1 clock enable	*/
#define RCC_APB1ENR_BKPEN					27	/*	Backup interface clock enable	*/
#define RCC_APB1ENR_CAN2EN					26	/*	CAN2 clock enable	*/
#define RCC_APB1ENR_CAN1EN					25	/*	CAN1 clock enable	*/
#define RCC_APB1ENR_I2C2EN					22	/*	I2C 2 clock enable	*/
#define RCC_APB1ENR_I2C1EN					21	/*	I2C 1 clock enable	*/
#define RCC_APB1ENR_UART5EN					20	/*	USART 5 clock enable	*/
#define RCC_APB1ENR_UART4EN					19	/*	USART 4 clock enable	*/
#define RCC_APB1ENR_UART3EN					18	/*	USART 3 clock enable	*/
#define RCC_APB1ENR_UART2EN					17	/*	USART 2 clock enable	*/
#define RCC_APB1ENR_SPI3EN					15	/*	SPI 3 clock enable	*/
#define RCC_APB1ENR_SPI2EN					14	/*	SPI 2 clock enable	*/
#define RCC_APB1ENR_WWDGEN					11	/*	Window watchdog clock enable	*/
#define RCC_APB1ENR_TIM7EN					5	/*	Timer 7 clock enable	*/
#define RCC_APB1ENR_TIM6EN					4	/*	Timer 6 clock enable	*/
#define RCC_APB1ENR_TIM5EN					3	/*	Timer 5 clock enable	*/
#define RCC_APB1ENR_TIM4EN					2	/*	Timer 4 clock enable	*/
#define RCC_APB1ENR_TIM3EN					1	/*	Timer 3 clock enable	*/
#define RCC_APB1ENR_TIM2EN					0	/*	Timer 2 clock enable	*/






///////////////////////////////////////////////////////////////////////////////////////
#define RCC_BDCR				*((volatile u32*)0x40021020)
///////////////////////////////////////////////////////////////////////////////////////
#define RCC_CSR					*((volatile u32*)0x40021024)

#endif /* RCC_REGISTERS_H_ */
