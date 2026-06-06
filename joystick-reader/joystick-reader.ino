const int x_pin=35;
const int y_pin=34;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run onc
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("x val :");
  Serial.print(analogRead(x_pin));
  Serial.print("    y val :");
  Serial.println(analogRead(y_pin));
delay(1000);
}
