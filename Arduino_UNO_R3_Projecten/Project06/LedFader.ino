/*
  Helderheid LED aanpassen
  
  Gebruik een PWM (Pulse Width Modulation) digitale poort om de helderheid van een LED aan te passen. 
  Laat de helderheid toenemen van 0 tot maximum en daarna terug afnemen naar 0.

*/

// constanten
const int ledPin = 9;  // de digitale PWM poort die de LED aanstuurt

// variabelen
int helderheid = 0;    // bewaart de huidige helderheid

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // initialiseer digitale poort als output.
  pinMode(ledPin, OUTPUT);
}


// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  
  // lus helderheid van laag (0) naar hoog (255)
  for (helderheid = 0; helderheid < 255; helderheid = helderheid + 5) {
    // stuur signaal naar de led poort
    analogWrite(ledPin, helderheid);
 
    // wacht even om de verandering zichtbaar te maken voor ons  
    delay(20);
  }

  // wacht even
  delay(1000);

  // lus helderheid van hoog (255) naar laag (0)
  for (helderheid = 255; helderheid > 0; helderheid = helderheid - 5) {
    // stuur signaal naar de led poort
    analogWrite(ledPin, helderheid);
 
    // wacht even om de verandering zichtbaar te maken voor ons  
    delay(20);
  }
  
  // wacht even
  delay(1000);
}


