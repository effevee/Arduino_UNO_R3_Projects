/*
    KY002 Trilling sensor
    
    Laat de ingebouwde led 13 flikkeren bij het detecteren van trillingen.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Trilling sensor KY002
    
*/

// constanten
const int led = 13;                        // interne led pin
const int trilling = 10;                   // KY002 signaal pin

// variabelen
int waarde;                                // KY002 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(trilling, INPUT);                // trilling sensor is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(trilling);          // lees sensor
  if (waarde == LOW) {                     // bij trilling
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  }  
}
