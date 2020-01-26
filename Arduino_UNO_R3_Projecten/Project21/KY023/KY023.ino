/*
    KY023 Mini X/Y Joystick
    
    Test de joystick module en toon de X- en Y-coordinaten alsook de status van 
    de drukknop in de seriële console.
    OPGELET: plaats een weerstand van 1K tussen de 5V en de drukknop pin !
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Mini X/Y joystick KY023
    - 1K ohm weerstand
    
*/

// constanten
const int xPin = A0;                       // KY023 X pin
const int yPin = A1;                       // KY023 Y pin
const int swPin = 10;                      // KY023 switch pin

// variabelen
int x_wrde, y_wrde, sw_wrde;               // KY023 variabelen

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(xPin, INPUT);                    // X pin is input
  pinMode(yPin, INPUT);                    // Y pin is input
  pinMode(swPin, INPUT);                   // switch pin is input
  Serial.begin(9600);                      // seriële console initialiseren
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  x_wrde = analogRead (xPin);              // X waarde
  y_wrde = analogRead (yPin);              // Y waarde
  sw_wrde = digitalRead (swPin);           // switch waarde
  Serial.print("X: ");                     // toon
  Serial.print(x_wrde, DEC);               // X waarde          
  Serial.print ("\tY: ");                  // toon
  Serial.print (y_wrde, DEC);              // Y waarde
  Serial.print("\tDrukknop: ");            // toon
  if (sw_wrde == HIGH){                    // drukknop niet gedrukt
    Serial.println ("OPEN");               // toon OPEN 
  } else {                                 // anders 
    Serial.println ("GESLOTEN");           // toon GESLOTEN
  }
  delay (500);                             // wacht 1/2 sec
}
