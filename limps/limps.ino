const int FwdPin = 26; //Forward Motor Pin//right
const int BwdPin = 32;  //Backward Motor Pin // forward right
// second monter pin
const int fwdPin1 = 21;  // left 
const int bwdPin1 = 18;   // foward left 

long ActTime = 3000; // The time for a particular part of the cycle.

int MaxSpd = 250; 
int MaxSpd1 = 250;//Top speed (0-255)

boolean DirFlag = true; //Flag for direction

void setup()
{
  pinMode(FwdPin, OUTPUT);
  pinMode(BwdPin, OUTPUT);
  pinMode(fwdPin1 , OUTPUT); 
  pinMode(bwdPin1 , OUTPUT); 
}

void loop()
{

 
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
}
