/*
 * DIO_register.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
///////////////////////////////////////////////////////////////////////////////////////
#define DIO_CRL_A	 	*((volatile u32*) 	0x40010800)

#define DIO_CRL_A_CNF7_1				31
#define DIO_CRL_A_CNF7_0				30
#define DIO_CRL_A_MODE7_1				29
#define DIO_CRL_A_MODE7_0				28

#define DIO_CRL_A_CNF6_1 				27
#define DIO_CRL_A_CNF6_0 				26
#define DIO_CRL_A_MODE6_1				25
#define DIO_CRL_A_MODE6_0				24

#define DIO_CRL_A_CNF5_1 				23
#define DIO_CRL_A_CNF5_0 				22
#define DIO_CRL_A_MODE5_1				21
#define DIO_CRL_A_MODE5_0				20

#define DIO_CRL_A_CNF4_1 				19
#define DIO_CRL_A_CNF4_0 				18
#define DIO_CRL_A_MODE4_1				17
#define DIO_CRL_A_MODE4_0				16

#define DIO_CRL_A_CNF3_1 				15
#define DIO_CRL_A_CNF3_0 				14
#define DIO_CRL_A_MODE3_1				13
#define DIO_CRL_A_MODE3_0				12

#define DIO_CRL_A_CNF2_1 				11
#define DIO_CRL_A_CNF2_0 				10
#define DIO_CRL_A_MODE2_1				9
#define DIO_CRL_A_MODE2_0				8

#define DIO_CRL_A_CNF1_1 				7
#define DIO_CRL_A_CNF1_0 				6
#define DIO_CRL_A_MODE1_1				5
#define DIO_CRL_A_MODE1_0				4

#define DIO_CRL_A_CNF0_1 				3
#define DIO_CRL_A_CNF0_0 				2
#define DIO_CRL_A_MODE0_1				1
#define DIO_CRL_A_MODE0_0				0


///////////////////////////////////////////////////////////////////////////////////////
#define DIO_CRH_A 		*((volatile u32*) 	0x40010804)

#define DIO_CRH_A_CNF15_1				31
#define DIO_CRH_A_CNF15_0   			30
#define DIO_CRH_A_MODE15_1  			29
#define DIO_CRH_A_MODE15_0  			28

#define DIO_CRH_A_CNF14_1   			27
#define DIO_CRH_A_CNF14_0   			26
#define DIO_CRH_A_MODE14_1  			25
#define DIO_CRH_A_MODE14_0  			24

#define DIO_CRH_A_CNF13_1   			23
#define DIO_CRH_A_CNF13_0   			22
#define DIO_CRH_A_MODE13_1  			21
#define DIO_CRH_A_MODE13_0  			20

#define DIO_CRH_A_CNF12_1   			19
#define DIO_CRH_A_CNF12_0   			18
#define DIO_CRH_A_MODE12_1  			17
#define DIO_CRH_A_MODE12_0  			16

#define DIO_CRH_A_CNF11_1   			15
#define DIO_CRH_A_CNF11_0   			14
#define DIO_CRH_A_MODE11_1  			13
#define DIO_CRH_A_MODE11_0  			12

#define DIO_CRH_A_CNF10_1   			11
#define DIO_CRH_A_CNF10_0   			10
#define DIO_CRH_A_MODE10_1  			9
#define DIO_CRH_A_MODE10_0  			8

#define DIO_CRH_A_CNF9_1    			7
#define DIO_CRH_A_CNF9_0    			6
#define DIO_CRH_A_MODE9_1   			5
#define DIO_CRH_A_MODE9_0   			4

#define DIO_CRH_A_CNF8_1    			3
#define DIO_CRH_A_CNF8_0    			2
#define DIO_CRH_A_MODE8_1   			1
#define DIO_CRH_A_MODE8_0   			0
///////////////////////////////////////////////////////////////////////////////////////
#define DIO_IDR_A 		*((volatile u32*) 	0x40010808)
#define DIO_ODR_A 		*((volatile u32*) 	0x4001080C)
#define DIO_BSRR_A		*((volatile u32*)	0x40010810)
#define DIO_BRR_A		*((volatile u32*)	0x40010814)
#define DIO_LCKR_A 		*((volatile u32*) 	0x40010818)
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define DIO_CRL_B	 	*((volatile u32*) 	0x40010C00)

#define DIO_CRL_B_CNF7_1   			31
#define DIO_CRL_B_CNF7_0   			30
#define DIO_CRL_B_MODE7_1  			29
#define DIO_CRL_B_MODE7_0  			28

#define DIO_CRL_B_CNF6_1   			27
#define DIO_CRL_B_CNF6_0   			26
#define DIO_CRL_B_MODE6_1  			25
#define DIO_CRL_B_MODE6_0  			24

#define DIO_CRL_B_CNF5_1   			23
#define DIO_CRL_B_CNF5_0   			22
#define DIO_CRL_B_MODE5_1  			21
#define DIO_CRL_B_MODE5_0  			20

#define DIO_CRL_B_CNF4_1   			19
#define DIO_CRL_B_CNF4_0   			18
#define DIO_CRL_B_MODE4_1  			17
#define DIO_CRL_B_MODE4_0  			16

#define DIO_CRL_B_CNF3_1   			15
#define DIO_CRL_B_CNF3_0   			14
#define DIO_CRL_B_MODE3_1  			13
#define DIO_CRL_B_MODE3_0  			12

#define DIO_CRL_B_CNF2_1   			11
#define DIO_CRL_B_CNF2_0   			10
#define DIO_CRL_B_MODE2_1  			9
#define DIO_CRL_B_MODE2_0  			8

#define DIO_CRL_B_CNF1_1   			7
#define DIO_CRL_B_CNF1_0   			6
#define DIO_CRL_B_MODE1_1  			5
#define DIO_CRL_B_MODE1_0  			4

#define DIO_CRL_B_CNF0_1   			3
#define DIO_CRL_B_CNF0_0   			2
#define DIO_CRL_B_MODE0_1  			1
#define DIO_CRL_B_MODE0_0  			0
///////////////////////////////////////////////////////////////////////////////////////
#define DIO_CRH_B 		*((volatile u32*) 	0x40010C04)

#define DIO_CRH_B_CNF15_1  			31
#define DIO_CRH_B_CNF15_0  			30
#define DIO_CRH_B_MODE15_1 			29
#define DIO_CRH_B_MODE15_0 			28

#define DIO_CRH_B_CNF14_1  			27
#define DIO_CRH_B_CNF14_0  			26
#define DIO_CRH_B_MODE14_1 			25
#define DIO_CRH_B_MODE14_0 			24

#define DIO_CRH_B_CNF13_1  			23
#define DIO_CRH_B_CNF13_0  			22
#define DIO_CRH_B_MODE13_1 			21
#define DIO_CRH_B_MODE13_0 			20

#define DIO_CRH_B_CNF12_1  			19
#define DIO_CRH_B_CNF12_0  			18
#define DIO_CRH_B_MODE12_1 			17
#define DIO_CRH_B_MODE12_0 			16

#define DIO_CRH_B_CNF11_1  			15
#define DIO_CRH_B_CNF11_0  			14
#define DIO_CRH_B_MODE11_1 			13
#define DIO_CRH_B_MODE11_0 			12

#define DIO_CRH_B_CNF10_1  			11
#define DIO_CRH_B_CNF10_0  			10
#define DIO_CRH_B_MODE10_1 			9
#define DIO_CRH_B_MODE10_0 			8

#define DIO_CRH_B_CNF9_1   			7
#define DIO_CRH_B_CNF9_0   			6
#define DIO_CRH_B_MODE9_1  			5
#define DIO_CRH_B_MODE9_0  			4

#define DIO_CRH_B_CNF8_1   			3
#define DIO_CRH_B_CNF8_0   			2
#define DIO_CRH_B_MODE8_1  			1
#define DIO_CRH_B_MODE8_0  			0
///////////////////////////////////////////////////////////////////////////////////////
#define DIO_IDR_B 		*((volatile u32*) 	0x40010C08)
#define DIO_ODR_B 		*((volatile u32*) 	0x40010C0C)
#define DIO_BSRR_B 		*((volatile u32*)	0x40010C10)
#define DIO_BRR_B		*((volatile u32*) 	0x40010C14)
#define DIO_LCKR_B 		*((volatile u32*) 	0x40010C18)
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define DIO_CRL_C 		*((volatile u32*) 	0x40011000)

///////////////////////////////////////////////////////////////////////////////////////
#define DIO_CRH_C 		*((volatile u32*) 	0x40011004)

#define DIO_CRH_C_CNF15_1     			31
#define DIO_CRH_C_CNF15_0     			30
#define DIO_CRH_C_MODE15_1    			29
#define DIO_CRH_C_MODE15_0    			28

#define DIO_CRH_C_CNF14_1     			27
#define DIO_CRH_C_CNF14_0     			26
#define DIO_CRH_C_MODE14_1    			25
#define DIO_CRH_C_MODE14_0    			24

#define DIO_CRH_C_CNF13_1     			23
#define DIO_CRH_C_CNF13_0     			22
#define DIO_CRH_C_MODE13_1    			21
#define DIO_CRH_C_MODE13_0    			20
///////////////////////////////////////////////////////////////////////////////////////
#define DIO_IDR_C 		*((volatile u32*) 	0x40011008)
#define DIO_ODR_C 		*((volatile u32*) 	0x4001100c)
#define DIO_BSRR_C		*((volatile u32*)	0x40011010)
#define DIO_BRR_C		*((volatile u32*) 	0x40011014)
#define DIO_LCKR_C 		*((volatile u32*)	0x40011018)


#endif /* DIO_REGISTER_H_ */
