#include "circles.h"
#include "Ultrasound_lib_function.h"


void setup() {
  // put your setup code here, to run once:
 int k;
 Serial.begin(115200);
 Serial.println(k,DEC);
 delay(5);
}

int speed2=0;
int speed1=0;
int distance=5;

void loop() {
  // put your main code here, to run repeatedly:
// int speed1=200;
 speed2=speed1;
 speed1=10*ultra_sound();
 Serial.println(speed1,DEC);
 if (speed1<0)speed1=0; 
 if (distance*10>speed1)speed1=0;
 if (distance*30>speed1)speed1=speed1/3;
 if (speed1>200)speed1=200;
//   if (speed1>100)speed1=100;
 delay(1);
 speed1=speed2*0.1+speed1*0.9;

//speed1=100-speed1;
    
 int k1;
// Serial.begin(115200);
//uncomment next line once values can be read in by ultrasonic sensor.
// k1=CircleSpeed(20*speed1);
CircleSpeed(speed1);
// Serial.println(101,DEC);
 Serial.println(speed1,DEC);
// Serial.println(102,DEC);
 delay(1);
// delay(10);
}
