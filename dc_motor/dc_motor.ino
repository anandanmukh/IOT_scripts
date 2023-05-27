// C++ code
//
void setup()
{
  //first motor
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  //pinMode(51, OUTPUT);
  //pinMode(53, OUTPUT);
}
void loop()
{
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  //digitalWrite(4, HIGH);
  //digitalWrite(5, LOW);
  analogWrite(3, 250);
  analogWrite(4, 250);
  analogWrite(5, 250);
  delay(1000); // Delay a little bit to improve simulation performance
}
