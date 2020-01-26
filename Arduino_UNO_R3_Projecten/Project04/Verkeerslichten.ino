/*
  Verkeerslichten
  
  Simuleer 2 verkeerslichten. Als verkeerslicht 1 groen toont, dan moet verkeerslicht 2 rood tonen en omgekeerd. 
  Maak ook dat als verkeerslicht 1 op rood gaat het niet onmiddellijk groen wordt op verkeerslicht 2. 
  Omgekeerd als verkeerslicht 2 rood wordt, dan mag verkeerslicht 1 ook pas met een kleine vertraging groen worden.

   De verkeerslichten schakelen om iedere 30 seconden. De vertraging bij groen aan de overkant is 2 seconden. 
  
*/

// constanten
const int ledRoodLinksPin = 13;  // de digitale poort die de rode LED links aanstuurt
const int ledGroenLinksPin = 12;  // de digitale poort die de groene LED links aanstuurt
const int ledRoodRechtsPin = 8;  // de digitale poort die de rode LED rechts aanstuurt
const int ledGroenRechtsPin = 7;  // de digitale poort die de groene LED rechts aanstuurt

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // initialiseer digitale poorten als output.
  pinMode(ledRoodLinksPin, OUTPUT);
  pinMode(ledGroenLinksPin, OUTPUT);
  pinMode(ledRoodRechtsPin, OUTPUT);
  pinMode(ledGroenRechtsPin, OUTPUT);
  
  // zet alle leds af
  digitalWrite(ledRoodLinksPin, LOW);  
  digitalWrite(ledGroenLinksPin, LOW);
  digitalWrite(ledRoodRechtsPin, LOW);  
  digitalWrite(ledGroenRechtsPin, LOW);
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  
  // zet rood rechts
  digitalWrite(ledGroenRechtsPin, LOW);
  digitalWrite(ledRoodRechtsPin, HIGH);

  // wacht 2 sec om groen links te zetten
  delay(2000);

  // zet groen links  
  digitalWrite(ledGroenLinksPin, HIGH);
  digitalWrite(ledRoodLinksPin, LOW);
  
  // wacht 30 sec  
  delay(30000);

  // zet rood links
  digitalWrite(ledGroenLinksPin, LOW);
  digitalWrite(ledRoodLinksPin, HIGH);
 
  // wacht 2 sec om groen rechts te zetten
  delay(2000);
 
  // zet groen rechts 
  digitalWrite(ledGroenRechtsPin, HIGH);
  digitalWrite(ledRoodRechtsPin, LOW);
   
  // wacht 30 sec  
  delay(30000);
}
