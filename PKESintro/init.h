/*
 * init.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */

void init() {
	//-------------------------------- Port A -------------------------------
	// set leds LED_X as output
	// alternative
	//     - intermediate
	//       DDRA=1+2+4+8;
	//     - using processor makros
	//       DDRA=((1<<DDA0) | (1<<DDA1) | (1<<DDA2) | (1<<DDA3));
	//     - using hardware specific makros
	DDRA |= ((1 << LED_0) | (1 << LED_1) | (1 << LED_2) | (1 << LED_3));
	DDRC = 0xff;
	// disable leds
	PORTA &= ~((1 << LED_0) | (1 << LED_1) | (1 << LED_2) | (1 << LED_3));
	//--------------------------------  ADMUX  -------------------------------
	//interne Referenz setzen
	ADMUX |= ((1 << REFS0) | (1 << REFS1));
	//adc rechtsbuendig
	ADMUX &= ~(1 << ADLAR);
	//kanal 0 setzen
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (1 << MUX3));
	//-------------------------------- ADCSRA -------------------------------
	//vorteiler auf 128
	ADCSRA |= ((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));

	//---------------------------------- PWM --------------------------------
	DDRB |= ((1 << OC1A) | (1 << OC1B)); //OC1A/OC1B auf Ausgang
	TCCR1A = ((1 << WGM10) | (1 << COM1A1) | (1 << COM1B1)); // PMW-Mode (1) Phase Correct, 8 Bit
	TCCR1B = ((1 << CS11) | (1 << CS10)); // Prescaler auf 64

	//--------------------------------- Motor -------------------------------
	// PortE 2/3 auf Ausgang (Motor_1 rechts)
	DDRE |= ((1 << 2) | (1 << 3));
	PORTE &= ~(1 << 2);
	PORTE |= (1 << 3);
	// PortG 0/1 auf Ausgang (Motor_2 links)
	DDRG |= ((1 << 0) | (1 << 1));
	PORTG &= ~(1 << 1);
	PORTG |= (1 << 0);
	OCR1A = 0;
	// PWM 1 auf null
	OCR1B = 0;
	// PWM 2 auf null
	//---------------------------------- Space --------------------------------
	S.bSbutton_S0 = 0;
	S.bSbutton_S1 = 0;
	S.bSbutton_S2 = 0;
	S.bSbutton_S3 = 0;
	tickslinks = 0;
	ticksrechts = 0;
	richtung = gerade;
	//-------------------------------- Interrupt ------------------------------
	/*
	 UCSR1A=0;
	 UCSR1B=0;
	 EIMSK = 0;
	 EICRA = 0;
	 EICRA |= ((1 << ISC21) | (0 << ISC20) | (1 << ISC31) | (0 << ISC30));
	 EIMSK |= ((1 << INT2) | (1 << INT3));
	 DDRD = 0; // alles auf eingang
	 //--------------------------------- UART ----------------------------------
	 */
	/* Set baud rate */
	//DDRD=0;
	//DDRD|=(1 << 3);
	UBRR1H = UBRRH_VALUE;
	UBRR1L = UBRRL_VALUE;
	/* Set frame format: 8data, no parity & 2 stop bits */
	UCSR1C = (0 << UMSEL1) | (0 << UPM1) | (1 << USBS1) | (3 << UCSZ1);
	/* Enable receiver and transmitter */
	UCSR1B = (1 << RXEN1) | (1 << TXEN1) | (1 << RXCIE1);
}

void lineInit() {
	VccOn(CNY70_1);
	VccOn(CNY70_2);
}

void distInit() {
	VccOn(ds1);
	VccOn(ds2);
	VccOn(ds3);
}
