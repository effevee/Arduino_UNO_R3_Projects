
/*

  Maak met behulp van de 74HC595 een running light met 8 rode leds (à la Knightrider).
  
*/

// constanten
const int latchPin = 5;                          
const int clockPin = 4;
const int dataPin = 6;

const int aantalPatronen = 16;
const byte pat[aantalPatronen] = { \              // byte patronen in binaire vorm 
  B00000001,B00000011,B00000110,B00001100, \
  B00011000,B00110000,B01100000,B11000000, \
  B10000000,B11000000,B01100000,B00110000, \
  B00011000,B00001100,B00000110,B00000011 };

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  byte leds;
  
  // pinnen als output declareren
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  
  // alle leds afzetten
  leds = 0;
  updateLeds(leds);
}
 
// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  byte leds;
  // lus door patronen
  for (int i=0; i<16; i++) {
    leds = pat[i];
    updateLeds(leds);
    delay(100);
  }
}

// data van leds seriëel inlezen en parallel uitsturen naar output pinnen   
void updateLeds(byte leds) {
  // latch pin laag zetten; we beginnen met inlezen 
  digitalWrite(latchPin, LOW);
  
  // data van leds serëel inlezen van datapin
  // LSBFIRST - Least Significant Bit First = minst belangrijke bit eerst
  // MSBFIRST - Most Significant Bit First = meest belanrijke bit eerst  
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  
  // alles is ingelezen; zet latch hoog zodat shift register beschikbaar komt op output pinnen
  digitalWrite(latchPin, HIGH);
}


