#include <Servo.h>

Servo myServo;

void setup()
{
  myServo.attach(2);
}

void loop()
{
  myServo.writeMicroseconds(1300); // Rotate on 0 degrees.
  delay(1000);

  myServo.writeMicroseconds(1500);
  delay(2000);
  
  myServo.writeMicroseconds(1700); // Rotate on 180 degrees.
  delay(1000);
}

