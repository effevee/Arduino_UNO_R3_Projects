/*
  Ping pong LEDs
  
  Laat een rode en groene LED afwisselend aan en uit gaan gedurende 1 seconde.
  
*/

// constanten
const int ledRoodPin = 8;  // de digitale poort die de rode LED aanstuurt
const int ledGroenPin = 7;  // de digitale poort die de groene LED aanstuurt

// variabelen


// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // initialiseer digitale poorten als output.
  pinMode(ledRoodPin, OUTPUT);
  pinMode(ledGroenPin, OUTPUT);
  
  // zet beide LEDs af
  digitalWrite(ledRoodPin, LOW);  
  digitalWrite(ledGroenPin, LOW);
}


// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  
  // zet de rode LED poort hoog
  digitalWrite(ledRoodPin, HIGH);
 
  // wacht 1 sec  
  delay(1000);
  
  // zet de rode LED poort laag
  digitalWrite(ledRoodPin, LOW);
  
  // zet de groene LED poort hoog
  digitalWrite(ledGroenPin, HIGH);
  
  // wacht 1 sec
  delay(1000);
  
  // zet de groene LED poort laag
  digitalWrite(ledGroenPin, LOW);
}
