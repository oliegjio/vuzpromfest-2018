const int trig = 2; // Input
const int echo = 3; // Output.

unsigned int time_us = 0;
unsigned int distance_sm = 0;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  time_us = pulseIn(echo, HIGH);
  distance_sm = time_us / 58;
  
  Serial.println(distance_sm);

  delay(100);
}

