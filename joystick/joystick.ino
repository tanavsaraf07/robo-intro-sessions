const int joy_x=A2;
const int joy_y=A1;
const int joy_sw=A0;


void setup() {
  // put your setup code here, to run once:
pinMode(joy_x,INPUT);
pinMode(joy_y,INPUT);
pinMode(joy_sw,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("joy_x :");
Serial.print(analogRead(joy_x));
Serial.print("joy_y :");
Serial.print(analogRead(joy_y));
Serial.print("joy_sw :");
Serial.print(analogRead(joy_sw));
delay(200);
Serial.println();
}
