#include <Wire.h>
#include <I2CEncoder.h>

I2CEncoder encoder;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  encoder.init(MOTOR_393_TORQUE_ROTATIONS, MOTOR_393_TIME_DELTA);
  
  delay(100);
}

void loop()
{
  float data = encoder.getPosition();
  Serial.println(data);
}
