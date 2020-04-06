/*
 * GSM_program.c
 *
 *  Created on: Mar 9, 2020
 *      Author: Mahmoud Fawzy
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DELAY_interface.h"
#include "RCC_interface.h"
#include "USART_Interface.h"
#include "GSM_interface.h"
#include "CLCD_interface.h"


void GSM_init(void)
{
	USART_voidTransmitString(" \r");
	_delay_ms(30);
}
void GSM_RESET(void)
{
	u8 Buffer[8];
	USART_voidTransmitString("ATZ0\r");
	_delay_ms(30);
	USART_voidTransmitString("AT+COPS=0,2\r");
	_delay_ms(10000);
}

u8 GSM_u8CheckConnection(void)
{
	u8 ReceivedStr[5],Local_u8Error = 1;

	USART_voidTransmitString("AT\r");
	// echo
	USART_u8ReceiveString(ReceivedStr);
	//response
	USART_u8ReceiveString(ReceivedStr);
	ReceivedStr[2] = '\0';

	if(strcmp(ReceivedStr,"OK") == 0)
	{
		Local_u8Error = 0;
	}

	return Local_u8Error;
}


u8 GSM_u8RunFullFunc(void)
{
	u8 ReceivedStr[11],Local_u8Error = 1;
	USART_voidTransmitString("AT+CFUN=1\r");
	USART_u8ReceiveString(ReceivedStr);
	USART_u8ReceiveString(ReceivedStr);
	ReceivedStr[2] = '\0';
	if(strcmp(ReceivedStr,"OK") == 0)
	{
		Local_u8Error = 0;
	}

	return Local_u8Error;
}



u8 GSM_u8AddInternetServiceProvider(void)
{
	u8 ReceivedStr[45],Local_u8Error = 1;

	USART_voidTransmitString("AT+CSTT=\"internet.vodafone.net\",\"\",\"\"\r");
	USART_u8ReceiveString(ReceivedStr);
	USART_u8ReceiveString(ReceivedStr);
	ReceivedStr[2] = '\0';
	if(strcmp(ReceivedStr,"OK") == 0)
	{
		Local_u8Error = 0;
	}

	return Local_u8Error;
}

u8 GSM_u8OpenData(u8 * Copy_Au8IP)
{
	u8 ReceivedStr[25],Local_u8Error = 1,i=0;

	USART_voidTransmitString("AT+CIICR\r");
	USART_u8ReceiveString(ReceivedStr);
	USART_u8ReceiveString(ReceivedStr);
	ReceivedStr[2] = '\0';

	if(strcmp(ReceivedStr,"OK") == 0)
	{
		Local_u8Error = 0;
		USART_voidTransmitString("AT+CIFSR\r");
		USART_u8ReceiveString(ReceivedStr);
		// clear the array
		while(i<16)
		{
			ReceivedStr[i++] = '\0';
		}
		i=0;

		USART_u8ReceiveString(ReceivedStr);

		while(ReceivedStr[i] != '\0')
		{
			Copy_Au8IP[i] = ReceivedStr[i];
			i++;
		}
	}

	return Local_u8Error;
}
u8 GSM_voidConnectToInternet(void)
{
	u8 ip[16],check = 1,Local_u8Mode = 0 , Local_u8Tries = 0;

	// try to connect to the internet and get an ip
	while (check!=0 && Local_u8Mode != 3 && Local_u8Tries < 20)
	{
		switch(Local_u8Mode)
		{
		case 0:
			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString("Check connection..");
			_delay_ms(250);
			check = GSM_u8CheckConnection();
			if (check == 0)
			{
				Local_u8Mode = 2;
			}
			_delay_ms(50);
			break;
		case 1:
			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString("Adding Network..");
			_delay_ms(250);
			check = GSM_u8AddInternetServiceProvider();

			if(check == 0)
			{
				Local_u8Mode = 2;
			}
			_delay_ms(50);
			break;
		case 2:
			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString("Getting IP..");
			_delay_ms(250);
			check = GSM_u8OpenData(ip);
			if(check == 0)
			{
				CLCD_voidSendCmnd(0x01);
				CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
				CLCD_voidSendString("Local IP:");
				CLCD_voidGoToXY(CLCD_SECOND_LINE,0);
				CLCD_voidSendString(ip);
				_delay_ms(250);
				Local_u8Mode = 3;
			}
			_delay_ms(50);
			break;
		}
		_delay_ms(100);
		Local_u8Tries ++;
	}
	return check;
}

u8 GSM_voidConnectToServer(void)
{
	u8 ReceivedStr[255],i=0,Local_u8Error=1, Local_u8Tries = 0;

	while (Local_u8Error!=0 && Local_u8Tries < 20)
	{
		CLCD_voidSendCmnd(0x01);
		CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
		CLCD_voidSendString("Server conne...");
		CLCD_voidGoToXY(CLCD_SECOND_LINE,0);
		CLCD_voidSendString("51.89.21.226:15000");
		_delay_ms(1000);
		USART_voidTransmitString("AT+CIPSTART=\"TCP\",\"51.89.21.226\",15000\r");
		USART_u8ReceiveString(ReceivedStr);
		USART_u8ReceiveString(ReceivedStr);
		USART_u8ReceiveString(ReceivedStr);
		USART_u8ReceiveString(ReceivedStr);

		//  the string received
		while(ReceivedStr[i] != '\r')
		{
			i++;
		}
		ReceivedStr[i] = '\0';
		// compare the received string with "CONNECT OK"
		if((strcmp(ReceivedStr,"CONNECT OK") == 0)||(strcmp(ReceivedStr,"ALREADY CONNECT") == 0))
		{
			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString(ReceivedStr);
			_delay_ms(250);
			Local_u8Error = 0;
		}
		_delay_ms(500);
	}

	return Local_u8Error;
}

void GSM_voidReceiveLineFromServer(u8 * ReceivedStr, u8 Copy_u8DataType)
{
	u8 i=0;

	// send packate to the server
	USART_voidTransmitString("AT+CIPSEND=1\r");
	_delay_ms(30);
	if (Copy_u8DataType == 3)
	{
		USART_voidTransmitString("3\r");
	}
	else
	{
		if (Copy_u8DataType == 1)
		{
			USART_voidTransmitString("1\r");
		}
		else if (Copy_u8DataType == 2)
		{
			USART_voidTransmitString("2\r");
		}

		USART_u8ReceiveString(ReceivedStr);

		i=0;
		while(ReceivedStr[i] != '\0')
		{
			ReceivedStr[i] = '\0';
			i++;
		}
		USART_u8ReceiveString(ReceivedStr);

		USART_u8ReceiveRecord(ReceivedStr);
	}
	_delay_ms(30);
}
