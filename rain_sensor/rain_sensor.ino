
int analog_value;

void setup()
{
  pinMode(4, INPUT); //digital input
  pinMode(A0, INPUT); //analog input
  Serial.begin(9600); 
}

void loop()
{
  int sensorValue = analogRead(A0);
  if (digitalRead(4) == LOW )
  {
    Serial.println("\nIt is raining\n");
    delay(10);
  }
  else
  {
    Serial.println(" \nIt is not raining\n");
    delay(10);
  }
  analog_value = analogRead(A0);
  Serial.print("Analog Value: ");
  Serial.print(analog_value);
  delay(1000);
}
