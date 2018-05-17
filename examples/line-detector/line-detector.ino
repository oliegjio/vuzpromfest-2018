// Порт, к которому подключен детектор:
const int lineTrackerPort = 48;
int lineTrackerState = 0;

void setup()
{
  pinMode(lineTrackerPort, INPUT);
  Serial.begin(9600);
}

void loop()
{
  lineTrackerState = digitalRead(lineTrackerPort);
  
  if (lineTrackerState == HIGH) Serial.println("White");
  else Serial.println("Black");
  
  delay(50);
}

