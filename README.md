# LCD-standard-versus-I2C
Arduino code voor standaard LCD omzetten naar I2C LCD
(LCD = Liquid Crystal Display)

In Arduino IDE vind je onder voorbeelden (via menu: Bestand - Voorbeelden - LiquidCrystal - HelloWorld) een voorbeeldprogramma dat je ook kan gebruiken in Tinkercad.
Terwijl een standaard LCD aangesloten wordt met een 12-tal draadjes (6 digitale pinnen) kan je een I2C lcd aansluiten met een 4-tal draadjes (voeding + I2C-bus).

## Vergelijk de aansluitingen:
![LCD-standaardM](https://user-images.githubusercontent.com/83965286/117715213-45617800-b1d8-11eb-8cc5-f32ab306d9aa.JPG)
Aansluiting van standaard LCD (in Tinkercad)

![fritzing-sketch-for-lcd1602](https://user-images.githubusercontent.com/83965286/117715169-367ac580-b1d8-11eb-8bf5-5eda6bc99e68.jpg)
Aansluiting van I2C LCD (in Fritzing): De I2C-bus op zit op Analoge pinnen 4 + 5
SCL = Serial Clock (op pin A5)
SDA = Serial Data (op pin A4) 

**De voordelen van een I2C-LCD zijn:**
* Minder aansluitingen (minder kans op foutieve aansluitingen)
* Meer pinnen op Arduino beschikbaar dan bij een aansluiting met standaard LCD
* De LCD-commando's voor I2C-LCD zijn identiek aan de standaard LCD, enkele de library is verschillend


## Hoe installeer je de I2C-library?
Via https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library kan je de code downloaden.
Unzip deze code en plaats de folder "Arduino-LiquidCrystal-I2C-library" in de map libraries onder Arduino
(vb voor Windowsgebruikers onder C:\Users\JouwAccount\Documents\Arduino\Libraries\ )
Bij deze bovenstaande manier dien je de Arduino IDE opnieuw op te starten, zodat de nieuwe library geladen word.
Een andere manier om een library vanaf zip-bestand te installeren, gaat via menu: Schets - Bibliotheek gebruiken - .ZIP-bibliotheek toevoegen
Zoals bij de meeste libraries zijn er ook hier enkele voorbeeldbestanden terug te vinden via menu: Bestand - Voorbeelden - Arduino-LiquidCrystal-I2C - HelloWorld


## Wat zijn de verschillen tussen de standaard LCD en I2C-LCD-library?
* Vervang LiquidCrystal.h door LiquidCrystal_I2C.h  (zie ook onderstaande afbeelding)
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
lcd.setCursor(10,1); | Zet cursor op 11e plaats op de 2e rij (Geef steeds de locatie aan waar je printen wil!!)
lcd.print(aantal);  | Print data uit variabele aantal
lcd.print("Hallo wereld!"); | Print tekst "Hallo wereld!"
lcd.clear(); | Wis het scherm
lcd.autoscroll(); | De tekst zal automatisch scrollen
lcd.noAutoscroll(); | De tekst zal niet meer automatisch scrollen

### Opmerking:
Wanneer je een waarde op LCD wil tonen, dan kies je met lcd.setCursor waar je deze op het LCD wil tonen.
Zodoende, indien je een teller van 100 naar 0 laat tellen op de 3e plaats van de 2e lijn op je LCD [lcd.setCursor(4,1)], dan blijven de rechtse overblijvende characters op je scherm staan. 
Dit kan je oplossen op 2 manieren:
##### Makkelijk:
Als je van 100 naar 99 telt, blijft er een 0 staat.  Je kan deze verwijderen door in dit geval 2 spaties te printen na het getal. (2 spaties zodat je van vb 100 naar 8 kan springen, zonder dat 0 blijft staat.

##### Moeilijk
Het ziet er veel beter uit als de waarde die je wil tonen, mooi rechts uitgelijnd is.
Dit zou je kunnen oplossen met deze beslissingen:
Als de waarde < 100, print dan 1 spatie
Als de waarde < 10, print dan 1 spatie, anders print je de waarde zonder spatie ervoor.
Op deze manier worden de waarden 100, 50, 2 correct getoond.
(zie ook voorbeeldprogramma)
