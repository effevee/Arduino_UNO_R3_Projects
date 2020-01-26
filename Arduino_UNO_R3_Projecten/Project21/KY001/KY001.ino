/*
    KY001 Digitale temperatuur sensor
    
    Gebruik de sensor om de omgevingstemperatuur te bewaken en geef alarm bij 
    het overschrijden van 25 °C. Toon de resultaten in de seriële monitor.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Digitale temperatuur sensor KY001
    - 4.7K ohm weerstand
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// constanten
const int tempPin = 10;                            // KY001 signaal pin

// object declaraties
OneWire oneWire(tempPin);                          // Onewire object
DallasTemperature sensors(&oneWire);               // KY001 sensor
DeviceAddress tempSensor = {0x28, 0xFF, 0x80, 0x55, 0x62, 0x15, 0x02, 0x9F};

// variabelen
int minTemp = 15;                                  // alarm min temperatuur
int maxTemp = 25;                                  // alarm max temperatuur
float tempC;                                       // temperatuur in °C 
char alarmTemp;                                    // alarm temperaturen

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(tempPin, INPUT);                         // sensor is input
  Serial.begin(9600);                              // init seriële console
  sensors.begin();                                 // init Dallas sensors 
  sensors.setHighAlarmTemp(tempSensor, maxTemp);   // alarm min temperatuur
  sensors.setLowAlarmTemp(tempSensor, minTemp);    // alarm max temperatuur
  sensors.setResolution(tempSensor, 12);           // gevoeligheid (9-12)
}  

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  sensors.requestTemperaturesByAddress(tempSensor);// request temperatuur
  alarmTemp = sensors.getLowAlarmTemp(tempSensor); // lees min alarm
  Serial.print("Min: ");                           // toon 
  Serial.print(alarmTemp, DEC);                    // min alarm
  Serial.print(" C");                              // in °C
  alarmTemp = sensors.getHighAlarmTemp(tempSensor);// lees max alarm
  Serial.print("\tMax: ");                         // toon
  Serial.print(alarmTemp, DEC);                    // max alarm
  Serial.print(" C");                              // in °C
  tempC = sensors.getTempC(tempSensor);            // lees temperatuur
  Serial.print("\tTemperatuur: ");                 // toon 
  Serial.print(tempC, 2);                          // temperatuur
  Serial.print(" C");                              // in °C
  if (sensors.hasAlarm(tempSensor)) {              // zijn er alarmen ?
    Serial.println("\tAlarm");                     // toon Alarm
  } else {                                         // anders
    Serial.println("\tGeen Alarm");                // toon Geen alarm
  }
  delay(1000);                                     // wachten 
}
