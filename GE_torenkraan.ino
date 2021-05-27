#include <Servo.h>

#define dsEcho 1
#define dsTrigger 2
#define cS0 = 3
#define cS1 = 4
#define cS2 = 5
#define cS3 = 6
#define cOut = 7
#define sPin = 8

Servo servo;

bool scanning = false;

int craneTimer = 0;
int craneTimerEnd = 10000;
int boomTimer = 0;
int boomTimerEnd = 2000;

void setup() {
  pinMode(dsEcho, INPUT);
  pinMode(dsTrigger, OUTPUT);

  pinMode(cS0, OUTPUT);
  pinMode(cS1, OUTPUT);
  pinMode(cS2, OUTPUT);
  pinMode(cS3, OUTPUT);
  pinMode(cOut, INPUT);

  servo.attach(sPin);
  
  Serial.begin(9600);
}

void loop() {
  if (!scanning) {
    spotlightOff();
    
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
  }

  if (getDistance() <= 10) {
    stopCraneMovement();
    spotlightOn();
    
    if (isForbidden()) {
      scanning = false;
    } else {
      scanning = true;
      servoExtend();
      delay(100);
      servoReturn();
    }
  }
}
