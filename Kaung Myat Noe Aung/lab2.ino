char input; // keyboard input

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // built in led
  Serial.begin(9600); // 
  }

void loop() {
  if (Serial.available() > 0) 
  { 
    input = Serial.read(); // read input
    if (input == 'k' or input == 'K') 
    { // if 'k'
      digitalWrite(LED_BUILTIN, LOW); // LED on
      Serial.println(input);
    }
    else if (input == 'm'or input== 'M') 
    { // if 'm'
      digitalWrite(LED_BUILTIN, HIGH); // LED off
      Serial.println(input);
    }
  }
}
