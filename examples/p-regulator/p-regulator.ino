const int rightLineTrackerPort = A8;
const int leftLineTrackerPort = A9;

int leftLineTrackerValue = 0;
int rightLineTrackerValue = 0;

int averageValue = 512;

const int armServoPin = 5;
const int clawServoPin = 2;

const int motorM1PinOne = 46;
const int motorM1PinTwo = 45;
const int motorM2PinOne = 6;
const int motorM2PinTwo = 7;

int motor1SetReversed = true;
int motor2SetReversed = false;

int motorSpeed = 80;

float kp = 0.13;
int es = 0;
int vt = 0;
int e = 0;

void setup()
{
  pinMode(leftLineTrackerPort, INPUT);
  pinMode(rightLineTrackerPort, INPUT);
  
  Serial.begin(9600);
  
  pinMode(motorM1PinOne, OUTPUT);
  pinMode(motorM1PinTwo, OUTPUT);
  
  pinMode(motorM2PinOne, OUTPUT);
  pinMode(motorM2PinTwo, OUTPUT);
  
  delay(100);
  
  rightLineTrackerValue = analogRead(rightLineTrackerPort);
  leftLineTrackerValue = analogRead(leftLineTrackerPort);
  
  es = leftLineTrackerValue - rightLineTrackerValue;
}

void loop()
{
  rightLineTrackerValue = analogRead(rightLineTrackerPort);
  leftLineTrackerValue = analogRead(leftLineTrackerPort);
  
  e = (e + (leftLineTrackerValue - rightLineTrackerValue - es)) / 2;
  int u = kp * e;
  vt = abs(e) / 150;
  
  powerMotor1(motorSpeed - u - vt);
  powerMotor2(motorSpeed + u - vt);
  
  delay(10);
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