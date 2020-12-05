/*
 * LPTMR.c
 *
 *  Created on: Oct 6, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */

#include "LPTMR.h"

void LPTMR_initPeripheral(void){
	SIM_SCGC5 |= SIM_SCGC5_LPTMR_MASK;
	LPTMR0_CSR = 0x00;
	LPTMR0_PSR = LPTMR_PSR_PCS(1) | LPTMR_PSR_PBYP_MASK;
}

void LPTMR_setTimeCount(unsigned int COMPARE){
	LPTMR0_CMR = COMPARE;
	LPTMR0_CSR |= LPTMR_CSR_TEN_MASK;
	while((LPTMR0_CSR & LPTMR_CSR_TCF_MASK) == 0x00);
	LPTMR0_CSR &= ~LPTMR_CSR_TEN_MASK;
}
