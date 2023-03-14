#include "DHT.h"
#define DHTTYPE DHT11

#define dht_dpin D1

DHT dht(dht_dpin, DHTTYPE);

void setup()
{
  dht.begin();
  Serial.begin(9600);
  delay(100);
  Serial.println("Initializing ESP8255...");
}

void loop()
{
  delay(3000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Current Humdity = ");
  Serial.print(h);
  Serial.print("% ");
  Serial.print("Tempaerature = ");
  Serial.print(t);
  Serial.println("C ");
if (t > 27 && h > 60) {
  Serial.println("AC + FAN");
}
else if (t < 18 && h < 40) {
  Serial.println("HEATER");
}
else if (t > 27 && h < 40) {
  Serial.println("AC");
}
else if (t < 18 && h > 60) {
  Serial.println("Heater + Fan");
}
else if (h>60) {
  Serial.println("FAN");
}
else if (t>26){
  Serial.println("AC");
}
else if (t<17){
  Serial.println("Heater");
}
}
