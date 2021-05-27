#define SERVO_POSITION_DELAY 10

int sPos = 0;

bool servoExtend() {
  for (sPos = 0; sPos <= 180; sPos += 1) {
    servo.write(sPos);
    delay(SERVO_POSITION_DELAY);
  }
  
  return true;
}

bool servoReturn() {
  for (sPos = 180; sPos >= 0; sPos -= 1) {
    servo.write(sPos);
    delay(SERVO_POSITION_DELAY);
  }
  
  return true;
}
