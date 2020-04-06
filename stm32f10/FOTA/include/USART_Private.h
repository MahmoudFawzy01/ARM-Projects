/*
 * USART_Private.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Nourhan
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/*starting address 0x40013800*/
#define USART1_STATE_REG			*((volatile u32*)0x40013800)

#define USART_STATE_REG_RXNE		5
#define USART_STATE_REG_TC			6


#define USART1_DATA_REG				*((volatile u32*)0x40013804)
#define USART1_BOUDRATE_REG			*((volatile u32*)0x40013808)

#define USART1_CONTROL_REG_1		*((volatile u32*)0x4001380C)
#define USART_ENABLE 					13
#define USART_WORD_LENGTH				12
#define USART_WAKE_METHOD				11
#define USART_PARITY_CONTROL_ENABLE 	10
#define USART_PARITY_SELECT				9
#define USART_PARITY_ERR_INT_ENABLE		8
#define USART_TX_ERR_INT_ENABLE			7
#define USART_RX_NOT_EMPTY_INT_ENABLE	5
#define USART_TX_ENABLE					3
#define USART_RX_ENABLE					2

#define USART1_CONTROL_REG_2		*((volatile u32*)0x40013810)
#define USART_STOP1			13
#define USART_STOP0			12
#define	USART_CLK_ENABLE	11

#define USART1_CONTROL_REG_3		*((volatile u32*)0x40013814)
#define USART1_GTPR					*((volatile u32*)0x40013818) /*Guard time and prescaler register*/

#define AFIO_MAPR					*((volatile u32*)0x40010004)
#define AFIO_MAPR_USAR1		2
#define AFIO_MAPR_USAR2		3
#define AFIO_MAPR_USAR3_0	4
#define AFIO_MAPR_USAR3_1	5
#define ENABLED 	1
#define DISABLED	0

#endif /* USART_PRIVATE_H_ */
