# Medical_Monitor
Final project

(This repository is an evidence of our final project and NOT as a software reference for new designs).


First of all, it is important to clarify that the main purpose of this project is as AUXILIARY DEVICE 
and NOT as MEDICAL DEVICE that guarantees to alleviate the disease but to control it with the help of the patient
and indeed the medical staff.

SENSOR BLOCK STAGES
	-Periodic Monitoring
		At 10:00/18:00 HOURS
	-Registration
		In RAM Memory
	-Calculation
		Of BPM and IBI
	-Sampling
		On the display in real time.
	-Shipping
		Through WiFi protocol to (Medical Institution) Server

THE PULSE SENSOR
	The amount of light is changing based on the amount of bood in your finger.


	The time difference between two R waves is the rate of an RR interval or Inter-Beat Interval (IBI), and is measured in 
	milliseconds (mS).
	The number of R wave that occurs in a minute is used to calculate Heart Rate (HR) and the standard unit is 
	Beats per Minute (BPM).
	
	
BPM
	To get your Heart Rate in Beats per Minute (BPM), the follow calculation is required:
		Count the number of R (peak) of a pulse signal during 15 seconds, and then multiply it by 4.
		Count the number of R (peak) of a pulse signal during 60 seconds.
		
MEDICAL PRESCRIPTION

	MEDICATION DOSE SCHEDULE
	*********************************************************
	*       Frecuency         *	 Scheluded hours	*
	*			  *				*
	*    Cada 4 horas	  *                             *
	*    Cada 6 horas	  *                             *   
	*    Cada 12 horas	  *                             * 
	*    Cada 24 horas	  *                             *	Each Breakfast/Lunch/Dinner
	*    Cada 48 horas	  *                             *  
	*    Cada 72 horas        *                             * 
	*                         *                             *
	*********************************************************
	Scheduled hours according to the common availability of the patient.
	
	Source: http://www.humv.es/webfarma/Informacion_Medicamentos/Formulario/normasadministracion.htm

BOTH are expected to work between 9:00 and 21:00 hours.


PINES USED IN THE SYSTEM

****************************************************************************************************
*   PIN       *   ASSIGNMENT	  *			  DESCRIPTION		                   *
*	      *                   *                                                                *
*	      *                   *                                                                *
*   PTA4      *     GPIO          *     PUSH BUTTON TO START MONITOR                               *
*   PTB2      *   ADC0_SE12	  *	PULSE SIGNAL                            	           *
*   PTB10     *	    GPIO	  *	BUZZER TO INDICATE ALARM                                   *
*   PTB22     *	    GPIO	  *     INTERNAL RED LED TO INDICATE BPM                           *
*   PTC0      *     GPIO          *     DC (OLED)                                                  *
*   PTC2      *     GPIO          *     RESET (OLED)                                               *
*   PTC16     *   UART3_RX        *     UART RX                                                    *
*   PTC17     *   UART3_TX        *     UART TX                                                    *
*   PTD0      *	  SPI0_PCS0       *	PROTOCOL SIGNAL                                            *
*   PTD1      *	  SPI0_SCK	  *	PROTOCOL SIGNAL                                            *
*   PTD2      *	  SPI0_SOUT	  *	PROTOCOL SIGNAL                                            *
*   PTD3      *	  SPI0_SIN        *	PROTOCOL SIGNAL 				           *
*   PTE26     *	    GPIO          * 	INTERNAL GREEN LED TO INDICATE PENDING MONITOR ALARM       *
****************************************************************************************************


