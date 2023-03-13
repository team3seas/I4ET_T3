#include <pitches.h>

#include <NewPingESP8266.h>

#include <NewPingESP8266.h>
#define TRIGGER_PIN D1
#define ECHO_PIN D2
#define MAX_DISTANCE 200 // Maximum distan
NewPingESP8266 sonar(TRIGGER_PIN, ECHO_PIN,MAX_DISTANCE);
void setup() {
Serial.begin(9600);
}
void loop()
 {
delay(500); 
unsigned int uS = sonar.ping(); // Send
Serial.print("Ping: ");
Serial.print(uS / US_ROUNDTRIP_CM);
Serial.println("cm");
}
