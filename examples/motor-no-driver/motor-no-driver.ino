// Пример без использования внешнего драйвера мотора.

const int motorPinOne = 6;
const int motorPinTwo = 7;

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(motorPinOne, HIGH);
  digitalWrite(motorPinTwo, LOW);
  delay(2000);
  digitalWrite(motorPinOne, LOW);
  digitalWrite(motorPinTwo, LOW);
  delay(2000);
  digitalWrite(motorPinOne, LOW);
  digitalWrite(motorPinTwo, HIGH);
  delay(2000);
  digitalWrite(motorPinOne, LOW);
  digitalWrite(motorPinTwo, LOW);
  delay(2000);
}

