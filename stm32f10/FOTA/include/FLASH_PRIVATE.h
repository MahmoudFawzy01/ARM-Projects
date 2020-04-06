#ifndef FLASH_PRIVATE_H_
#define FLASH_PRIVATE_H_

typedef struct		//arrangement is important
{
	/*this REG to check flags of UART */
	volatile u32 ACR ;
	/*this REG to read data at receive / write data at transmit
	in hardware receiver and transmitter have different register*/
	volatile u32 KEYR ;
	/*this REG to put baud rat of UART */
	volatile u32 OPTKEYR ;
	/*this REG1 to SELECT CONTROLS AND MODES OF UART */
	volatile u32 SR ;
	/*this REG2 to SELECT CONTROLS AND MODES OF UART */
	volatile u32 CR;
	/*this REG3 to SELECT CONTROLS AND MODES OF UART */
	volatile u32 AR ;
	/*this REG2 to SELECT CONTROLS AND MODES OF UART */
	volatile u32 OBR;
	/*this REG3 to SELECT CONTROLS AND MODES OF UART */
	volatile u32 WRPR ;
}FALSH_REG;

/*address of struct each element have address	to an REG from FLASH */
#define FLASH		((volatile FALSH_REG*)0x40022000)
#define FLASH_LOCK_KEY_1			0x45670123
#define FLASH_LOCK_KEY_2			0xCDEF89AB

#define FLASH_PAGE_BASE_ADDRESS		0x08000000

/******************BITS in FLASH_ACR REG**************************************/
#define FLASH_ACR_HLFCYA			3  /*Flash half cycle access enable*/
/*****************************************************************************/
/******************flags in FLASH_SR REG**************************************/
#define FLASH_SR_EOP				5	/*End of operation FLAG*/
#define FLASH_SR_WRPRTERR			4  	/*Write protection error flag*/
#define FLASH_SR_PGERR				2  /*Programming error flag*/
#define FLASH_SR_BSY				0  /*Busy flag*/
/*****************************************************************************/
/******************bits in FLASH_CR REG**************************************/
#define FLASH_CR_EOPIE				12  /*End of operation interrupt enable*/
#define FLASH_CR_ERRIE				10  /*Error interrupt enable*/
/*	This bit is set on writing the correct key
	sequence to the FLASH_OPTKEYR register.		*/
#define FLASH_CR_OPTWRE				9  /*Option bytes write enable*/
/*	This bitis reset by hardware
 * 	after detecting the unlock sequence
 * 	put KEY1. KEY2 in FLASH_KEYR		*/
#define FLASH_CR_LOCK				7  /*Lock flash from write or erase*/
/*	all this bits enable	by set
 * 					disable	by clear	*/
#define FLASH_CR_STRT				6  /*Start erase operation*/
#define FLASH_CR_OPTER				5  /*Option byte erase*/
#define FLASH_CR_OPTPG				4  /*Option byte programming*/
#define FLASH_CR_MER				2  /*Mass erase all sectors*/
#define FLASH_CR_PER				1  /*flash Page erase */
#define FLASH_CR_PG					0  /*Programming flash*/
/*****************************************************************************/
/******************flags in FLASH_OBR REG**************************************/
#define FLASH_OBR_nRST_STDBY			4	/*End of operation FLAG*/
#define FLASH_OBR_nRST_STOP				3  	/*Write protection error flag*/
#define FLASH_OBR_WDG_SW				2  /*Programming error flag*/
#define FLASH_OBR_RDPRT					1  /*Read protection*/
/*****************************************************************************/
/******************flags in FLASH_WRPR REG**********************************************************/
/*FLASH_WRPR REG [32 bits] consist of WRP3[31:24bits]WRP2[23:16bits]WRP1[15:8bits]WRP0[7:0bits]    */
/* 	WRP0: Write-protects pages 0 to 31                                                             */
/*	WRP1: Write-protects pages 32 to 63                                                            */
/*	WRP2: Write-protects pages 64 to 95                                                            */
/*	WRP3: Write-protects pages 96 to 127                                                           */
/*	WRP: Write protect                                                                             */
/*	This register contains the write-protection option bytes loaded by the OBL.                    */
/*	0: Write protection active                                                                     */
/*	1: Write protection not active                                                                 */
/*	Note: These bits are read-only.                                                                */
/***************************************************************************************************/

#define PRIVATE_ENABLE				1
#define PRIVATE_DISABLE				2

#endif
