/*
    KY009 Drie kleuren SMD led
    
    Laat de drie kleuren led verschillende kleuren tonen door de 
    rood, groen en blauw pinnen aan te sturen met verschillende waarden.
    OPGELET : Gebruik hiervoor PWM poorten op de Arduino.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Drie kleuren SMD led KY009
    
*/

// constanten
const int rPin = 9;                        // KY009 rode pin
const int gPin = 10;                       // KY009 groene pin
const int bPin = 11;                       // KY009 blauwe pin

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(rPin, OUTPUT);                   // rood is output
  pinMode(gPin, OUTPUT);                   // groen is output
  pinMode(bPin, OUTPUT);                   // blauw is output
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  // HTML kleuren
  kleur(0xFF, 0x00, 0x00);                 // rood
  kleur(0x00, 0xFF, 0x00);                 // limoen
  kleur(0x00, 0x00, 0xFF);                 // blauw
  kleur(0xFF, 0x00, 0xFF);                 // magenta
  kleur(0xFF, 0xFF, 0x00);                 // geel
  kleur(0x00, 0xFF, 0xFF);                 // cyaan
  kleur(0xFF, 0xFF, 0xFF);                 // wit
  kleur(0xC0, 0xC0, 0xC0);                 // zilver 
  kleur(0x80, 0x00, 0x00);                 // bordeaux 
  kleur(0x00, 0x80, 0x00);                 // groen 
  kleur(0x00, 0x00, 0x80);                 // marine
  kleur(0x80, 0x00, 0x80);                 // purper 
  kleur(0x80, 0x80, 0x00);                 // olijf
  kleur(0x00, 0x80, 0x80);                 // groenblauw
  kleur(0x80, 0x80, 0x80);                 // grijs 
}

// functie om de kleur in te stellen
void kleur(int rood, int groen, int blauw) {
  analogWrite(rPin, rood);                 // rood
  analogWrite(gPin, groen);                // groen
  analogWrite(bPin, blauw);                // blauw
  delay(1000);                             // wacht 1 sec
}  

