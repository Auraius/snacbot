
//to control: 1. roscore 2.rosrun rosserial_python serial_node.py /dev/ttyACM0 3.rostopic pub servo std_msgs/UInt16
// Rather than using various loops I have done each motor seperatly so it is easier to change the boxes (from what they are currently labeled)
# include <ros.h>

# if defined(ARDUINO) && ARDUINO >= 100 
  #include "Arduino.h"
# else 
  #include <wprogram.h>
# endif

# include <Servo.h>

# include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

void servo_box( const std_msgs::UInt16& cmd_msg){
  int a = cmd_msg.data;
   if (a == 0) {
    servo0.write(80); 
    delay(5000);
    servo0.write(10);
   }
   if (a == 1) {
    servo1.write(110); 
    delay(5000);
    servo1.write(170);
    } 
   if (a == 2) {
    servo2.write(110); 
    delay(5000);
    servo2.write(170);
   }
   if (a == 3) {
    servo3.write(80); 
    delay(5000);
    servo3.write(10);
   }
   
}

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_box);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);

  servo0.attach(8);
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);
 
}

void loop() {
  nh.spinOnce();
  delay(1);
}
