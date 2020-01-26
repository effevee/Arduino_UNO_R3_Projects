
/*

  Laat op de 8x8 Dot LED matrix de afzonderlijke LEDs één voor één oplichten, 
  alsook alle rijen en kolommen. 
  
*/

// constanten
const int rij[8] = { 5, 16, 6, 2, 13, 7, 12, 9 };    // pinnen die de rijen (anodes) sturen
const int kol[8] = { 17, 11, 10, 4, 8, 3, 15, 14 };  // pinnen die de kolommen (kathodes) sturen
const boolean Aan = true;                            // matrix aan
const boolean Uit = false;                           // matrix uit
const int tijd = 300;                                // wachttijd

// variabelen
int r = 0;                                           // loop variabele voor reeks rij
int k = 0;                                           // loop variabele voor reeks kol

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup(){

  // declaratie pinnen
  for (int i=0; i<8; i++) {
    pinMode(rij[i], OUTPUT);                         // rij pinnen als output
    pinMode(kol[i], OUTPUT);                         // kolom pinnen als output
  }

  // Matrix uit
  InitMatrix(Uit);
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {

  // Alle leds aan- en uitzetten
  InitMatrix(Aan);                                   // alles aan
  delay(tijd);                                       // wacht tijd
  
  InitMatrix(Uit);                                   // alles uit
  delay(tijd);                                       // wacht tijd
  
  // Alle leds één voor één aan- en uitzetten
  for (r=0; r<8; r++) {                              // voorwaarts
    for (k=0; k<8; k++) {
      digitalWrite(rij[r], HIGH);                    // rij pin anode aan
      digitalWrite(kol[k], LOW);                     // kol pin kathode uit
      delay(tijd);                                   // wacht tijd
      digitalWrite(rij[r], LOW);                     // rij pin anode uit
      digitalWrite(kol[k], HIGH);                    // kol pin kathode aan
    }
  }
  delay(tijd);                                       // wacht tijd
  
  for (r=7; r>=0; r--) {                             // achterwaarts 
    for (k=7; k>=0; k--) {
      digitalWrite(rij[r], HIGH);                    // rij pin anode aan
      digitalWrite(kol[k], LOW);                     // kol pin kathode uit
      delay(tijd);                                   // wacht tijd
      digitalWrite(rij[r], LOW);                     // rij pin anode uit
      digitalWrite(kol[k], HIGH);                    // kol pin kathode aan
    }
  }
  delay(tijd);                                       // wacht tijd
  
  // Alle rijen één voor één aan- en uitzetten
  for (k=0; k<8; k++) {                              // alle kol pinnen uit 
    digitalWrite(kol[k], LOW);                       // kol pin kathode uit
  }
  for (r=0; r<8; r++) {                              // voorwaarts
    digitalWrite(rij[r], HIGH);                      // rij pin anode aan
    delay(tijd);                                     // wacht tijd
    digitalWrite(rij[r], LOW);                       // rij pin anode uit
  }
  delay(tijd);                                       // wacht tijd
  
  for (r=7; r>=0; r--) {                             // achterwaarts 
    digitalWrite(rij[r], HIGH);                      // rij pin anode aan
    delay(tijd);                                     // wacht tijd
    digitalWrite(rij[r], LOW);                       // rij pin anode uit
  }
  for (k=0; k<8; k++) {                              // alle kol pinnen aan 
    digitalWrite(kol[k], HIGH);                      // kol pin kathode aan
  }
  delay(tijd);                                       // wacht tijd

  // Alle kolommen één voor één aan- en uitzetten
  for (r=0; r<8; r++) {                              // alle row pinnen aan 
    digitalWrite(rij[r], HIGH);                      // row pin anode aan
  }
  for (k=0; k<8; k++) {                              // voorwaarts 
    digitalWrite(kol[k], LOW);                       // kol pin kathode uit
    delay(tijd);                                     // wacht tijd
    digitalWrite(kol[k], HIGH);                      // kol pin kathode aan
  }
  delay(tijd);                                       // wacht tijd

  for (k=7; k>=0; k--) {                             // achterwaarts 
    digitalWrite(kol[k], LOW);                       // kol pin kathode uit
    delay(tijd);                                     // wacht tijd
    digitalWrite(kol[k], HIGH);                      // kol pin kathode uit
  }
  for (r=0; r<8; r++) {                              // alle row pinnen uit 
    digitalWrite(rij[r], LOW);                       // row pin anode uit
  }
  delay(tijd);                                       // wacht tijd
}

// initialisatie van de LED matrix
void InitMatrix(boolean Aan) {
  if (Aan) {                                         // alle leds aan 
    for (int i=0; i<8; i++) {
      digitalWrite(rij[i], HIGH);                    // rij pin anode aan
      digitalWrite(kol[i], LOW);                     // kol pin kathode uit
    }
  } else {                                           // alles leds uit 
    for (int i=0; i<8; i++) {
      digitalWrite(rij[i], LOW);                     // rij pin anode uit
      digitalWrite(kol[i], HIGH);                    // kol pin kathode aan
    }
  }
}

