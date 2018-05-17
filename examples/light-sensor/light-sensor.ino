int sensorPort = A0;
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPort);
  // С конвертацией в вольты:
  Serial.println(sensorValue * 0.0049); 
  delay(50);
}

