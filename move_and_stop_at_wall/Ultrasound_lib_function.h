#define TRIG_PIN A2
#define ECHO_PIN A3

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

int readPing()
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, cm;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  return cm ;
}

int ultra_sound()
{
  int temp = readPing();
//  Serial.println(temp,DEC);
  delay(1);
  return temp;
}
