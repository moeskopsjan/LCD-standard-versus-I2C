/*  Jan Moeskops - oktober 2019
Een I2C-LCD waarvan volgende pinnen aangesloten zijn op
SCL op A5
SDA op A4

Dit programma werkt met een I2C-LCD
Opgelet: bij deze LCD's bestaan er 2 I2C adressen:
0x27 of 0x3F

Sterretje rollen over het scherm
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);     // hier bepaal je ook de grootte van het LCD
//LiquidCrystal_I2C lcd(0x3F, 16, 2);   // indien bij 0x27 niets getoond wordt

void setup()
{
	// initialize the LCD
	lcd.begin();
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
