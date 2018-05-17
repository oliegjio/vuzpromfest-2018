#include <Servo.h>

Servo myServo;

void setup()
{
  // Порт M13(5):
  myServo.attach(5);
}

// Установить в положение 0 градусов.
// Ждать секунду.
// Установить в положение 180 градусов.
// Жджать секунду.
// Повторить.
void loop()
{
  myServo.write(0);
  delay(1000);
  myServo.write(180);
  delay(1000);
}

