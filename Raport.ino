#include <Servo.h>            //dolaczenie biblioteki obslugujacej serwomechanizmy
#include <LiquidCrystal_I2C.h>//dolaczenie bibilioteki obslugujacej wyswietlacz

#define trigPin 10
#define echoPin 11
Servo serwo_test; // definiowanie serwomechanizmu
LiquidCrystal_I2C lcd(0x27,16,2); //adres magistrali wyswietlacza

void setup() {
  pinMode(7,INPUT_PULLUP);    //przypisanie przycisku do pinu 7
  pinMode(8,OUTPUT);          //przypisanie diody do pinu 8
  pinMode(10,OUTPUT);         //podlaczenie pinu trig jako wyjscie
  pinMode(11,INPUT);          //podlaczenie pinu echo jako wejscie
  serwo_test.attach(9);       //przypisanie serwomechanizmu do pinu 9

  lcd.init();                 //inicjalizacja wyswietlacza
  lcd.backlight();            //zalaczenie podswietlenia
  lcd.print("Hello world");   //wyswietlenie tekstu
}

void loop() {
  if(digitalRead(7)==LOW)      //gdy przycisk zostanie wcisniety serwomechanizm obroci sie o -90 stopni
  {
    serwo_test.write(-90);
    lcd.print("obrot");       //wyswietli sie tekst na wyswietlaczu
  }else                       //gdy przycisk zostanie puszczony serwomechanizm obroci sie o 90 stopni
    {
      serwo_test.write(90);
      lcd.print("powrot");    //wyswietli sie tekst na wyswietlaczu
      }
  lcd.clear();
  lcd.print(odleglosc());     //wywolanie funkcji odleglosc i wyswietlenie jej na wyswietlaczu
  lcd.print(" cm");
  
}
int odleglosc()
  {                         //utworzenie funkcji odleglosc do pomiaru 
    long czas, dystans;
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    czas = pulseIn(echoPin,HIGH); //zmierzenie czasu trwania impulsu podanego na wejscie echoPin
    dystans = czas /58;           //podzielenie otrzymanego wyniku alby wynik byl w cm

    return dystans;
    }
