/*
 * SSD1351.h
 *
 *  Created on: Nov 16, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: 1.5" Diagonal OLED 
 *     				128x128 RGB pixels
 *     				16-bit color resolution
 *     				SSD1351 driver chip
 *     				
 *     				Display configuration
 */

#ifndef SSD1351_H_
#define SSD1351_H_

	#include "derivative.h"
	#include "fonts.h"
	#include "LPTMR.h"
	#include "SPI.h"

	#define RESET_PIN	2
	#define DC_PIN		0
	
	void OLED_initDevice(void);
	void OLED_setCursor(unsigned char x, unsigned char y);
	void OLED_setDisplayColor(unsigned short int color);
	void OLED_writeCommand(unsigned char command);
	void OLED_writeData(unsigned char data);
	void OLED_enterSleepMode(void);
	void OLED_exitSleepMode(void);

	
	
#endif
