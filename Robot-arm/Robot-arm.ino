#include <ESP32Servo.h>
#include <iostream>
using namespace std;

Servo myservo; // create servo object to control a servo
Servo myservo1;
int posVal = 0; // variable to store the servo position
int servoPin = 25; // Servo motor pin blue left arm // Zero head
const int FwdPin = 26; //Forward Motor Pin//right red
const int BwdPin = 32;  //Backward Motor Pin // forward right  purble
// second monter pin
const int fwdPin1 = 21;  // left  white
const int bwdPin1 = 18;   // foward left blue

long ActTime = 3000; // The time for a particular part of the cycle.

int MaxSpd = 250; 
int MaxSpd1 = 250;//Top speed (0-255)

boolean DirFlag = true; //Flag for direction


void setup() {
myservo.setPeriodHertz(50); // standard 50 hz servo
myservo.attach(servoPin, 500, 2500); // attaches the servo on servoPin to the servo object
Serial.begin(9600);
while (!Serial);

}


void loop() {
  myservo.write(135);
 // int b = myservo.read();
  // Serial.print(b);
for (posVal = 135; posVal <= 180; posVal += 1) { // goes from 0 degrees to 180 degrees
// in steps of 1 degree
myservo.write(posVal); 
delay(13);}
delay(3000);

if(DirFlag)
  {
    analogWrite(FwdPin,MaxSpd);  //Send instructions to Forward motor pin
    analogWrite(fwdPin1,MaxSpd1);
    delay(ActTime);
    analogWrite(FwdPin,0);
    analogWrite(fwdPin1,0);
    DirFlag = !DirFlag; //Toggle Direction flag
    delay(ActTime);
  }
  else
  {
    analogWrite(BwdPin,MaxSpd); 
    analogWrite(bwdPin1, MaxSpd1); //Send instructions to Backward motor pin
    delay(ActTime);
    analogWrite(BwdPin,0);
     analogWrite(bwdPin1,0);
    DirFlag =! DirFlag; //Toggle Direction flag
    delay(ActTime);
  }
/*

for (posVal = 135; posVal <= 180; posVal += 1) { // goes from 180 degrees to 0 degrees
myservo.write(posVal); // tell servo to go to position in variable
Serial.print(posVal);
delay(6000); // waits 15ms for the servo to reach the position
                                                                                                    }
delay(6000);
  /*if (Serial.available() > 0) { // Check if data is received
        char in= Serial.read(); // Read the character
        if (in == 'r') { // If 'r' is pressed
            rightArm();}
        else if (in == 'l'){
            LeftArm();}
} */ 
}

void rightArm() {
 myservo.write(180);
 // int b = myservo.read();
  // Serial.print(b);
for (posVal = 180; posVal >= 130; posVal -= 1) { // goes from 0 degrees to 180 degrees
// in steps of 1 degree
myservo.write(posVal); 
delay(13);}
delay(6000);
for (posVal = 135; posVal <= 180; posVal += 1) { // goes from 180 degrees to 0 degrees
myservo.write(posVal); // tell servo to go to position in variable
Serial.print(posVal);
delay(6000); // waits 15ms for the servo to reach the position
                                                                                                    }
delay(6000);
} // tell servo to go to position in variable
// waits 15ms for the servo to reach the position
void LeftArm() {
 myservo.write(0);
 // int b = myservo.read();
  // Serial.print(b);
for (posVal = 0; posVal <= 90; posVal += 1) { // goes from 0 degrees to 180 degrees
// in steps of 1 degree
myservo.write(posVal); 
delay(13);}
delay(6000);
for (posVal = 90; posVal >= 0; posVal -= 1) { // goes from 180 degrees to 0 degrees
myservo.write(posVal); // tell servo to go to position in variable
Serial.print(posVal);
delay(6000); // waits 15ms for the servo to reach the position
                                                                                                    }
delay(6000);
} // tell servo to go to position in variable
// waits 15ms for the servo to reach the position

