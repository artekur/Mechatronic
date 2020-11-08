int licznik=0;  //zmienna globalna licząca włączenie programu
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
  digitalWrite(6, LOW);//silnik wyłączony
 while (digitalRead(7) == LOW)    //Włączenie programu
 {
  delay(300);       //redukcja drgań
  digitalWrite(6, HIGH);    //włączenie silnika
  licznik = licznik++;      //zwiększenie licznika
  Serial.println(licznik);  //wyświetlenie licznika

  while (digitalRead(8) == LOW)     //włączenie obrotów w lewo
  {
    if (digitalRead(8)== LOW && digitalRead(9)== LOW) // zabezpieczenie przed jednoczesnym wciśnieciem obu przycisków
  {
    digitalWrite(6, LOW);   //wyłączenie zasilania silnika
  }
    delay(300);     //redukcja drgan przycisku
    digitalWrite(10, LOW); //Silnik obroty w lewo
    digitalWrite(11, HIGH);
  }
  while (digitalRead(9) == LOW)  //włączenie obrotów w prawo
  {
    if (digitalRead(8)== LOW && digitalRead(9)== LOW) // zabezpieczenie przed jednoczesnym wciśnieciem obu przycisków
  {
    digitalWrite(6, LOW);   //wyłączenie zasilania silnika
  }
    delay(300);   //redukcja drgan przycisku
    digitalWrite(10, HIGH); //Silnik obroty w lewo
    digitalWrite(11, LOW);
  }
  
  
}
}
