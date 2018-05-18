#include <Servo.h>

Servo grab;

void setup()
{
  grab.attach(2); // Указать порт, к которому подключен мотор клешни.
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
  reveal(); // Раскрыть хват.
  delay(2000);
  
  close(); // Сомкнуть хват.
  delay(2000);
}
