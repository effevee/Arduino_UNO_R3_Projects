/*

  Gebruik de TCRT5000 optische sensor module om zwart en wit te detecteren op een blad papier. 
  Toon de resultaten in de seriële monitor. 
  Experimenteer ook eens met de potentiometer om de gevoeligheid aan te passen.

*/

// constanten
const int sensorPin = A0;                     // Pin TCRT5000

// variabelen
int sensorWaarde = 0;                         // sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // de pinnen initialiseren
  pinMode(sensorPin, INPUT);
  
  // Seriele monitor initialiseren
  Serial.begin(9600);
}
 
// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  // lees de sensorwaarde
  sensorWaarde = analogRead(sensorPin);
  
  // toon sensorwaarde in seriële monitor
  Serial.print("sensorwaarde: ");
  Serial.println(sensorWaarde);
  
  // korte pauze
  delay(200);
}      



