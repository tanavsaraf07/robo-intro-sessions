const int out_pin=A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(out_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(out_pin));
  delay(100);
}
