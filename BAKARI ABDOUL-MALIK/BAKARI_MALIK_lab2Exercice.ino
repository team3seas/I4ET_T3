byte invalue = 0;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(230400);
}

void loop() 
{
if (Serial.available() > 0)
{
  invalue = Serial.read();
  Serial.println(invalue);
if (invalue == 109)
  {
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("ON");  
 } 
 else if (invalue == 107)
  {
    digitalWrite(LED_BUILTIN,HIGH);
     Serial.println("OFF");    
  }
}
}