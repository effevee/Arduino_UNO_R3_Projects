/*
    KY012 Actieve zoemer
    
    Laat de zoemer afwisselend geluid produceren.
    OPGELET : de pin lay-out van deze module is als volgt :
              - = GND / midden = niet aangesloten / signaal = 5V

    Benodigdheden :
    - Arduino UNO, breadboard, jumper kabeltjes
    - Actieve zoemer KY012
    
*/

// constanten
const int zoemPin = 7;                   // KY012 signaal pin 

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(zoemPin, OUTPUT);              // zoemer is output
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  digitalWrite(zoemPin, HIGH);           // geluid aan
  delay(50);                             // voor 50 msec
  digitalWrite(zoemPin, LOW);            // geluid uit 
  delay(50);                             // voor 50 msec 
}
