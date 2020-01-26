/*
   Drie kleuren LED of RGB LED
   
   Laat een drie kleuren LED (RGB LED) achtereenvolgens rood, groen en blauw oplichten.
   
*/

// constanten
const int roodLedPin = 9;
const int groenLedPin = 10;
const int blauwLedPin = 11;

// variabelen

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {

  // initialisatie van de RGB led pinnen als output
  pinMode(roodLedPin, OUTPUT);
  pinMode(groenLedPin, OUTPUT);
  pinMode(blauwLedPin, OUTPUT);
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {

  // zet rood aan, wacht 2 sec en zet rood af
  digitalWrite(roodLedPin, HIGH);
  delay(2000);
  digitalWrite(roodLedPin, LOW);

  // zet groen aan, wacht 2 sec en zet groen af
  digitalWrite(groenLedPin, HIGH);
  delay(2000);
  digitalWrite(groenLedPin, LOW);
  
  // zet blauw aan, wacht 2 sec en zet blauw af
  digitalWrite(blauwLedPin, HIGH);
  delay(2000);
  digitalWrite(blauwLedPin, LOW);

}
