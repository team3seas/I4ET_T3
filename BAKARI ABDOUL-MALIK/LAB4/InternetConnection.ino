#include <ESP8266WiFi.h>
// WiFi network parameters
const char* ssid = "Malik BOSS";
const char* password = "00000001";
const char* host = "dweet.io";
WiFiClient client;
const int httpPort = 80;
void setup() {
// Start serial
Serial.begin(115200);
//a small delay is added to initialize the :
delay (10);
// Connecting to a WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{delay(500);
Serial.print(" .");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi. localIP());
}
void loop() 
{
//a 5 sec delay is added for Wifi initialization and avoi delay (5000);
Serial.print("connecting to ");
Serial.println(host);
// A connection to the website is openned
if (!client.connect(host, httpPort))
{
Serial.printIn("connection failed");
return;
}
// The specific URL is indicated and the connection reque
String url = "/dweet/for/my-thing-name?value=test";
Serial.print("Requesting URL: ");
Serial.println(url);
client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Ho
/ We wait 5 sec for the server response
unsigned long timeout = millis );
while (client.available == 0) {
if (millis) - timeout > 5000) {
Serial.printIn(">>> Client Timeout !"); client.stop;
return;
}
}
while(client.available()){ // The server response is pr
String line = client.readStringUntil("\r");
Serial.print(line);
}
Serial.println);
Serial.printIn("closing connection");
}