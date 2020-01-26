/*
    Afstandsensor
    
    Experimenteer met de HC-SR04 afstand sensor en toon de resultaten in de seriële console.
    
*/

// constanten
const int TriggerPin = 8;
const int EchoPin = 9;

// variabelen
int tijd, afstand; 

void setup() {
  // de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
  // wanneer op de reset knop gedrukt wordt

  // Initialiseer de seriële monitor
  Serial.begin(9600);
  
  // Declaratie afstand sensor pinnen
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  // Stuur de geluidsignalen uit
  digitalWrite(TriggerPin, HIGH);     // Start Trigger
  delayMicroseconds(1000);            // wacht 1 ms
  digitalWrite(TriggerPin, LOW);      // Stop Trigger
  
  // bereken de echo tijd
  tijd = pulseIn(EchoPin, HIGH);      // als de EchoPin hoog is wordt de tijd opgeslagen in de variabele
  
  // bereken de afstand
  afstand = (tijd/2) / 29.1;          // zie formule
 
  // toon resultaten in serële monitor
  if (afstand >= 200 || afstand <= 0) {
    // ongeldige afstand
    Serial.println("Ongeldig bereik");
  } else {
    // geldige afstand
    Serial.print("Afstand: ");
    Serial.print(afstand);
    Serial.println(" cm");
  }

  // Even wachten
  delay(500);  
}
