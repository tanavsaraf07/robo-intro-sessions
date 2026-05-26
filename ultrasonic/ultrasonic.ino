const int trig=7;
const int echo=6;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long dur =pulseIn(echo,HIGH);
  float dist=(dur*0.343)/2;
  Serial.println(dist);
  delay(5);
}
