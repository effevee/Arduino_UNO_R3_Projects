
/*
    ST7735 1.8" TFT kleurenscherm
    
    Experimenteer met het ST7735 1.8" TFT kleurenscherm
    Afbeelden van een bitmap afbeelding van de SD kaart op het scherm
    
*/

// bibliotheken
#include <SPI.h>
#include <SD.h>
#include <TFT.h>

// constanten
const int sclk = 13;
const int mosi = 11;
const int cs = 10;
const int dc = 9;
const int rst = 8;
const int cs_sd = 4;

const int PixelBuffer = 20;                      // buffer voor pixels

// variabelen
int ST7735_wit, ST7735_zwart;                    // kleuren

// object declaratie              
TFT scherm = TFT(cs, dc, rst);                   // lcd scherm
PImage logo;                                     // bitmap afbeelding

void setup() {
  // de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
  // wanneer op de reset knop gedrukt wordt

  ST7735_wit = scherm.Color565(255, 255, 255);   // wit
  ST7735_zwart = scherm.Color565(0, 0, 0);       // zwart
  
  scherm.begin();                                // initialisatie scherm
  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.setTextSize(2);                         // tekst grootte
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Init SDcard");                 // Initialisatie SD kaart
  if (SD.begin(cs_sd)) {
    scherm.println(" OK");                       // ok
  } else {
    scherm.println(" FOUT");                     // fout
    return;                                      // stoppen
  }
  delay(1000);                                   // wachten

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Zoeken");                      // Zoeken
  scherm.println(" parrot.bmp");                 // bitmap afbeelding
  logo = scherm.loadImage("parrot.bmp");         // bitmap openen
  if (logo.isValid()) {
    scherm.println(" OK");                       // ok
  } else {
    scherm.println(" FOUT");                     // fout
    return;                                      // stoppen
  }
  delay(1000);                                   // wachten

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println(" Resolutie");                  // Resolutie
  scherm.print(" ");            
  scherm.print(logo.width());                    // breedte
  scherm.print(" x ");                           // x
  scherm.println(logo.height());                 // hoogte
  delay(1000);                                   // wachten 

  scherm.setRotation(0);                         // logo rechtop  
  scherm.image(logo, 0, 0);                      // bitmap tekenen 
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
}


