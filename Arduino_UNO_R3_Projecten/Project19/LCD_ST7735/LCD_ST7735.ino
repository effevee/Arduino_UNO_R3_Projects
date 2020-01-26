
/*
    ST7735 1.8" TFT kleurenscherm
    
    Experimenteer met het ST7735 1.8" TFT kleurenscherm.
    
*/

// bibliotheken
#include <TFT.h>
#include <SPI.h>

// constanten
const int sclk = 13;
const int mosi = 11;
const int cs = 10;
const int dc = 9;
const int rst = 8;
const int cs_sd = 4;

const String rot[4] = { " 270 gr ", "   0 gr ", "  90 gr ", " 180 gr "};
const String kleur[8] = { " Rood ", " Groen ", " Blauw ", " Geel ", \
                          " Magenta ", " Cyaan ", " Wit ", " Zwart "};

// variabelen
int ST7735_zwart, ST7735_wit, ST7735_rood, ST7735_groen, ST7735_blauw, \
ST7735_geel, ST7735_magenta, ST7735_cyaan;        // variabelen voor basiskleuren

int x, y;                                         // variabelen voor x, y
int k = 0;                                        // kleurindex

// object declaratie              
TFT scherm = TFT(cs, dc, rst);                    // lcd scherm

void setup() {
  // de setup functie wordt 1 maal uitgevoerd bij de start van de sketch 
  // wanneer op de reset knop gedrukt wordt

  scherm.begin();                                 // initialisatie scherm
  
  ST7735_rood = scherm.Color565(0, 0, 255);       // initialisatie basiskleuren
  ST7735_groen = scherm.Color565(0, 255, 0);
  ST7735_blauw = scherm.Color565(255, 0, 0);
  ST7735_geel = scherm.Color565(0, 255, 255);
  ST7735_magenta = scherm.Color565(255, 0, 255);
  ST7735_cyaan = scherm.Color565(255, 255, 0);
  ST7735_wit = scherm.Color565(255, 255, 255);
  ST7735_zwart = scherm.Color565(0, 0, 0);
}

