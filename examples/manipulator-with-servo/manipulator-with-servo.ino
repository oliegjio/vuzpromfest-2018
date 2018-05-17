// (!!!) Из-за использования библиотеки Servo блокируются порты M1(45, 46).

#include <Servo.h>

Servo grab;
Servo roll;

void setup()
{
  grab.attach(2); // Указать порт, к которому подключен мотор клешни.
  roll.attach(5); // Указать порт, к которому подключен мотор штанги.
  
  reveal(); // Раскрыть хват.
  delay(2000);
  
  close(); // Сомкнуть хват.
  delay(2000);
  
  reroll_up(); // Поднять руку вверх.
  delay(2000);
  
  reveal();
  delay(2000);
  
  close();
  reroll_down();
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

void reroll_up()
{
  roll.writeMicroseconds(1800);
  delay(1000);
  roll.writeMicroseconds(1500);
}

void reroll_down()
{
  roll.writeMicroseconds(1200);
  delay(1000);
  roll.writeMicroseconds(1500);
}

void loop() {
  //
}