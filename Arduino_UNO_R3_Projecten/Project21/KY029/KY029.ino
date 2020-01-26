/*
    KY029 Kleine twee kleuren led
    
    Laat de twee kleuren led afwisselend groen en rood in- en uitfaden.
    OPGELET : de pin layout van deze module is als volgt :
              - = groen / midden = rood / signaal = GND 
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Twee kleuren led KY029
*/

// constanten
const int rPin = 10;                       // KY029 rode pin
const int gPin = 11;                       // KY029 groene pin

// variabelen
int waarde;                                // KY029 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(rPin, OUTPUT);                   // rode pin is output
  pinMode(gPin, OUTPUT);                   // groene pin is output
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  for (waarde=255; waarde>0; waarde--) {
    analogWrite(gPin, waarde);             // groen
    analogWrite(rPin, 255-waarde);         // rood
    delay(15);                             // even wachten
  }  
  for (waarde=0; waarde<255; waarde++) {
    analogWrite(gPin, waarde);             // groen
    analogWrite(rPin, 255-waarde);         // rood
    delay(15);                             // even wachten
  }  
}
