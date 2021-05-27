#define SCAN_COLOR_DELAY 100

bool isForbidden() {
  return false;
}

bool scanColors() {
  r = scanR();
  delay(SCAN_COLOR_DELAY);
  g = scanG();
  delay(SCAN_COLOR_DELAY);
  b = scanB();
  delay(SCAN_COLOR_DELAY);

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

bool spotlightOn() {
  return true;
}

bool spotlightOff() {
  return true;
}
