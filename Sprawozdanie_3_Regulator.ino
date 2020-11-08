int Distance = 0;
double BaseDistance = 150;
double CurrentDistance;
double KP = 2;
double time;
double error=0;
double signal;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
 pinMode(triggerPin, OUTPUT); //Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); //Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  //Reads the echo pin, and returns the sound wave travel in microseconds
  time = pulseIn(echoPin, HIGH);
  return 0.01723 *time; //stała podana od producenta; zwraca odleglsc w cm 
}

void setup() {
 Serial.begin(9600);
 pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  
 CurrentDistance = readUltrasonicDistance(7, 7);
  error = BaseDistance - CurrentDistance;
  signal = error*KP;
  Serial.println(CurrentDistance);
  
  if (signal > 255)
  {
    signal = 255;
  }
  else if (signal < -255)
  {
    signal = -255;
  }
  
  if (signal >= 0)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
  if (signal <0)
  {
    signal = abs(signal);
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  }
  
  analogWrite(6,signal);
  
}