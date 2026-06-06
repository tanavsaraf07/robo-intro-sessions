#include <BleCombo.h>

const int x_pin = 34;
const int y_pin = 35;
const int sw_pin = 32;
const int red = 25;
const int green = 26;
const int blue = 27;

typedef enum{
  scroll,
  cursor,
  scr_vol
} states;
states cur_st = scroll;

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  Mouse.begin();
  pinMode(sw_pin, INPUT_PULLUP);
  ledcSetup(0, 5000, 8);
  ledcAttachPin(red, 0);
  ledcSetup(1, 5000, 8);
  ledcAttachPin(green, 1);
  ledcSetup(2, 5000, 8);
  ledcAttachPin(blue, 2);
}

void setColor(int r, int g, int b){
  ledcWrite(0, r);
  ledcWrite(1, g);
  ledcWrite(2, b);
}

void loop() {
  if (Keyboard.isConnected()){
    if (digitalRead(sw_pin)==LOW){
      delay(200);
      if(cur_st == scr_vol) cur_st = scroll;
      else if(cur_st == scroll) cur_st = cursor;
      else cur_st = scr_vol;
    }

    int x = analogRead(x_pin);
    int y = analogRead(y_pin);

    // deadzone
    if (abs(x - 2048) < 300) x = 2048;
    if (abs(y - 2048) < 300) y = 2048;

    Serial.print(x);
    Serial.print(" ");
    Serial.println(y);

    if(cur_st == scroll){
      setColor(0, 255, 255);
      int scroll_y = map(y, 0, 4095, -5, 5);
      int scroll_x = map(x, 0, 4095, -5, 5);
      if (abs(scroll_y) < 1) scroll_y = 0;   // snap to zero
      if (abs(scroll_x) < 1) scroll_x = 0;
      Mouse.move(0, 0, scroll_y, scroll_x);
    }
    else if (cur_st == cursor){
      setColor(0, 0, 255);
      int move_x = map(x, 0, 4095, -10, 10);
      int move_y = map(y, 0, 4095, -10, 10);
      if (abs(move_x) < 1) move_x = 0;       // snap to zero
      if (abs(move_y) < 1) move_y = 0;
      Mouse.move(move_x, move_y, 0, 0);
    }
    else{
      setColor(0, 255, 0);
      if (x > 2500){
        Keyboard.write(KEY_F7);
        delay(200);
      }
      else if (x < 1500){
        Keyboard.write(KEY_F6);
        delay(200);
      }
      if (y > 2500){
        Keyboard.write(KEY_F3);
        delay(200);
      }
      else if (y < 1500){
        Keyboard.write(KEY_F2);
        delay(200);
      }
    }
  }
  else {
    setColor(255, 0, 0);
  }
}