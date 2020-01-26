/*
    KY040 Rotary encoder
    
    Toon de positie en draairichting van de rotary encoder in de seriële monitor.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Rotary encoder KY040
    - 2 capaciteiten 0.1µF (debounce)
    - 1 weerstand 10K ohm
*/

// constanten
const int pinA = 2;                        // KY040 CLK pin
const int pinB = 3;                        // KY040 DT pin
const int pinSW = 4;                       // KY040 SW pin 

// variabelen
volatile int encoderPositie = 0;           // positie
boolean encoderRechts;                     // richting

// interrupt routine bij rotatie encoder
// uitgevoerd wanneer pinB van hoog naar laag gaat
void isr() {
  if (!digitalRead(pinB)) {                // pin B laag
    encoderPositie++;                      // positie vermeerderen 
    encoderRechts = true;                  // richting rechts
  } else {                                 // pin B hoog 
    encoderPositie--;                      // positie verminderen  
    encoderRechts = false;                 // richting links
  }
}  

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(pinA, INPUT);                    // pin A is input
  pinMode(pinB, INPUT);                    // pin B is input
  pinMode(pinSW, INPUT);                   // pin SW is input
  Serial.begin(9600);                      // seriële console initialiseren
  attachInterrupt(0, isr, FALLING);        // interrupt 0 voor rotatie
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  int laatstePositie = 0;                  // laatste positie
  while (true) {                           // blijven uitvoeren 
    if (!digitalRead(pinSW)) {             // switch ingedrukt
      encoderPositie = 0;                  // reset positie
      while (!digitalRead(pinSW)) {}       // wacht tot switch wordt losgelaten
      delay(10);                           // debounce
      Serial.println("RESET positie");     // toon RESET
    }  
    if (encoderPositie!=laatstePositie) {  // rotatie
      laatstePositie = encoderPositie;     // laatste positie updaten
      Serial.print("Encoder positie: ");   // toon
      Serial.print(encoderPositie);        // positie
      Serial.print("\tRichting: ");        // toon richting
      if (encoderRechts)
        Serial.println("Rechts");          // rechts
      else                                 // anders 
         Serial.println("Links");          // links
    }  
  } 
}
