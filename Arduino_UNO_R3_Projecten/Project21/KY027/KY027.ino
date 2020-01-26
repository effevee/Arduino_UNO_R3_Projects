/*
    KY027 Magische led cup module
    
    Laat de led op de module flikkeren naargelang de stand van de kwik tilt schakelaar.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Magische led cup module KY027
*/

// constanten
const int swPin = 8;                       // KY027 signaal pin
const int ledPin = 9;                      // KY027 led pin

// variabelen
int waarde;                                // KY027 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(swPin, INPUT);                   // switch is input
  pinMode(ledPin, OUTPUT);                 // led is output
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(swPin);             // lees sensor
  if (waarde == LOW) {                     // bij schakeling
    digitalWrite(ledPin, HIGH);            // led aanzetten
  } else {                                 // anders
    digitalWrite(ledPin, LOW);             // led afzetten  
  }  
}
