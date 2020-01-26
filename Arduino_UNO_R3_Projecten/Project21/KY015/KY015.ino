/*
    KY015 Temperatuur en vochtigheid sensor
    
    Toon temperatuur en vochtigheid in de seriële console. 
              
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Temperatuur en vochtigheid sensor KY015

*/

#include <DHT.h>                           // DHTxx bibliotheek 
#define DHTTYPE DHT11                      // wij gebruiken een DHT11

// constanten
const int dht11Pin = 9;                    // KY015 signaal pin

// object declaratie
DHT sensor(dht11Pin, DHTTYPE);

// variabelen
float vochtigheid;                         // vochtigheid
float temperatuur;                         // temperatuur (°C) 
float gevoelstemp;                         // gevoelstemperatuur (°C)

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  Serial.begin(9600);                      // init seriële console
  sensor.begin();                          // init KY015 sensor
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  delay(2000);                             // even wachten - trage sensor !  
  vochtigheid = sensor.readHumidity();     // lees vochtigheid
  temperatuur = sensor.readTemperature();  // lees temperatuur
  // bereken gevoelstemperatuur (parameter 3 : false voor °C, true voor °F)   
  gevoelstemp = sensor.computeHeatIndex(temperatuur, vochtigheid, false);
  Serial.print("Vochtigheid: ");           // toon 
  Serial.print(vochtigheid);               // vochtigheid
  Serial.print(" %");                      // in procent
  Serial.print("\tTemperatuur: ");         // toon
  Serial.print(temperatuur);               // temperatuur
  Serial.print(" C");                      // in Celsius
  Serial.print("\tGevoelstemperatuur: ");  // toon
  Serial.print(gevoelstemp);               // gevoelstemperatuur
  Serial.println(" C");                    // in Celsius  
}

  

