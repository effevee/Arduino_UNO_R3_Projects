/*
    KY005 Infrarode zender
    
    Zet je tv uit met de IR zender.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Infrarode zender KY005
    - TV
*/

#include <IRremoteInt.h>
#include <IRremote.h>

// declaratie objecten
IRsend IRzender;                            // KY005 IR zender

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  for (int i = 0; i <50; i++) {
    IRzender.sendSony (0xa90, 12);          // Sony TV power code
    delay (40);                             // even wachten
  }
}
