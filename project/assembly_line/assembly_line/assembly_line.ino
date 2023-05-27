#include <Stepper.h>

//#define echoPin 2 //echo pin to D2
//#define trigPin 3 //trigger pin to D3

int trigPin = 3;
int echoPin = 2;

// defines variables
long duration; //duration of sound wave travel
int distance; 
const int stepsPerRevolution = 50;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  myStepper.setSpeed(5);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance >= 5){
    myStepper.step(stepsPerRevolution);
  }
  else
  {
    myStepper.step(0);
  } 
}


