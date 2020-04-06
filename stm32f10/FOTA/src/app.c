/*
 * app.c
 *
 *  Created on: Mar 1, 2020
 *      Author: sasafizo
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "HEX_ParserPhases.h"
#include "FLASH_INTERFACE.h"
#include "DELAY_interface.h"
#include "DIO_interface.h"
#include "USART_Interface.h"
#include "GSM_interface.h"
#include "CLCD_interface.h"

#define APP_ADDRESS_OFFSET	0x08000000
#define CURRENT_VER			"1.0.0"

enum {
	CheckAppVer,
	UpdateAvailable,
	WriteApp,
	JumpToApp
}APPLiCATION;

__attribute__((naked)) static void BranchToApp(u32 pc, u32 sp) {
    __asm("           \n\
          msr msp, r1 /* load r1 into MSP */\n\
          bx r0       /* branch to the address at r0 */\n\
    ");
}

void main(void)

{
	u8 Buffer[521] = {0},Local_u8ConnectionStatus = 0,i=0;

	RCC_voidProcessorClockInit();

	/*Enable Port A*/
	RCC_voidEnableClock(RCC_APB2_BUS,RCC_APB2_IOPAEN);
	/*Enable Port B*/
	RCC_voidEnableClock(RCC_APB2_BUS,RCC_APB2_IOPBEN);

	/*Enable Port C*/
	RCC_voidEnableClock(RCC_APB2_BUS,RCC_APB2_IOPCEN);

	/*Enable USART1 Clock*/
	RCC_voidEnableClock(RCC_APB2_BUS,RCC_APB2_USART1EN);

	/*	DIO init	*/
	DIO_voidInit();

	/*	CLCD init	*/
	CLCD_voidInit();

	/*	USART init	*/
	USART_voidInit();

	/*USART in Full Duplex Mode*/
	DIO_EnuSetPinMode(USART1_TX,DIO_OUT_2M_AFPP);
	DIO_EnuSetPinMode(USART1_RX,DIO_IN_PULL_UP);

	// Flash init
	FLASH_voidInt();

	// GSM init
	GSM_init();

	u32 *app_code = (u32 *)0x08004000;
	u32 app_sp = app_code[0];
	u32 app_pc = app_code[1];
	u32	CheckValue = 0,o=0;

	/*
	 * connect to the server or the hex file provider and take record by record from it then send the current record to the parser.
	 * extract the record info  using the parser.
	 * */
	// try to connect to server
	GSM_voidConnectToInternet();
	_delay_ms(1000);
	Local_u8ConnectionStatus = GSM_voidConnectToServer();
	_delay_ms(3000);

	// check for update of var and return to APPLiCATION
	if(Local_u8ConnectionStatus == 1)
	{
		APPLiCATION = JumpToApp;
	}
	else
	{
		APPLiCATION = CheckAppVer;
	}

	while(1)
	{
		//////////////////////////////
		switch (APPLiCATION)
		{
		case CheckAppVer:
			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString("Checking ver..");
			_delay_ms(250);
			GSM_voidReceiveLineFromServer(Buffer,RECEIVE_APP_VER);

			//  the string received
			while(Buffer[i] != '\r')
			{
				i++;
			}
			Buffer[i] = '\0';
			i=0;

			// compare the received string with Current app ver
			if(strcmp(Buffer,CURRENT_VER) == 0)
			{
				CLCD_voidSendCmnd(0x01);
				CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
				CLCD_voidSendString("Up to date..");
				_delay_ms(250);
				// jump to the app.
				APPLiCATION = JumpToApp;
			}
			else
			{
				CLCD_voidSendCmnd(0x01);
				CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
				CLCD_voidSendString("new ver:");
				CLCD_voidSendString(Buffer);
				_delay_ms(250);
				APPLiCATION = UpdateAvailable;
			}
			// CLEAR THE BUFFER
			while(o < 521)
			{
				Buffer[o] = '\0';
				o++;
			}
			break;
		case UpdateAvailable:
			// if there is new update or new app version go write the app
			// jump to the app
			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString("Updating..");
			_delay_ms(250);
			APPLiCATION = WriteApp;
			break;
		case WriteApp:
			do
			{
				// Get the new record from the server
				/*
				 * this record will update the buffer
				 * */
				GSM_voidReceiveLineFromServer(Buffer,RECEIVE_NEXT_LINE);
				// convert the string to hex
				HEX_StrToHex(Buffer);
				// Parse the Buffer
				HEX_RecordParser(Buffer,&Current_Hex_Record_Info);

				// CLEAR THE BUFFER
				while(o < 521)
				{
					Buffer[o] = '\0';
					o++;
				}
				// flash the data using the flash driver.
				/*
				 * */
				if (Current_Hex_Record_Info.DataBytesCount > 0)
				FLASH_EnumWriteString(ONE_WORD,Current_Hex_Record_Info.DataArray,APP_ADDRESS_OFFSET+Current_Hex_Record_Info.Address,(Current_Hex_Record_Info.DataBytesCount)/4);
			}
			while(Current_Hex_Record_Info.RecordType != 1);

			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString("Update finished.");
			_delay_ms(250);
			// reset server to first line
			GSM_voidReceiveLineFromServer(Buffer,RESET_SERVER);
			// jump to the app
			APPLiCATION = JumpToApp;

			break;
		case JumpToApp:
			CLCD_voidSendCmnd(0x01);
			CLCD_voidGoToXY(CLCD_FIRST_LINE,0);
			CLCD_voidSendString("Opening App.");
			_delay_ms(250);
			BranchToApp(app_pc,app_sp);
			break;
		}
	}
}

