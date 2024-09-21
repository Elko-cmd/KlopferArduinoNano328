#include <Arduino.h>
// Die AK47 hat eine Schussfrequenz von 600 Schuss pro Minute. Das sind 10 Schuss pro Sekunde. Also alle 50ms ein Schuss. Die MAgazinggröße der AK47 variiert zwischen 10, 20, 25, 30, 40 und 75, 100 Patronen.

//CONFIG START ###########################################################
// Arduino Pins
  int KloppferPin = 2;

// Magazin Kapazitaet
  int magazinCap = 40;
//MAgazinwechsel Zeit in Millisekunden (1000 = 1 Sekunde)
 unsigned int magazinWechsel = 5000;
//Schussfrequenz in Millisekunden (1000 = 1 Sekunde)
  const int interval = 100; // 10 mal in der Sekunde
//Schusszähler
  int schuss = 0;
//CONFIG END ###########################################################

void setup() {
  // put your setup code here, to run once:
  pinMode(KloppferPin, OUTPUT);
};

void loop() {

if(schuss <= magazinCap){
  digitalWrite(KloppferPin, HIGH);
  delay(interval);
  digitalWrite(KloppferPin, LOW);
  delay(20);
  schuss++;
}else{
  schuss = 0;
  delay(magazinWechsel);
}
}

