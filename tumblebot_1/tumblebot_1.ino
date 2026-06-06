const int ir_bl=5;
const int ir_br=4;
const int ir_tl=3;
const int ir_tr=2;

const int ena=9;
const int enb=10;
const int in1=8;
const int in2=7;
const int in3=11;
const int in4=12;

unsigned long lastChange = 0;

void setup() {
  pinMode(ir_bl,INPUT);
  pinMode(ir_br,INPUT);
  pinMode(ir_tl,INPUT);
  pinMode(ir_tr,INPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  randomSeed(analogRead(A0));    // add this
}

void front_drive(int speed_a,int speed_b){
  digitalWrite(in1,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  analogWrite(ena,speed_a);
  analogWrite(enb,speed_b);
}

void rear_drive(int speed_a,int speed_b){
  digitalWrite(in2,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in3,LOW);
  analogWrite(ena,speed_a);
  analogWrite(enb,speed_b);
}

void right_drive(int speed_a,int speed_b){
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in4,LOW);
  analogWrite(ena,speed_a);
  analogWrite(enb,speed_b);
}

void left_drive(int speed_a,int speed_b){
  digitalWrite(in1,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  analogWrite(ena,speed_a);
  analogWrite(enb,speed_b);
}

void stop_func(){
  digitalWrite(in1,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
}

void random_move(){
  int move = random(0,4);
  if (move==0) front_drive(150,150);
  else if (move==1) left_drive(150,150);
  else if (move==2) right_drive(150,150);
  else rear_drive(150,150);
  delay(random(200,600));
}

/*void loop() {
  int read_ir_bl=digitalRead(ir_bl);    // add int to all 4
  int read_ir_br=digitalRead(ir_br);
  int read_ir_tl=digitalRead(ir_tl);
  int read_ir_tr=digitalRead(ir_tr);

  if (read_ir_bl==HIGH && read_ir_br==HIGH){
    front_drive(255,255);
    delay(500);
    random_move();                        
  }
  else if (read_ir_tl==HIGH && read_ir_tr==HIGH){
    rear_drive(255,255);
    delay(500);
    random_move();
  }
  else if (read_ir_tl==HIGH){
    right_drive(150,150);
    delay(200);
    random_move();
  }
  else if (read_ir_tr==HIGH){
    left_drive(150,150);
    delay(200);
    random_move();
  }
  else if (read_ir_bl==HIGH){
    front_drive(150,150);
    delay(200);
    right_drive(150,150);
    delay(200);
    random_move();
  }
  else if (read_ir_br==HIGH){
    front_drive(150,150);
    delay(200);
    left_drive(150,150);
    delay(200);
    random_move();
  }
  else {
     if (millis() - lastChange > random(800, 2000)) {  // random interval
      random_move();
      lastChange = millis();
  }}
}*/
void loop() {
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

analogWrite(enb, 255);
analogWrite(ena, 255);
}