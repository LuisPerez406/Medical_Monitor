/*
 * NVIC.h
 *
 *  Created on: Oct 6, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: Nested Vectored Interrupt Controller (NVIC)
 *     				Interrupt and Priority Settings
 */

#ifndef NVIC_H_
#define NVIC_H_

	#include "derivative.h"

	void NVIC_DisableIRQ(unsigned char IRQ);
	void NVIC_EnableIRQ(unsigned char IRQ, unsigned char PRIO);
	void NVIC_SetPriority(unsigned char IRQ, unsigned char PRIO);

#endif
