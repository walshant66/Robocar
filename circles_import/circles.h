
#include <UCMotor.h>
#include <Servo.h>
#include "UCNEC.h"
typedef struct MeModule
{
  int device;
  int port;
  int slot;
  int pin;
  int index;
  float values[3];
} MeModule;
union {
  byte byteVal[4];
  float floatVal;
  long longVal;
} val;

union {
  byte byteVal[8];
  double doubleVal;
} valDouble;

union {
  byte byteVal[2];
  short shortVal;
} valShort;


String mVersion = "0d.01.105";
boolean isAvailable = false;
boolean isBluetooth = false;
boolean isDetecte = false;
int len = 52;
char buffer[52];
char bufferBt[52];
byte index = 0;
byte dataLen;
boolean isStart = false;
char serialRead;
// define the device ID
#define ROBOTCAR 54
#define ULTRASONIC_SENSOR 55
#define SERVO 56

#define GET 1
#define RUN 2
#define RESET 4
#define START 5
unsigned char prevc = 0;
double lastTime = 0.0;
uint8_t keyPressed = 0;
uint8_t command_index = 0;

bool isSmartMode  = true;
bool isIrMode  = true;
unsigned int S;
unsigned int Sleft;
unsigned int Sright;

uint32_t irValue = 0;

#define TURN_DIST 40

#define TRIG_PIN A2
#define ECHO_PIN A3
#define SERVO_PIN 10

UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);

Servo neckControllerServoMotor;
UCNEC myIR(2);

int CircleSpeed (int speed1){
  
  pinMode(ECHO_PIN, INPUT); //Set the connection pin output mode Echo pin
  pinMode(TRIG_PIN, OUTPUT);//Set the connection pin output mode trog pin
  neckControllerServoMotor.attach(SERVO_PIN);
  neckControllerServoMotor.write(90);
  delay(2000);
  neckControllerServoMotor.detach();
  delay(100);
  myIR.begin();
  Serial.begin(115200);
  Serial.print("Version: ");
  Serial.println(mVersion);

UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);

leftMotor1.run(1);leftMotor1.setSpeed(speed1);
leftMotor2.run(1);leftMotor2.setSpeed(speed1);
rightMotor1.run(2);rightMotor1.setSpeed(speed1);
rightMotor2.run(2);rightMotor2.setSpeed(speed1);
  
  }
  
