/*
    KY039 Hartslag sensor
    
    Laat de ingebouwde led oplichten in het ritme van je hartslag. Plaats hiervoor je vinger 
    tussen de infrarode sensor en de fototransistor van de module.
    
    Benodigdheden :
    - Arduino UNO, breadbord, jumper kabeltjes
    - Hartslag sensor KY039
*/

// constanten
const int sensorPin = A0;                  // KY039 signaal pin
const int led = 13;                        // led pin

// variabelen
float alpha = 0.75;                        // 
float change = 0.0;                        //
float maxval = 0.0;                        //
int period = 50;                           //

// de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
// of wanneer op de reset knop gedrukt wordt
void setup() {
  pinMode(led, OUTPUT);                    // led is output
  pinMode(sensorPin, INPUT);               // KY039 pin is input
  Serial.begin(9600);                      // seriële monitor initialiseren
  Serial.println("Hartslag detectie");    
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt
void loop() {
  static float oldValue=1009;
  static float oldChange=0.2;

  // This is generic code provided with the board.
  int rawValue=analogRead(sensorPin);
  float value= alpha*oldValue +(1-alpha)* rawValue;
  change=value-oldValue;

  // Display data on the LED via a blip:
  // Empirically, if we detect a peak as being X% from
  // absolute max, we find the pulse even when amplitude
  // varies on the low side.
  
  // Reset max every time we find a new peak
  if (change >= maxval) {
    maxval = change;
    Serial.println("  |");
    digitalWrite(led, HIGH);
  } else {
    Serial.println("|");
    digitalWrite(led, LOW);
  }
  // Slowly decay max for when sensor is moved around
  // but decay must be slower than time needed to hit
  // next heartbeat peak.
  maxval = maxval * 0.98;
  
  // Display debug data on the console
  Serial.print(value);
  Serial.print(", ");
  Serial.print(change);
  Serial.print(", ");
  Serial.println(maxval);

  oldValue=value;
  oldChange=change;
  delay(period);
}


