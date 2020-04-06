/*
 * RCC_private.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef RCC_PRIVATE_H_			/*HEADER GUARD*/
#define RCC_PRIVATE_H_			/*HEADER GUARD*/


#define PRIVATE_ENABLE 						1 	/*enable*/
#define PRIVATE_DISABLE 					0 	/*Disable*/

/*	Microcontroller clock output	*/
#define PRIVATE_MCO_SYSTEM_CLOCK			0	/*SYSTEM CLOCK AS A SOURCE FOR MCO*/
#define PRIVATE_MCO_HSI						1	/*HSI AS A SOURCE FOR MCO*/
#define PRIVATE_MCO_HSE						2	/*HSE AS A SOURCE FOR MCO*/
#define PRIVATE_MCO_PLL						3	/*PLL AS A SOURCE FOR MCO*/
#define	PRIVATE_MCO_NOT_USED				4	/*NOT USED MCO*/


#define PRIVATE_PLL_MUL_2					0	/*PLL multiplication factor 2*/
#define PRIVATE_PLL_MUL_3					1	/*PLL multiplication factor 3*/
#define PRIVATE_PLL_MUL_4					2	/*PLL multiplication factor 4*/
#define PRIVATE_PLL_MUL_5					3	/*PLL multiplication factor 5*/
#define PRIVATE_PLL_MUL_6					4	/*PLL multiplication factor 6*/
#define PRIVATE_PLL_MUL_7					5	/*PLL multiplication factor 7*/
#define PRIVATE_PLL_MUL_8					6	/*PLL multiplication factor 8*/
#define PRIVATE_PLL_MUL_9					7	/*PLL multiplication factor 9*/
#define PRIVATE_PLL_MUL_10					8	/*PLL multiplication factor 10*/
#define PRIVATE_PLL_MUL_11					9	/*PLL multiplication factor 11*/
#define PRIVATE_PLL_MUL_12					10	/*PLL multiplication factor 12*/
#define PRIVATE_PLL_MUL_13					11	/*PLL multiplication factor 13*/
#define PRIVATE_PLL_MUL_14					12	/*PLL multiplication factor 14*/
#define PRIVATE_PLL_MUL_15					13	/*PLL multiplication factor 15*/
#define PRIVATE_PLL_MUL_16					14	/*PLL multiplication factor 16*/
#define PRIVATE_PLL_MUL_NOT_USED			15	/*PLL multiplication factor NOT USED*/


#define PRIVATE_PLL_XTPRE_HSE				0	/*HSE clock not divided source of PLL*/
#define PRIVATE_PLL_XTPRE_HSE_DIV_2			1	/*HSE clock divided by 2 source of PLL*/
#define PRIVATE_PLL_XTPRE_NOT_USED			2	/*HSE clock divider not used*/

#define PRIVATE_PLL_SRC_HSI						0	/*SOURCE OF PLL IS HSI*/
#define PRIVATE_PLL_SRC_HSE						1	/*SOURCE OF PLL IS HSE*/
#define PRIVATE_PLL_SRC_NOTUSED					2	/*SOURCE OF PLL IS NOT USED*/


#define PRIVATE_SW_HSI						0	/*System clock switch is HSI*/
#define PRIVATE_SW_HSE						1	/*System clock switch is HSE*/
#define PRIVATE_SW_PLL						2	/*System clock switch is PLL*/


#endif
/*RCC_PRIVATE_H_*/
