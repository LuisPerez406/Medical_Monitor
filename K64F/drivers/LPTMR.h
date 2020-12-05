/*
 * LPTMR.h
 *
 *  Created on: Oct 6, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: Low Power Timer (LPTMR)
 *     				Time Configuration
 */

#ifndef LPTMR_H_
#define LPTMR_H_

	#include "derivative.h"

	void LPTMR_initPeripheral(void);
	void LPTMR_setTimeCount(unsigned int COMPARE);

#endif
