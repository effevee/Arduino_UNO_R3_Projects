/*
    Sirene
    
    Maak een sirene die 4 maal van laag naar hoog en terug naar laag gaat.
    
*/

// constanten
const int passieveZoemPin = 7;           // de pin waar de positieve pin van de zoemer is aangesloten
const int lengteNoot = 1000/8;           // lengte van de noot (msec)
const int pauseNoot = lengteNoot * 0.2;  // pause tussen de noten (msec)

// variabelen
int aantalLoops = 0;                     // aantal loops voor de sirene
int noot = 0;                            // lus voor de noten

void setup() {
  // de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
  // wanneer op de reset knop gedrukt wordt

  // de sirene gaat 4 maal op en af
  for (aantalLoops = 0; aantalLoops < 4; aantalLoops++) {
    // speel de noten van laag naar hoog
    for (noot = 25; noot < 120; noot++) {
      // speel de noot
      tone(passieveZoemPin, 20 * noot, lengteNoot);
      // pauze voor volgende noot
      delay(pauseNoot);
    }
  
    // speel de noten van hoog naar laag
    for (noot = 120; noot >= 25; noot--) {
      // speel de noot
      tone(passieveZoemPin, 20 * noot, lengteNoot);
      // pauze voor de volgende noot
      delay(pauseNoot);
    }
  }  
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {

}
