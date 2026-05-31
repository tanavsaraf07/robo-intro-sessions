#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

byte eye1_00[]={0, 0, 1, 3, 3, 6, 6, 6};
byte eye1_01[]={0, 0, 16, 24, 24, 12, 12, 12};
byte eye1_10[]={6, 12, 12, 12, 24, 24, 16, 16};
byte eye1_11[]={12, 6, 6, 6, 3, 3, 1, 1};

byte eye2_00[]={0, 0, 1, 2, 4, 4, 12, 8};
byte eye2_01[]={0, 0, 16, 8, 4, 4, 6, 2};
byte eye2_10[]={8, 12, 4, 4, 2, 1, 0, 0};
byte eye2_11[]={2, 6, 4, 4, 8, 16, 0, 0};

byte eye3_00[]={0, 0, 0, 0, 0, 0, 7, 31};
byte eye3_01[]={0, 0, 0, 0, 0, 0, 28, 31};
byte eye3_10[]={31, 7, 0, 0, 0, 0, 0, 0};
byte eye3_11[]={31, 28, 0, 0, 0, 0, 0, 0};

byte eye4_00[]={0, 0, 0, 0, 3, 4, 12, 8};
byte eye4_01[]={0, 0, 0, 0, 24, 4, 6, 2};
byte eye4_10[]={8, 8, 6, 3, 0, 0, 0, 0};
byte eye4_11[]={2, 2, 12, 24, 0, 0, 0, 0};

byte eye5_00[]={0, 0, 0, 0, 1, 1, 3, 2};
byte eye5_01[]={0, 0, 0, 0, 16, 16, 24, 8};
byte eye5_10[]={4, 4, 12, 8, 16, 0, 0, 0};
byte eye5_11[]={4, 4, 6, 2, 1, 0, 0, 0};

void loadEye(byte eye_00[], byte eye_01[], byte eye_10[], byte eye_11[]) {
  lcd.createChar(0, eye_00);
  lcd.createChar(1, eye_01);
  lcd.createChar(2, eye_10);
  lcd.createChar(3, eye_11);
}
void drawEyes() {
  // left eye
  lcd.setCursor(4, 0); lcd.write(0);  // TL
  lcd.setCursor(5, 0); lcd.write(1);  // TR
  lcd.setCursor(4, 1); lcd.write(2);  // BL
  lcd.setCursor(5, 1); lcd.write(3);  // BR
  
  // right eye — same chars, different position
  lcd.setCursor(12, 0); lcd.write(0);
  lcd.setCursor(13, 0); lcd.write(1);
  lcd.setCursor(12, 1); lcd.write(2);
  lcd.setCursor(13, 1); lcd.write(3);
}

void setup() {
  lcd.init();
  lcd.backlight();
} 
void loop(){
  loadEye(eye1_00,eye1_01,eye1_10,eye1_11);
  drawEyes();
  delay(1000);
  loadEye(eye5_00,eye5_01,eye5_10,eye5_11);
  drawEyes();
  delay(100);
  loadEye(eye3_00,eye3_01,eye3_10,eye3_11);
  drawEyes();
  delay(1000);
  loadEye(eye5_00,eye5_01,eye5_10,eye5_11);
  drawEyes();
  delay(100);
}
