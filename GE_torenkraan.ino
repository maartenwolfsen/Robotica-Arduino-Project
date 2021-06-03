//#include <Servo.h>

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

//Servo servo;

int timer = 0;
int timerMax = 4600;

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
  Serial.print("Timer Left: ");
  Serial.println(timerMax - timer);
  
  if (getDistance() <= 15) {
    stopBoomMovement();
    spotlightOn();
    
    if (!isForbidden()) {
      servoExtend();
    } else {
      servoReturn();
    } 
  } else {
    spotlightOff();
    servoReturn();
    startBoomMovement();
    timer++;
  }

  /**
   * Move Crane One Step
   */
  if (timer > timerMax) {
    timer = 0;
    stopBoomMovement();
    startCraneMovement();
    delay(1000);
    stopCraneMovement();
  }
}
