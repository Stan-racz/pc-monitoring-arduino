#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const byte LCDcolumns = 20;
const byte LCDrows = 4;

// 0x27 is the default address. Is your address 0x3F - if so, change 0x27 to 0x3F
LiquidCrystal_I2C lcd(0x27, LCDcolumns, LCDrows);

String serData;
int lengthString;

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino is ready!");
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("");
}

void loop() {
  while(Serial.available() > 0){
    char rec = Serial.read();
    serData += rec;
    if (rec=='%'){
      //lengthString = serData.length();
      //serData.remove(lengthString - 1, lengthString);
      Serial.print("Message received: ");
      lcd.setCursor(0, 0);
      lcd.print("RAM: " + serData);
      serData="";
    }
  }

delay(10);
}
