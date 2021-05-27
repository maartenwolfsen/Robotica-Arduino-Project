#define SCAN_ITERATION_TIME 100

bool isForbidden() {
  return false;
}

bool scanColors() {
  r = scanR();
  delay(SCAN_ITERATION_TIME);
  g = scanG();
  delay(SCAN_ITERATION_TIME);
  b = scanB();
  delay(SCAN_ITERATION_TIME);

  return true;
}

int scanR() {
  digitalWrite(cS2, LOW);
  digitalWrite(cS3, LOW);
  
  return pulseIn(cOut, LOW);
}

int scanG() {
  digitalWrite(cS2, HIGH);
  digitalWrite(cS3, HIGH);
  
  return pulseIn(cOut, LOW);
}

int scanB() {
  digitalWrite(cS2, LOW);
  digitalWrite(cS3, HIGH);
  
  return pulseIn(cOut, LOW);
}
