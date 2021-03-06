/*
    KY037 Grote microfoon
    
    Laat de ingebouwde led oplichten bij detectie van geluiden door de microfoon. 
    Experimenteer met de potentiemeter om de gevoeligheid van de detectie bij te regelen.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Grote microfoon KY037
*/

// constanten
const int geluid = 10;                     // KY037 DO signaal pin
const int led = 13;                        // led pin

// variabelen
int sensorwaarde;                          // KY037 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(geluid, INPUT);                  // KY037 pin is input
  digitalWrite(led, LOW);                  // led afzetten
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  sensorwaarde = digitalRead(geluid);      // lees sensor
  if (sensorwaarde == HIGH) {              // geluid gedetecteerd
    digitalWrite(led, HIGH);               // led aan
  } else {                                 // anders
    digitalWrite(led, LOW);                // led af
  }
}  
