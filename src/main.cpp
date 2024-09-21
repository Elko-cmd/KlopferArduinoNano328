#include <Arduino.h>
// Die AK47 hat eine Schussfrequenz von 600 Schuss pro Minute. Das sind 10 Schuss pro Sekunde. Also alle 50ms ein Schuss. Die MAgazinggröße der AK47 variiert zwischen 10, 20, 25, 30, 40 und 75, 100 Patronen.

// CONFIG START ###########################################################
//  Arduino Pins
int KloppferPin = 2;

// Magazin Kapazitaet
int magazinCap = 40; // 40 Patronen im Magazin
// MAgazinwechsel
unsigned int magazinWechsel = 5000; // Zeit in Millisekunden (1000 = 1 Sekunde)
// Schussfrequenz in Millisekunden (1000 = 1 Sekunde)
const int interval = 100; // 10 mal in der Sekunde
// Schusszähler
int schuss = 0; // aktuelle Schussanzahl
// Glockenkapazitaet
int glockenKapazitaet = 200; // 200 Patronen aus einer Glocke
int glockenKapazitaetCounter = 0;  // aktuelle Glockenkapazitaet
int glockenDelay = 100000; // 100 Sekunden (1000 = 1 Sekunde)
// CONFIG END ###########################################################

void setup()
{
    // put your setup code here, to run once:
    pinMode(KloppferPin, OUTPUT);
    Serial.begin(9600);
};

void loop()
{
    while (glockenKapazitaetCounter <= glockenKapazitaet) {
        if (schuss <= magazinCap) {
            digitalWrite(KloppferPin, HIGH);
            delay(interval);
            digitalWrite(KloppferPin, LOW);
            delay(50);
            schuss++;
            glockenKapazitaetCounter++;
        } else {
            schuss = 0;
            delay(magazinWechsel);
        }
        Serial.print("\t");
        Serial.print("Glocke: ");
        Serial.print(glockenKapazitaetCounter);
        Serial.print("\t");
        Serial.print("Schuss: ");
        Serial.println(schuss);
    }
    delay(glockenDelay);
    glockenKapazitaetCounter = 0;
    schuss = 0;
};
