#include <SoftwareSerial.h>
#define seriport Serial2
void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
seriport.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("hello");
seriport.println("hello");
delay(1000);
}
