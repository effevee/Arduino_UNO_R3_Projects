/*

  Laat op de 8x8 Dot LED matrix de letters van “HALLO” van rechts naar links scrollen 
  gevolgd door een smiley :-)
  
*/
#include <FrequencyTimer2.h>

#define H { \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
}

#define A  { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
}

#define L { \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}  \
}

#define O { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}  \
}

#define Smiley { \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 1, 0, 0, 1, 0, 1}, \
    {1, 0, 0, 0, 0, 0, 0, 1}, \
    {1, 0, 1, 0, 0, 1, 0, 1}, \
    {1, 0, 0, 1, 1, 0, 0, 1}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}  \
}

// constanten
const int rij[8] = { 5, 16, 6, 2, 13, 7, 12, 9 };     // pinnen die de rijen (anodes) sturen
const int kol[8] = { 17, 11, 10, 4, 8, 3, 15, 14 };   // pinnen die de kolommen (kathodes) sturen
const int AantalPatronen = 6;                         // aantal patronen
const byte pat[AantalPatronen][8][8] = \
    { H, A, L, L, O, Smiley };                        // af te beelden patronen
const boolean Aan = true;                             // led matrix aan
const boolean Uit = false;                            // led matrix uit

// variabelen
int r = 0;                                            // loop variabele voor reeks rij
int k = 0;                                            // loop variabele voor reeks kol
int p = 0;                                            // loop variabele voor reeks pat
byte led[8][8];                                       // led matrix reeks
byte row = 0;                                         // bijhouden rij voor interrupt routine 

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup(){

  // declaratie pinnen
  for (int i=0; i<8; i++) {
    pinMode(rij[i], OUTPUT);                          // rij pinnen als output
    pinMode(kol[i], OUTPUT);                          // kolom pinnen als output
  }

  // initialisatie matrix
  InitMatrix(Uit);                                    // led matrix uitzetten
  
  // setup library
  FrequencyTimer2::disable();                         // afzetten gebruik pin 11
  FrequencyTimer2::setPeriod(2000);                   // interrupt iedere 2000 µs
  FrequencyTimer2::setOnOverflow(TekenMatrix);        // interrupt routine
  
  // patroon ophalen
  LaadPatroon(p);                                     // patroon opladen
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  p = ++p % AantalPatronen;
  ScrollPatroon(p, 150); 
}

// initialisatie van de LED matrix
void InitMatrix(boolean Aan) {
  if (Aan) {                                          // alle leds aan 
    for (int r=0; r<8; r++) {
      for (int k=0; k<8; k++) { 
        led[r][k] = 1;                                // led aan
        digitalWrite(rij[r], HIGH);                   // rij pin anode aan
        digitalWrite(kol[k], LOW);                    // kol pin kathode uit
      }  
    }
  } else {                                            // alles leds uit 
    for (int r=0; r<8; r++) {
      for (int k=0; k<8; k++) { 
        led[r][k] = 0;                                // led uit
        digitalWrite(rij[r], LOW);                    // rij pin anode uit
        digitalWrite(kol[k], HIGH);                   // kol pin kathode aan
      }  
    }
  }
}

// opladen patroon
void LaadPatroon(int p) {
  for (int r=0; r<8; r++) {
    for (int k=0; k<8; k++) {
      led[r][k] = pat[p][r][k];                       // patroon naar led kopieren
    }
  }
}
 
// interrupt routine - teken het patroon op de LED matrix
void TekenMatrix() {
  digitalWrite(rij[row], LOW);                        // vorige rij pin anode af
  row++;                                              // rij variabele + 1
  if (row == 8) {                                     // overflow
    row = 0;                                          // rij variabele resetten
  }
  for (k=0; k<8; k++) {
    if (led[row][k] == 1) {
      digitalWrite(kol[k], LOW);                      // kol pin kathode uit
    } else {
      digitalWrite(kol[k], HIGH);                     // kol pin kathode aan
    }
  }    
  digitalWrite(rij[row], HIGH);                       // rij pin anode aan
}

// scroll patroon rechts naar links
void ScrollPatroon(int p, int tijd) {
  for (int l = 0; l < 8; l++) {
    for (int r=0; r<8; r++) {                         // lus rijen  
      for (int k=0; k<7; k++) {                       // lus kolommen
        led[r][k] = led[r][k+1];                      // steek volgende kol in huidige 
      }
    }
    for (int r=0; r<8; r++) {                         // lus rijen 
      led[r][7] = pat[p][r][0 + l];                   // steek 1ste kol patroon in laatste kol
    }
    delay(tijd);                                      // wacht tijdje
  }
}


