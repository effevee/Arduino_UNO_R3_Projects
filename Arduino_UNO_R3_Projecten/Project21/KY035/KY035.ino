/*
    KY035 Analoge Hall sensor
    
    Laat de ingebouwde led 13 sneller flikkeren bij detectie van een magnetisch veld en
    toon de analoge Hall sensorwaarde in de seriële monitor.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Analoge Hall sensor KY035
    - Magneetje
*/

// constanten
const int led = 13;                        // interne led pin
const int emveld = A5;                     // KY035 Hall signaal pin

// variabelen
int waarde;                                // KY035 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(emveld, INPUT);                  // Hall sensor is input
  Serial.begin(9600);                      // seriële console initialiseren
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = analogRead(emveld);             // lees sensor
  digitalWrite(led, HIGH);                 // led aanzetten
  delay(waarde);                           // wacht waarde msec
  digitalWrite(led, LOW)  ;                // led afzetten  
  delay(waarde);                           // wacht waarde msec
  Serial.print("Sensorwaarde: ");          // toon
  Serial.println(waarde, DEC);             // sensorwaarde  
}
