/*
 * FLASH_PROGRAM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abanob
 */



#include "STD_Types.h"
#include "BIT_MATH.h"
#include "FLASH_INTERFACE.h"
#include "FLASH_PRIVATE.h"
#include "FLASH_CONFIGURATION.h"




void FLASH_voidInt(void)
{
#if FLASH_HALF_CYCLE_ACCESS_ENABLE	== PRIVATE_DISABLE
	CLR_BIT(FLASH->ACR,FLASH_ACR_HLFCYA);

#elif FLASH_HALF_CYCLE_ACCESS_ENABLE	==	PRIVATE_ENABLE
	SET_BIT(FLASH->ACR,FLASH_ACR_HLFCYA);

#endif

#if FLASH_END_OF_OPERATION_INTERRUPT	== PRIVATE_DISABLE
	CLR_BIT(FLASH->CR,FLASH_CR_EOPIE);

#elif FLASH_END_OF_OPERATION_INTERRUPT	==	PRIVATE_ENABLE
	SET_BIT(FLASH->CR,FLASH_CR_EOPIE);

#endif

#if FLASH_ERROR_INTERRUPT	== PRIVATE_DISABLE
	CLR_BIT(FLASH->CR,FLASH_CR_ERRIE);

#elif FLASH_ERROR_INTERRUPT	==	PRIVATE_ENABLE
	SET_BIT(FLASH->CR,FLASH_CR_ERRIE);

#endif


}

u8 FLASH_u8GetStatues(void)
{
	if(GET_BIT(FLASH->SR,FLASH_SR_BSY) == 1)
	{
		return 1; //busy
	}
	else if(GET_BIT(FLASH->SR,FLASH_SR_PGERR) == 1)
	{
		return 2; //Programming error. Programming a non-zeroxff address
	}
	else if(GET_BIT(FLASH->SR,FLASH_SR_WRPRTERR) == 1)
	{
		return 3; //write protection error
	}
	return 0; //End of operation
}

u8 FLASH_WaitDone(u16 time)
{

	do{
		//Get status
		if(FLASH_u8GetStatues() == 0)
		{
			break; //not busy
		}
		//delay_us(1);
		time--;
	}
	while(time);
	if(time==0)
	{
		//timeout without do any thing
		return 1;
	}
	// you can do your operation
	return 0;
}

FlashStatus FLASH_EnumWrite(u8 Copy_u8TypeOfData,u32 Copy_u32Data,u32 Copy_u32Address)
{
	FlashStatus Status = FLASH_EnumUnlock();
	u8 Local_u8I;
	u8 Local_u8NumberOfLoop = 0;
	if(Status == unlocked)
	{
		switch(Copy_u8TypeOfData)
		{
		case HALF_WORD:
			Local_u8NumberOfLoop = 1;
			break;
		case ONE_WORD:
			Local_u8NumberOfLoop = 2;
			break;
		case TWO_WORD:
			Local_u8NumberOfLoop = 4;
			break;
		}
		for(Local_u8I = 0; Local_u8I < Local_u8NumberOfLoop; Local_u8I++)
		{
			FLASH_EnumWriteHalfWord((u16)(Copy_u32Data >> (16*Local_u8I)),(Copy_u32Address + (2*Local_u8I)));
		}
		Status = FLASH_EnumLock();
	}
	else
	{
		Status	= notwrite;
	}
	return Status;

}

FlashStatus FLASH_EnumWriteString(u8 Copy_u8TypeOfData,u32 *Copy_pu32Buffer,u32 Copy_u32Address,u16 Copy_u16Size)
{
	u8 Local_u8I;
	FlashStatus Status = notwrite;
	for(Local_u8I = 0;Local_u8I < Copy_u16Size;Local_u8I++)
	{
		Status = FLASH_EnumWrite(Copy_u8TypeOfData,Copy_pu32Buffer[Local_u8I],Copy_u32Address);
		Copy_u32Address = Copy_u32Address + Copy_u8TypeOfData;
	}
	return Status;
}

u16 FLASH_u16ReadHalfWord(u32 Copy_u32Address)
{
	return *(u16*)Copy_u32Address;
}

void FLASH_voidRead(u8 Copy_u8TypeOfData,u64 *Copy_u64ReadData,u32 Copy_u32Address)
{

	u8 Local_u8I;
	u8 Local_u8NumberOfLoop = 0;
	*Copy_u64ReadData = 0;
	switch(Copy_u8TypeOfData)
	{
	case HALF_WORD:
		Local_u8NumberOfLoop = 1;
		break;
	case ONE_WORD:
		Local_u8NumberOfLoop = 2;
		break;
	case TWO_WORD:
		Local_u8NumberOfLoop = 4;
		break;
	}
	for(Local_u8I = 0; Local_u8I < Local_u8NumberOfLoop; Local_u8I++)
	{
		*Copy_u64ReadData = *Copy_u64ReadData | (FLASH_u16ReadHalfWord((Copy_u32Address + (2*Local_u8I)))<<16*Local_u8I);
	}


}

