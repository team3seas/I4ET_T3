#include <ESP8266WiFi.h>
// WiFi network parameters
const char* ssid = "Malik BOSS";
const char* password = "00000001";
const char* host = "postman-echo.com";
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
  // put your main code here, to run repeatedly:
  delay(5000);
  Serial.print("connecting to ");
  Serial.println(host);

  //a connection to the website is open
  if(!client.connect(host, httpPort))
{
  Serial.println("connection failed");
  return;
}
//the specific url is indicated and the connection request is sent
String url="/get";
Serial.print("Requesting URL: ");
Serial.println(url);
client.print(String("GET ") + url + "HTTP/1.1\r\n"+"Host: "+ host + "\r\n" + "Connection: close\r\n\r\n");

//we wait 5sec for the server response
unsigned long timeout = millis();
while (client.available() == 0) {
  if (millis()-timeout > 5000) {
    Serial.println(">>> Client Timeout !");
    client.stop();
    return;
  }
}
while(client.available()){ // the server response is processed
String line=client.readStringUntil('\r');
Serial.print(line);
}
Serial.println();
Serial.println("closing connection");
}