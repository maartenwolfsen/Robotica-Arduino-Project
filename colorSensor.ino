#define SCAN_COLOR_DELAY 100

int r, g, b = 0;

bool isForbidden() {
  scanColors();
  Serial.print("R: ");
  Serial.print(r);
  Serial.print("G: ");
  Serial.print(g);
  Serial.print("B: ");
  Serial.println(b);

  if (r > 1000 && g > 2000 && b > 2000) {
    Serial.println("Forbidden color detected!");
    return true;
  }
  
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
  digitalWrite(spotlight, HIGH);
  
  return true;
}

bool spotlightOff() {
  digitalWrite(spotlight, LOW);
  
  return true;
}
