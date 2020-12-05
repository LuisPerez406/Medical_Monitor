
#include "derivative.h" 							// INCLUDE PERIPHERAL DECLARATIONS
#include "ADC.h"
#include "LPTMR.h"
#include "PIT.h"
#include "RTC.h"
#include "SPI.h"
#include "SSD1351.h"
#include "UART.h"

void APP_alarmSound(void);
void APP_initPins(void);
void APP_initVariables(void);
void APP_sendMonitoring(void);
void APP_startMonitoring(unsigned char x);

/***************************************************************************************************
 *  VARIABLES
 ***************************************************************************************************/

typedef struct{
	unsigned char name[50];
	unsigned char amount[50];						//PORTION OF MEDICATION
	unsigned char period;							//HOURS
	unsigned char length;							//DURATION: DAYS
	unsigned char hour;								//SCHEDULED TIME
	unsigned char hour_aux;
}medicine_t;

typedef struct{
	unsigned char BPM;
	unsigned char IBI;
	unsigned char hour;
	unsigned char alarmFlag;
}monitoring_t;

monitoring_t monitor[2];
medicine_t medicine[3];

extern RTCalendar_t time;

/***************************************************************************************************
 *  MAIN
 ***************************************************************************************************/

int main(void){
	unsigned char cont = 0;
	
	LPTMR_initPeripheral();
	UART3_initPeripheral();
	APP_initVariables();
	APP_initPins();
	SPI0_initPeripheral();
	SPI0_setMaster();
	OLED_initDevice();
	//OLED_writeCommand(0xA4);
	//OLED_writeCommand(0xA6);
	//OLED_writeCommand(0xA5);
	//OLED_writeCommand(0xA6);
	//OLED_setDisplayColor(BLACK);
	ADC0_InitPeripheral();
	PIT_InitPeripheral();
	RTC_setTime();
	RTC_initPeripheral();

	while(1){
		if(time.flag.bit.adjust){
			RTC_adjusTime();
		}
		if(time.flag.bit.hour){
			if(time.hour > 8 && time.hour < 22){
				cont = 0x00;
				while(cont < 3){
					if((time.hour == medicine[cont].hour_aux) && (medicine[cont].length != 0)){
						time.flag.bit.alarm = 1;
						medicine[cont].hour_aux += medicine[cont].period;
						//PRINTF PANTALLA
					}
					cont++;
				}
				cont = 0x00;
				while(cont < 2){
					if(time.hour == monitor[cont].hour){
						time.flag.bit.alarm = 1;
						monitor[cont].alarmFlag = 1;
					}
					cont++;
				}
			}
			if(time.hour == 22)
				APP_sendMonitoring();
			time.flag.bit.hour = 0;
		}
		if(time.flag.bit.day){
			cont = 0;
			while(cont < 3){
				medicine[cont].hour_aux = medicine[cont].hour;
				if(medicine[cont].length != 0)
					medicine[cont].length--;
				cont++;
			}
		}
		if(time.flag.bit.alarm){
			APP_alarmSound();
			time.flag.bit.alarm = 0;
		}
		
		if((monitor[0].alarmFlag == 1) | (monitor[1].alarmFlag == 1)){
			GPIOE_PTOR |= (1 << 26);
			LPTMR_setTimeCount(1500);
			if((GPIOA_PDIR & 0x10) == 0){
				GPIOE_PSOR |= (1 << 26);
				if(monitor[0].alarmFlag)
					APP_startMonitoring(0);
				else
					APP_startMonitoring(1);
				monitor[0].alarmFlag = 0;
				monitor[1].alarmFlag = 0;
			}
		}
	}
}

/***************************************************************************************************
 *  FUNCTIONS
 ***************************************************************************************************/
void APP_alarmSound(void){
	unsigned char counter_1 = 0x00, counter_2 = 0x00;
	
	while(counter_1 < 3){
		while(counter_2 < 3){
			GPIOB_PSOR |= (1 << 10);
			LPTMR_setTimeCount(100);
			GPIOB_PCOR |= (1 << 10);
			LPTMR_setTimeCount(100);
			counter_2++;
		}
		LPTMR_setTimeCount(1000);	
		counter_1++;
		counter_2 = 0;
	}
}

void APP_initPins(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK;
	PORTA_PCR4  = PORT_PCR_MUX(1);
	PORTB_PCR10 = PORT_PCR_MUX(1);
	PORTB_PCR22 = PORT_PCR_MUX(1);
	PORTE_PCR26 = PORT_PCR_MUX(1);
	GPIOB_PSOR |= (1 << 22);
	GPIOE_PSOR |= (1 << 26);
	GPIOB_PDDR |= (1 << 10) | (1 << 22);
	GPIOE_PDDR |= (1 << 26);
}

void APP_initVariables(void){
   unsigned char cont = 0;

   while(cont < 1){
       UART3_transmitData(0x0A);
       UART3_receivePacket(medicine[cont].name, 0x0A);
       UART3_receivePacket(medicine[cont].amount, 0x0A);
       UART3_receivePacket(&medicine[cont].period, 0x0A);
       UART3_receivePacket(&medicine[cont].length, 0x0A);
       UART3_receivePacket(&medicine[cont].hour, 0x0A);
       medicine[cont].hour_aux = medicine[cont].hour;
       cont++;
   }
   monitor[0].hour = 10;
   monitor[1].hour = 18;
}

void APP_sendMonitoring(void){
	unsigned char cont = 0;
	
	UART3_transmitData(0x0B);
	while(cont < 2){
		UART3_transmitData(monitor[cont].BPM);
		UART3_transmitData(monitor[cont].IBI);
		UART3_transmitData(monitor[cont].hour);
		cont++;
	}
}

void APP_startMonitoring(unsigned char x){
	unsigned short int threshold = 35000;				//SIGNAL THERESHOLD FROM PULSE SENSOR 53384
	unsigned short int ADCvalue = 0x0000, cont_1 = 0x0000, cont_2 = 0x0000, IBI = 0x0000;
	unsigned char BPM = 0x00, highIndicator = 0, numBeat = 1;
	
	PITx_InitChannel(1, 0, 0, 0x11E1A2FF);
	PITx_InitChannel(0, 0, 1, 0x00009C3F);
	do{
		while((ADC0_SC1A & ADC_SC1_COCO_MASK) == 0);
		ADCvalue = ADC0_RA;
		cont_1 += 2;
		if(ADCvalue > threshold){
			GPIOB_PCOR |= (1 << 22);
			highIndicator = 1;
		}
			
		else{
			GPIOB_PSOR |= (1 << 22);
			if(highIndicator){
				BPM++;
				if(numBeat == 1){
					cont_2 = cont_1;
					numBeat = 2;
				}
				else{
					IBI = cont_1 - cont_2;
					cont_1 = 0;
					cont_2 = 0;
					numBeat = 1;
				}
				highIndicator = 0;
			}
		}
	}while((PIT_TFLG1 & PIT_TFLG_TIF_MASK) == 0);
	GPIOB_PSOR |= (1 << 22);
	PITx_DisableChannel(0);
	PITx_DisableChannel(1);
	monitor[x].BPM = (BPM * 4);
	monitor[x].IBI = (60000 / IBI);
}
