#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
lcd.init() ;
lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
     // turns backlight on
lcd.setCursor(0,0);     // same as before
lcd.print("HOLA");
lcd.setCursor(0,1);
lcd.print("Me TANAV");
delay(500);
lcd.setCursor(10,0);
lcd.print("HEHE");
delay(100);
lcd.clear();

}
