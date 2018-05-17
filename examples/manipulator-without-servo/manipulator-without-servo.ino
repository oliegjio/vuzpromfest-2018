const int armServoPin = 5;
const int clawServoPin = 2;

void setup()
{
  pinMode(armServoPin, OUTPUT);
  pinMode(clawServoPin, OUTPUT);
  
  reveal();
  delay(2000);
  
  close();
  delay(2000);
  
  reroll_up();
  delay(2000);
  
  reveal();
  delay(2000);
  
  close();
  reroll_down();
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

void reroll_up()
{
  analogWrite(armServoPin, 155);
  delay(1000);
  analogWrite(armServoPin, 188);
}

void reroll_down()
{
  analogWrite(armServoPin, 221);
  delay(1000);
  analogWrite(armServoPin, 188);
}

void loop()
{
  //
}