#include <Stepper.h>
const int stepsPerRevolution = 100;
// change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int trigPin = 6;
int echoPin = 5;

long duration; //duration of sound wave travel
int distance; 

void setup() {
   pinMode(trigPin, OUTPUT); 
   pinMode(echoPin, INPUT); 
   // set the speed at 60 rpm:
   myStepper.setSpeed(60);
   // initialize the serial port:
   Serial.begin(9600);
}

void loop() {
  //ultrasound code
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
  
  if (distance >=5)
  {
    // step one revolution in the other direction:
    myStepper.step(stepsPerRevolution);
  }
  else
  {
    delay(2000);
  }
  
   // step one revolution in the other direction:
   //myStepper.step(stepsPerRevolution);
}
