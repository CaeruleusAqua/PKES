/*
 * interrupt.h
 *
 *  Created on: 26.05.2012
 *      Author: time
 */

ISR( INT2_vect) {
	tickslinks++;
	if(tickslinks>100)ledOff(0);
	else ledOn(0);
}

ISR( INT3_vect) {
	ticksrechts++;
	if(ticksrechts>100)ledOff(1);
	else ledOn(1);
}
