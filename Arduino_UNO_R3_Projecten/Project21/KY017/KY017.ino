/*
    KY017 Kwik schakelaar
    
    Laat de ingebouwde led 13 branden bij het sluiten van de schakelaar.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Kwik schakelaar KY017
    
*/

// constanten
const int led = 13;                        // interne led pin
const int switchPin = 8;                   // KY017 signaal pin

// variabelen
int waarde;                                // KY017 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(switchPin, INPUT);               // schakeaar is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(switchPin);         // lees sensor
  if (waarde == LOW) {                     // bij sluiten schakelaar
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  }  
}
