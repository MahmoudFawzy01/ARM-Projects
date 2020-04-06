/*
 * RCC_program.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Mahmoud Fawzy
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_registers.h"


void RCC_voidProcessorClockInit(void)
{

	/*
	 * Enable or disable the PLL
	 *
	 * Description : used to reach the max speed of the processor.
	 *
	 * Options :
	 * PRIVATE_DISABLE
	 * PRIVATE_ENABLE
	 * */
#if PLL_ON_OFF 					== PRIVATE_ENABLE					/*enable  PLL*/
	SET_BIT(RCC_CR,RCC_CR_PLLON);
#elif PLL_ON_OFF				== PRIVATE_DISABLE					/*disable PLL*/

	CLR_BIT(RCC_CR,RCC_CR_PLLON);
#endif


	/*
	 * enable or disable Clock security system bit
	 *
	 * Description :
	 * if this bit is enabled the and if the system clock configured as HSE.
	 * in case HSE is not stable or any failure happened the system clock will use HSI
	 * as a default system clock.
	 *
	 * Options :
	 * PRIVATE_DISABLE
	 * PRIVATE_ENABLE
	 * */
#if CSS_ON_OFF					== PRIVATE_ENABLE					/*enable CSS*/
	SET_BIT(RCC_CR,RCC_CR_CSSON);
#elif CSS_ON_OFF 				== PRIVATE_DISABLE					/*disable CSS*/
	CLR_BIT(RCC_CR,RCC_CR_CSSON);
#endif


	/*
	 * enable or disable HSE bypass
	 *
	 * Description :
	 * Used in case the HSE will be an electrical RC clock source.
	 * Supports freq 3~25 MHz
	 *
	 * Options :
	 * PRIVATE_DISABLE
	 * PRIVATE_ENABLE
	 * */
#if HSE_BYP_ON_OFF 				== PRIVATE_ENABLE					/*enable HSE BY PASS*/
	SET_BIT(RCC_CR,RCC_CR_HSEBYP);
#elif HSE_BYP_ON_OFF 			== PRIVATE_DISABLE					/*disable HSE BY PASS*/
	CLR_BIT(RCC_CR,RCC_CR_HSEBYP);
#endif



	/*
	 * enable or disable HSE SOURCE
	 *
	 * Description :
	 * Used to enable the high speed freq of the MC.
	 * Depends on the clock src freq if it's mechanical (Crystal/ceramic resonators) [up to 16 MHz]
	 * or RC circuit [up to 25 MHz].
	 *
	 * Options :
	 * PRIVATE_DISABLE
	 * PRIVATE_ENABLE
	 * */
#if HSE_ON_OFF 					== PRIVATE_ENABLE					/*enable HSE SOURCE*/
	SET_BIT(RCC_CR,RCC_CR_HSEON);
#elif HSE_ON_OFF 				== PRIVATE_DISABLE					/*disable HSE SOURCE*/
	CLR_BIT(RCC_CR,RCC_CR_HSEON);
#endif


	/*
	 * enable or disable HSI SOURCE
	 *
	 * Description :
	 * Used to enable the internal high speed freq of the MC using RC clock src system up to 8 MHz.
	 *
	 * Options :
	 * PRIVATE_DISABLE
	 * PRIVATE_ENABLE
	 * */
#if HSI_ON_OFF 					== PRIVATE_ENABLE					/*enable HSI SOURCE*/
	SET_BIT(RCC_CR,RCC_CR_HSION);
#elif HSI_ON_OFF 				== PRIVATE_DISABLE					/*disable HSI SOURCE*/
//	CLR_BIT(RCC_CR,RCC_CR_HSION);
#endif


	/*
	 * DISABLE OR SELECT ONE SOURCE HSE , HSI , PLL, SYSTEM CLOCK
	 *
	 * Description :
	 * used to extern a clock source on the MCO pin. this pin used to drive another MC on cascade systems.
	 * this clock could be one of those options.
	 *
	 * Options :
	 * PRIVATE_MCO_NOT_USED
	 * PRIVATE_MCO_PLL
	 * PRIVATE_MCO_HSE
	 * PRIVATE_MCO_HSI
	 * PRIVATE_MCO_SYSTEM_CLOCK
	 * */
