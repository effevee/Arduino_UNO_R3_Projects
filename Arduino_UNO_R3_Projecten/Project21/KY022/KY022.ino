/*
    KY022 Infrarode ontvanger
    
    Test de IR ontvanger module met een IR afstandsbediening en 
    toon de resultaten in de seriële console.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Infrarode ontvanger KY022
    - Infrarode afstandsbediening
*/

#include <IRremoteInt.h>
#include <IRremote.h>

// constanten
const int irPin = 10;                       // KY022 signaal pin

// declaratie objecten
IRrecv IRontvanger(irPin);                  // KY022 IR ontvanger
decode_results resultaten;                  // gedecodeerde resultaten

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(irPin, INPUT);                    // IR ontvanger is input
  IRontvanger.enableIRIn();                 // IR ontvanger starten
  Serial.begin(9600);                       // seriële console initialiseren
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  if (IRontvanger.decode(&resultaten)) {    // zijn er signalen ?
    Serial.println (resultaten.value, HEX); // toon ze 
    IRontvanger.resume();                   // ontvang volgende
  }
}
