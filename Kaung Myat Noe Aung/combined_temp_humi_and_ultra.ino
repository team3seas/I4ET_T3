#include "DHT.h"
#define DHTTYPE DHT11

#define dht_dpin D1

DHT dht(dht_dpin, DHTTYPE);

#include <NewPingESP8266.h>

#define TRIGGER_PIN D2
#define ECHO_PIN D3
#define MAX_DISTANCE 200

NewPingESP8266 sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
char input;
bool measure = false;

void setup()
{
  dht.begin();
  Serial.begin(9600);
  delay(100);
  Serial.println("Initializing ESP8255...");
}

void loop()
{
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
    if (distance <= 40) {
      Serial.println(distance);
      Serial.println("Person detected");
      delay(3000); // Wait for 3 seconds for DHT sensor readings
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      Serial.print("Current Humidity = ");
      Serial.print(h);
      Serial.print("% ");
      Serial.print("Temperature = ");
      Serial.print(t);
      Serial.println("C ");

      if (t > 27 && h > 60) {
        Serial.println("AC + FAN");
        // Control AC and FAN
      }
      else if (t < 18 && h < 40) {
        Serial.println("HEATER");
        // Control Heater
      }
      else if (t > 27 && h < 40) {
        Serial.println("AC");
      }
      else if (t < 18 && h > 60) {
        Serial.println("Heater + Fan");
      }
      else {
        Serial.println("Conditions are optimal");
    }
    }
    else if (distance>40){
      Serial.println(distance);
      Serial.println("nothing detected");
      delay(3000);
    }
  }
}
