/*
 * ADC.h
 *
 *  Created on: Oct 8, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: Analog-to-Digital Converter (ADC)
 *     				Calibration, Interrupt Service Routine(ISR) and Peripheral Configuration
 */

#ifndef ADC_H_
#define ADC_H_

	#include "derivative.h"
	#include "NVIC.h"
	
	unsigned char ADC0_Calibration(void);
	void ADC0_InitPeripheral(void);
	void ADC0_IRQHandler(void);

#endif
