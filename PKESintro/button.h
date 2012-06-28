/*
 * button.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */

uint8_t pushButton(uint8_t button) {
	switch (button) {
	case 0: {
		if (S.bSbutton_S0 == 1 && button(0) == 0) {
			S.bSbutton_S0 = 0;
			return 1;
		}
		S.bSbutton_S0 = button(0);
		return 0;
	}
	case 1: {
		if (S.bSbutton_S1 == 1 && button(1) == 0) {
			S.bSbutton_S1 = 0;
			return 1;
		}
		S.bSbutton_S1 = button(1);
		return 0;
	}
	case 2: {
		if (S.bSbutton_S2 == 1 && button(2) == 0) {
			S.bSbutton_S2 = 0;
			return 1;
		}
		S.bSbutton_S2 = button(2);
		return 0;
	}
	case 3: {
		if (S.bSbutton_S3 == 1 && button(3) == 0) {
			S.bSbutton_S3 = 0;
			return 1;
		}
		S.bSbutton_S3 = button(3);
		return 0;
	}
	}
	return 0;
}
