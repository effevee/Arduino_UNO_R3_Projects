/*

  Gebruik de L298N motorsturing module om 2 DC motoren te sturen. 
  We besturen de motoren via toetsaanslagen in de seriële monitor : 
	Motor 1 : '1' = vooruit – '2' = stoppen – '3' = achteruit
	Motor 2 : '4' = vooruit – '5' = stoppen – '6' = achteruit

*/

// constanten
const int In1Pin = 6;                         // In1 pin motor A (draairichting)
const int In2Pin = 7;                         // In2 pin motor A (draairichting)
const int EnAPin = 10;                        // EnA pin motor A (snelheid - PWM!)

const int In3Pin = 8;                         // In3 pin motor B (draairichting)
const int In4Pin = 9;                         // In4 pin motor B (draairichting)
const int EnBPin = 5;                         // EnB pin motor B (snelheid - PWM!)

// variabelen
int snelheid;                                 // variabele voor snelheid

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {
  // de pinnen initialiseren
  pinMode(In1Pin, OUTPUT);
  pinMode(In2Pin, OUTPUT);
  pinMode(In3Pin, OUTPUT);
  pinMode(In4Pin, OUTPUT);
  pinMode(EnAPin, OUTPUT);
  pinMode(EnBPin, OUTPUT);
  
  // Seriele monitor initialiseren
  Serial.begin(9600);
  Serial.println("Motor A: 1=vooruit - 2=stoppen - 3=achteruit");
  Serial.println("Motor B: 4=vooruit - 5=stoppen - 6=achteruit");
  Serial.println("--------------------------------------------");
  
}
 
// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  if (Serial.available() > 0) {                // toetsaanslag ontvangen ?
    int toets = Serial.read();                 // toets inlezen 
    
    switch(toets) {                
    
      case '1':  
        Serial.println("Motor A vooruit");
        digitalWrite(In1Pin, LOW);             // vooruit - laag
        digitalWrite(In2Pin, HIGH);            // vooruit - hoog
        for (snelheid=0; snelheid<256; snelheid++) {                
          analogWrite(EnAPin, snelheid);       // opspinnen
          delay(20);                           // korte pauze
        }  
        break;
      
      case '2':  
        Serial.println("Motor A stoppen"); 
        for (snelheid=255; snelheid>=0; snelheid--) {                
          analogWrite(EnAPin, snelheid);       // afspinnen
          delay(20);                           // korte pauze
        }  
        digitalWrite(In1Pin, LOW);             // stoppen  
        digitalWrite(In2Pin, LOW);             // stoppen  
        break;

      case '3':  
        Serial.println("Motor A achteruit"); 
        digitalWrite(In1Pin, HIGH);            // achteruit - hoog
        digitalWrite(In2Pin, LOW);             // achteruit - laag
        for (snelheid=0; snelheid<256; snelheid++) {                
          analogWrite(EnAPin, snelheid);       // opspinnen
          delay(20);                           // korte pauze
        }  
        break;

      case '4':  
        Serial.println("Motor B vooruit"); 
        digitalWrite(In3Pin, LOW);             // vooruit - laag
        digitalWrite(In4Pin, HIGH);            // vooruit - hoog
        for (snelheid=0; snelheid<256; snelheid++) {                
          analogWrite(EnBPin, snelheid);       // opspinnen
          delay(20);                           // korte pauze
        }  
        break;

      case '5':  
        Serial.println("Motor B stoppen"); 
        for (snelheid=255; snelheid>=0; snelheid--) {                
          analogWrite(EnBPin, snelheid);       // afspinnen
          delay(20);                           // korte pauze
        }  
        digitalWrite(In3Pin, LOW);             // stoppen  
        digitalWrite(In4Pin, LOW);             // stoppen  
        break;

      case '6':  
        Serial.println("Motor B achteruit"); 
        digitalWrite(In3Pin, HIGH);            // achteruit - hoog
        digitalWrite(In4Pin, LOW);             // achteruit - laag
        for (snelheid=0; snelheid<256; snelheid++) {                
          analogWrite(EnBPin, snelheid);       // opspinnen
          delay(20);                           // korte pauze
        }  
        break;

      default: 
        Serial.println("Ongeldige toets");
    }
  }  
}      



