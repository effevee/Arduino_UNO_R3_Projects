/*
    KY008 Laser diode
    
    Laat de ingebouwde led 13 oplichten wanneer de laser diode actief is.
    OPGELET : KIJK NOOIT RECHTSTREEKS IN DE LASERSTRAAL !!!!!!
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Laser diode module KY008
    
*/

// constanten
const int led = 13;                        // interne led pin
const int laser = 10;                      // KY008 signaal pin

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(laser, OUTPUT);                  // laser is output
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  digitalWrite(laser, HIGH);               // laser aanzetten
  digitalWrite(led, HIGH);                 // led aanzetten
  delay(1000);                             // wacht 1 sec
  digitalWrite(laser, LOW);                // laser afzetten
  digitalWrite(led, LOW);                  // led afzetten
  delay(1000);                             // wacht 1 sec
}
