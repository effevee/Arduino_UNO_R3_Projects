/*

  Infrarode afstandsbediening

  Gebruik de VS 1838B infrarode (IR) sensor om drie leds aan en uit te zetten met de UNO. 
  Gebruik hiervoor de toetsen 1, 2 en 3 van de afstandsbediening. 
  Met toets 4 schakelen we alle leds terug uit.
  
*/

#include <IRremoteInt.h>
#include <IRremote.h>

// constanten
const int IRPin = 2;                          // pin van de IR sensor 
const int LedRPin = 10;                       // pin voor de rode led
const int LedGPin = 9;                        // pin voor de groene led
const int LedBPin = 8;                        // pin voor de blauwe led

// variabelen
boolean Rood = false;                         // status rode led
boolean Groen = false;                        // status groene led
boolean Blauw = false;                        // status blauwe led

// declaratie objecten
IRrecv IRontvanger(IRPin);                    // IR ontvanger object
decode_results resultaten;                    // vertaalde IR kodes

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // de pinnen initialiseren
  pinMode(IRPin, INPUT);
  pinMode(LedRPin, OUTPUT);
  pinMode(LedGPin, OUTPUT);
  pinMode(LedBPin, OUTPUT);
  
  // de leds uitzetten
  digitalWrite(LedRPin, LOW);
  digitalWrite(LedGPin, LOW);
  digitalWrite(LedBPin, LOW);
  
  // de serële monitor initialiseren
  Serial.begin(9600);
  Serial.print("IR HEX data");
  Serial.println("\tIR vertaalde data");
  
  // start de IR ontvanger
  IRontvanger.enableIRIn();
}
 
// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  if (IRontvanger.decode(&resultaten)) {     // IR signaal ontvangen
    Serial.print(resultaten.value, HEX);     // toon de rauwe data in de seriële monitor
    IRdispatcher();                          // IR dispatcher 
    IRontvanger.resume();                    // haal volgende data op 
  }
}

// dispatcher functie die acties doet bij bepaalde IR codes/toetsen
void IRdispatcher() {

  switch(resultaten.value) {

    case 0xFF30CF:  
      Serial.println("\ttoets 1 - ROOD aan/uit");
      if (Rood) {
        digitalWrite(LedRPin, LOW);          // rood af
      } else {
        digitalWrite(LedRPin, HIGH);         // rood aan
      }  
      Rood = !Rood;                          // status rood omkeren
      break;
      
    case 0xFF18E7:  
      Serial.println("\ttoets 2 - GROEN aan/uit"); 
      if (Groen) {
        digitalWrite(LedGPin, LOW);          // groen af
      } else {
        digitalWrite(LedGPin, HIGH);         // groen aan
      }  
      Groen = !Groen;                        // status groen omkeren
      break;
      
    case 0xFF7A85:  
      Serial.println("\ttoets 3 - BLAUW aan/uit"); 
      if (Blauw) {
        digitalWrite(LedBPin, LOW);          // blauw af
      } else {
        digitalWrite(LedBPin, HIGH);         // blauw aan
      }  
      Blauw = !Blauw;                        // status blauw omkeren
      break;

    case 0xFF10EF:  
      Serial.println("\ttoets 4 - ALLES uit"); 
      digitalWrite(LedRPin, LOW);            // rood af
      digitalWrite(LedGPin, LOW);            // groen af
      digitalWrite(LedBPin, LOW);            // blauw af
      Rood = false;                          // status rood
      Groen = false;                         // status groen
      Blauw = false;                         // status blauw
      break;

    default: 
      Serial.println("\tandere toets");
  }
}  
      



