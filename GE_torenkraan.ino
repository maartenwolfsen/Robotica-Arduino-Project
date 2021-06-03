#include <Servo.h>

#define dsEcho 12
#define dsTrigger 11
#define cS0 6
#define cS1 7
#define cS2 8
#define cS3 9
#define cOut 10
#define sPin 13
#define spotlight 24
#define boomLeft 22
#define boomRight 23
#define craneLeft 25

Servo servo;

bool scanning = false;

int craneTimer = 0;
int craneTimerEnd = 10000;
int boomTimer = 0;
int boomTimerEnd = 2000;

int frequency = 0;

void setup() {
  pinMode(dsTrigger, OUTPUT);
  pinMode(dsEcho, INPUT);

  pinMode(cS0, OUTPUT);
  pinMode(cS1, OUTPUT);
  pinMode(cS2, OUTPUT);
  pinMode(cS3, OUTPUT);
  pinMode(cOut, INPUT);
  pinMode(spotlight, OUTPUT);

  // Frequency Scaling 20%
  digitalWrite(cS0,HIGH);
  digitalWrite(cS1,LOW);

  pinMode(craneLeft, OUTPUT);
  pinMode(boomLeft, OUTPUT);
  pinMode(boomRight, OUTPUT);

  servo.attach(sPin);

  servoReturn();
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(boomRight, LOW);
  digitalWrite(boomLeft, HIGH);
  delay(1000);
  digitalWrite(boomLeft, LOW);
  digitalWrite(boomRight, HIGH);
  delay(1000);
  /*if (getDistance() <= 15) {
    if (!isForbidden()) {
      servoExtend();
    } else {
      servoReturn();
    } 
  } else {
    servoReturn();
  }*/
  
  /*spotlightOn();
  
  if (!scanning) {
    if (craneTimer >= craneTimerEnd) {
      stopCraneMovement();
      startBoomMovement();
      boomTimer++;

      if (boomTimer >= boomTimerEnd) {
        stopBoomMovement();
        boomtimer = 0;
        craneTimer = 0;
      }
    } else {
      startCraneMovement();
      craneTimer++;
    }

    if (getDistance() <= 15) {
      stopCraneMovement();
      scanning = true;
      
      if (isForbidden()) {
        scanning = false;
      } else {
        scanning = true;
        servoExtend();
        delay(100);
        servoReturn();
      }
    }
  } else {

    if (isForbidden()) {
      scanning = false;
    }
  }*/
}
