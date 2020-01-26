/*
    KY025 Grote Reed schakelaar
    
    Laat de ingebouwde led 13 oplichten wanneer de Reed schakelaar gesloten is.
              
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Grote Reed schakelaar KY025
    - Magneetje
*/

// constanten
const int led = 13;                        // interne led pin
const int emdigitaal = 10;                 // KY025 digitale signaal pin
const int emanaloog = A5;                  // KY025 analoge signaal pin

// variabelen
int wrde_digitaal;                         // KY025 digitale sensorwaarde
int wrde_analoog;                          // KY025 analoge sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(emdigitaal, INPUT);              // Reed sensor is input
  pinMode(emanaloog, INPUT);               // Reed sensor is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  wrde_digitaal = digitalRead(emdigitaal); // lees sensor digitaal
  wrde_analoog = analogRead(emanaloog);    // lees sensor analoog
  if (wrde_digitaal == HIGH) {             // bij magnetisch veld
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  }
}
