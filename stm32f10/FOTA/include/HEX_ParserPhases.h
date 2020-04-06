#ifndef _HEX_PARSER_PHASES_H_
#define _HEX_PARSER_PHASES_H_

typedef struct cRecord HexRecord;
struct cRecord {
	u8 		DataBytesCount;
	u32		DataArray[11];
	u8		RecordType;
	u16 	Address;
};

/************************************************************************/
/*	Function:		HEX_RecordParser
	Description:	extract the recored elements CC/ADD/RT/DATA
	Parameters:		record	 -> char pointer to the start of the record passed
					Copy_StrReturn -> Struct contains all info of the record
	returns:		int (1/0)  1- means that the var added successfully
					0- means that the var is not added successfully		*/
/************************************************************************/ 
u8 HEX_RecordParser(u8 * record, HexRecord * Copy_StrReturn);


/************************************************************************/
/*	Function:		HEX_StrToHex
	Description:	used to convert the record from string to hex array
	Parameters:		record	 -> char pointer to the start of the record passed

	returns:		u16 returns the array size							*/
/************************************************************************/
u16 HEX_StrToHex(u8 * record);


extern HexRecord Current_Hex_Record_Info;

#endif /*_HEX_PARSER_PHASES_H_*/
