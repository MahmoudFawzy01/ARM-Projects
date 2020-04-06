/*
 * USART_Prog.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Nourhan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_Interface.h"
#include "USART_Config.h"
#include "USART_Private.h"



void USART_voidInit(void)
{
#if USART_1 == ENABLED
	/* Set BoudRate to 9600*/
	USART1_BOUDRATE_REG = 0x340;

	/*Enable USART*/
	SET_BIT(USART1_CONTROL_REG_1 , USART_ENABLE);
	/*Enable Transmission*/
	SET_BIT(USART1_CONTROL_REG_1 , USART_TX_ENABLE);
	/*Enable Reception*/
	SET_BIT(USART1_CONTROL_REG_1 , USART_RX_ENABLE);

#if USART_1_RECEIVE_INT_ENABLE == ENABLED
	/*Enable Reception*/
//	SET_BIT(USART1_CONTROL_REG_1 , USART_RX_NOT_EMPTY_INT_ENABLE);
#else
#endif
//
//	/* Select Word Length = 8bits*/
//	CLR_BIT(USART1_CONTROL_REG_1 , USART_WORD_LENGTH);
//	/* Set Wake method to IDle line*/
//	CLR_BIT(USART1_CONTROL_REG_1 , USART_WAKE_METHOD);
//	/* Enable Parity Control*/
//	SET_BIT(USART1_CONTROL_REG_1 , USART_PARITY_CONTROL_ENABLE);
//	/* Choose Even Parity*/
//	CLR_BIT(USART1_CONTROL_REG_1 , USART_PARITY_SELECT);
//	/* Enable Parity Error Interrupt*/
//	SET_BIT(USART1_CONTROL_REG_1 , USART_PARITY_ERR_INT_ENABLE);
//	/*Enable TX error Interrupt*/
//	SET_BIT(USART1_CONTROL_REG_1 , USART_TX_ERR_INT_ENABLE);
//	/*USE 1 STOP BIT*/
//	CLR_BIT(USART1_CONTROL_REG_2 , USART_STOP0);
//	CLR_BIT(USART1_CONTROL_REG_2 , USART_STOP1);
//	/*enable the CK pin*/
//	SET_BIT(USART1_CONTROL_REG_2 , USART_CLK_ENABLE);
	/*SET TX And RX pins of USARt1 to PB6 and PB7 alternatively*/
//	CLR_BIT(AFIO_MAPR , AFIO_MAPR_USAR1);
#elif USART_2 == ENABLED
#elif USART_3 == ENABLED
#elif UART_4  == ENABLED
#elif UART_5  == ENABLED
#endif
}

void USART_voidTransmitDataByte(u8 Copy_u8Data)
{
#if USART_1		==  ENABLED
	/*Add Data to Data Register*/
	USART1_DATA_REG = Copy_u8Data;
	while(GET_BIT(USART1_STATE_REG,USART_STATE_REG_TC) == 0);
#elif USART_2	==  ENABLED
#elif USART_3	==  ENABLED
#elif UART_4 	==	ENABLED
#elif UART_5 	==	ENABLED
#endif
}

void USART_voidTransmitString(u8 * Copy_Au8Data)
{
	u8 i = 0;
	while(Copy_Au8Data[i]!='\0')
	{
		USART_voidTransmitDataByte(Copy_Au8Data[i]);
		i++;
	}
}


u8   USART_u8ReceiveDataByte(void)
{
#if USART_1 	==	ENABLED
	while  ((GET_BIT(USART1_STATE_REG,USART_STATE_REG_RXNE) == 0))
	{

	}

#elif USART_2	==  ENABLED
#elif USART_3	==  ENABLED
#elif UART_4 	==	ENABLED
#elif UART_5 	==	ENABLED
#endif
	return (u8)USART1_DATA_REG;
}

void   USART_u8ReceiveString(u8 * Copy_Au8Data)
{
	u8 i = 0,Local_u8DataReceived;

	while((Local_u8DataReceived !='\n'))
	{
		Local_u8DataReceived = USART_u8ReceiveDataByte();
		Copy_Au8Data[i] = Local_u8DataReceived;
		i++;
	}
}


void   USART_u8ReceiveRecord(u8 * Copy_Au8Data,u8 size)
{
	u8 i = 0,Local_u8DataReceived;

	while((Local_u8DataReceived !='\r'))  //(i<size)
	{
		Local_u8DataReceived = USART_u8ReceiveDataByte();
		Copy_Au8Data[i] = Local_u8DataReceived;
		i++;
	}
}
