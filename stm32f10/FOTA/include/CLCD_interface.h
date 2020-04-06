/*
 * CLCD_interface.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


#define CLCD_FIRST_LINE		0x80
#define CLCD_SECOND_LINE	0xC0
#define CLCD_CLR_LCD_CMD	0x01


#define CLCD_COL_0	0
#define CLCD_COL_1	1
#define CLCD_COL_2	2
#define CLCD_COL_3	3
#define CLCD_COL_4	4
#define CLCD_COL_5	5
#define CLCD_COL_6	6
#define CLCD_COL_7	7
#define CLCD_COL_8	8
#define CLCD_COL_9	9
#define CLCD_COL_10	10
#define CLCD_COL_11	11
#define CLCD_COL_12	12
#define CLCD_COL_13	13
#define CLCD_COL_14	14
#define CLCD_COL_15	15
// OUT of range vars
#define CLCD_COL_16	16


#define CLCD_COL_0	0
#define CLCD_COL_1	1
#define CLCD_COL_2	2
#define CLCD_COL_3	3
#define CLCD_COL_4	4
#define CLCD_COL_5	5
#define CLCD_COL_6	6
#define CLCD_COL_7	7




void CLCD_voidInit(void);

void CLCD_voidSendCmnd(u8 Copy_u8Cmnd);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidCustomChar(u8 Copy_u8CharIndex);

void CLCD_voidUpdateCustomChar(u8 Copy_Pu8Array[8][8]);

void CLCD_voidSendString(u8 * Copy_u8String);

void CLCD_voidGoToXY(u8 Copy_u8Row,u8 Copy_Column);

void CLCD_voidPrintNum(u32 Copy_num);

#endif /* CLCD_INTERFACE_H_ */
