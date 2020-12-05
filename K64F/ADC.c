/*
 * ADC.c
 *
 *  Created on: Oct 8, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */

#include "ADC.h"

unsigned char ADC0_Calibration(void){
	unsigned short int calResult = 0x0000;
	
	ADC0_CFG1 |= ADC_CFG1_ADIV(2);
	ADC0_SC3 |= ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(3);
	ADC0_SC3 |= ADC_SC3_CAL_MASK;
	while((ADC0_SC1A & ADC_SC1_COCO_MASK) == 0);
	if((ADC0_SC3 & ADC_SC3_CALF_MASK) == ADC_SC3_CALF_MASK){
		return 0;																			//FAILED PROCESS
	}
	calResult += ADC0_CLPS + ADC0_CLP4 + ADC0_CLP3 + ADC0_CLP2 + ADC0_CLP1 + ADC0_CLP0;
	calResult /= 2;
	calResult |= 0x8000;
	ADC0_PG = calResult;
	calResult = 0x0000;
	calResult += ADC0_CLMS + ADC0_CLM4 + ADC0_CLM3 + ADC0_CLM2 + ADC0_CLM1 + ADC0_CLM0;
	calResult /= 2;
	calResult |= 0x8000;
	ADC0_MG = calResult;
	(void)ADC0_RA;
	return 1;																				//SUCCESFUL PROCESS
}

void ADC0_InitPeripheral(void){
	unsigned char FLG = 0;
	
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM_SOPT7 |= SIM_SOPT7_ADC0ALTTRGEN_MASK | SIM_SOPT7_ADC0TRGSEL(4);
	FLG = ADC0_Calibration();
	ADC0_CFG1 = ADC_CFG1_MODE(3);
	ADC0_SC2 |= ADC_SC2_ADTRG_MASK;  //| ADC_SC2_DMAEN_MASK
	//ADC0_SC1A |= ADC_SC1_AIEN_MASK;
	//NVIC_EnableIRQ(INT_ADC0-16, 0x20);
	ADC0_SC1A = ADC_SC1_ADCH(12);                     										//PTB2 => ADC0_SE12 CHANNEL
}
 
void ADC0_IRQHandler(void){
	(void)ADC0_RA;
}
