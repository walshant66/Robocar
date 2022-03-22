#include "circles.h"


void setup() {
  // put your setup code here, to run once:
 int k;
 Serial.begin(115200);
 Serial.println(k,DEC);
 delay(5);
}


void loop() {
  // put your main code here, to run repeatedly:
 int speed1=200;
 int k1;
 Serial.begin(115200);
 k1=CircleSpeed(speed1);
 Serial.println(k1,DEC);
 delay(5);
}
