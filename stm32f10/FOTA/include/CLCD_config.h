/*
 * CLCD_config.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* Data Pins */
#define CLCD_D0_PIN		DIO_PIN_1	// 1
#define CLCD_D1_PIN		DIO_PIN_2	// 2
#define CLCD_D2_PIN		DIO_PIN_3	// 3
#define CLCD_D3_PIN		DIO_PIN_4	// 4
#define CLCD_D4_PIN		DIO_PIN_5	// 5
#define CLCD_D5_PIN		DIO_PIN_6	// 6
#define CLCD_D6_PIN		DIO_PIN_7	// 7
#define CLCD_D7_PIN		DIO_PIN_8	// 8

/* Control pins  */
/*Register status pin
 *
 * this pin used to select that you write data or  cmnd
 * */
#define CLCD_RS_PIN		DIO_PIN_17	// B5

/*RW pin
 *
 * this pin used to select the mode (write or read)
 * */
#define CLCD_RW_PIN		DIO_PIN_26	// B4

/*RE pin
 *
 * this pin used to tell the LCD MC that i finished the data writing and confirm the data to show
 *
 * rh default is low and to confirm we should make it high for 130 ns
 * */
#define CLCD_E_PIN		DIO_PIN_27	// B3





#endif /* CLCD_CONFIG_H_ */
