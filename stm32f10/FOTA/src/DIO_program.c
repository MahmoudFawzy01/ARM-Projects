/*
 * DIO_program.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Mahmoud Fawzy
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"


/*
 * Description : Set all pins mode.
 * Inputs  :
 * Outputs :
 * */
void DIO_voidInit(void)
{
	/*	Configure	All pins mode	*/
	DIO_CRL_A 	= CONC(	DIO_PIN_0_MODE,
						DIO_PIN_1_MODE,
						DIO_PIN_2_MODE,
						DIO_PIN_3_MODE,
						DIO_PIN_4_MODE,
						DIO_PIN_5_MODE,
						DIO_PIN_6_MODE,
						DIO_PIN_7_MODE);

	DIO_CRH_A	= CONC(	DIO_PIN_8_MODE,
						DIO_PIN_9_MODE,
						DIO_PIN_10_MODE,
						DIO_PIN_11_MODE,
						DIO_PIN_12_MODE,
						DIO_PIN_13_MODE,
						DIO_PIN_14_MODE,
						DIO_PIN_15_MODE);

	DIO_CRL_B 	= CONC(	DIO_PIN_16_MODE,
						DIO_PIN_17_MODE,
						DIO_PIN_18_MODE,
						DIO_PIN_19_MODE,
						DIO_PIN_20_MODE,
						DIO_PIN_21_MODE,
						DIO_PIN_22_MODE,
						DIO_PIN_23_MODE);

	DIO_CRH_B 	= CONC( DIO_PIN_24_MODE,
						DIO_PIN_25_MODE,
						DIO_PIN_26_MODE,
						DIO_PIN_27_MODE,
						DIO_PIN_28_MODE,
						DIO_PIN_29_MODE,
						DIO_PIN_30_MODE,
						DIO_PIN_31_MODE);

	DIO_CRH_C 	= CONC( DIO_PIN_34_MODE,
						DIO_PIN_33_MODE,
						DIO_PIN_32_MODE,
						0,
						0,
						0,
						0,
						0);
}

/*
 * Description : Set the desired pin value.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~34)]   -  [Copy_u8PinValue -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinValue(u8 Copy_u8PinNumber ,u8 Copy_u8PinValue)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].


	// to ensure that the passed Pin Number value is between [0~34]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_34))
	{
		u8	Local_u8PortNum = Copy_u8PinNumber / 16;
		u8	Local_u8PinNum = Copy_u8PinNumber % 16;

		// to ensure that the passed Direction value is between [0/1]
		if ((Copy_u8PinValue >= DIO_PIN_LOW) && (Copy_u8PinValue <= DIO_PIN_HIGH))
		{
			switch (Local_u8PortNum)
			{
			case 0: ASSIGN_BIT(DIO_ODR_A,Local_u8PinNum,Copy_u8PinValue); Local_EnuError = OK; break;
			case 1: ASSIGN_BIT(DIO_ODR_B,Local_u8PinNum,Copy_u8PinValue); Local_EnuError = OK; break;
			case 2: ASSIGN_BIT(DIO_ODR_C,Local_u8PinNum,Copy_u8PinValue); Local_EnuError = OK; break;
			default:Local_EnuError = OUTOFRANGE;						  break;
			}
		}
		else
		{
			Local_EnuError = OUTOFRANGE;
		}
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}


	return Local_EnuError;
}


/*
* Description : Get the desired pin value.
* Inputs  :[Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)] - [* Copy_u8Value used to receive the pin value 0/1]
* Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
* */
ErrorStatus DIO_EnuGetPinValue(u8 Copy_u8PinNumber ,u8 * Copy_Pu8PinValue)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	// to ensure that the passed Pin Number value is between [0~34]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_34))
	{
		u8	Local_u8PortNum = Copy_u8PinNumber / 16;
		u8	Local_u8PinNum = Copy_u8PinNumber % 16;
		// Check if the pointer passed
		if (Copy_Pu8PinValue != NULL_POINTER)
		{
			switch (Local_u8PortNum)
			{
			case 0: *Copy_Pu8PinValue =  GET_BIT(DIO_IDR_A,Local_u8PinNum); Local_EnuError = OK; break;
			case 1: *Copy_Pu8PinValue =  GET_BIT(DIO_IDR_B,Local_u8PinNum); Local_EnuError = OK; break;
			case 2: *Copy_Pu8PinValue =  GET_BIT(DIO_IDR_C,Local_u8PinNum); Local_EnuError = OK; break;
			default: Local_EnuError = OUTOFRANGE;						  break;
			}
		}
		else
		{
			Local_EnuError = NULLPOINTER;
		}
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}


	return Local_EnuError;
}


