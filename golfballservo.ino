/* 
to control: 1. roscore 2.rostopic pub golfBall std_msgs/UInt16  <on/On or off/Off>
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

Servo myservo;

int motorPin = 9;
int pos = 0;

void run_golf(const std_msgs::UInt32& cmd_msg){
	
	int i = cmd_msg.data
	
	if (i == on || On) {
		for (pos = 0; pos <= 180; pos += 1) { 
			myservo.write(pos);              
	    		delay(10);                       
	  	}
		for (pos = 180; pos >= 0; pos -= 1) { 
			myservo.write(pos);              
			delay(10);             
	 	}

		break;		 
	}
	
	if (i == off || Off) {
		myservo.write(90);
		break; 	
	}
	
}

ros::Subscriber<std_msgs::UInt16> sub("golfBall", run_golf);

void setup(){
	nh.initNode();
	nh.subscribe(sub);
	myservo.attach(motorPin); 
}

void loop(){
	nh.spinOnce();
	delay(1);
}

