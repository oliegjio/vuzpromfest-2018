/**
 * Motor with motor driver.
 */

#include <Servo.h>

Servo grab;

void setup()
{
  grab.attach(2);
}

void reveal()
{
  grab.writeMicroseconds(1800);
  delay(900);
  grab.writeMicroseconds(1500);
}

void close()
{
  grab.writeMicroseconds(1200);
  delay(900);
  grab.writeMicroseconds(1500);
}

void loop() {
  reveal();
  delay(2000);
  
  close();
  delay(2000);
}
