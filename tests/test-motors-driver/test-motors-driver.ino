#include <Servo.h>

Servo myServo;

void setup()
{
  myServo.attach(5);
}

void loop() 
{
  myServo.writeMicroseconds(1300);
  delay(2000);
  myServo.writeMicroseconds(1500);
  delay(2000);
}

