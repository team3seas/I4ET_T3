#include <OneWire.h> //temperature sensor
#include <DallasTemperature.h> //temperature sensor
#define ONE_WIRE_BUS D3 //temperature sensor
OneWire oneWire(ONE_WIRE_BUS); //temperature sensor
DallasTemperature sensors(&oneWire); //temperature sensor
//---------------------------------------------------
#include <NewPingESP8266.h> //ultrasound
#define TRIGGER_PIN D6 //ultrasound
#define ECHO_PIN D5 //ultrasound
#define MAX_DISTANCE 200 //ultrasound
NewPingESP8266 sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //ultrasound
//----------------------------------------------------
int CO2_pin = A0; //CO2
float CO2_value; //CO2
//---------------------------------------------------
#include "DHT.h" //humidity sensor
#define DHTTYPE DHT11 //humidity sensor
#define dht_dpin D1 //humidity sensor
DHT dht(dht_dpin, DHTTYPE); //humidity sensor
//--------------------------------------------------
#include <dweetESP8266.h> //dweet
#define THIG_NAME "test1" //dweet
const char* ssid = "Sentry"; //dweet
const char* password = "kaung123"; //dweet
dweet DweetClient; //dweet
//----------------------------------------------------
char *key0 = "CO2";
char *key1 = "Humidity";
char *key2 = "Temperature";
char *key3 = "Temp";
char *key5 = "Distance";
char val0[16];
char val1[16];
char val2[16];
char val3[16];
char val5[16];
//------------------------------------------------------
void setup() {
// Initialize serial communication at 9600 bits per second
sensors.begin(); //temperature sensor
dht.begin(); //humidity
// Serial.println("Starting all sensors...");
Serial.begin(9600);
delay(10);
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("Wifi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}

//---------------------------------------------------------
void loop()
{
float co2_a = analogRead(CO2_pin);
float humidity_b = dht.readHumidity();
float temperature_c = dht.readTemperature();
sensors.requestTemperatures();
float temp_d = sensors.getTempCByIndex(0);
unsigned int uS = sonar.ping();
float sonar_e = uS / US_ROUNDTRIP_CM;
//------------------------------------------------------------- 
String co2 = String (co2_a,2);
co2.toCharArray(val0,16);
Serial.println(val0);
DweetClient.add(key0, val0);
//---------------------------------------------------------
String humidity = String (humidity_b,2);
humidity.toCharArray(val1,16);
Serial.println(val1);
DweetClient.add(key1, val1);
//----------------------------------------------------------
String temperature = String (temperature_c,2);
temperature.toCharArray(val2,16);
Serial.println(val2);
DweetClient.add(key2, val2);
//------------------------------------------------------------
String temp = String (temp_d,2);
temp.toCharArray(val3,16);
Serial.println(val3);
DweetClient.add(key3, val3);
//-------------------------------------------------------------
String sonar = String (sonar_e,2);
sonar.toCharArray(val5,16);
Serial.println(val5);
DweetClient.add(key5, val5);
//------------------------------------------------------------
DweetClient.sendAll(THIG_NAME);
delay(5000);
}