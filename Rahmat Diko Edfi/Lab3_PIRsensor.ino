int ledPin = LED_BUILTIN;
int inputPin = D1;
int pirState = LOW;
int val = 0;
void setup ()
{
pinMode(ledPin, OUTPUT);
pinMode(inputPin, INPUT);
Serial. begin (9600);
}
void loop()
{
val = digitalRead(inputPin); 
delay(500);
// read input value
if (val == HIGH) {
// check if the input is HIGH
Serial.println(val);
digitalWrite(ledPin, HIGH); // turn LED ON
Serial.println("Motion detected!");
pirState = HIGH;
} else 
{
digitalWrite(ledPin, LOW); Serial.println(val);// turn LED OFF
Serial.println("Motion ended!");
pirState = LOW;
}

}
