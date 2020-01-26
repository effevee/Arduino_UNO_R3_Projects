/*
  LEDs met drukknop
  
  Gebruik een drukknop om afwisselend de rode en de groene LED aan en uit te laten gaan. Bij een
  eerst druk gaat de groene led aan en de rode uit. Bij een volgende druk gaat de groene led uit en de
  rode led aan.
  
*/

// constanten
const int ledRoodPin = 13;                  // de digitale poort die de rode LED aanstuurt
const int ledGroenPin = 12;                 // de digitale poort die de groene LED aanstuurt
const int switchPin = 2;                    // de digitale poort voor de status van de drukknop

// variabelen
int switchStatus = 0;                       // houdt de status van de drukknop bij
boolean groeneLedAan = false;               // houdt bij als de groene LED aan is

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {

  // initialiseer digitale poorten voor de LEDs als output.
  pinMode(ledRoodPin, OUTPUT);
  pinMode(ledGroenPin, OUTPUT);
  
  // initialiseer de digitale poort voor de drukknop als input.
  pinMode(switchPin, INPUT);
  
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  
  // lees de status van de drukkop
  switchStatus = digitalRead(switchPin);
  
  // is de drukknop ingedrukt ?
  if (switchStatus == HIGH) {
    // drukknop is ingedrukt - we controleren welke LED aan/uit moet
    if (groeneLedAan == true) {
      // groen is aan -> we zetten groen af en rood aan
      digitalWrite(ledGroenPin, LOW);
      digitalWrite(ledRoodPin, HIGH);
    }
    else {
      // groen is af -> we zetten rood af en groen aan
      digitalWrite(ledRoodPin, LOW);
      digitalWrite(ledGroenPin, HIGH);
    }

    // status van groene led bijwerken (status omkeren)
    groeneLedAan = not groeneLedAan;
   
    // kleine vertraging inbouwen
    delay(250);
  }  
}
