char receivedByte = 0;
int GREENPIN = D3;
int REDPIN = D2;
int BLUEPIN = D1;


int val;
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0)
{
  receivedByte = Serial.read();
  Serial.println(receivedByte);
  if (receivedByte == 'R' || receivedByte == 'r')
  {
    analogWrite(REDPIN, 255);
    analogWrite(GREENPIN, 0);
    analogWrite(BLUEPIN, 0);

  }
   else if (receivedByte == 'G' || receivedByte == 'g')
  {
    analogWrite(REDPIN, 0);
    analogWrite(GREENPIN, 255);
    analogWrite(BLUEPIN, 0);

  }
   else if (receivedByte == 'B' || receivedByte == 'b')
  {
    analogWrite(REDPIN, 0);
    analogWrite(GREENPIN, 0);
    analogWrite(BLUEPIN, 255);

  }
}
}
