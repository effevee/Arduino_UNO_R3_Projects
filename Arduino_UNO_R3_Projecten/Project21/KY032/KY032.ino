/*
    KY032 Obstakel detectie sensor
    
    Laat de ingebouwde led 13 flikkeren bij het detecteren van een obstakel.
    Experimenteer met de potentiometer om de afstand van de detectie te varieren.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Obstakel detectie sensor KY032
    
*/

// constanten
const int led = 13;                        // interne led pin
const int obstakel = 9;                    // KY032 out pin

// variabelen
int waarde;                                // KY032 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(obstakel, INPUT);                // out pin is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(obstakel);          // lees sensor
  if (waarde == LOW) {                     // bij obstakel
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  } 
  delay(1000);                             // even wachten 
}
