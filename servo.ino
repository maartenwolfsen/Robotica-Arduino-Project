/**
 * Extend Servo to Pop Balloon
 */
bool servoExtend() {
  servo.write(0);
  
  return true;
}

/**
 * Return Servo to Safe State
 */
bool servoReturn() {    
  servo.write(180);
    
  return true;
}
