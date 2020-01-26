/*
    KY036 Aanraking sensor
    
    Laat de ingebouwde led oplichten bij aanraken van de sensor en bij de volgende aanraking 
    terug uitdoven. Experimenteer met de potentiemeter om de gevoeligheid bij te regelen.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Aanraking sensor KY036
*/

// constanten
const int touch = 2;                       // KY036 DO signaal pin
const int led = 13;                        // led pin

// variabelen
unsigned long laatsteTijd = 0;             // tijd laatste aanraking
boolean ledAan = false;                    // status van de led

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(touch, INPUT);                   // KY036 pin is input
  digitalWrite(led, LOW);                  // led afzetten
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  int touchStatus = digitalRead(touch);    // lees touch sensor
  if (touchStatus == HIGH) {               // als aangeraakt
    if (millis()-laatsteTijd > 50) {       // en meer dan 50 ms geleden
      ledAan = not ledAan;                 // boolean led status aanpassen
      digitalWrite(led,ledAan?HIGH:LOW);   // led omschakelen
    }
    laatsteTijd = millis();                // tijd bewaren
  }
}  
