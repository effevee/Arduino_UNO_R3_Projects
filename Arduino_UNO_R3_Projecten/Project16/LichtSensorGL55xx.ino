/*
  Maak met behulp van een lichtsensor GL55xx een schakeling die afhankelijk van de lichtsterkte 
  van de omgeving een led feller of zwakker laat oplichten. Hoe groter de lichtsterkte, 
  hoe zwakker de led moet branden. Gebruik de potentiometer om de lichtsterkte waarbij de led 
  begint te branden te regelen.
  
*/

// constanten
const int sensorPin = A0;                     // pin van de lichtsensor 
const int ledPin = 3;                         // pin van de rode led

// variabelen
int lichtsterkte;                             // lichtsterkte sensor meetwaarde
int minLicht = 1023, maxLicht = 0;            // variabelen voor min en max lichtsterkte

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // de pinnen initialiseren
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // de led uitzetten
  digitalWrite(ledPin, LOW);
  
  // de serële monitor initialiseren
  Serial.begin(9600);
}
 
// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  // lees de lichtsterkte (0-1023)
  lichtsterkte = analogRead(sensorPin);
  
  // toon gemeten lichtsterkte
  Serial.print("sensor: ");
  Serial.print(lichtsterkte);
  
  // zet de waarde om naar PWM range (0-255) voor de led aansturing
  autoTune();
  
  // toon geconverteerde stuurwaarde
  Serial.print("\tled: ");
  Serial.println(lichtsterkte);
  
  // laat de led branden op lichtsterkte
  analogWrite(ledPin, lichtsterkte);
  
  // even wachten
  delay(500);
}

// functie om lichtsterkte automatisch om te zetten naar de juiste waarde
// bij nacht moet led maximaal branden; bij dag moet led uit zijn.
void autoTune() {
  
  // pas minimum gemeten lichtsterkte aan
  if (lichtsterkte < minLicht) {
    minLicht = lichtsterkte;
  }
  
  // pas maximum lichtsterkte aan
  if (lichtsterkte > maxLicht) {
    maxLicht = lichtsterkte;
  }
  
  // toon min en max in seriële monitor
  Serial.print("\tmin: ");
  Serial.print(minLicht);
  Serial.print("\tmax: ");
  Serial.print(maxLicht);
  
  // zet lichtsterkte om naar optimale waarde voor PCM poort led (0-255)
  lichtsterkte = map(lichtsterkte, minLicht+30, maxLicht-30, 0, 255);
  lichtsterkte = constrain(lichtsterkte, 0, 255);
}  

