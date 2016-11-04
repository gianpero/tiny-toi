#define C0  100
#define D0  200
#define E0  300
#define F0  400
#define G0  500
#define B0  600

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 0;

byte smiley[8] = {
    0b00000,
    0b11011,
    0b11011,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000
};

byte sad[8] = {
    0b00000,
    0b00000,
    0b11011,
    0b11011,
    0b00000,
    0b01110,
    0b10001,
    0b00000
};



int tempRaw;
float temp;
int B=4250;
float equivResistance;

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Temperature:");
  lcd.createChar(3, smiley);
  lcd.createChar(4, sad);
}

void loop()
{
  tempRaw=analogRead(0);
  equivResistance=(float)(1023-tempRaw)*10000/tempRaw;
  temp=1/(log(equivResistance/10000)/B+1/298.15)-273.15;
  Serial.println(temp);
  lcd.setCursor(0, 1);
  lcd.print(temp);
  noTone(3);
  if (temp > 28){
    lcd.setCursor(7, 1);
    lcd.write(4);
    delay(1000);
    tone(3,C0,1000);
    delay(100);
    tone(3,D0,1000);
    delay(100);
    tone(3,E0,1000);
    delay(100);
    tone(3,F0,1000);
    delay(100);
    tone(3,G0,1000);
    delay(100);
    tone(3,B0,1000);
    delay(100);
    }
    else{
        lcd.setCursor(7, 1);
        lcd.write(3);
      }
      delay(2000);
 }
