/*
    KY018 LDR sensor
    
    Laat de ingebouwde led 13 sneller knipperen naarmate het donkerder wordt.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - LDR sensor KY018
    
*/

// constanten
const int led = 13;                        // interne led pin
const int sensorPin = A5;                  // KY018 signaal pin

// variabelen
int waarde;                                // KY018 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(sensorPin, INPUT);               // licht sensor is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = analogRead(sensorPin);          // lees sensor
  digitalWrite(led, HIGH);                 // led aanzetten
  delay(1024-waarde);                      // wachten
  digitalWrite(led, LOW);                  // led afzetten  
  delay(1024-waarde);                      // wachten
}
