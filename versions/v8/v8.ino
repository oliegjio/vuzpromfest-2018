/**
 * Двигатель.
 */

#include <Wire.h>
#include "I2CEncoder.h"

#define FORWARD1 299
#define FORWARD2 297
#define FORWARD3 80
#define FORWARD4 310
#define ANGLE1 90
#define ANGLE2 85

#define PI 3.1416

I2CEncoder encoderLeft, encoderRight;

const int motorM1PinOne = 46;
const int motorM1PinTwo = 45;
const int motorM2PinOne = 6;
const int motorM2PinTwo = 7;

const int armServoPin = 5;
const int clawServoPin = 2;

int motor1SetReversed = false;
int motor2SetReversed = true;

int motorSpeed = 140;
int kp = 175;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  encoderLeft.init(MOTOR_393_TORQUE_ROTATIONS, MOTOR_393_TIME_DELTA);
  encoderLeft.setReversed(true);
  encoderLeft.unTerminate();
  encoderRight.init(MOTOR_393_TORQUE_ROTATIONS, MOTOR_393_TIME_DELTA);

  pinMode(armServoPin, OUTPUT);
  pinMode(clawServoPin, OUTPUT);
  
  pinMode(motorM1PinOne, OUTPUT);
  pinMode(motorM1PinTwo, OUTPUT);
  pinMode(motorM2PinOne, OUTPUT);
  pinMode(motorM2PinTwo, OUTPUT);
  
  delay(5000);
  
  start();
}

void start()
{
  int steps1 = 1700;

  forward(FORWARD1);
  stopAll();

  reroll_up(steps1);
  delay(2000);

  reroll_down(steps1);
  delay(2000);

  backward(FORWARD1);
  stopAll();
}

void loop() {}

void forward(float l)
{
  double posLeft = encoderLeft.getPosition();
  double posRight = encoderRight.getPosition();

  int u = 0.0;
  int error = 0.0;

  powerMotor1(motorSpeed - 80);
  powerMotor2(motorSpeed);

  while (abs(posLeft - encoderLeft.getPosition()) < 2.0 * l / (PI * 10.3))
  {
    error = encoderLeft.getPosition() * 100 - encoderRight.getPosition() * 100;
    u = kp * error;
    
    powerMotor1(motorSpeed - u);
    powerMotor2(motorSpeed + u);
  }

  encoderLeft.zero();
  encoderRight.zero();
}

void backward(float l)
{
  double posLeft = encoderLeft.getPosition();
  double posRight = encoderRight.getPosition();

  int u = 0.0;
  int error = 0.0;

  powerMotor1(-motorSpeed - 80);
  powerMotor2(-motorSpeed);

  while (abs(posLeft - encoderLeft.getPosition()) < 2.0 * l / (PI * 10.3))
  {
    error = encoderLeft.getPosition() * 100 - encoderRight.getPosition() * 100;
    u = kp * error;
    
    powerMotor1(-motorSpeed - u);
    powerMotor2(-motorSpeed + u);
  }

  encoderLeft.zero();
  encoderRight.zero();
}

void stopAll()
{ 
  analogWrite(clawServoPin, 188);
  analogWrite(armServoPin, 188);
  
  powerMotor1(0);
  powerMotor2(0);
  
  delay(1000);
}

void powerMotor1(int speedValue)
{
  int direction = motor1SetReversed ? -1 : 1;
  speedValue = constrain(speedValue, -254, 254);
  
  if (speedValue == 0)
  {
    digitalWrite(motorM1PinOne, LOW);
    digitalWrite(motorM1PinTwo, LOW);
  }
  if (direction * speedValue > 0)
  {
    digitalWrite(motorM1PinOne, LOW);
    analogWrite(motorM1PinTwo, abs(speedValue));
  }
  if (direction * speedValue < 0)
  {
    analogWrite(motorM1PinOne, abs(speedValue));
    digitalWrite(motorM1PinTwo, LOW);
  }
}

void powerMotor2(int speedValue)
{
  int direction = motor2SetReversed ? -1 : 1;
  speedValue = constrain(speedValue, -254, 254);
  
  if (speedValue == 0)
  {
    digitalWrite(motorM2PinOne, LOW);
    digitalWrite(motorM2PinTwo, LOW);
  }
  if (direction * speedValue > 0)
  {
    digitalWrite(motorM2PinOne, LOW);
    analogWrite(motorM2PinTwo, abs(speedValue));
  }
  if (direction * speedValue < 0)
  {
    analogWrite(motorM2PinOne, abs(speedValue));
    digitalWrite(motorM2PinTwo, LOW);
  }
}

void reveal()
{
  analogWrite(clawServoPin, 221);
  delay(900);
  analogWrite(clawServoPin, 188);
}

void close()
{
  analogWrite(clawServoPin, 155);
  delay(900);
  analogWrite(clawServoPin, 188);
}

void reroll_up(int duration)
{
  analogWrite(armServoPin, 155);
  delay(duration);
  analogWrite(armServoPin, 188);
}

void reroll_down(int duration)
{
  analogWrite(armServoPin, 221);
  delay(duration);
  analogWrite(armServoPin, 188);
}
