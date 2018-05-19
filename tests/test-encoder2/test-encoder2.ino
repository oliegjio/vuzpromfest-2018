#include <Wire.h>
#include <I2CEncoder.h>

I2CEncoder encoderLeft, encoderRight;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  encoderLeft.init(MOTOR_393_TORQUE_ROTATIONS, MOTOR_393_TIME_DELTA);
  encoderLeft.setReversed(true);
  encoderLeft.unTerminate();
  encoderRight.init(MOTOR_393_TORQUE_ROTATIONS, MOTOR_393_TIME_DELTA);
  
  delay(100);
}

void loop()
{
  float data1 = encoderLeft.getPosition();
  float data2 = encoderRight.getPosition();
  Serial.print(data1);
  Serial.print(" ");
  Serial.println(data2);
  
}
