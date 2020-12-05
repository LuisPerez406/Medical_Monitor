/*
 * UART.c
 *
 *  Created on: Nov 24, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */

#include "UART.h"

void UART3_initPeripheral(){
	SIM_SCGC4 |= SIM_SCGC4_UART3_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC_PCR16 = PORT_PCR_MUX(3);				//UART3_RX
	PORTC_PCR17 = PORT_PCR_MUX(3);				//UART3_TX
	UART3_BDH = 0x00;
	UART3_BDL = 130;
	UART3_C1 = 0x00;
	UART3_C2 = 0x2C;
	UART3_C3 = 0x00;
}

void UART3_receivePacket(unsigned char *ptr, unsigned char endCommand){
	unsigned char RXD = 0x00;
	
	while(1){
		while((UART3_S1 & UART_S1_RDRF_MASK) == 0x00);
		(void)UART3_S1;
		RXD = UART3_D;
		if(RXD == endCommand)
			break;
		*ptr = RXD;
		ptr++;
	}
}

void UART3_transmitData(unsigned char data){
	UART3_C2 |= UART_C2_TE_MASK;
	(void)UART3_S1;
	UART3_D = data;
	while((UART3_S1 & UART_S1_TC_MASK) == 0);
	UART3_C2 &= ~UART_C2_TE_MASK;
}

void UART3_transmitPacket(unsigned char *ptr){
	while(*ptr){
		UART3_C2 |= UART_C2_TE_MASK;
		(void)UART3_S1;
		UART3_D = *ptr;
		while((UART3_S1 & UART_S1_TC_MASK) == 0);
		UART3_C2 &= ~UART_C2_TE_MASK;
		ptr++;
	}
}
