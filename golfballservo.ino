//to control: 1. roscore 2.rosrun rosserial_python serial_node.py /dev/ttyACM0 3.rostopic pub golfBall std_msgs/UInt16
 
#include <ros.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else

#endif

#include <Servo.h> 
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo myservo;
int motorPin = 9;
int pos = 170;

void run_golf(const std_msgs::UInt16& cmd_msg){
	
 int a = cmd_msg.data;
 int pos =180;
 if (a== 1) {
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(10);        
  }
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(10);        
  }
 }
}

ros::Subscriber<std_msgs::UInt16> sub("golfBall", run_golf);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  myservo.attach(motorPin); 
}

void loop() {
  nh.spinOnce();
  delay(1);
}
