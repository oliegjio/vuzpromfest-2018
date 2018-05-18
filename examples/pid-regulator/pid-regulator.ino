const int rightLineTrackerPort = A8;
const int leftLineTrackerPort = A9;

int rightLineTrackerValue = 0;
int leftLineTrackerValue = 0;

const int armServoPin = 5;
const int clawServoPin = 2;

const int motorM1PinOne = 46;
const int motorM1PinTwo = 45;
const int motorM2PinOne = 6;
const int motorM2PinTwo = 7;

int motor1SetReversed = true;
int motor2SetReversed = false;

int speedMotor = 100;

int averageValue = 0;

int es = 0;
int error = 0;
float ku = 0.14;
float kp = 0.6 * ku;
float tu = 0.95;
float ki = 2 * kp / tu;
float kd = kp * tu / 8;
int vt = 0;

long timeOld = 0;
int errorOld = 0;
float errorIntegral = 0;

void setup()
{
  pinMode(rightLineTrackerPort, INPUT);
  pinMode(leftLineTrackerPort, INPUT);
  
  pinMode(motorM1PinOne, OUTPUT);
  pinMode(motorM1PinTwo, OUTPUT);
  pinMode(motorM2PinOne, OUTPUT);
  pinMode(motorM2PinTwo, OUTPUT);
  
  Serial.port(9600);
  
  delay(100);
  
  rightLineTrackerValue = analogRead(rightLineTrackerPort);
  leftLineTrackerValue = analogRead(leftLineTrackerPort);
  
  es = leftLineTrackerValue - rightLineTrackerValue;
}

void loop()
{
  rightLineTrackerValue = analogRead(rightLineTrackerPort);
  leftLineTrackerValue = analogRead(leftLineTrackerPort);
  
  long time = millis();
  float dt = (time - timeOld) / 1000.0;
  timeOld = time;
  
  error = (error + (leftLineTrackerValue - rightLineTrackerValue - es)) / 2;
  
  float errorDerivative = (error - errorOld) / dt;
  errorOld = error;
  errorIntegral += error * dt;
  
  int u = kp * error +
          ki * errorIntegral +
          kd * errorDerivative;
  
  vt = abs(error) / 150;
  
  powerMotor1(motorSpeed - u - vt);
  powerMotor2(motorSpeed + u - vt);
  
  delay(2);
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