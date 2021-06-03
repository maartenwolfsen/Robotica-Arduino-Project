#include <Servo.h>

// Define pins
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
#define craneForward 25
#define craneBackward 21

Servo servo;

bool scanning = false;

void setup() {
  // Distance Sensor
  pinMode(dsTrigger, OUTPUT);
  pinMode(dsEcho, INPUT);

  // Color Sensor
  pinMode(cS0, OUTPUT);
  pinMode(cS1, OUTPUT);
  pinMode(cS2, OUTPUT);
  pinMode(cS3, OUTPUT);
  pinMode(cOut, INPUT);
  pinMode(spotlight, OUTPUT);

  // Frequency Scaling 20%
  digitalWrite(cS0,HIGH);
  digitalWrite(cS1,LOW);

  // Crane Movement
  pinMode(craneForward, OUTPUT);
  pinMode(craneBackward, OUTPUT);
  pinMode(boomLeft, OUTPUT);
  pinMode(boomRight, OUTPUT);

  // Servo
  servo.attach(sPin);
  servoReturn();
  
  Serial.begin(9600);
}

void loop() {
  startCraneMovement();
  delay(2000);
  stopCraneMovement();
  delay(2000);
  /*if (getDistance() <= 15) {
    digitalWrite(boomLeft, LOW);
    if (!isForbidden()) {
      servoExtend();
    } else {
      servoReturn();
    } 
  } else {
    digitalWrite(boomLeft, HIGH);
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
