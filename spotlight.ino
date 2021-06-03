/**
 * Turn Spotlight On
 */
bool spotlightOn() {
  digitalWrite(spotlight, HIGH);
  
  return true;
}

/**
 * Turn Spotlight Off
 */
bool spotlightOff() {
  digitalWrite(spotlight, LOW);
  
  return true;
}
