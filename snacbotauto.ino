#include <Servo.h>

// motors 6 & 11 go too far

int pins[4] = [10,6,11,9]

int pos = 10;

void setup () {
	int i;
	for (i=0; i<4; i++) {
		servos[i].attach(pins[i]);
	}
}

void loop () {
	for (pos = 10; pos <=80; pos += 1) {
	
		int i;
		for (i=1; i<4; i++) {
			if (i=1 || i=2) {
				servos[i].write(180-pos);
				delay(10);
			}
			else {
				servos[i].write(pos);
				delay(10);
			}
		}
		}
	for (pos = 80; pos >= 80; pos -= 1) {
		int j;
		for (j=1; j<4; j++) {
			if (i=2 || i=3) {
				servos[i].write(180-pos);
				delay(10);
			}
			else {
				servos[i].write(pos);
				delay(10);
			}
		}
		}
}
