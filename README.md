# LCD-standard-versus-I2C
Arduino code voor standaard LCD omzetten naar I2C LCD
(LCD = Liquid Crystal Display)

In Arduino IDE vind je onder voorbeelden (via menu: Bestand - Voorbeelden - LiquidCrystal - HelloWorld) een voorbeeldprogramma dat je ook kan gebruiken in Tinkercad.
Terwijl een standaard LCD aangesloten wordt met een 12-tal draadjes (6 digitale pinnen) kan je een I2C lcd aansluiten met een 4-tal draadjes (voeding + I2C-bus).

**Dus de voordelen van een I2C-LCD zijn:**
* Minder aansluitingen (minder kans op foutieve aansluitingen)
* Meer pinnen op Arduino beschikbaar dan bij een aansluiting met standaard LCD
* De LCD-commando's voor I2C-LCD zijn identiek aan de standaard LCD, enkele de library is verschillend


## Hoe installeer je de I2C-library?
Via https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library kan je de code downloaden.
Unzip deze code en plaats de folder "Arduino-LiquidCrystal-I2C-library" in de map libraries onder Arduino
(vb voor Windowsgebruikers onder C:\Users\JouwAccount\Documents\Arduino\Libraries\ )

## Wat zijn de verschillen tussen de standaard LCD en I2C-LCD-library?
* Vervang LiquidCrystal.h door LiquidCrystal_I2C.h
* Voeg Wire.h toe
* Vervang LiquidCrystal lcd(12, 11, 5, 4, 3, 2) door LiquidCrystal_I2C lcd(0x27,16,2)
  * 0x27 is een hexadecimaal adres voor je I2C LCD.  Dit kan soms ook 0x3F zijn.
  * 16,2 is de grootte van je scherm: 16 characters over 2 lijnen.  Een grotere LCD is 20,4.
* lcd.begin(16,2); wordt vervangen door lcd.begin(); 
* lcd.backlight();  mag je weglaten

![LCD-klassiekVersusI2C](https://user-images.githubusercontent.com/83965286/117681063-04566d00-b1b2-11eb-9f3c-deb9e1d0283f.PNG)

## Welke lcd-commando's zijn gemeenschappelijk tussen beide libraries:
LCD commando | betekenis
------------ | ---------
lcd.print(aantal);  | print data uit variabele aantal
lcd.print("Hallo wereld!"); | print tekst "Hallo wereld!"
lcd.setCursor(10,1); | zet cursor op 11e plaats op de 2e rij
lcd.clear(); | Wis het scherm
lcd.autoscroll(); | De tekst zal automatisch scrollen
lcd.noAutoscroll(); | De tekst zal niet meer automatisch scrollen

### Opmerking:
Wanneer je een teller van 100 naar 0 laat tellen op je LCD, dan blijven de rechtse tekens op je scherm staan. 
Dit kan je oplossen op 2 manieren:
##### Makkelijk:
123

##### Moeilijk