#if MCO_SOURCE					==	PRIVATE_MCO_NOT_USED				/*NOT USED*/
	/*NOTHING*/
#elif MCO_SOURCE				==	PRIVATE_MCO_HSE						/*DISABLE OR SELECT ONE SOURCE HSE*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_3);
#elif MCO_SOURCE				==	PRIVATE_MCO_HSI						/*DISABLE OR SELECT ONE SOURCE HSI*/
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_3);
#elif MCO_SOURCE				==	PRIVATE_MCO_PLL						/*DISABLE OR SELECT ONE SOURCE PLL*/
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_3);
#elif MCO_SOURCE				==	PRIVATE_MCO_SYSTEM_CLOCK			/*DISABLE OR SELECT ONE SOURCE SYSTEM CLOCK*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_MCO_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_MCO_3);
#endif


	/*
	 * SELECT THE VALUE OF MULTIPLIER OF PLL
	 *
	 * Description :
	 * If the PLL is enabled you can use this option to select the desired extreme speed of the MC
	 * by multiply the freq at mult circuit.
	 *
	 * Note: please make sure that the result freq won't exceed 72 MHz
	 *
	 * Options :
	 * PRIVATE_PLL_MUL_NOT_USED
	 * PRIVATE_PLL_MUL_2
	 * PRIVATE_PLL_MUL_3
	 * PRIVATE_PLL_MUL_4
	 * PRIVATE_PLL_MUL_5
	 * PRIVATE_PLL_MUL_6
	 * PRIVATE_PLL_MUL_7
	 * PRIVATE_PLL_MUL_8
	 * PRIVATE_PLL_MUL_9
	 * PRIVATE_PLL_MUL_10
	 * PRIVATE_PLL_MUL_11
	 * PRIVATE_PLL_MUL_12
	 * PRIVATE_PLL_MUL_13
	 * PRIVATE_PLL_MUL_14
	 * PRIVATE_PLL_MUL_15
	 * PRIVATE_PLL_MUL_16
	 * */
#if PLL_MUL						==	PRIVATE_PLL_MUL_NOT_USED		/*not used*/
	/*NOTHING*/
#elif PLL_MUL					==	PRIVATE_PLL_MUL_2				/*SELECT THE VALUE OF MULTIPLIER OF PLL 2*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_3				/*SELECT THE VALUE OF MULTIPLIER OF PLL 3*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_4				/*SELECT THE VALUE OF MULTIPLIER OF PLL 4*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_5				/*SELECT THE VALUE OF MULTIPLIER OF PLL 5*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_6				/*SELECT THE VALUE OF MULTIPLIER OF PLL 6*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_7				/*SELECT THE VALUE OF MULTIPLIER OF PLL 7*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_8				/*SELECT THE VALUE OF MULTIPLIER OF PLL 8*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_9				/*SELECT THE VALUE OF MULTIPLIER OF PLL 9*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_10				/*SELECT THE VALUE OF MULTIPLIER OF PLL 10*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_11				/*SELECT THE VALUE OF MULTIPLIER OF PLL 11*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_12				/*SELECT THE VALUE OF MULTIPLIER OF PLL 12*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_13				/*SELECT THE VALUE OF MULTIPLIER OF PLL 13*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_14				/*SELECT THE VALUE OF MULTIPLIER OF PLL 14*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_15				/*SELECT THE VALUE OF MULTIPLIER OF PLL 15*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#elif PLL_MUL					==	PRIVATE_PLL_MUL_16				/*SELECT THE VALUE OF MULTIPLIER OF PLL 16*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
#endif


	/*
	 * select HSE DIVIDED BY 2 OR NOT
	 *
	 * Description :
	 * Used to div the input freq to PLL before the multiplication process.
	 * This option can be used only when PLL is enabled.
	 *
	 * Options :
	 * PRIVATE_PLL_XTPRE_HSE
	 * PRIVATE_PLL_XTPRE_HSE_DIV_2
	 * PRIVATE_PLL_XTPRE_NOT_USED
	 * */