// de loop functie wordt steeds herhaald tot de stroom wegvalt.
void loop() {
  
  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.setTextSize(2);                         // tekst grootte 
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Achtergrond");                 // achtergrond
  scherm.println(" kleuren");                    // kleuren
  delay(2000);                                   // wacht
  
  for (int i=0; i<7; i++) {                      // lus achtergrondkleur
    scherm.setCursor(10, 50);                    // cursor positie 
    scherm.setTextColor(ST7735_zwart,ST7735_wit); // tekstkleur zwart
    scherm.fillScreen(haalkleur(i));             // kleur achtergrond
    scherm.println(kleur[i]);                    // toon kleurnaam
    delay(2000);                                 // wacht
  }
 
  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.setTextSize(2);                         // tekst grootte 
  scherm.fillScreen(ST7735_zwart);               // achtergrond
  scherm.println("Fontsize");                    // tekst grootte
  delay(2000);                                   // wacht
  
  for (int f=1; f<11; f++) {                     // lus fontsize
    scherm.fillScreen(ST7735_zwart);             // achtergrond zwart
    scherm.setCursor(10, 40);                    // cursor positie
    k = volgendkleur();                          // volgend kleur
    scherm.setTextColor(haalkleur(k));           // tekst kleur
    scherm.setTextSize(f);                       // tekst grootte f 
    scherm.println(f);                           // print f
    delay(2000);                                 // wacht
  }  

  scherm.setCursor(0, 0);                        // cursor positie 
  scherm.setTextSize(1);                         // letter grootte                    
  scherm.setTextWrap(true);                      // zet tekstwrap aan
  k = volgendkleur();                            // volgend kleur
  scherm.setTextColor(haalkleur(k));             // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec commodo a tortor vitae lacinia. Praesent aliquet sodales ullamcorper. Donec sed euismod quam, hendrerit dignissim velit. Morbi aliquet interdum elit eu suscipit. Etiam accumsan auctor augue, non euismod velit scelerisque vel. Nullam molestie ullamcorper posuere. Quisque malesuada auctor lorem non dignissim. Etiam cursus ligula in mauris ultricies volutpat. Curabitur elementum leo odio, ac aliquam lacus euismod eu. Sed a neque vitae odio cursus commodo sed non massa. Proin sapien turpis, tincidunt ut rutrum quis, viverra nec odio. Quisque venenatis felis vestibulum porttitor iaculis. Donec mollis feugiat nunc, nec auctor mauris porta vitae. Etiam lacinia neque et congue efficitur. ");
  scherm.setTextWrap(false);                     // zet tekstwrap af
  delay(2000);                                   // wacht

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextSize(2);                         // letter grootte 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Lijnen");                      // Lijnen demo

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  k = volgendkleur();                            // volgend kleur
  for (x=0; x<scherm.width(); x=x+5) {           // lus x LB
    scherm.drawLine(0, 0, x, scherm.height(), haalkleur(k));
  }  
  k = volgendkleur();                            // volgend kleur
  for (y=scherm.height(); y>0; y=y-5) {          // lus y LB
    scherm.drawLine(0, 0, scherm.width(), y, haalkleur(k));
  }  
  
  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  
  k = volgendkleur();                            // volgend kleur
  for (x=0; x<scherm.width(); x=x+5) {           // lus x LO
    scherm.drawLine(0, scherm.height(), x, 0, haalkleur(k));
  }  
  k = volgendkleur();                            // volgend kleur
  for (y=0; y<scherm.height(); y=y+5) {          // lus y LO
    scherm.drawLine(0, scherm.height(), scherm.width(), y, haalkleur(k));
  }  

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  
  k = volgendkleur();                            // volgend kleur
  for (x=scherm.width(); x>0; x=x-5) {           // lus x RB
    scherm.drawLine(scherm.width(), 0, x, scherm.height(), haalkleur(k));
  }  
  k = volgendkleur();                            // volgend kleur
  for (y=scherm.height(); y>0; y=y-5) {          // lus y RB
    scherm.drawLine(scherm.width(), 0, 0, y, haalkleur(k));
  }  
  
  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  
  k = volgendkleur();                            // volgend kleur
  for (x=scherm.width(); x>0; x=x-5) {           // lus x RO
    scherm.drawLine(scherm.width(), scherm.height(), x, 0, haalkleur(k));
  }  
  k = volgendkleur();                          // volgend kleur
  for (y=0; y<scherm.height(); y=y+5) {          // lus y RO
    scherm.drawLine(scherm.width(), scherm.height(), 0, y, haalkleur(k));
  }  

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  for (y=0; y<scherm.height(); y=y+5) {          // lus y horizontaal
    k = volgendkleur();                          // volgend kleur
    scherm.drawFastHLine(0, y, scherm.width(), haalkleur(k));
  }  
  for (x=0; x<scherm.width(); x=x+5) {           // lus x vertikaal
    k = volgendkleur();                          // volgend kleur
    scherm.drawFastVLine(x, 0, scherm.height(), haalkleur(k));
  }  

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextSize(2);                         // letter grootte 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Rechthoeken");                 // rechthoeken

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  
  for (y=0; y<scherm.height()/2; y=y+5) {        // lus y rechthoeken  
    k = volgendkleur();                          // volgend kleur
    scherm.drawRect(y, y, scherm.width()-2*y, scherm.height()-2*y, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  for (y=0; y<scherm.height()/2; y=y+5) {        // lus y opgevulde rechthoeken  
    k = volgendkleur();                          // volgend kleur
    scherm.fillRect(y, y, scherm.width()-2*y, scherm.height()-2*y, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextSize(2);                         // letter grootte 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Afgeronde");                   // afgeronde 
  scherm.println(" rechthoeken");                // rechthoeken

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  
  for (y=0; y<scherm.height()/2-10; y=y+5) {     // lus y rechthoeken  
    k = volgendkleur();                          // volgend kleur
    scherm.drawRoundRect(y, y, scherm.width()-2*y, scherm.height()-2*y, 10, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  for (y=0; y<scherm.height()/2-5; y=y+5) {      // lus y opgevulde rechthoeken  
    k = volgendkleur();                          // volgend kleur
    scherm.fillRoundRect(y, y, scherm.width()-2*y, scherm.height()-2*y, 10, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  
  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextSize(2);                         // letter grootte 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Cirkels");                     // cirkels

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  for (y=0; y<scherm.height()/2; y=y+5) {        // lus y cirkels  
    k = volgendkleur();                          // volgend kleur
    scherm.drawCircle(scherm.width()/2, scherm.height()/2, scherm.height()/2-y, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  k = 0;
  for (y=0; y<scherm.height()/2; y=y+5) {        // lus y opgevulde cirkels  
    k = volgendkleur();                          // volgend kleur
    scherm.fillCircle(scherm.width()/2, scherm.height()/2, scherm.height()/2-y, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextSize(2);                         // letter grootte 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Driehoeken");                  // driehoeken

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  for (y=0; y<scherm.height()/2; y=y+5) {        // lus y driehoeken  
    k = volgendkleur();                          // volgend kleur
    scherm.drawTriangle(scherm.width()/2, y, y, scherm.height()-y, scherm.width()-y, scherm.height()-y, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  for (y=0; y<scherm.height()/2; y=y+5) {        // lus y opgevulde driehoeken  
    k = volgendkleur();                          // volgend kleur
    scherm.fillTriangle(scherm.width()/2, y, y, scherm.height()-y, scherm.width()-y, scherm.height()-y, haalkleur(k));
  }

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextSize(2);                         // letter grootte 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Roteer");                      // roteer
  scherm.println(" scherm");                     // scherm

  for (x=0; x<4; x++) {                          // lus rotatie
    scherm.setCursor(10, 50);                    // cursor positie 
    scherm.fillScreen(ST7735_zwart);             // zwarte achtergrond
    scherm.setRotation(x);                       // roteer
    scherm.setTextColor(ST7735_zwart, ST7735_wit); // zwart op wit
    scherm.println(rot[x]);                      // toon rotatie graden
    delay(2000);                                 // wacht
  }

  scherm.setRotation(1);                         // rotatie 90°  
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.setTextSize(2);                         // letter grootte 
  scherm.setTextColor(ST7735_wit);               // tekstkleur wit
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
  scherm.println("Inverteer");                   // inverteer
  scherm.println(" scherm");                     // scherm

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.invertDisplay(true);                    // inverteer
  scherm.println(" Inverted ");                  // toon tekst

  delay(2000);                                   // wacht
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond

  scherm.setCursor(10, 50);                      // cursor positie 
  scherm.invertDisplay(false);                   // normaal
  scherm.println(" Normaal ");                   // toon tekst

  delay(2000);                                   // wacht 
  scherm.fillScreen(ST7735_zwart);               // zwarte achtergrond
}

// functie om volgend kleur te bepalen
int volgendkleur() {
  k++;                                           // kleur index ophogen
  k=k%7;                                         // kleur index max 6 
  return k;                                      // return waarde
}
  
// functie waarde kleur ophalen
int haalkleur(int k) {
  int kleur;

  switch(k) {                                    // kleur selecteren 
    case 0:
      kleur = ST7735_rood;
      break;
    case 1:
      kleur = ST7735_groen;
      break;
    case 2:
      kleur = ST7735_blauw;
      break;
    case 3:
      kleur = ST7735_geel;
      break;
    case 4:
      kleur = ST7735_magenta;
      break;
    case 5:
      kleur = ST7735_cyaan;
      break;
    case 6:
      kleur = ST7735_wit;
      break;
    default:
      kleur = ST7735_wit;
  }

  return kleur;                                // return waarde
}

