char receivedByte = 0;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(230400);
}

void loop() {
if (Serial.available() > 0)
{
  receivedByte = Serial.read();
  Serial.println(receivedByte);
  if (receivedByte == 'M' || receivedByte == 'm')
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (receivedByte == 'B' || receivedByte == 'b')
  {
    digitalWrite(LED_BUILTIN, HIGH); 
  }
}
}
