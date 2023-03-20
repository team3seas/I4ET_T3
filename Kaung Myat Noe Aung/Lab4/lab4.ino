#include <ESP8266WiFi.h>
// WiFi network parameters 
const char* ssid = "Sentry";
const char* password = "kaung123";

const char* host = "postman-echo.com";//Host to connect to and Wifi client parameters
WiFiClient client;
const int httpPort = 80;

void setup() {
  Serial.begin(115200); // Start serial
  delay(10);//a small delay is added to initialize the serial port
  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); 
    while (WiFi.status() != WL_CONNECTED) {
      delay (500);
      Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi. localIP());
}

void loop() {
  delay (5000); //a 5 sec delay is added for Wifi initialization and avoid continuous loop requests
  Serial.print("connecting to ");
  Serial.println(host);

  if (!client.connect(host, httpPort))// A connection to the website is openned 
  {
    Serial.println("connection failed");
    return;
  }

  // The specific URL is indicated and the connection request is sent
  String url = "/get";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

  unsigned long timeout = millis();  // We wait 5 sec for the server response 
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !"); 
      client.stop();
      return;
    }
  }

while(client.available()){ // The server response is processed
  String line = client.readStringUntil('\r');
  Serial.print(line);
}

Serial.println();
Serial.println("closing connection");

}