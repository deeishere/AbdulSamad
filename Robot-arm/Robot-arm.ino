#include <ESP32Servo.h>



Servo myservo; // create servo object to control a servo
Servo myservo1;
int posVal = 180; // variable to store the servo position
int servoPin = 25; // Servo motor pin blue left arm // Zero head
const int FwdPin = 26; //Forward Motor Pin//right green 
const int BwdPin = 32;  //Backward Motor Pin // forward right light blue
// second monter pin
const int fwdPin1 = 21;  // left yellow 
const int bwdPin1 = 18;   // foward left white 

long ActTime = 1000; // The time for a particular part of the cycle.

int MaxSpd = 250; 
int MaxSpd1 = 250;//Top speed (0-255)

boolean DirFlag = true; //Flag for direction
const int pwmChannel1 = 0; // PWM channel for FwdPin and BwdPin
const int pwmChannel2 = 1; // PWM channel for fwdPin1 and bwdPin1
const int pwmFrequency = 5000; // PWM frequency (5 kHz)
const int pwmResolution = 8; // 8-bit resolution (0-255)

void setup() {
myservo.attach(12);
  pinMode(fwdPin1, OUTPUT);
  pinMode(bwdPin1, OUTPUT);
  pinMode(FwdPin, OUTPUT);
  pinMode(BwdPin, OUTPUT);
    //ledcSetup(1, 5000, 8); 

     // Configure PWM channel
}


void loop() {

 // int b = myservo.read();
  // Serial.print(b);
//myservo.write(100); 
for (posVal = 120; posVal <= 180; posVal += 1) { 
myservo.write(posVal); 
delay(50);
}

delay(1000);


    analogWrite(FwdPin,MaxSpd);  //Send instructions to Forward motor pin
    analogWrite(fwdPin1,MaxSpd1);
    analogWrite(fwdPin1,0);
   // DirFlag = !DirFlag; //Toggle Direction flag

    delay(ActTime);
    analogWrite(BwdPin,MaxSpd); 
    analogWrite(bwdPin1, MaxSpd1); //Send instructions to Backward motor pin
    delay(ActTime);
    analogWrite(BwdPin,0);
    analogWrite(bwdPin1,0);
   // DirFlag =! DirFlag; //Toggle Direction flag*/
   // delay(2000);*/
//myservo.write(180);delay(ActTime);
    analogWrite(FwdPin,0);
    
for (posVal = 180; posVal >= 120; posVal -= 1) { // goes from 180 degrees to 0 degrees
myservo.write(posVal); // tell servo to go to position in variable
delay(50); // waits 15ms for the servo to reach the position

}


}    


  /*if (Serial.available() > 0) { // Check if data is received
        char in= Serial.read(); // Read the character
        if (in == 'r') { // If 'r' is pressed
            rightArm();}
        else if (in == 'l'){
            LeftArm();}*/



