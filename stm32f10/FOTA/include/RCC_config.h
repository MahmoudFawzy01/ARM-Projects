/*
 * RCC_config.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef RCC_CONFIG_H_			/*HEADER GUARD*/
#define RCC_CONFIG_H_			/*HEADER GUARD*/

/*
 * Enable or disable the PLL
 *
 * Description : used to reach the max speed of the processor.
 *
 * Options :
 * PRIVATE_DISABLE
 * PRIVATE_ENABLE
 * */
#define PLL_ON_OFF					PRIVATE_DISABLE

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
#define CSS_ON_OFF					PRIVATE_DISABLE

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
#define HSE_BYP_ON_OFF				PRIVATE_DISABLE

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
#define HSE_ON_OFF					PRIVATE_ENABLE

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
#define HSI_ON_OFF					PRIVATE_DISABLE

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
#define MCO_SOURCE					PRIVATE_MCO_NOT_USED

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
#define PLL_MUL						PRIVATE_PLL_MUL_NOT_USED

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
#define PLL_XTPRE					PRIVATE_PLL_XTPRE_NOT_USED

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
#define	PLL_SRC						PRIVATE_PLL_SRC_NOTUSED

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
#define SW_SYSTEM_CLOCK_SWITCH		PRIVATE_SW_HSE

#endif								/*HEADER GUARD*/
