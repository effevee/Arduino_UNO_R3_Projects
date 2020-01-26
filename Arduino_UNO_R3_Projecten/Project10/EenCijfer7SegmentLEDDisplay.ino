/*

  Het één cijfer 7 segment LED display
  
  Maak een schakeling met het één cijfer 7 segment LED display waarbij éénmalig :
    – alle segmenten samen worden aan- en uitgezet. 
    – de segmenten afzonderlijk één voor één worden aan- en uitgezet.
  Vervolgens moet het één cijfer 7 segment LED display voortdurend optellen van 0 tot 9.

*/

// constanten
const int segA = 2;         // pin voor segment A van LED display
const int segB = 3;         // pin voor segment B van LED display  
const int segC = 4;         // pin voor segment C van LED display
const int segD = 6;         // pin voor segment D van LED display
const int segE = 7;         // pin voor segment E van LED display
const int segF = 9;         // pin voor segment F van LED display
const int segG = 8;         // pin voor segment G van LED display
const int segPt = 5;        // pin voor decimaal punt van LED display

const int pauseTijd = 1000; // wachttijd tussen de updates

// variabelen

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  
  // initialisatie van de LED display poorten
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segPt, OUTPUT);

  // set alle segmenten tegelijk aan en uit
  allesAanUit();
  
  // set segmenten één voor één aan en uit
  segmentenAanUit();
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {

  // lus om cijfers te tonen
  for (int digit = 0; digit < 10; digit++) {
    // select voor de cijfers
    switch(digit) {
      case 0:
        nul();
        break;
      case 1:
        een();
        break;
      case 2:
        twee();
        break;
      case 3:
        drie();
        break;
      case 4:
        vier();
        break;
      case 5:
        vijf();
        break;
      case 6:
        zes();
        break;
      case 7:
        zeven();
        break;
      case 8:
        acht();
        break;
      case 9:
        negen();
        break;
    }
    
    // wacht even zodat we iets kunnen zien
    delay(pauseTijd);
  }
}

// functie om cijfer 1 te tonen
void een() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 2 te tonen
void twee() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 3 te tonen
void drie() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 4 te tonen
void vier() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 5 te tonen
void vijf() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 6 te tonen
void zes() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 7 te tonen
void zeven() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 8 te tonen
void acht() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 9 te tonen
void negen() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

// functie om cijfer 0 te tonen
void nul() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}

// functie om alle segmenten tegelijk aan en uit te zetten
void allesAanUit() {
  // alle segmenten aan
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, HIGH);

  // even wachten
  delay(pauseTijd);
  
  // alle segmenten uit
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);

  // even wachten
  delay(pauseTijd);
}

// functie om de segmenten één voor één aan en uit te zetten
void segmentenAanUit() {
  // segment A
  digitalWrite(segA, HIGH);
  delay(pauseTijd);
  digitalWrite(segA, LOW);
  delay(pauseTijd);
  // segment B
  digitalWrite(segB, HIGH);
  delay(pauseTijd);
  digitalWrite(segB, LOW);
  delay(pauseTijd);
  // segment C
  digitalWrite(segC, HIGH);
  delay(pauseTijd);
  digitalWrite(segC, LOW);
  delay(pauseTijd);
  // segment D
  digitalWrite(segD, HIGH);
  delay(pauseTijd);
  digitalWrite(segD, LOW);
  delay(pauseTijd);
  // segment E
  digitalWrite(segE, HIGH);
  delay(pauseTijd);
  digitalWrite(segE, LOW);
  delay(pauseTijd);
  // segment F
  digitalWrite(segF, HIGH);
  delay(pauseTijd);
  digitalWrite(segF, LOW);
  delay(pauseTijd);
  // segment G
  digitalWrite(segG, HIGH);
  delay(pauseTijd);
  digitalWrite(segG, LOW);
  delay(pauseTijd);
  // Decimaal punt
  digitalWrite(segPt, HIGH);
  delay(pauseTijd);
  digitalWrite(segPt, LOW);
  delay(pauseTijd);  
}  
