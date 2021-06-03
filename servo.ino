#define SERVO_POSITION_DELAY 10

bool extended = false;

/**
 * Return Servo to Safe State
 */
bool servoReturn() {
    //servo.write(180);

  extended = false;
  
  return true;
}

/**
 * Extend Servo to Pop Balloon
 */
bool servoExtend() {
  if (!extended) {
    //servo.write(20);
  }

  extended = true;
  
  return true;
}
