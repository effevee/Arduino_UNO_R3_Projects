/*
    KY026 Vlammen sensor
    
    Laat de ingebouwde led 13 oplichten wanneer een vlam gedetecteerd wordt.
    Experimenteer met de potentiometer om de gevoeiligheid aan te passen.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Vlammen sensor KY026
    - Aansteker
*/

// constanten
const int led = 13;                        // interne led pin
const int vlamPin = 8;                     // KY026 signaal pin

// variabelen
int waarde;                                // KY026 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(vlamPin, INPUT);                 // vlammen sensor is input
  Serial.begin(9600);                      // seriële console initialiseren
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(vlamPin);           // lees sensor
  if (waarde == LOW) {                     // vlam gedetecteerd
    digitalWrite(led, HIGH);               // led aanzetten
    Serial.println("GEVAAR VLAM!");        // toon in console
  } else {                                 // anders   
    digitalWrite(led, LOW);                // led afzetten  
    Serial.println("Alles OK");            // toon in console
  }
  delay(1000);                             // even wachten
}
