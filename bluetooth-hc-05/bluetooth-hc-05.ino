  const int enpin=8;
  const int statepin=9;

  
  void setup() {
  // put your setup code here, to run once:
  pinMode(enpin,OUTPUT);
  pinMode(statepin,INPUT);
  Serial.begin(9600);
  digitalWrite(enpin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()){
  char data=Serial.read();
  Serial.println(data);
  }

}
