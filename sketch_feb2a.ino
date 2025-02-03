#include <ESP32Servo.h>
#include <stdio.h>

Servo myservo; // create servo object to control a servo
Servo myservo1;
int posVal = 0; // variable to store the servo position
int servoPin = 25; // Servo motor pin

void setup() {
  //upper 
myservo.setPeriodHertz(50); // standard 50 hz servo
myservo.attach(servoPin, 500, 2500); // attaches the servo on servoPin to the servo object
Serial.begin(115200);

// كوع 
 pinMode(FwdPin, OUTPUT);
  pinMode(BwdPin, OUTPUT);
  pinMode(fwdPin1 , OUTPUT); 
  pinMode(bwdPin1 , OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

}
