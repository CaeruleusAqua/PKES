
/*
 * motor.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */

void stopall() {
	Motor_old_1_Speed=Motor_1_Speed;
	Motor_old_2_Speed=Motor_2_Speed;
	Motor_1_Speed = 0;
	Motor_2_Speed = 0;
	Motor_1_adjSpeed = 0;
	Motor_2_adjSpeed = 0;

}
void setSpeed_1(int16_t speed) {
	if (speed >= 0) {
		// motor_1 vorwärts
		PORTE &= ~(1 << 3);
		PORTE |= (1 << 2);
		OCR1A = speed;
	} else {
		speed = -speed;
		if (speed > 255)
			speed = 255;
		// motor_1 rückwärts
		PORTE &= ~(1 << 2);
		PORTE |= (1 << 3);
		OCR1A = speed;

	}
}

void steuer(int16_t richtung) {
	setMotorSpeed_1(richtung);
	setMotorSpeed_2(-richtung);
}

void setSpeed_2(int16_t speed) {
	if (speed >= 0) {
		// motor_2 vorwärts
		PORTG &= ~(1 << 0);
		PORTG |= (1 << 1);
		OCR1B = speed;
	} else {
		speed = -speed;
		if (speed > 255)
			speed = 255;
		// motor_2 rückwärts
		PORTG &= ~(1 << 1);
		PORTG |= (1 << 0);

		OCR1B = speed;

	}
}

void setMotorBaseSpeed_1(int16_t speed) {
	if (speed > 255)
		speed = 255;
	if (speed < -255)
		speed = -255;
	Motor_1_Speed = speed;

}

void setMotorBaseSpeed_2(int16_t speed) {
	if (speed > 255)
		speed = 255;
	if (speed < -255)
		speed = -255;
	Motor_2_Speed = speed;

}

void modMotorBaseSpeed_1(int16_t speed) {
	Motor_1_Speed += speed;
	if (Motor_1_Speed > 255)
		Motor_1_Speed = 255;
	if (Motor_1_Speed < -255)
		Motor_1_Speed = -255;
}

void modMotorBaseSpeed_2(int16_t speed) {
	Motor_2_Speed += speed;
	if (Motor_2_Speed > 255)
		Motor_2_Speed = 255;
	if (Motor_2_Speed < -255)
		Motor_2_Speed = -255;
}

void modMotorSpeed_1(int16_t speed) {
	Motor_1_adjSpeed += speed;
	if (Motor_1_adjSpeed > 255)
		Motor_1_adjSpeed = 255;
	if (Motor_1_adjSpeed < -255)
		Motor_1_adjSpeed = -255;

}
void modMotorSpeed_2(int16_t speed) {
	Motor_2_adjSpeed += speed;
	if (Motor_2_adjSpeed > 255)
		Motor_2_adjSpeed = 255;
	if (Motor_2_adjSpeed < -255)
		Motor_2_adjSpeed = -255;

}
void setMotorSpeed_1(int16_t speed) {
	Motor_1_adjSpeed = speed;
}
void setMotorSpeed_2(int16_t speed) {
	Motor_2_adjSpeed = speed;
}

void adjSpeed() {
	int m1 = Motor_1_Speed + Motor_1_adjSpeed;
	int m2 = Motor_2_Speed + Motor_2_adjSpeed;
	if (m1 > 255)
		m1 = 255;
	if (m1 < -255)
		m1 = -255;
	if (m2 > 255)
		m2 = 255;
	if (m2 < -255)
		m2 = -255;
	setSpeed_1(m1);
	setSpeed_2(m2);

}
