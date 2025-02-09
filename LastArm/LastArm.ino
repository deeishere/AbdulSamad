#include <ESP32Servo.h>
Servo myservo;
int posVal;
int shoulderPin = 12;//brown
int FwdPin = 26,BwdPin=32;//right (Green-light blue)
int ActTime = 1000; 
int MaxSpd = 250; 


void setup() {
  myservo.attach(12);

}

void loop() {
  for (posVal = 120; posVal <= 180; posVal += 1) { 
myservo.write(posVal); 
delay(50);
}

 analogWrite(FwdPin,MaxSpd); 
  delay(ActTime);
  analogWrite(FwdPin,0);
  analogWrite(BwdPin,MaxSpd); 
   delay(ActTime);
  analogWrite(BwdPin,0);
  
for (posVal = 180; posVal >= 120; posVal -= 1) { 
myservo.write(posVal); 
delay(50); 


}
