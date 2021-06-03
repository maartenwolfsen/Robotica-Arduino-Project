#define SERVO_POSITION_DELAY 10

bool extended = false;

bool servoReturn() {
    servo.write(180);

  extended = false;
  
  return true;
}

bool servoExtend() {
  if (!extended) {
    servo.write(0);
  }

  extended = true;
  
  return true;
}
