// MQ2 sensor is used to measure methane, butane, LPG, smoke
//https://components101.com/sensors/mq2-gas-sensor for graph
// made by @anandanmukh
int sensor = A0;
int reading;

void setup() {
  Serial.begin(9600);
}

void loop() {
  reading = analogRead(sensor);
  Serial.println("Reading: ");
  delay(2000);
  Serial.print(reading); 
  Serial.println("");
}
