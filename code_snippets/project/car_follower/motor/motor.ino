#include <AFMotor.h>

AF_DCMotor motor1(1); //initialize the motor 1
AF_DCMotor motor2(2); //initialize the motor 2


int IRsensor1 = 4; //initialize sensor 1(left)
int IRsensor2 = 5; //initialize sensor 2(middle)
int IRsensor3 = 6; //initialize sensor 3(right)


/* if the forward is detected, left and right not detected, go straigt
  if the left is detected or left and straight both, turn left
  if the right is detected or the right and straight both, turn right
  if all are detecting, stop and sound buzzer
*/

void setup ()
{
  
  pinMode(IRsensor1, INPUT);
  pinMode(IRsensor2, INPUT);
  pinMode(IRsensor3, INPUT);
  //Set initial speed of the motor & stop
  //motor 1
  motor1.setSpeed (200);
  motor1.run (RELEASE);
  //motor 2
  motor2.setSpeed (200);
  motor2.run (RELEASE);
}

void go_left()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(0);
  motor2.setSpeed(50);
}

void go_right()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(50);
  motor2.setSpeed(0);
}

void go_straight()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
}

void obstacle()
{
  //buzzer code
}
void loop ()
{
  
  int statusSensor1 = digitalRead(IRsensor1); //left
  int statusSensor2 = digitalRead(IRsensor2); //middle
  int statusSensor3 = digitalRead(IRsensor3); //right
  
  //go straight
  if(statusSensor1 == 0 and statusSensor2 == 1 and statusSensor3 == 0)
  {
    go_straight();
  }
  
  //for right
  else if((statusSensor1 == 0 and statusSensor2 == 0 and statusSensor3 == 1) or (statusSensor1 == 0 and statusSensor2 == 1 and statusSensor3 == 1))
  {
    go_right();
  }
  
  //go left
  else if((statusSensor1 == 1 and statusSensor2 == 0 and statusSensor3 == 0 ) or (statusSensor1 == 1 and statusSensor2 == 1 and statusSensor3 == 0 ))
  {
    go_left();
  }
  
  //to stop
  else if (statusSensor1 == 1 and statusSensor2 == 1 and statusSensor3 == 1 )
  {
    obstacle();
  }
}

