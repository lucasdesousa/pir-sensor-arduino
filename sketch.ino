#define sensor D7
int val = 0;
bool motionState = false; // We start with no motion detected.

void setup() {
  pinMode(sensor, INPUT);   // declare sensor as input
  Serial.begin(115200);
  Serial.println("Started!");
}

void loop() {
  val = digitalRead(sensor);
  if (val == HIGH) {
    // Change the motion state to true (motion detected):
    Serial.println("Motion!");
    if (motionState == false) {
      Serial.println("Motion detected!");
      motionState = true;
    }
  }
  // If no motion is detected (pirPin = LOW), do the following:
  else {
    Serial.println("No Motion!");
    // Change the motion state to false (no motion):
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;
    }
  }
  delay(1000);
}
