/*
    KY004 Drukknop
    
    Laat de ingebouwde led 13 oplichten wanneer de drukknop ingedrukt wordt.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Drukknop KY004
    
*/

// constanten
const int led = 13;                        // interne led pin
const int drukknop = 10;                   // KY004 signaal pin

// variabelen
int waarde;                                // KY004 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(drukknop, INPUT);                // drukknop is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(drukknop);          // lees drukknop
  if (waarde == LOW) {                     // bij indrukken drukknop
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  }  
}
