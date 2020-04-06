/*
 * USART_Interface.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Nourhan
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define USART1_TX	9
#define USART1_RX	10

void USART_voidInit(void); /*1- Set BoudRate , 2- Set Mode , 3-  */

void USART_voidTransmitDataByte(u8 Copy_u8Data);

void USART_voidTransmitString(u8 * Copy_Au8Data);

u8   USART_u8ReceiveDataByte(void);

void   USART_u8ReceiveString(u8 * Copy_Au8Data);


#endif /* USART_INTERFACE_H_ */
