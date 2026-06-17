#include <Wire.h>


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();
Wire.beginTransmission(0x68);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission();
Serial.print("AWAKEEEE");
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(0x68);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(0x68,14);

  if (Wire.available() == 14) {
    int16_t raw_accel_x = (Wire.read() << 8) | Wire.read();
    int16_t raw_accel_y = (Wire.read() << 8) | Wire.read();
    int16_t raw_accel_z = (Wire.read() << 8) | Wire.read();
    
    int16_t raw_temp    = (Wire.read() << 8) | Wire.read(); // Skip or use this
    
    int16_t raw_gyro_x  = (Wire.read() << 8) | Wire.read();
    int16_t raw_gyro_y  = (Wire.read() << 8) | Wire.read();
    int16_t raw_gyro_z  = (Wire.read() << 8) | Wire.read();

  Serial.print(raw_accel_x);
  Serial.print("|");
  Serial.print(raw_accel_y);
  Serial.print("|");
  Serial.print(raw_accel_z);
  Serial.print("|");
  Serial.print(raw_gyro_x);
  Serial.print("|");
  Serial.print(raw_gyro_y);
  Serial.print("|");
  Serial.print(raw_gyro_z);
  Serial.println("|");
  
}
delay(1000);
}
