/*  Jan Moeskops - oktober 2019
Een standaard LCD waarvan volgende pinnen aangesloten zijn op
rs = 12 
en = 11 
d4 = 5 
d5 = 4 
d6 = 3 
d7 = 2;

Dit programma werkt in Tinkercad

Sterretje rollen over het scherm
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  lcd.begin(16, 2);   // hier bepaal je de grootte van je LCD
  lcd.setCursor(4, 1); // op de 5e plaats op de 2e rij
  lcd.print("Moeskops");  // print deze tekst
}

void loop() 
{
  lcd.setCursor(0, 0);  //start Cursor vanaf de eerste plaats, bovenste regel
 for(int teller = 16; teller>=0; teller=teller-1)
 {
  // print 16 sterretjes
  lcd.print("*");
  delay(200);      // wacht 200 ms
 }
 delay(500); 
  
 for(int teller = 15; teller>= 0; teller=teller-1)
 {
  // wis de sterretjes
  lcd.setCursor(teller, 0);
  lcd.print(" ");
  delay(50);
 }
 delay(500);
}
