/*
 * UART.h
 *
 *  Created on: Nov 24, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: Universal Asynchronous Receiver Transmitter (UART) 
 *     				Serial Protocol configuration
 */

#ifndef UART_H_
#define UART_H_

	#include "derivative.h"

	void UART3_initPeripheral();
	void UART3_receivePacket(unsigned char *ptr, unsigned char endCommand);
	void UART3_transmitData(unsigned char data);
	void UART3_transmitPacket(unsigned char *ptr);

#endif
