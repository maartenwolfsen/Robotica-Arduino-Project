int getDistance() {
  digitalWrite(dsTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(dsTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(dsTrigger, LOW);
  
  return pulseIn(dsEcho, HIGH) * 0.034 / 2;
}
