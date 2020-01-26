/*
  Spanningsdeler
  
  Plaats een vaste weerstand en een variabele weerstand (potentiometer) in serie met elkaar 
  en meet de spanning over de vaste weerstand. Draai aan de potentiometer en toon de
  resultaten in de seriële monitor.
  
*/

// constanten
const int meetPin = A0;      // de analoge poort voor de meting

// variabelen
int meetwaarde = 0;          // houdt de ruwe meetwaarde bij
float spanning = 0.0;        // spanning over de vaste weerstand

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// wanneer op de reset knop gedrukt wordt
void setup() {

  // initialiseer analoge poort voor de meting als input.
  pinMode(meetPin, INPUT);
  
  // initialiseer de seriële monitor op 9600 baud (bits/sec).
  Serial.begin(9600);
  
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  
  // lees de waarde op de meetPin
  meetwaarde = analogRead(meetPin);
  
  // toon de meetwaarde in de seriële monitor
  Serial.print("Vaste weerstand - meetwaarde: ");
  Serial.print(meetwaarde);
  
  // De meting van de analoge poort geeft een resultaat van 0 tot 1023
  // We gebruiken de regel van 3 om de meetwaarde om te zetten naar de werkelijke spanning
  spanning = (meetwaarde/1024.0) * 5.0;
    
  // toon de spanning in de seriële monitor
  Serial.print("\t spanning: ");
  Serial.print(spanning);
  Serial.println("V");
  
  // kleine vertraging inbouwen
  delay(1000);
    
}
