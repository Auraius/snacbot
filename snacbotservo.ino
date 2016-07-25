/* 
This is a publisher & suscriber method to control which box to open. Control servo with rosserial and an Arduino. 

to control: 1. roscore 2.rostopic pub servo std_msgs/UInt16  <motor#>
*/ 
#include <ros.h>
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
//
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo.servos[4];
int pins[4] = [10,6,11,9]
int pos = 10;

void open_close(const std_msgs::UInt16& cmd_msg){
	int i = cmd_msg.data // set motor 0-3

	for (pos = 10; pos <= 80; pos += 1) {
		if (i==1 || i==2) {
			servos[i].write(180-pos);
			delay(10);
		}
		else {
			servos[i].write(pos);
			delay(10);
		}
	}

	delay(10000) // 10 seconds to get the food out

	for (pos = 150; pos >= 10; pos -= 1) {
		if (i==1 || i==2) {
			servos[i].write(180-pos);
			delay(10);
		}
		else {
			servos[i].write(pos);
			delay(10);
		}
	}
}

ros::Subscriber<std_msgs::UInt16> sub("servo", open_close);

lose

void setup(){
	nh.initNode();
	nh.subscribe(sub);
	int i;
	for (i=0; i<4; i++) {
		servos[i].attach(pins[i]);
	}
}

void loop(){
	nh.spinOnce();
	delay(1);
}
