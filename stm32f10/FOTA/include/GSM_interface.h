/*
 * GSM_interface.h
 *
 *  Created on: Mar 9, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef GSM_INTERFACE_H_
#define GSM_INTERFACE_H_

#define RECEIVE_APP_VER			1
#define RECEIVE_NEXT_LINE		2
#define RESET_SERVER			3


void GSM_init(void);
u8 GSM_u8CheckConnection(void);
u8 GSM_u8RunFullFunc(void);
u8 GSM_u8AddInternetServiceProvider(void);
u8 GSM_u8OpenData(u8 * Copy_Au8IP);
void GSM_RESET(void);
u8 GSM_voidConnectToInternet(void);
u8 GSM_voidConnectToServer(void);
void GSM_voidReceiveLineFromServer(u8 * ReceivedStr, u8 Copy_u8DataType);

#endif /* GSM_INTERFACE_H_ */
