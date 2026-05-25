const int out_pin=2;
void setup() {
  // put your setup code here, to run once:
  pinMode(out_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(out_pin)==LOW) {
    Serial.println("Surface");

  }
  else {
    Serial.println("CLIFFFFFFF");
  }
}
