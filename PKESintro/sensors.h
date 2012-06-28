/*
 * Sensors.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */


void setADC(uint8_t channel){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (1 << MUX3));
	ADMUX |= channel;
	ADCSRA |= (1 << ADSC);
	while ((1 << ADSC) & ADCSRA) {}


}
uint16_t getData() {
	ADCSRA |= (1 << ADSC);
	while ((1 << ADSC) & ADCSRA) {
	}
	return ADC;
}
