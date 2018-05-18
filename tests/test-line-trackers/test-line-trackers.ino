const int lineTrackerPort1 = 48;
const int lineTrackerPort2 = 49;
const int lineTrackerPort3 = 50;

int lineTrackerValue1 = 0;
int lineTrackerValue2 = 0;
int lineTrackerValue3 = 0;

void setup()
{
  pinMode(lineTrackerPort1, INPUT);
  pinMode(lineTrackerPort2, INPUT);
  pinMode(lineTrackerPort3, INPUT);
  Serial.begin(9600);
}

void loop()
{
  lineTrackerValue1 = analogRead(lineTrackerPort1);
  lineTrackerValue2 = analogRead(lineTrackerPort2);
  lineTrackerValue3 = analogRead(lineTrackerPort3);
  Serial.println("Tracker 1: " + lineTrackerValue1);
  Serial.println("Tracker 2: " + lineTrackerValue2);
  Serial.println("Tracker 3: " + lineTrackerValue3);
  delay(50);
}

