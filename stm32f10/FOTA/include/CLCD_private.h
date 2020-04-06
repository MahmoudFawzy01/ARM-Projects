/*
 * CLCD_private.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define CLCD_DataBitIndex0	0
#define CLCD_DataBitIndex1	1
#define CLCD_DataBitIndex2	2
#define CLCD_DataBitIndex3	3
#define CLCD_DataBitIndex4	4
#define CLCD_DataBitIndex5	5
#define CLCD_DataBitIndex6	6
#define CLCD_DataBitIndex7	7


static void CLCD_voidSetValue(u8 Copy_u8Value);

#define CGRAM_ADDRESS	0x40

#define CLCD_SpecialCharNumbers	8
#define CLCD_SpecialCharBytes	8
#endif /* CLCD_PRIVATE_H_ */
