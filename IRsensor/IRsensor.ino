int IRsensor = 4;

void setup() {
  pinMode(IRsensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int statusSensor = digitalRead(IRsensor);
  if (statusSensor == 1)
  {
    Serial.println("Object Detected\n");
    delay(300);
  }
  else
  {
    Serial.println("No object detected\n");
    delay(300);
  }
  
}
