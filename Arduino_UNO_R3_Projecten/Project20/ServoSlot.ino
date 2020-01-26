/*
  Servo slot
  
  Maak een slot met behulp van de servo motor en het piezo element. De piezo wordt in dit geval gebruikt als input
  element : de trillingen van het kloppen worden omgezet in electrische spanning die door de anologe poort van de UNO
  kunnen worden gedetecteerd. Gebruik 3 leds om de status weer te geven : rood = gesloten, groen = open, geel = geldige klop
  Gebruik een drukknop om het slot te sluiten. Je kan het terug openen met het juiste aantal geldige kloppen.  
*/

#include <Servo.h>

// constanten
const int piezo = A0;                        // analoge poort voor piezo
const int switchPin = 2;                     // digitale poort voor switch
const int geleLed = 3;                       // digitale poort voor gele led
const int groeneLed = 4;                     // digitale poort voor groene led
const int rodeLed = 5;                       // digitale poort voor rode led
const int servoPin = 9;                      // digitale poort voor servo

const int zachteKlop = 10;                   // zachte klop waarde
const int hardeKlop = 100;                   // harde klop waarde

// variabelen
int klopWaarde;                              // klopwaarde
int switchWaarde;                            // switchwaarde
boolean gesloten = false;                    // status slot
int aantalKloppen = 0;                       // aantal kloppen

// objecten
Servo servoslot;                             // servo object 

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {

  servoslot.attach(servoPin);                // servo init
  
  pinMode(piezo, INPUT);                     // piezo inout
  pinMode(switchPin, INPUT);                 // switch input   
  pinMode(geleLed, OUTPUT);                  // led output
  pinMode(groeneLed, OUTPUT);                // led output
  pinMode(rodeLed, OUTPUT);                  // led output
  
  digitalWrite(geleLed, LOW);                // led afzetten     
  digitalWrite(groeneLed, LOW);              // led afzetten     
  digitalWrite(rodeLed, LOW);                // led afzetten     

  Serial.begin(9600);                        // seriële monitor
  servoslot.write(0);                        // servo 0°
  digitalWrite(groeneLed, HIGH);             // led afzetten     
  Serial.println("OPEN");                    // bericht

}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {

  if (not gesloten) {                        // open
    switchWaarde = digitalRead(switchPin);   // lees switch
    if (switchWaarde == HIGH) {              // ingedrukt
      gesloten = true;                       // status aanpassen
      servoslot.write(90);                   // servo 90° 
      digitalWrite(groeneLed, LOW);          // groen afzetten     
      digitalWrite(rodeLed, HIGH);           // rood aanzetten
      Serial.println("GESLOTEN");            // bericht
      delay(1000);                           // wachten
    }  
  }

  if (gesloten) {                            // gesloten
    klopWaarde = analogRead(piezo);          // lees piezo
    if (aantalKloppen < 3 && klopWaarde > 1) {
      if (geldigeKlop(klopWaarde)) {         // klop is ok
        aantalKloppen++;                     // tellen ophogen 
      }
      Serial.print("Nog ");                  // nog
      Serial.print(3-aantalKloppen);         // zoveel
      Serial.println(" kloppen te gaan");    // kloppen te gaan
    }
    if (aantalKloppen >= 3) {                // aantal kloppen ok
       gesloten = false;                     // status aanpassen
       servoslot.write(0);                   // servo 0° 
       digitalWrite(groeneLed, HIGH);        // groen aanzetten     
       digitalWrite(rodeLed, LOW);           // rood afzetten
       Serial.println("OPEN");               // bericht
       aantalKloppen = 0;                    // reset aantal kloppen
    }
  }   
}

// functie om te controleren of de klop geldig is
boolean geldigeKlop (int waarde) {
  if (waarde > zachteKlop && waarde < hardeKlop) {  // geldige klop
    digitalWrite(geleLed, HIGH);             // geel aanzetten
    delay(50);                               // even wachten
    digitalWrite(geleLed, LOW);              // geel afzetten
    Serial.print("Geldige klop waarde ");    // toon geldige
    Serial.println(waarde);                  // klopwaarde
    return true;                             // geldige returnwaarde
  } else {                                   // ongeldige waarde
    Serial.print("Ongeldige klop waarde ");  // toon ongeldige
    Serial.println(waarde);                  // klopwaarde
    return false;                            // geldige returnwaarde
  }
}
