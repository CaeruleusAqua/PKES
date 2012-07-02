/*
 * define.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */

//-------------------------------- USART -------------------------------

#ifndef F_CPU
#warning "F_CPU war noch nicht definiert, wird nun nachgeholt mit 16000000"
#define F_CPU 16000000UL  // Systemtakt in Hz - Definition als unsigned long beachten
	// Ohne ergeben sich unten Fehler in der Berechnung
#endif

#define BAUD 19200UL      // Baudrate
#define UART_MAXSTRLEN 30



/*! Makros for led control*/
#define ledOn(x)	(PORTA |= (1<<x))
#define ledOff(x) 	(PORTA &=~(1<<x))
#define button(x)	((PINA & (16<<x))==0)

/*! Makros for Sensor control*/

#define VccOn(x)	(PORTC &=~(1<<x))
#define VccOff(x)	(PORTC |= (1<<x))
#define enableACD() ADCSRA |= (1 << ADEN);
#define CNY70_1		4
#define CNY70_2		3
#define ds1			0
#define ds2			1
#define ds3			2


/*! Robby Board Specification*/
//-------------------------------- Port A -------------------------------
#define LED_0		0
#define LED_1		1
#define LED_2		2
#define LED_3		3
#define BUTTON_0	4
#define BUTTON_1	5
#define BUTTON_2	6
#define BUTTON_4	7
//-------------------------------- ADMUX --------------------------------
#define MUX0		0
#define MUX1		1
#define MUX2		2
#define MUX3		3
#define ADLAR		5
#define REFS0		6
#define REFS1		7
//-------------------------------- ADCSRA -------------------------------
#define ADEN		7
#define ADSC		6
#define ADFR		5
#define ADIF		4
#define ADIE		3
#define ADPS2		2
#define ADPS1		1
#define ADPS0		0
//---------------------------------- PWM --------------------------------
#define OC1A		5
#define OC1B		6
//------------------------------- TCCR1A -----------------------------
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
#define COM1C1		3
#define COM1C0		2
#define WGM11		1
#define WGM10		0
//------------------------------- TCCR1B -----------------------------
#define ICNC1		7
#define ICES1		6
#define WGM13		4
#define WGM12		3
#define CS12		2
#define CS11		1
#define CS10		0



