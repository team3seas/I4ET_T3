byte receivedByte = 0;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(230400);
}

void loop() {
if (Serial.available() > 0)
{
  receivedByte = Serial.read();
  Serial.println(receivedByte);
  if (receivedByte == 77 || receivedByte == 109)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (receivedByte == 98 || receivedByte == 66)
  {
    digitalWrite(LED_BUILTIN, HIGH); 
  }
}
}
