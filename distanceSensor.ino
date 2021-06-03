long duration;
long OnTime = 10;
long OffTime = 2;
int distance;

int getDistance() {
  digitalWrite(dsTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(dsTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(dsTrigger, LOW);

  duration = pulseIn(dsEcho, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance (cm): ");
  Serial.println(distance);
  
  return distance;
}
