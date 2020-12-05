*
 * SPI.c
 *
 *  Created on: Oct 16, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */

#include "SPI.h"

void SPI0_initPeripheral(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK;
	SIM_SCGC6 |= SIM_SCGC6_SPI0_MASK;
	PORTD_PCR0 = PORT_PCR_MUX(2);			//SPI0_PCS0
	PORTD_PCR1 = PORT_PCR_MUX(2);			//SPI0_SCK
	PORTD_PCR2 = PORT_PCR_MUX(2);			//SPI0_SOUT
	PORTD_PCR3 = PORT_PCR_MUX(2);			//SPI0_SIN
}

void SPI0_setMaster(void){
	SPI0_MCR |= SPI_MCR_MSTR_MASK | SPI_MCR_PCSIS_MASK | SPI_MCR_DIS_TXF_MASK | SPI_MCR_DIS_RXF_MASK;
	SPI0_CTAR0 = SPI_CTAR_DBR_MASK | SPI_CTAR_FMSZ(7) | SPI_CTAR_CPHA_MASK | SPI_CTAR_CPOL_MASK;
	SPI0_MCR &= (~SPI_MCR_HALT_MASK & ~SPI_MCR_MDIS_MASK); 
}

void SPI0_send8Bits(unsigned char CS, signed long int numTransfers, unsigned char *ptr){
	SPI0_MCR |= SPI_MCR_HALT_MASK | SPI_MCR_CLR_TXF_MASK;
	SPI0_MCR &= ~SPI_MCR_HALT_MASK;
	while(numTransfers >= 0){
		if(numTransfers != 0)
			SPI0_PUSHR = SPI_PUSHR_CONT_MASK | SPI_PUSHR_CTAS(0) | SPI_PUSHR_PCS(CS) | (*(unsigned char*)ptr);
		else
			SPI0_PUSHR = SPI_PUSHR_EOQ_MASK | SPI_PUSHR_CTAS(0) | SPI_PUSHR_PCS(CS) | (*(unsigned char*)ptr);
		while((SPI0_SR & SPI_SR_TCF_MASK) == 0);
		SPI0_SR |= SPI_SR_TCF_MASK;
		ptr = (unsigned char*)ptr + 1;
		numTransfers--;
	}
	SPI0_SR |= SPI_SR_TFFF_MASK;
}
