

void setup() {
  Serial.begin(9600); //Ustawienie prędkości transmiji
  Serial.println("Witaj w kalulatorze"); //Jednorazowe wysłanie tekstu
}

void loop() {
  double wynik = 0; //Deklaracja wyniku
  int a = 0; // deklaracja pierwszej liczby
  int b = 0; //deklaracja drugiej liczby
  String odebraneDane = ""; //Pusty ciąg odebranych danych
  int pomocnicza = 0;
  
Serial.println("Wpisz 1 liczbę");

  
  
    
  while (a==0)
  {
    delay(500);
    a = Serial.parseInt();  //wpisanie 1 liczby 
  }

  delay(1000);
  
  Serial.println(a);
delay(1000);

  Serial.println("Wpisz 2 liczbę");

    
while (b==0)
{
  delay(500);
  b = Serial.parseInt();  //wpisanie 2 liczby
}

delay(1000);
Serial.println(b);

  
   
Serial.println("Wybierz rodzaj operacji:  + , - , * , /");

  while(odebraneDane == "")
  {
        delay(500);
        odebraneDane = Serial.readStringUntil('\n');
  
 }
 
        if (odebraneDane == "+")
        {
          wynik = a+b;
        }
        
        if (odebraneDane == "-")
        {
          wynik = a-b;
        }
        
        if (odebraneDane == "*")
        {
          wynik = a*b;
        }
        
        if (odebraneDane == "/")
        {
          wynik = a/b;
        }
       
   if(odebraneDane != "+" || odebraneDane != "-" || odebraneDane != "*" || odebraneDane != "/" )
   {
    Serial.println("Error");
    
   }
       
        
      
  
  Serial.println(wynik);

    
  }

    
  
    
  
