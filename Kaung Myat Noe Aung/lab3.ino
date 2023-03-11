#include <NewPingESP8266.h>

#define TRIGGER_PIN D1
#define ECHO_PIN D2
#define MAX_DISTANCE 200

NewPingESP8266 sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
char input;
bool measure = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();
    if (input == '1') {
      measure = true;
      Serial.println("Measuring distance...");
    } else if (input == '2') {
      measure = false;
      Serial.println("System stopped");
    }
  }

  if (measure) {
    unsigned int distance = sonar.ping_cm();
    if (distance <= 50) {
      Serial.println("Person detected");
    } else {
      Serial.println("Nothing detected");
    }
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500); 
  }
}