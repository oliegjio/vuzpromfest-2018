#include <Servo.h>

Servo myServo;

void setup()
{
  myServo.attach(5);
}

void loop()
{
  myServo.write(0); // Rotate on 0 degrees.
  delay(1000);
  
  myServo.write(180); // Rotate on 180 degrees.
  delay(1000);
}

