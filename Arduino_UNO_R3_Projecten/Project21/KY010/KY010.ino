/*
    KY010 Licht onderbreking sensor
    
    Laat de ingebouwde led 13 oplichten wanneer het licht onderbroken wordt in de sensor.
    OPGELET : deze module is verkeerd gelabeld : signaal pin en - pin zijn omgewisseld !!!
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Licht onderbreking sensor KY010
    
*/

// constanten
const int led = 13;                        // interne led pin
const int onderbreking = 10;               // KY010 signaal pin

// variabelen
int waarde;                                // KY010 sensorwaarde

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(onderbreking, INPUT);            // onderbreking sensor is input
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  waarde = digitalRead(onderbreking);      // lees sensor
  if (waarde == HIGH) {                    // bij onderbreking
    digitalWrite(led, HIGH);               // led aanzetten
  } else {                                 // anders
    digitalWrite(led, LOW);                // led afzetten  
  }  
}
