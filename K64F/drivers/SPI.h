/*
 * SPI.h
 *
 *  Created on: Oct 16, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: Serial Peripheral Interface (SPI)
 *     				Serial Protocol configuration
 */

#ifndef SPI_H_
#define SPI_H_

	#include "derivative.h"

	void SPI0_initPeripheral(void);
	void SPI0_setMaster(void);
	void SPI0_send8Bits(unsigned char CS, signed long int numTransfers, unsigned char *ptr);

#endif
