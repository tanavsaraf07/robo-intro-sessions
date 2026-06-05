#include <BleCombo.h>

const int x_pin = 35;
const int y_pin = 34;
const int sw_pin = 32;
const int red = 25;
const int green = 26;
const int blue = 27;

typedef enum {
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

void setColor(int r, int g, int b) {
  ledcWrite(0, r);
  ledcWrite(1, g);
  ledcWrite(2, b);
}

void loop() {
  if (Keyboard.isConnected()) {
    if (digitalRead(sw_pin) == LOW) {
      delay(200);
      if (cur_st == scr_vol) cur_st = scroll;
      else if (cur_st == scroll) cur_st = cursor;
      else cur_st = scr_vol;
    }

    int x_raw = analogRead(x_pin);
    int y_raw = analogRead(y_pin);

    // per mode deadzone
    int deadzone_x, deadzone_y;
    if (cur_st == scroll)       { deadzone_x = 700; deadzone_y = 700; }
    else if (cur_st == cursor)  { deadzone_x = 500; deadzone_y = 300; }
    else                        { deadzone_x = 900; deadzone_y = 900; }

    bool x_active = abs(x_raw - 1255) > deadzone_x;
    bool y_active = abs(y_raw - 1867) > deadzone_y;

    if (cur_st == scroll) {
      setColor(0, 255, 255);
      int scroll_x = x_active ? map(x_raw, 0, 2612, -5, 5) : 0;
      int scroll_y = y_active ? map(y_raw, 0, 4095, 5, -5) : 0;
      if (abs(scroll_x) < 2) scroll_x = 0;
      if (abs(scroll_y) < 2) scroll_y = 0;
      Mouse.move(0, 0, scroll_y, scroll_x);
    }
    else if (cur_st == cursor) {
      setColor(0, 0, 255);
      int move_x = x_active ? map(x_raw, 0, 2612, -10, 10) : 0;
      int move_y = y_active ? map(y_raw, 0, 4095, -10, 10) : 0;
      Mouse.move(move_x, move_y, 0, 0);
    }
    else {
      setColor(0, 255, 0);
      if (x_active) {
        if (x_raw > 1255) { Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT); Keyboard.write('2'); Keyboard.releaseAll(); }
        else              { Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT); Keyboard.write('1'); Keyboard.releaseAll(); }
        delay(300);
      }
      if (y_active) {
        if (y_raw > 1867) { Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT); Keyboard.write('9'); Keyboard.releaseAll(); }
        else              { Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT); Keyboard.write('0'); Keyboard.releaseAll(); }
        delay(300);
      }
    }
  }
  else {
    setColor(255, 0, 0);
  }
  delay(10);
}