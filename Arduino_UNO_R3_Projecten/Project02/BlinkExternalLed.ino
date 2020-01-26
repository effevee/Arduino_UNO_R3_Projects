/*
  Knipperende LED
  
  Laat een externe LED knipperen met een frequentie van 2 maal per seconde
  
*/

// constanten
const int ledPin = 8;  // de digitale poort die de LED aanstuurt

// variabelen


// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // initialiseer digitale poort als output.
  pinMode(ledPin, OUTPUT);
}


// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  
  // zet de LED poort hoog (3.3V) zodat de LED brandt
  digitalWrite(ledPin, HIGH);
 
  // wacht 500 msec (=1/2 sec)  
  delay(500);
  
  // zet de LED poort laag (0V) zodat LED dooft
  digitalWrite(ledPin, LOW);
  
  // wacht weer 500 msec
  delay(500);
}


