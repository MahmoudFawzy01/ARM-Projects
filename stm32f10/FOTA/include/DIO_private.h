/*
 * DIO_private.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


// to concatinate the port value and replace each pin to the value configured with.
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)	CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)	0x##b7##b6##b5##b4##b3##b2##b1##b0



#define     PRIVATE_IN_ANALOG			0
#define     PRIVATE_IN_FLOATING			4
#define     PRIVATE_IN_PULL_DOWN		8
#define     PRIVATE_IN_PULL_UP			12

#define     PRIVATE_OUT_10M_PP			1
#define     PRIVATE_OUT_10M_OD			5
#define     PRIVATE_OUT_10M_AFPP		9
#define     PRIVATE_OUT_10M_AFOD		13

#define     PRIVATE_OUT_2M_PP			2
#define     PRIVATE_OUT_2M_OD			6
#define 	PRIVATE_OUT_2M_AFPP			10
#define     PRIVATE_OUT_2M_AFOD			14

#define     PRIVATE_OUT_50M_PP			3
#define     PRIVATE_OUT_50M_OD			7
#define     PRIVATE_OUT_50M_AFPP		11
#define     PRIVATE_OUT_50M_AFOD		15



#define PRIVATE_PIN0 	0
#define PRIVATE_PIN1 	1
#define PRIVATE_PIN2 	2
#define PRIVATE_PIN3 	3
#define PRIVATE_PIN4 	4
#define PRIVATE_PIN5 	5
#define PRIVATE_PIN6 	6
#define PRIVATE_PIN7 	7
#define PRIVATE_PIN8 	8
#define PRIVATE_PIN9 	9
#define PRIVATE_PIN10	10
#define PRIVATE_PIN11	11
#define PRIVATE_PIN12	12
#define PRIVATE_PIN13	13
#define PRIVATE_PIN14	14
#define PRIVATE_PIN15	15
#define PRIVATE_PIN16	16
#define PRIVATE_PIN17	17
#define PRIVATE_PIN18	18
#define PRIVATE_PIN19	19
#define PRIVATE_PIN20	20
#define PRIVATE_PIN21	21
#define PRIVATE_PIN22	22
#define PRIVATE_PIN23	23
#define PRIVATE_PIN24	24
#define PRIVATE_PIN25	25
#define PRIVATE_PIN26	26
#define PRIVATE_PIN27	27
#define PRIVATE_PIN28	28
#define PRIVATE_PIN29	29
#define PRIVATE_PIN30	30
#define PRIVATE_PIN31	31
#define PRIVATE_PIN32	45
#define PRIVATE_PIN33	46
#define PRIVATE_PIN34	47

#endif /* DIO_PRIVATE_H_ */
