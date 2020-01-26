/*
    KY031 Schok sensor
    
    Laat de ingebouwde led 13 flikkeren bij het detecteren van schokken.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Schok sensor KY031
    
*/

// constanten
const int led = 13;                        // interne led pin
const int schok = 10;                      // KY031 signaal pin

// variabelen
int waarde;                                // KY031 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(schok, INPUT);                   // schok sensor is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(schok);             // lees sensor
  if (waarde == LOW) {                     // bij trilling
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  }  
}
