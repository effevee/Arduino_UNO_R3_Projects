/*
    KY006 Passieve zoemer
    
    Maak een sirene die van laag naar hoog en terug naar laag gaat.
    
    Benodigdheden :
    - Arduino UNO, breadboard, jumper kabeltjes
    - Passieve zoemer KY006
    
*/

// constanten
const int zoemPin = 7;                   // KY006 signaal pin 
const int lengteNoot = 125;              // lengte van de noot (msec)
const int pauseNoot = 25;                // pause tussen de noten (msec)

// variabelen
int noot;                                // lus voor de noten

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(zoemPin, OUTPUT);              // zoemer is output
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  for (noot=25; noot<120; noot++) {      // laag naar hoog
    tone(zoemPin, 20*noot, lengteNoot);  // speel noot
    delay(pauseNoot);                    // pause noot
  }
  for (noot=120; noot>=25; noot--) {     // hoog naar laag
    tone(zoemPin, 20*noot, lengteNoot);  // speel noot
    delay(pauseNoot);                    // pause noot
  }
}
