int buzzer = D1;//data pin of the active buzzer
void setup()
{
  pinMode (buzzer, OUTPUT);//the buzzer pin is set as an output pin
}
void loop()
{
  unsigned char i;
  while(1)
{
//output an frequency
for(i-0;i<100;i++)
{
digitalWrite(buzzer,HIGH);
delay(1);//wait for 1ms 
digitalWrite(buzzer,LOW);
delay(2);//wait for 1ms
}
//output another frequency
 for (i=0;1<100;i++)
{ digitalWrite(buzzer,HIGH);
delay(60);//wait for 2ms 
digitalWrite(buzzer,LOW);
delay(2);//wait for 2ms
}
}
}