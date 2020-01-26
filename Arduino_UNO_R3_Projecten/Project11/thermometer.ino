/*

  Elektronische thermometer
  
  Maak een thermometer die de temperatuur in °C toont op het viercijfer LED display. 
  Gebruik hiervoor de temperatuur sensor LM35.

*/

// constanten
const int sensorPin = A0;   // pin van de temperatuur sensor
const float offset = 0.13;  // offset waarde voor temperatuur sensor

const int segA = 5;         // pin voor segment A van LED display
const int segB = 13;        // pin voor segment B van LED display  
const int segC = 10;        // pin voor segment C van LED display
const int segD = 8;         // pin voor segment D van LED display
const int segE = 7;         // pin voor segment E van LED display
const int segF = 4;         // pin voor segment F van LED display
const int segG = 11;        // pin voor segment G van LED display
const int segPt = 9;        // pin voor decimaal punt van LED display
const int dig1 = 6;         // pin voor digit 1 van LED display
const int dig2 = 3;         // pin voor digit 2 van LED display
const int dig3 = 2;         // pin voor digit 3 van LED display
const int dig4 = 12;        // pin voor digit 4 van LED display

// variabelen
int pauseTijd = 900;        // wachttijd tussen de updates van de digits
int teller = 0;             // aantal loops
int sensorWaarde = 0;       // waarde van temperatuur sensor (0-1023)
float spanning = 0.0;       // spanning op temperatuur sensor (V) 
float temperatuur = 0.0;    // temperatuur decimaal (°C)

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  
  // start seriele monitor voor debugging
  Serial.begin(9600);

  // initialisatie van de temperatuur sensor poort
  pinMode(sensorPin, INPUT);

  // initialisatie van de LED display poorten
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segPt, OUTPUT);
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);  
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {

  // lees de temperatuur maar om de 500 loops
  if (teller%500 == 0) {
      
    // lees de temperatuur sensor
    sensorWaarde = analogRead(sensorPin);

    // converteer de sensorwaarde (0-1023) naar spanning
    spanning = (sensorWaarde / 1024.0) * 5.0;

    // bereken de temperatuur - iedere 10 mV = 1 °C
    temperatuur = (spanning - offset) * 100.0;

    // toon waarden in seriele monitor voor debugging
    Serial.print("Sensorwaarde: ");
    Serial.print(sensorWaarde);
    Serial.print("\t Spanning: ");
    Serial.print(spanning);
    Serial.print(" V\t Temperatuur : ");
    Serial.print(temperatuur);
    Serial.println(" C");

    // reset teller
    teller = 0;
  }

  // we sturen de digits van het LED display één voor één aan met de juiste informatie
  
  // digit 1 bevat het tiental van de temperatuur waarde 
  selectDigit(1);                    // selecteer digit 1
  stuurDigit(tiental(temperatuur));  // stuur tiental van temperatuur door
  delayMicroseconds(pauseTijd);      // wacht even
  digitalWrite(dig1, HIGH);          // toon digit 1
  
  // digit 2 bevat de eenheden van de temperatuur waarde 
  selectDigit(2);                    // selecteer digit 2
  stuurDigit(eenheid(temperatuur));  // stuur eenheid van temperatuur door
  decimaalpunt();                    // stuur decimale punt door 
  delayMicroseconds(pauseTijd);      // wacht even
  digitalWrite(dig2, HIGH);          // toon digit 2
  
  // digit 3 bevat de decimalen van de temperatuur waarde
  selectDigit(3);                    // selecteer digit 3
  stuurDigit(decimaal(temperatuur)); // stuur decimaal van temperatuur door
  delayMicroseconds(pauseTijd);      // wacht even
  digitalWrite(dig3, HIGH);          // toon digit 3

  // digit 4 toont de hoofdletter C voor Celsius
  selectDigit(4);                    // selecteer digit 4
  cee();                             // stuur de C door
  delayMicroseconds(pauseTijd);      // wacht even
  digitalWrite(dig4, HIGH);          // toon digit 4

  // teller voor de loops verhogen
  teller ++;

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

// functie om letter C te tonen
void cee() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}

// functie om decimaal punt te tonen
void decimaalpunt() {
  digitalWrite(segPt, HIGH);
}


// functie om de juiste digit (1-4) te selecteren
void selectDigit(int d) {
  // we zetten eerst de digit laag voordat we die updaten
  switch (d) {
    case 1:
      digitalWrite(dig1, LOW);
      break;
    case 2:
      digitalWrite(dig2, LOW);
      break;
    case 3:
      digitalWrite(dig3, LOW);
      break;
    default:
      digitalWrite(dig4, LOW);
      break;
  }
}

// functie om het teken x naar de juiste digit (1-4) te sturen
void stuurDigit(int x) {

  switch(x) {
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
    case 10:
      cee();
      break;
    default:
      nul();
      break;
  }
}


// functie om het tiental van een decimaal getal x te berekenen
int tiental(float x) {
  float divided = x / 10.0;
  return (int)divided;
}

// functie om de eenheid van een decimaal getal x te berekenen
int eenheid(float x) {
  float divided = x - (10.0 * tiental(x));
  return (int)divided;
}

// functie om de decimaal van een decimaal getal x te berekenen
int decimaal(float x) {
  float divided = x - (10.0 * tiental(x)) - eenheid(x);
  divided *= 10;
  return (int)divided;
}
