/*
 * PIT.c
 *
 *  Created on: Oct 6, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */

#include "PIT.h"

void PIT_InitPeripheral(void){
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT_MCR = (~PIT_MCR_MDIS_MASK | PIT_MCR_FRZ_MASK);
}

void PITx_InitChannel(unsigned char x, unsigned char CHN, unsigned char TIE, unsigned long int TSV){
	PIT_BASE_PTR->CHANNEL[x].LDVAL = TSV;
	PIT_BASE_PTR->CHANNEL[x].TFLG = PIT_TFLG_TIF_MASK;
	if(TIE == 1){
		PIT_BASE_PTR->CHANNEL[x].TCTRL |= PIT_TCTRL_TIE_MASK;
		NVIC_EnableIRQ(INT_PIT0+x-16, 0x02);
	}
	PIT_BASE_PTR->CHANNEL[x].TCTRL |= PIT_TCTRL_TEN_MASK | (PIT_TCTRL_CHN_MASK & CHN);
}

void PITx_DisableChannel(unsigned char x){
	PIT_BASE_PTR->CHANNEL[x].TCTRL = ~PIT_TCTRL_TEN_MASK;
}

void PIT0_IRQHandler(void){
 	PIT_TFLG0 = PIT_TFLG_TIF_MASK;
}
