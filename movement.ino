/**
 * Start Rotational Movement
 */
bool startBoomMovement() {
  digitalWrite(boomLeft,  HIGH);

  return true;
}

/**
 * Stop Rotational Movement
 */
bool stopBoomMovement() {
  digitalWrite(boomLeft,  LOW);

  return true;
}

/**
 * Start Horizontal Movement
 */
bool startCraneMovement() {
  digitalWrite(craneForward, HIGH);

  return true;
}

/**
 * Stop Horizontal Movement
 */
bool stopCraneMovement() {
  digitalWrite(craneForward, LOW);

  return true;
}
