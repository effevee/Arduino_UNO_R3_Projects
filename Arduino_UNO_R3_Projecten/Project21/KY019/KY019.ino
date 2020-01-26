/*
    KY019 Relais
    
    Laat de ingebouwde led 13 knipperen wanneer het relais schakelt.
    Test het NO en NC contact van het relais met een multimeter.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Relais KY019
    - Multimeter
    
*/

// constanten
const int led = 13;                        // interne led pin
const int relaisPin = 10;                  // KY019 signaal pin

// variabelen
int waarde;                                // KY019 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(relaisPin, OUTPUT);              // relais pin is output
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  digitalWrite(led, HIGH);                 // led aanzetten
  digitalWrite(relaisPin, HIGH);           // relais aanzetten
  delay(2000);                             // wacht 2 seconden
  digitalWrite(led, LOW);                  // led afzetten
  digitalWrite(relaisPin, LOW);            // relais afzetten
  delay(2000);                             // wacht 2 seconden
}
