#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_Types.h"
#include "HEX_ParserPhases.h"

enum recordLevels {
	RECORD_CC0,
	RECORD_CC1,
	RECORD_Address0,
	RECORD_Address1,
	RECORD_Address2,
	RECORD_Address3,
	RECORD_RT0,
	RECORD_RT1
};

// global var used to contain the info of the record (CC/ADD/RT/DATA)
HexRecord Current_Hex_Record_Info;

/************************************************************************/
/*	Function:		HEX_RecordParser
	Description:	extract the recored elements CC/ADD/RT/DATA
	Parameters:		record	 -> char pointer to the start of the record passed
					Copy_StrReturn -> Struct contains all info of the record
	returns:		int (1/0)  1- means that the var added successfully
					0- means that the var is not added successfully		*/
/************************************************************************/ 

u8 HEX_RecordParser(u8 * record, HexRecord * Copy_StrReturn)
{
	u16 i = 0,y = 0,z=0, DataArrayHexDigitsRemained,DataArrayHexDigitsCount;
	u8 Local_Au8DataArray[512] = {0};

	// clear the word arr before use 

	Copy_StrReturn -> DataBytesCount = 0;
	Copy_StrReturn -> Address = 0;
	// clear array
	for (z = 0;z<512; z++)
	{
		Copy_StrReturn -> DataArray[z] = '\0';
	}
	Copy_StrReturn -> RecordType = 0;

	// extract info till data
	Copy_StrReturn -> DataBytesCount |= (record[RECORD_CC0]<<4) | (record[RECORD_CC1]);
	Copy_StrReturn -> Address |= (record[RECORD_Address0]<<12) | (record[RECORD_Address1]<<8) | (record[RECORD_Address2]<<4) | (record[RECORD_Address3]);
	Copy_StrReturn -> RecordType |= (record[RECORD_RT0]<<4) | (record[RECORD_RT1]);

	y = 8;
	z = 0;
	for (i = 0; i < (2*Copy_StrReturn -> DataBytesCount); i++)
	{
		Local_Au8DataArray [i] = record[y];

		if (((i+1) % 8 == 0)&& (i != 0))
		{
			Copy_StrReturn -> DataArray [z] =  Local_Au8DataArray [i-1]<<28 | Local_Au8DataArray [i]<<24 | Local_Au8DataArray [i-3]<<20 | Local_Au8DataArray [i-2]<<16 | Local_Au8DataArray [i-5]<<12 | Local_Au8DataArray [i-4]<<8 | Local_Au8DataArray [i-7]<<4 | Local_Au8DataArray [i-6];
			z++;
		}
		y++;
	}

	/////////////////////////////////////////////////////////////////
	// in case of the remained digits not inserted to the DataArray//
	/////////////////////////////////////////////////////////////////
	/* this case rare to happen */
	DataArrayHexDigitsCount = (((z)*8)-1);
	if ( DataArrayHexDigitsCount < ((2*Copy_StrReturn -> DataBytesCount) -1))
	{
		DataArrayHexDigitsRemained = ((2*Copy_StrReturn -> DataBytesCount)-1) - DataArrayHexDigitsCount;

		for (i = 0;i< DataArrayHexDigitsRemained;i++)
		{
			Copy_StrReturn -> DataArray[z] |= Local_Au8DataArray[DataArrayHexDigitsCount + i]<<(28- (4*i));
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

/************************************************************************/
/*	Function:		HEX_StrToHex
	Description:	used to convert the record from string to hex array
	Parameters:		record	 -> char pointer to the start of the record passed
	returns:		u16 returns the array size							*/
/************************************************************************/
u16 HEX_StrToHex(u8 * record)
{
	u16 i = 1;

	while(record[i] != '\0')
	{
		if (record[i]>='0'&&record[i]<='9')
		{
			record[i-1] = record[i] - 0x30 ;
			record[i] = '\0';

		}
		else if (record[i]>='A'&&record[i]<='F')
		{
			record[i-1] = record[i] - 0x37 ;
			record[i] = '\0';
		}

		i++;
	}
	return i;
}
