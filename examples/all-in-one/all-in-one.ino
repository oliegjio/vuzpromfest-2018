#include <Servo.h>

Servo grub;
Servo roll;

const int motorM1PinOne = 6;
const int motorM1PinTwo = 7;
const int motorM2PinOne = 46;
const int motorM2PinTwo = 45;

int sensorPort1 = 37;
int sensorPort2 = 36;
int sensorPort3 = 35;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

const int input = 48;
const int output = 49;

unsigned int time_us = 0;
unsigned int distance_sm = 0;
unsigned int distance = 0;

void setup()
{
    pinMode(sensorPort1, INPUT);
    pinMode(sensorPort2, INPUT);
    pinMode(sensorPort3, INPUT);
    
    pinMode(motorM1PinOne, OUTPUT);
    pinMode(motorM1PinTwo, OUTPUT);
    pinMode(motorM2PinOne, OUTPUT);
    pinMode(motorM2PinTwo, OUTPUT);
    
    pinMode(input, OUTPUT);
    pinMode(output, INPUT);
    
    grab.attach(2);
    roll.attach(5);
    
    Serial.begin(9600);
}

void loop()
{
  forward();
  
  distance = ultrasonic();
  
  if (distance <= 20)
  {
    reveal();
    delay(1100);
    
    stopMove();
    close();
    delay(500);
    
    reroll_up();
    delay(2000);
    
    reveal();
    delay(2000);
    
    close();
    reroll_up();
  }
  
  sensorValue1 = digitalRead(sensorPort1);
  sensorValue2 = digitalRead(sensorPort2);
  sensorValue3 = digitalRead(sensorPort3);
  
  if (sensorValue3) { right(); }
  if (sensorValue1) { left(); }
  if (sensorValue1 && sensorValue2 && sensorValue3) { stopMove(); }
  
  delay(10);
}

void forward()
{
  digitalWrite(motorM2PinOne, LOW);
  digitalWrite(motorM2PinTwo, HIGH);
  
  digitalWrite(motorM1PinOne, LOW);
  digitalWrite(motorM1PinTwo, HIGH);
}

void right()
{
  digitalWrite(motorM2PinOne, HIGH);
  digitalWrite(motorM2PinTwo, LOW);
  
  digitalWrite(motorM1PinOne, LOW);
  digitalWrite(motorM1PinTwo, HIGH);
}

void left()
{
  digitalWrite(motorM2PinOne, LOW);
  digitalWrite(motorM2PinTwo, HIGH);
  
  digitalWrite(motorM1PinOne, HIGH);
  digitalWrite(motorM1PinTwo, LOW);
}

void stopMove()
{
  digitalWrite(motorM2PinOne, LOW);
  digitalWrite(motorM2PinTwo, LOW);
  
  digitalWrite(motorM1PinOne, LOW);
  digitalWrite(motorM1PinTwo, LOW);
}

unsigned int ultrasonic()
{
  digitalWrite(input, HIGH);
  delayMicroseconds(10);
  digitalWrite(input, LOW);
  
  time_us = pulseIn(output, HIGH);
  distance_sm = time_us / 58;
  
  return distance_sm;
}

void reveal()
{
  grab.writeMicroseconds(1800);
  delay(700);
  grab.writeMicroseconds(1500);
}

void close()
{
  grab.writeMicroseconds(1200);
  delay(700);
  grab.writeMicroseconds(1500);
}

void reroll_up()
{
  roll.writeMicroseconds(1800);
  delay(2000);
  roll.writeMicroseconds(1500);
}

void reroll_down()
{
  roll.writeMicroseconds(1200);
  delay(2000);
  roll.writeMicroseconds(1500);
}