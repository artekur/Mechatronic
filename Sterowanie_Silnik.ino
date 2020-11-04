void setup() 
{
  pinMode(6, OUTPUT); //Sygnał PWM silnika 
  pinMode(7,INPUT_PULLUP); 
  pinMode(8,INPUT_PULLUP); 
  pinMode(9,INPUT_PULLUP); 

  pinMode(10, OUTPUT); //Sygnaly sterujace kierunkiem obrotów silnika 
  pinMode(11, OUTPUT);
  
}

void loop() {
  int licznik=0;
 if (digitalRead(7) == LOW)
 {
  delay(500);
  digitalWrite(6, HIGH);
  licznik = licznik++;
  Serial.println(licznik);
if (digitalRead(8)== LOW && digitalRead(9)== LOW)
  {
    digitalWrite(6, LOW);
  }
  if (digitalRead(8) == LOW)
  {
    delay(500);
    digitalWrite(10, LOW); //Silnik obroty w lewo
    digitalWrite(11, HIGH);
  }
  if (digitalRead(9) == LOW)
  {
    delay(500);
    digitalWrite(10, HIGH); //Silnik obroty w lewo
    digitalWrite(11, LOW);
  }
  
  
}
}
