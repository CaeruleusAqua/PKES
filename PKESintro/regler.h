/*
 * regler.h
 *
 *  Created on: 25.05.2012
 *      Author: time
 */

#ifndef REGLER_H_
#define REGLER_H_

void line() {
	setADC(CNY70_1);
	uint16_t cny1 = 0;
	uint16_t cny2 = 0;
	for (int i = 0; i < 4; i++) {
		cny1 += getData();
	}
	cny1 >>= 2;
	setADC(CNY70_2);
	for (int i = 0; i < 4; i++) {
		cny2 += getData();
	}
	cny2 >>= 2;
	//rechts weiß
	if ((cny1 >= 800) && (cny2 < 800)) {
		esum -= 4;
		//fahre links
		steuer(-80 + esum);
		ledOn(1);
		richtung = links;
	}
	// links weiß
	if ((cny1 < 800) && (cny2 >= 800)) {
		//fahre rechts
		esum += 4;
		steuer(80 + esum);
		ledOn(0);
		richtung = rechts;
	}
	//beide schwarz
	if ((cny1 >= 800) && (cny2 >= 800)) {
		steuer(0);
		ledOff(0);
		ledOff(1);
		esum >>= 4;
		richtung = gerade;
	}
	//beide weiß
	if ((cny1 < 800) && (cny2 < 800)) {
		if (richtung == rechts) {
			steuer(600);
			ledOn(0);
		}
		if (richtung == links) {
			steuer(-600);
			ledOn(1);
		}
		esum >>= 4;

	}

	//Begrenzung I-Anteil
	if (esum < -100) {
		esum = -100;
	}
	if (esum > 100) {
		esum = 100;
	}
}

void dist() {
	uint16_t dds1 = 0;
	uint16_t dds2 = 0;
	uint16_t dds3 = 0;
	setADC(ds1);
	for (int i = 0; i < 8; i++) {
		dds1 += getData();
	}
	dds1 >>= 3;
	setADC(ds2);
	for (int i = 0; i < 8; i++) {
		dds2 += getData();
	}
	dds2 >>= 3;
	setADC(ds3);
	for (int i = 0; i < 8; i++) {
		dds3 += getData();
	}
	dds3 >>= 3;
	if (dds2 > 200) {
		if (dds1 > 200)
			steuer(-600);
		else
			steuer(600);

	} else
		steuer(0);
	if (dds1 > 200)
		steuer(-600);
	if (dds3 > 200)
		steuer(600);

}

void strecke(uint16_t s){
	uint16_t el=-(s-tickslinks);
	uint16_t er=-(s-ticksrechts);
	esuml+=(el>>8);
	esumr+=(er>>8);
	if(tickslinks>s+10){
		esuml=0;
		el=0;
	}
	if(ticksrechts>s+10){
		esumr=0;
		er=0;
	}
	setMotorBaseSpeed_1((er>>8)+esumr);
	setMotorBaseSpeed_2((el>>8)+esuml);
	if (esuml < -200) {
		esuml = -200;
	}
	if (esuml > 200) {
		esuml = 200;
	}
	if (esumr < -200) {
		esumr = -200;
	}
	if (esumr > 200) {
		esumr = 200;
	}
}

#endif /* REGLER_H_ */
