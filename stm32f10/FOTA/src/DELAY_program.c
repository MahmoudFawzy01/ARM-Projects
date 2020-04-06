/*
 * DELAY_program.c
 *
 *  Created on: Feb 9, 2020
 *      Author: Mahmoud Fawzy
 */
#include "STD_Types.h"
#include "DELAY_interface.h"

void _delay_ms(u32 Copy_u32TimeMS)
{
	u32 x=((system_clock_MHZ*Copy_u32TimeMS*1000UL)-33)/9;
	while(x--)
	{
		asm("nop");
	}
}

void _delay_us(u32 Copy_u32TimeUS)
{
	u32 x=((system_clock_MHZ*Copy_u32TimeUS)-36)/9;
	if (Copy_u32TimeUS >= 40)
	{
		while(x--)
		{
			asm("nop");
		}
	}
}