#if PLL_XTPRE					==	PRIVATE_PLL_XTPRE_NOT_USED		/*not used*/
#elif PLL_XTPRE					==	PRIVATE_PLL_XTPRE_HSE			/*select HSE not DIVIDED*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PXTPRE);
#elif PLL_XTPRE					==	PRIVATE_PLL_XTPRE_HSE_DIV_2			/*select HSE divided by 2*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PXTPRE);
#endif


	/*
	 * SELECT SOURCE:
	 *
	 * HSI oscillator clock / 2 selected as PLL input clock
	 * Clock from PREDIV1 selected as PLL input clock ( the HSE source after div or not)
	 *
	 * Description :
	 * Select PLL clock source. This option can be used only when PLL is enabled.
	 *
	 * Options :
	 * PRIVATE_PLL_SRC_HSI
	 * PRIVATE_PLL_SRC_HSE
	 * PRIVATE_PLL_SRC_NOTUSED
	 * */
#if	PLL_SRC						==	PRIVATE_PLL_SRC_NOTUSED		/*not used*/
#elif	PLL_SRC					==	PRIVATE_PLL_SRC_HSE			/*SELECT SOURCE HSE*/
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
#elif	PLL_SRC					==	PRIVATE_PLL_SRC_HSI			/*HSI/2*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
#endif


	/*
	 * TO SELECT THE SOURCE OF SYSTEM :
	 *
	 * - HSI selected as system clock
	 * - HSE selected as system clock
	 * - PLL selected as system clock
	 *
	 * Options :
	 * PRIVATE_SW_HSI
	 * PRIVATE_SW_HSE
	 * PRIVATE_SW_PLL
	 * */
#if SW_SYSTEM_CLOCK_SWITCH		==	PRIVATE_SW_HSE					/*TO SELECT THE SOURCE OF SYSTEM CLOCK HSE*/
	SET_BIT(RCC_CFGR,RCC_CFGR_SW_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW_1);
#elif SW_SYSTEM_CLOCK_SWITCH	==	PRIVATE_SW_HSI					/*TO SELECT THE SOURCE OF SYSTEM CLOCK HSI*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW_0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW_1);
#elif SW_SYSTEM_CLOCK_SWITCH	==	PRIVATE_SW_PLL					/*TO SELECT THE SOURCE OF SYSTEM CLOCK	PLL*/
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW_0);
	SET_BIT(RCC_CFGR,RCC_CFGR_SW_1);
#endif

}



void RCC_voidEnableClock(u8 copy_u8Bus,u8 copy_u8Peripheral)
{
	switch(copy_u8Bus)
	{
	case 0 :
		SET_BIT(RCC_AHBENR,copy_u8Peripheral);      /*	Enable the peripheral from the AHB bus	*/
		break ;
	case 1 :
		SET_BIT(RCC_APB1ENR,copy_u8Peripheral);     /*	Enable the peripheral from the APB1 bus	*/
		break ;
	case 2 :
		SET_BIT(RCC_APB2ENR,copy_u8Peripheral);     /*	Enable the peripheral from the APB2 bus	*/
		break ;
	default:
		/*nothing*/
		break ;

	}
}


void RCC_voidDisableClock(u8 copy_u8Bus,u8 copy_u8Peripheral)
{
	switch(copy_u8Peripheral)
	{
	case 0 :
		CLR_BIT(RCC_AHBENR,copy_u8Peripheral); 	/*	Disable the peripheral from the AHB bus 	*/
		break ;
	case 1 :
		CLR_BIT(RCC_APB1ENR,copy_u8Peripheral);	/*	Disable the peripheral from the APB1 bus	*/
		break ;
	case 2 :
		CLR_BIT(RCC_APB2ENR,copy_u8Peripheral);	/*	Disable the peripheral from the APB2 bus	*/
		break ;
	default:
		/*nothing*/
		break ;
	}
}
