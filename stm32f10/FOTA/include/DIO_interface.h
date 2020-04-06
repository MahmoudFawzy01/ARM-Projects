/*
 * DIO_interface.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define DIO_PIN_0 	0        //PRIVATE_PIN0
#define DIO_PIN_1 	1        //PRIVATE_PIN1
#define DIO_PIN_2 	2        //PRIVATE_PIN2
#define DIO_PIN_3 	3        //PRIVATE_PIN3
#define DIO_PIN_4 	4        //PRIVATE_PIN4
#define DIO_PIN_5 	5        //PRIVATE_PIN5
#define DIO_PIN_6 	6        //PRIVATE_PIN6
#define DIO_PIN_7 	7        //PRIVATE_PIN7
#define DIO_PIN_8 	8        //PRIVATE_PIN8
#define DIO_PIN_9 	9        //PRIVATE_PIN9
#define DIO_PIN_10	10       //PRIVATE_PIN10
#define DIO_PIN_11	11       //PRIVATE_PIN11
#define DIO_PIN_12	12       //PRIVATE_PIN12
#define DIO_PIN_13	13       //PRIVATE_PIN13
#define DIO_PIN_14	14       //PRIVATE_PIN14
#define DIO_PIN_15	15       //PRIVATE_PIN15
#define DIO_PIN_16	16       //PRIVATE_PIN16
#define DIO_PIN_17	17       //PRIVATE_PIN17
#define DIO_PIN_18	18       //PRIVATE_PIN18
#define DIO_PIN_19	19       //PRIVATE_PIN19
#define DIO_PIN_20	20       //PRIVATE_PIN20
#define DIO_PIN_21	21       //PRIVATE_PIN21
#define DIO_PIN_22	22       //PRIVATE_PIN22
#define DIO_PIN_23	23       //PRIVATE_PIN23
#define DIO_PIN_24	24       //PRIVATE_PIN24
#define DIO_PIN_25	25       //PRIVATE_PIN25
#define DIO_PIN_26	26       //PRIVATE_PIN26
#define DIO_PIN_27	27       //PRIVATE_PIN27
#define DIO_PIN_28	28       //PRIVATE_PIN28
#define DIO_PIN_29	29       //PRIVATE_PIN29
#define DIO_PIN_30	30       //PRIVATE_PIN30
#define DIO_PIN_31	31       //PRIVATE_PIN31
#define DIO_PIN_32	45       //PRIVATE_PIN32
#define DIO_PIN_33	46       //PRIVATE_PIN33
#define DIO_PIN_34	47       //PRIVATE_PIN34


#define     DIO_IN_ANALOG			0       //PRIVATE_IN_ANALOG
#define     DIO_IN_FLOATING			4       //PRIVATE_IN_FLOATING
#define     DIO_IN_PULL_DOWN		8       //PRIVATE_IN_PULL_DOWN
#define     DIO_IN_PULL_UP			12      //PRIVATE_IN_PULL_UP
                                            //
#define     DIO_OUT_10M_PP			1       //PRIVATE_OUT_10M_PP
#define     DIO_OUT_10M_OD			5       //PRIVATE_OUT_10M_OD
#define     DIO_OUT_10M_AFPP		9       //PRIVATE_OUT_10M_AFPP
#define     DIO_OUT_10M_AFOD		13      //PRIVATE_OUT_10M_AFOD
                                            //
#define     DIO_OUT_2M_PP			2       //PRIVATE_OUT_2M_PP
#define     DIO_OUT_2M_OD			6       //PRIVATE_OUT_2M_OD
#define 	DIO_OUT_2M_AFPP			10      //PRIVATE_OUT_2M_AFPP
#define     DIO_OUT_2M_AFOD			14      //PRIVATE_OUT_2M_AFOD
                                            //
#define     DIO_OUT_50M_PP			3       //PRIVATE_OUT_50M_PP
#define     DIO_OUT_50M_OD			7       //PRIVATE_OUT_50M_OD
#define     DIO_OUT_50M_AFPP		11      //PRIVATE_OUT_50M_AFPP
#define     DIO_OUT_50M_AFOD		15      //PRIVATE_OUT_50M_AFOD

#define DIO_PIN_LOW		0
#define DIO_PIN_HIGH	1
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/*
 * Description : Set all pins direction.
 * Inputs  :
 * Outputs :
 * */
void DIO_voidInit(void);

/*
 * Description : Set the desired pin value.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~34)]   -  [Copy_u8PinValue -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PinValue);

/*
* Description : Get the desired pin value.
* Inputs  :[Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)] - [* Copy_u8Value used to receive the pin value 0/1]
* Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
* */
ErrorStatus DIO_EnuGetPinValue(u8 Copy_u8PinNumber ,u8 * Copy_Pu8PinValue);

/*
 * Description : Set the desired pin mode.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~34)]   -  [Copy_u8PinMode -> pin mode is between [DIO_IN_ANALOG~PRIVATE_OUT_50M_AFOD]
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinMode(u8 Copy_u8PinNumber,u8 Copy_u8PinMode);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif /* DIO_INTERFACE_H_ */
