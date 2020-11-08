#include <Servo.h>
#include <math.h>

int servoPin = 3;
int Distance = 0;
double BaseDistance = 150;
double CurrentDistance;
double ArmLenght = 5;
double Angle;
double P = 10;
double time;
Servo servo;

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
 servo.attach(servoPin);
 servo.write(0);
}

void loop() {
  
 CurrentDistance = readUltrasonicDistance(7, 7) - BaseDistance;
  Distance = int(CurrentDistance / 10) * P;
  Angle = atan(Distance/ArmLenght)*(180/3.14);
  //Serial.println(Distance);
  Serial.println(Angle);
 servo.write(P*Angle); 
}