/*
 * RTC.h
 *
 *  Created on: Oct 16, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 *     
 *     Description: Real Time Clock (RTC) configuration
 */

#ifndef RTC_H_
#define RTC_H_

	#include "derivative.h"
	#include "NVIC.h"

	#define Saturday	0
	#define Monday		1
	#define	Tuesday		2
	#define Wednesday	3
	#define Thursday	4
	#define Friday		5
	#define Sunday		6
	
	void RTC_initPeripheral(void);
	void RTC_Alarm_IRQHandler(void);
	void RTC_adjusTime(void);
	void RTC_setTime(void);
	void RTC_leapYear(void);
	
	typedef union{
		unsigned char byte;
		struct{
			unsigned char minute	:1;
			unsigned char hour		:1;
			unsigned char day		:1;
			unsigned char month		:1;
			unsigned char year		:1;
			unsigned char 			:1;
			unsigned char alarm		:1;
			unsigned char adjust	:1;
		}bit;
	}flag_t;
	
	typedef struct{
		unsigned short int year;
		unsigned char month;
		unsigned char weekday;
		unsigned char day;
		unsigned char hour;
		unsigned char minute;
		flag_t flag;
	}RTCalendar_t;

#endif
