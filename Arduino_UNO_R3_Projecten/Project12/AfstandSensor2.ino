#include <NewPing.h>
/*
    Afstandsensor
    
    Experimenteer met de HC-SR04 afstand sensor en toon de resultaten in de seriële console.
    
*/

// constanten
const int TriggerPin = 8;
const int EchoPin = 9;
const int MaxBereik = 200;    // in cm

// NewPing instance
NewPing sonar(TriggerPin, EchoPin, MaxBereik);

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
  // Stuur de ping uit en geeft de tijd terug
  tijd = sonar.ping();
  
  // bereken de afstand in cm
  afstand = sonar.convert_cm(tijd);
 
  // toon resultaten in seriële monitor
  if (afstand >= MaxBereik || afstand <= 0) {
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