/*void FLASH_voidReadString(u8 Copy_u8TypeOfData,u64 *Copy_pu64Buffer,u32 Copy_u32Address,u16 Copy_u16Size)
{
	u8 Local_u8I;
	for(Local_u8I = 0;Local_u8I < Copy_u16Size;Local_u8I++)
	{
		FLASH_voidRead(Copy_u8TypeOfData,Copy_pu64Buffer[Local_u8I],Copy_u32Address);
		Copy_u32Address = Copy_u32Address + Copy_u8TypeOfData;
	}

}
 */





FlashStatus FLASH_EnumErasePage(u32 Copy_u32Address)
{
	u8 Local_u8Ret = FLASH_WaitDone(1000);
	FlashStatus Status;
	if(Local_u8Ret == 0)
	{
		Status = FLASH_EnumUnlock();
		if(Status == unlocked )
		{
			//Enable page erase
			SET_BIT(FLASH->CR,FLASH_CR_PER);
			//Select the page to be erased
			FLASH->AR = Copy_u32Address;
			//Start erasing
			SET_BIT(FLASH->CR,FLASH_CR_STRT);
			//Wait for erasure completion
			//Local_u8Ret = FLASH_WaitDone(1000);
			//if(Local_u8Ret == 0)//not busy
			//{
				//Disable page erase
				CLR_BIT(FLASH->CR,FLASH_CR_PER);
				Status = FLASH_EnumLock();

				Status = erased;
			//}
			/*else
			{

				Status = FLASH_EnumLock();
				Status = noterased;

			}*/

		}
		else
		{
			Status = noterased;
		}

	}
	else
	{
		Status = noterased;
	}
	return Status;
}

FlashStatus FLASH_EnumEraseAllPage(void)
{


	u8 Local_u8Ret = FLASH_WaitDone(1000);
	FlashStatus Status;
	if(Local_u8Ret == 0)
	{
		Status = FLASH_EnumUnlock();
		if(Status == unlocked )
		{
			//Enable MASS erase(ALL pages)
			SET_BIT(FLASH->CR,FLASH_CR_MER);

			//Start erasing
			SET_BIT(FLASH->CR,FLASH_CR_STRT);
			//Wait for erasure completion
			Local_u8Ret = FLASH_WaitDone(0x5fff);
			if(Local_u8Ret == 0)//not busy
			{
				//Disable MER erase
				CLR_BIT(FLASH->CR,FLASH_CR_MER);
				Status = FLASH_EnumLock();
				Status = erased;
			}
			else
			{
				Status = FLASH_EnumLock();
				Status = noterased;
			}
		}
		else
		{
			Status = noterased;
		}

	}
	else
	{
		Status = noterased;
	}
	return Status;
}

FlashStatus FLASH_EnumUnlock(void)
{
	FlashStatus Status = unlocked;
	if(GET_BIT(FLASH->CR,FLASH_CR_LOCK) == 1)/*IF FLASH IS LOCKED OPEN IT BY*/
	{
		FLASH->KEYR = FLASH_LOCK_KEY_1;
		FLASH->KEYR = FLASH_LOCK_KEY_2;
		/*to check if lock became = 0 and flash control is unlocked */

		if(GET_BIT(FLASH->CR,FLASH_CR_LOCK) == 1)
		{
			Status = locked;
		}
		else
		{
			Status = unlocked;
		}
	}
	else
	{

	}
	return Status;
}

FlashStatus FLASH_EnumLock(void)
{
	FlashStatus Status = locked;
	if(GET_BIT(FLASH->CR,FLASH_CR_LOCK) == 0)/*IF FLASH IS unLOCKED lock IT*/
	{
		SET_BIT(FLASH->CR,FLASH_CR_LOCK);
		/*to check if lock became = 1 and flash control is locked*/
		if(GET_BIT(FLASH->CR,FLASH_CR_LOCK) == 0)
		{
			Status = unlocked;
		}
		else
		{
			Status = locked;
		}
	}
	else
	{

	}
	return Status;

}

void FLASH_EnumWriteHalfWord(u16 Copy_u16HalfWord,u32 Copy_u32Address)
{
	while(GET_BIT(FLASH->SR,FLASH_SR_BSY) == 1);/*wait until FLASH finish operation*/
	SET_BIT(FLASH->CR,FLASH_CR_PG);
	*(u16*)Copy_u32Address = Copy_u16HalfWord;

}
