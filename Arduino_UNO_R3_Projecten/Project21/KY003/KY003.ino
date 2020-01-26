/*
    KY003 Hall magnetisch veld sensor
    
    Laat de ingebouwde led 13 flikkeren bij het detecteren van een magnetisch veld.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Hall magnetisch veld sensor KY003
    - Magneetje
    
*/

// constanten
const int led = 13;                        // interne led pin
const int emveld = 10;                     // KY003 signaal pin

// variabelen
int waarde;                                // KY003 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(emveld, INPUT);                  // Hall sensor is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(emveld);            // lees sensor
  if (waarde == LOW) {                     // bij magnetisch veld
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  }  
}
