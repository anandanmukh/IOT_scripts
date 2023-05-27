#include <SoftwareSerial.h>
SoftwareSerial MyBlue(2, 3); // RX | TX 

void setup() {
  MyBlue.begin(9600);
  Serial.begin(9600); 
  
}
void loop() {

    if (MyBlue.available())
    {
      Serial.print(MyBlue.read());
    }    
}
