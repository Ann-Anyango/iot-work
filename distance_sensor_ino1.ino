int trigger = 5;
int echo = 6;
int led = 4;
int led2 = 3; 

long duration = 0;
int cm = 0;
int inch = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
   pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
 // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{ 
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  cm = duration*0.034/2;
  inch = duration*0.0133/2;

  if (cm < 100){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
    if (cm > 100){
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }

  if (cm < 100 ) {
    Serial.print("Cm: ");
    Serial.println(cm);
  }
  delay(500);
}



  
 