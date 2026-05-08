#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0*27, 16, 2);

unsigned long startMillis;
unsigned long elapsedMillis;

void setup(){

    Wire.begin(20, 21);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Study Timer");
    delay(2000);

    startMillis = millis();
}

void loop(){
    elapsedMillis = millis() - startMillis;
    unsigned long seconds = elapsedMillis / 1000;
    unsigned long minutes = seconds / 60;
    seconds = seconds % 60;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.printf("Study Timer:");
    lcd.setCursor(0, 1);
    lcd.print("m ");
    lcd.print(seconds);
    lcd.print("s");

    delay(1000);
}
