/*
 * PIT.h
 *
 *  Created on: Oct 6, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: Periodic Interrupt Timer (PIT)
 */

#ifndef PIT_H_
#define PIT_H_

	#include "derivative.h"
	#include "NVIC.h"

	void PIT_InitPeripheral(void);
	void PITx_InitChannel(unsigned char x, unsigned char CHN, unsigned char TIE, unsigned long int TSV);
	void PITx_DisableChannel(unsigned char x);
	void PIT0_IRQHandler(void);

#endif
