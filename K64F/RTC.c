/*
 * RTC.c
 *
 *  Created on: Oct 16, 2020
 *      Author: Luis Pérez
 *     Version: 1.0
 */


#include "RTC.h"

RTCalendar_t time;
unsigned char DaysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void RTC_initPeripheral(void){
	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;
	RTC_CR = RTC_CR_SWR_MASK;
	RTC_CR = ~RTC_CR_SWR_MASK;
	RTC_CR = RTC_CR_OSCE_MASK;
	RTC_TSR = 0x00000000;
	RTC_TAR = 59;
	NVIC_EnableIRQ(INT_RTC-16,0x20);
	RTC_SR |= RTC_SR_TCE_MASK;
}

void RTC_Alarm_IRQHandler(void){
	RTC_SR = ~RTC_SR_TCE_MASK;
	RTC_TPR = 0x00000000;
	RTC_TSR = 0x00000000;
	if((RTC_SR & RTC_SR_TAF_MASK) == RTC_SR_TAF_MASK){
		RTC_TAR = 59;
		time.flag.bit.adjust = 1;
	}
	RTC_SR |= RTC_SR_TCE_MASK;
}

void RTC_adjusTime(void){
	time.minute++;
	if(time.minute == 60){
		time.minute = 0;
		time.hour++;
		if(time.hour == 24){
			time.hour = 0;
			time.day++;
			if(time.day > DaysOfMonth[time.month-1]){
				time.day = 1;
				time.month++;
				if(time.month == 13){
					time.month = 1;
					time.year++;
					RTC_leapYear();
					time.flag.bit.year = 1;
				}
				time.flag.bit.month = 1;
			}
			time.weekday++;
			if(time.weekday == 7){
				time.weekday = Saturday;
			}
			time.flag.bit.day = 1;
		}
		time.flag.bit.hour = 1;
	}
	time.flag.bit.minute = 1;
	time.flag.bit.adjust = 0;
}

void RTC_setTime(void){
	time.minute = 59;
	time.hour = 21;
	time.weekday = Thursday;
	time.day = 26;
	time.month = 11;
	time.year = 2020;
	RTC_leapYear();
	time.flag.byte = 0x00;
}

void RTC_leapYear(void){
	if((time.year % 4) == 0){
		if((time.year % 100)){
			if(time.year % 400)
				DaysOfMonth[1] = 29;
			else
				DaysOfMonth[1] = 28;
		}
		else
			DaysOfMonth[1] = 29;
	}
	else
		DaysOfMonth[1] = 28;
}
