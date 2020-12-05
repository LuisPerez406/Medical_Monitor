/*
 * NVIC.c
 *
 *  Created on: Oct 6, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */

#include "NVIC.h"

void NVIC_DisableIRQ(unsigned char IRQ){
	unsigned char NIPR_NUM = 0x00, BIT = 0x00;
	
	if(IRQ <= 85){
		NIPR_NUM = (IRQ/32u);
		BIT = (IRQ%32u);
		NVIC_BASE_PTR->ICER[NIPR_NUM] = (1 << BIT);
	}
	else{
		__asm("bkpt");
	}
 }

void NVIC_EnableIRQ(unsigned char IRQ, unsigned char PRIO){
	unsigned char NIPR_NUM = 0x00, BIT = 0x00;
	
	if(IRQ <= 85){
		NIPR_NUM = (IRQ/32u);
		BIT = (IRQ%32u);
		NVIC_BASE_PTR->ICPR[NIPR_NUM] = (1 << BIT);
		NVIC_BASE_PTR->ISER[NIPR_NUM] = (1 << BIT);
		NVIC_BASE_PTR->IP[IRQ] = PRIO;
	}
	else{
		__asm("bkpt");
	}
}

void NVIC_SetPriority(unsigned char IRQ, unsigned char PRIO){
	if(IRQ <= 85){
		NVIC_BASE_PTR->IP[IRQ] = PRIO;
	}
	else{
		__asm("bkpt");
	}
}
