const int ana_read=A0;
const int dig_read=2;

struct reading{
  int ana_val;
  int dig_val;
};

reading readings[100];
int index=0;
void setup() {
  // put your setup code here, to run once:
pinMode(ana_read,INPUT);
pinMode(dig_read,INPUT);
Serial.begin(9600);
}
void loop(){
  Serial.println(analogRead(ana_read));
  delay(500);
}
/*
void loop() {

  if (index < 100) {
    readings[index].ana_val = analogRead(ana_read);
    readings[index].dig_val = digitalRead(dig_read);
    index++;
    delay(100);
  }
  else {
    for (int i = 0; i < 100; i++) {
      Serial.print(readings[i].ana_val);
      Serial.print(", ");
      Serial.println(readings[i].dig_val);
    }
    while(true);
  }
}
*/