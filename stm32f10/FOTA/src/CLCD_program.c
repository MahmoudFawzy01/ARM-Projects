/*
 * CLCD_program.c
 *
 *  Created on: Jan 15, 2020
 *      Author: Mahmoud Fawzy
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DELAY_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"




void CLCD_voidInit(void)
{
	DIO_EnuSetPinMode(DIO_PIN_1,DIO_OUT_2M_PP);/*D0_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_2,DIO_OUT_2M_PP);/*D1_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_3,DIO_OUT_2M_PP);/*D2_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_4,DIO_OUT_2M_PP);/*D3_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_5,DIO_OUT_2M_PP);/*D4_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_6,DIO_OUT_2M_PP);/*D5_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_7,DIO_OUT_2M_PP);/*D6_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_8,DIO_OUT_2M_PP);/*D7_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_9,DIO_OUT_2M_PP);/*RS_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_10,DIO_OUT_2M_PP);/*RW_Pin of LCD*/
	DIO_EnuSetPinMode(DIO_PIN_11,DIO_OUT_2M_PP);/*E_Pin of LCD*/
	_delay_ms(40);
	/*
	 * // function set cmd
	 * cmd 0 0 1 DL N F x x
	 *
	 * N (number of lines LCD support)
	 * F (font of char)
	 *
	 * DL (0,1)	  4pin mode / 8 pin mode
	 *
	 * N  (0,1)  number of lines
	 *
	 * F (0,1)  5*7 / 5*10
	 *
	 * then w8 for 40 us
	 * */

	CLCD_voidSendCmnd(0b00111100);
	_delay_ms(1);

	/*Display ON/OFF cmd
	 *  cmd 0 0 0 0 1 D C B
	 *
	 * D (Display On/Off) (1/0)
	 * C (Cursor on/Off)  (1/0)
	 * B (Blink cursor on/off)	(1/0)
	 *
	 * amd w8 40us
	 * */

	CLCD_voidSendCmnd(0b00001100);

	_delay_ms(1);

	/*
	 * Display Clear cmd
	 * cmd 0 0 0 0 0 0 0 1
	 *
	 * and w8 for 2ms
	 * */

	CLCD_voidSendCmnd(0b00000001);

	_delay_ms(2);

	/*
	 * Entry mode set cmd
	 * cmd 0 0 0 0 0 1 I/D SH
	 *
	 *	I/D (1 = Increment at DDRAM which means from left to right/ 0 decrement which means from right to left)
	 *	SH (Shift   1 = shift while writing data / 0 don't shift  while writing)
	 * and w8 for 2ms
	 * */

	CLCD_voidSendCmnd(0b00000010);

}

void CLCD_voidSetValue(u8 Copy_u8Value)
{
	DIO_EnuSetPinValue(CLCD_D0_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex0));
	DIO_EnuSetPinValue(CLCD_D1_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex1));
	DIO_EnuSetPinValue(CLCD_D2_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex2));
	DIO_EnuSetPinValue(CLCD_D3_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex3));
	DIO_EnuSetPinValue(CLCD_D4_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex4));
	DIO_EnuSetPinValue(CLCD_D5_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex5));
	DIO_EnuSetPinValue(CLCD_D6_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex6));
	DIO_EnuSetPinValue(CLCD_D7_PIN,GET_BIT(Copy_u8Value,CLCD_DataBitIndex7));
}


void CLCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
	/* Rs = 0 */
	DIO_EnuSetPinValue(CLCD_RS_PIN,DIO_PIN_LOW);
	/* Rw = 0 */
	DIO_EnuSetPinValue(CLCD_RW_PIN,DIO_PIN_LOW);
	/* Write Command */
	CLCD_voidSetValue(Copy_u8Cmnd);
	/* Enable pulse  = 1 for 230 ns the = 0 */
	DIO_EnuSetPinValue(CLCD_E_PIN,DIO_PIN_HIGH);
	_delay_us(60);
	DIO_EnuSetPinValue(CLCD_E_PIN,DIO_PIN_LOW);
	_delay_ms(1);
}


void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* Rs = 1 */
	DIO_EnuSetPinValue(CLCD_RS_PIN,DIO_PIN_HIGH);
	/* Rw = 0 */
	DIO_EnuSetPinValue(CLCD_RW_PIN,DIO_PIN_LOW);
	/* Write Command */
	CLCD_voidSetValue(Copy_u8Data);
	/* Enable pulse  = 1 for 230 ns the = 0 */
	DIO_EnuSetPinValue(CLCD_E_PIN,DIO_PIN_HIGH);
	_delay_us(60);
	DIO_EnuSetPinValue(CLCD_E_PIN,DIO_PIN_LOW);
}



void CLCD_voidSendString(u8 * Copy_u8String)
{
	u8 Local_u8Index = 0;

	while (Copy_u8String[Local_u8Index]!= '\0')
	{
		CLCD_voidSendData(Copy_u8String[Local_u8Index]);
		Local_u8Index++;
	}
}


void CLCD_voidGoToXY(u8 Copy_u8Row,u8 Copy_Column)
{
	if (((Copy_u8Row == CLCD_FIRST_LINE) || (Copy_u8Row == CLCD_SECOND_LINE)) && ( (Copy_Column >= CLCD_COL_0)&&(Copy_Column <= CLCD_COL_15)))
	{
		CLCD_voidSendCmnd(Copy_u8Row+Copy_Column);
	}
}

void CLCD_voidUpdateCustomChar(u8 Copy_Pu8Array[CLCD_SpecialCharNumbers][CLCD_SpecialCharBytes])
{
	u8 Local_u8Index,Local_u8Index1;

	CLCD_voidSendCmnd(CGRAM_ADDRESS);
	for (Local_u8Index = 0; Local_u8Index < 8 ;Local_u8Index++)
	{
		for (Local_u8Index1 = 0; Local_u8Index1 < 8 ;Local_u8Index1++)
		{
			CLCD_voidSendData(Copy_Pu8Array[Local_u8Index][Local_u8Index1]);
		}
	}
	CLCD_voidGoToXY(CLCD_FIRST_LINE,CLCD_DataBitIndex0);
}

void CLCD_voidCustomChar(u8 Copy_u8CharIndex)
{
	CLCD_voidSendData(Copy_u8CharIndex);
}


void CLCD_voidPrintNum(u32 Copy_num)
{
	u8 remainder;
	u32 reverse = 0;
	u8 Local_u8Firstdigit;

	while(Copy_num > 0)
	{
		remainder = Copy_num % 10;
        reverse = reverse * 10 + remainder;
        Copy_num /= 10;
	}
	while(reverse != 0 )
	{
		Local_u8Firstdigit = reverse %10;
		CLCD_voidSendData(Local_u8Firstdigit+48);
		reverse = reverse/10;
	}
}
