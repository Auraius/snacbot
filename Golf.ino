
#include <Servo.h>

Servo myservo;  
const int pin = 9;

int pos = 0;    
void setup() {
  myservo.attach(pin);  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(10);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(10);                       
  }
}
# Golf-Ball-Dispenser
