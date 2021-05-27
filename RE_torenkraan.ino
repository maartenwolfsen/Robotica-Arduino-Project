#define dsEcho 2
#define dsTrigger 3

bool scanning = false;

void setup() {
  pinMode(dsEcho, INPUT);
  pinMode(dsTrigger, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if (!scanning) {
    // motor high
  }

  if (getDistance() <= 10) {
    // motor false
    if (isForbidden()) {
      scanning = false;
    } else {
      scanning = true;
      pop();
    }
  }
}
