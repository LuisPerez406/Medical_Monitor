/*
 * SSD1351.c
 *
 *  Created on: Nov 16, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */

#include "SSD1351.h"

typedef struct{
	unsigned char x;
	unsigned char y;
}cursor_t;

typedef union{
	unsigned char data_8[32768];
	unsigned short int data_16[16384];
}GDDRAM_t;

cursor_t cursor;
GDDRAM_t GDDRAM;

void OLED_initDevice(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC_PCR0 = PORT_PCR_MUX(1);
	PORTC_PCR2 = PORT_PCR_MUX(1);
	GPIOC_PSOR |= (1 << RESET_PIN);
	GPIOC_PDDR |= (1 << RESET_PIN) | (1 << DC_PIN);

	LPTMR_setTimeCount(500);
	GPIOC_PCOR |= (1 << RESET_PIN);
	LPTMR_setTimeCount(500);
	GPIOC_PSOR |= (1 << RESET_PIN);
	LPTMR_setTimeCount(500);
	
	OLED_writeCommand(0xFD);							//COMMAND LOCK
	OLED_writeData(0x12);
	OLED_writeCommand(0xFD);							//COMMAND LOCK
	OLED_writeData(0xB1);
	OLED_writeCommand(0xAE);							//SET SLEEP MODE ON
	OLED_writeCommand(0xB3);							//SET DISPLAY CLOCK DIVIDE RATIO/OSCILLATOR FREQUENCY
	OLED_writeData(0xF1);
	OLED_writeCommand(0xCA);							//SET MULTIPLEX RATIO
	OLED_writeData(0x7F);
	LPTMR_setTimeCount(600);
	
	OLED_writeCommand(0xA2);							//SET DISPLAY OFFSET
	OLED_writeData(0x00);
	OLED_writeCommand(0xA1);							//SET DISPLAY START LINE
	OLED_writeData(0x00);
	OLED_writeCommand(0xA0);							//SET RE-MAP & COLOR DEPTH
	OLED_writeData(0x24);
	OLED_writeCommand(0xB5);							//SET GPIO
	OLED_writeData(0x00);
	OLED_writeCommand(0xAB);							//FUNCTION SELECTION
	OLED_writeData(0x01);
	OLED_writeCommand(0xB4);							//SET SEGMENT LOW VOLTAGE
	OLED_writeData(0xA0);
	OLED_writeData(0xB5);
	OLED_writeData(0x55);
	OLED_writeCommand(0xC1);
	OLED_writeData(0xC8);
	OLED_writeData(0x80);
	OLED_writeData(0xC8);
	OLED_writeCommand(0xC7);
	OLED_writeData(0x0F);
	
	OLED_writeCommand(0xB8);
	OLED_writeData(0x02);
	OLED_writeData(0x03);
	OLED_writeData(0x04);
	OLED_writeData(0x05);
	OLED_writeData(0x06);
	OLED_writeData(0x07);
	OLED_writeData(0x08);
	OLED_writeData(0x09);
	OLED_writeData(0x0A);
	OLED_writeData(0x0B);
	OLED_writeData(0x0C);
	OLED_writeData(0x0D);
	OLED_writeData(0x0E);
	OLED_writeData(0x0F);
	OLED_writeData(0x10);
	OLED_writeData(0x11);
	OLED_writeData(0x12);
	OLED_writeData(0x13);
	OLED_writeData(0x15);
	OLED_writeData(0x17);
	OLED_writeData(0x19);
	OLED_writeData(0x1B);
	OLED_writeData(0x1D);
	OLED_writeData(0x1F);
	OLED_writeData(0x21);
	OLED_writeData(0x23);
	OLED_writeData(0x25);
	OLED_writeData(0x27);
	OLED_writeData(0x2A);
	OLED_writeData(0x2D);
	OLED_writeData(0x30);
	OLED_writeData(0x33);
	OLED_writeData(0x36);
	OLED_writeData(0x39);
	OLED_writeData(0x3C);
	OLED_writeData(0x3F);
	OLED_writeData(0x42);
	OLED_writeData(0x45);
	OLED_writeData(0x48);
	OLED_writeData(0x4C);
	OLED_writeData(0x50);
	OLED_writeData(0x54);
	OLED_writeData(0x58);
	OLED_writeData(0x5C);
	OLED_writeData(0x60);
	OLED_writeData(0x64);
	OLED_writeData(0x68);
	OLED_writeData(0x6C);
	OLED_writeData(0x70);
	OLED_writeData(0x74);
	OLED_writeData(0x78);
	OLED_writeData(0x7D);
	OLED_writeData(0x82);
	OLED_writeData(0x87);
	OLED_writeData(0x8C);
	OLED_writeData(0x91);
	OLED_writeData(0x96);
	OLED_writeData(0x9B);
	OLED_writeData(0xA0);
	OLED_writeData(0xA5);
	OLED_writeData(0xAA);
	OLED_writeData(0xAF);
	OLED_writeData(0xB4);
	
	OLED_writeCommand(0xB1);							//SET PHASE LENGTH
	OLED_writeData(0x32);
	
	
	OLED_writeCommand(0xB2);							//ENHANCE DRIVING SCHEME CAPABILITY
	OLED_writeData(0xA4);
	OLED_writeData(0x00);
	OLED_writeData(0x00);
	OLED_writeCommand(0xBB);							//SET PRE-CHARGE VOLTAGE
	OLED_writeData(0x17);
	
	
	OLED_writeCommand(0xB6);							//SET SECOND PRE-CHARGE PERIOD
	OLED_writeData(0x01);
	OLED_writeCommand(0xBE);							//SET VCOMH VOLTAGE
	OLED_writeData(0x05);
	OLED_writeCommand(0xA6);							//SET DISPLAY MODE
	//CLEAR SCREEN
	OLED_writeCommand(0xAF);							//SET SLEEP MODE OFF
	LPTMR_setTimeCount(200);
}

void OLED_setCursor(unsigned char x, unsigned char y){
	if(x <= 127 && y <= 127){
		cursor.x = x;
		cursor.y = y;
	}
}

void OLED_setDisplayColor(unsigned short int color){
	unsigned short int cont = 0;
	
	while(cont < 16384){
		GDDRAM.data_16[cont] = color;
		cont++;
	}
	OLED_writeCommand(0x5C);
	GPIOC_PSOR |= (1 << DC_PIN);
	SPI0_send8Bits(1, 32768, GDDRAM.data_8);
	OLED_writeCommand(0x5C);
}

void OLED_writeCommand(unsigned char command){
	GPIOC_PCOR |= (1 << DC_PIN);
	SPI0_send8Bits(1, 1, &command);
	LPTMR_setTimeCount(5);
}

void OLED_writeData(unsigned char data){
	GPIOC_PSOR |= (1 << DC_PIN);
	SPI0_send8Bits(1, 1, &data);
	LPTMR_setTimeCount(5);
}

void OLED_enterSleepMode(void){
	OLED_writeCommand(0xAE);
	OLED_writeCommand(0xAB);
}

void OLED_exitSleepMode(void){
	OLED_writeCommand(0xAB);
	LPTMR_setTimeCount(5);
	OLED_writeCommand(0xAF);
}
