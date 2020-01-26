/*
    KY013 Analoge temperatuur sensor
    
    Meet de omgevingstemperatuur met de sensor en toon de resultaten
    in de seriële console.
    OPGELET : Foute labeling module : midden = GND / - = 5V !!!!
    
    Benodigdheden :
    - Arduino UNO, breadboard, jumper kabeltjes
    - Analoge temperatuur sensor KY013
*/

#include <math.h>

// constanten
const int sensorPin = A5;                // signaal pin temperatuur sensor 

// variabelen
int waarde;                              // KY013 sensorwaarde
double temp;                             // temperatuur

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(sensorPin, INPUT);             // temperatuur is output
  Serial.begin(9600);                    // seriële console initialiseren
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  waarde = analogRead(sensorPin);        // lees sensor
  temp = thermistor(waarde);             // waarde omzetten naar temperatuur
  Serial.print("Sensor: ");        
  Serial.print(waarde);                  // toon sensor waarde
  Serial.print("\tTemperatuur: ");
  Serial.print(temp);                    // toon temperatuur
  Serial.println(" C");                  // in graden Celsius  
  delay(1000);                           // even wachten 
}

// de thermistor functie doet de omzetting van de sensorwaarde naar temperatuur
double thermistor(int waarde) {
  double Temp;
  Temp = log(10000.0 * ((1024.0 / waarde - 1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp = Temp - 273.15;                  // Converteer Kelvin naar Celcius
  return Temp;
}