/*
 * Description : Set the desired pin mode.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~34)]   -  [Copy_u8PinMode -> pin mode is between [DIO_IN_ANALOG~PRIVATE_OUT_50M_AFOD]
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinMode(u8 Copy_u8PinNumber,u8 Copy_u8PinMode)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	// to ensure that the passed Pin Number value is between [0~34]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_34))
	{
		u8	Local_u8PortNum = Copy_u8PinNumber / 16;
		u8	Local_u8PinNum = Copy_u8PinNumber % 16;
		// to ensure that the passed pin mode value is between [DIO_IN_ANALOG~PRIVATE_OUT_50M_AFOD]
		if ((Copy_u8PinMode >= DIO_IN_ANALOG) && (Copy_u8PinMode <= PRIVATE_OUT_50M_AFOD))
		{
			switch (Local_u8PortNum)
			{
			case 0:
				if (Local_u8PinNum <= 7)
				{
					if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
					{
						ASSIGN_4BITS(DIO_CRL_A,Local_u8PinNum,PRIVATE_IN_PULL_DOWN);
					}
					else
					{
						ASSIGN_4BITS(DIO_CRL_A,Local_u8PinNum,Copy_u8PinMode);
					}
				}
				else if (Local_u8PinNum > 7)
				{
					if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
					{
						ASSIGN_4BITS(DIO_CRH_A,(Local_u8PinNum-8),PRIVATE_IN_PULL_DOWN);
					}
					else
					{
						ASSIGN_4BITS(DIO_CRH_A,(Local_u8PinNum-8),Copy_u8PinMode);
					}
				}

				if (Copy_u8PinMode == PRIVATE_IN_PULL_DOWN)
				{
					ASSIGN_BIT(DIO_ODR_A,Local_u8PinNum,DIO_PIN_LOW);
				}
				else if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
				{
					ASSIGN_BIT(DIO_ODR_A,Local_u8PinNum,DIO_PIN_HIGH);
				}
				Local_EnuError = OK;
				break;
			case 1:
				if (Local_u8PinNum <= 7)
				{
					if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
					{
						ASSIGN_4BITS(DIO_CRL_B,Local_u8PinNum,PRIVATE_IN_PULL_DOWN);
					}
					else
					{
						ASSIGN_4BITS(DIO_CRL_B,Local_u8PinNum,Copy_u8PinMode);
					}

				}
				else if (Local_u8PinNum > 7)
				{
					if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
					{
						ASSIGN_4BITS(DIO_CRH_B,(Local_u8PinNum-8),PRIVATE_IN_PULL_DOWN);
					}
					else
					{
						ASSIGN_4BITS(DIO_CRH_B,(Local_u8PinNum-8),Copy_u8PinMode);
					}

				}

				if (Copy_u8PinMode == PRIVATE_IN_PULL_DOWN)
				{
					ASSIGN_BIT(DIO_ODR_B,Local_u8PinNum,DIO_PIN_LOW);
				}
				else if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
				{
					ASSIGN_BIT(DIO_ODR_B,Local_u8PinNum,DIO_PIN_HIGH);
				}
				Local_EnuError = OK;
				break;
			case 2:
				if (Local_u8PinNum >= 13)
				{
					if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
					{
						ASSIGN_4BITS(DIO_CRH_C,(Local_u8PinNum-8),PRIVATE_IN_PULL_DOWN);
					}
					else
					{
						ASSIGN_4BITS(DIO_CRH_C,(Local_u8PinNum-8),Copy_u8PinMode);
					}
				}

				if (Copy_u8PinMode == PRIVATE_IN_PULL_DOWN)
				{
					ASSIGN_BIT(DIO_ODR_C,Local_u8PinNum,DIO_PIN_LOW);
				}
				else if (Copy_u8PinMode == PRIVATE_IN_PULL_UP)
				{
					ASSIGN_BIT(DIO_ODR_C,Local_u8PinNum,DIO_PIN_HIGH);
				}
				Local_EnuError = OK;
				break;
			default: Local_EnuError = OUTOFRANGE; break;
			}
		}
		else
		{
			Local_EnuError = OUTOFRANGE;
		}
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}


	return Local_EnuError;
}
