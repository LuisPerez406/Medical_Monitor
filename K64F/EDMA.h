/*
 * EDMA.h
 *
 *  Created on: Oct 12, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: enhanced Direct Memory Access (eDMA)
 *     				Channel Configuration
 */

#ifndef EDMA_H_
#define EDMA_H_

	#include "derivative.h"
	#include "RTC.h"

	void DMA_InitPeripheral(void);
	void DMA_SetChannel0(void);
	void DMA_SetChannel4(void);
	
	extern RTCalendar_t time;

#endif
