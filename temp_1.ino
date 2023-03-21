#include<Servo.h>
int pin_temp = A5;
int pin_servo = 4;

Servo myPin;
void setup()
{
  myPin.attach(pin_servo);
  Serial.begin(9600);
  myPin.write(0);
  }

void loop()
{
  int analog_value = analogRead(pin_temp);
  float temp = (((analog_value*5.0)/1024.0)-0.5)*100;
  Serial.println(temp);
  if(temp >= 30)
  {
    myPin.write(90);
  }
  else
  {
    myPin.write(0);
  }
  delay(50);
}
  
