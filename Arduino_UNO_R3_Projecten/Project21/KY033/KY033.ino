/*
    KY033 Lijn volgende sensor
    
    Laat de ingebouwde led 13 trager flikkeren bij het detecteren van een zwarte lijn.
    Experimenteer met de potentiometer om de gevoeligheid van de detectie te varieren.
    Toon de resultaten in de seriële monitor.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Lijn volgende sensor KY033
*/

// constanten
const int led = 13;                        // interne led pin
const int lijn = A5;                       // KY033 signaal pin

// variabelen
int waarde;                                // KY033 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(lijn, INPUT);                    // sensor is input
  Serial.begin(9600);                      // seriële console initialiseren 
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = analogRead(lijn);               // lees sensor
  digitalWrite(led, HIGH);                 // led aanzetten
  delay(waarde);                           // wachten
  digitalWrite(led, LOW);                  // led afzetten  
  delay(waarde);                           // wachten 
  Serial.print("Sensorwaarde: ");          // toon
  Serial.print(waarde);                    // sensorwaarde
  if (waarde > 500) {                  
    Serial.println("\tZWART");             // zwart
  } else {
    Serial.println("\tWIT");               // wit
  }    
}
