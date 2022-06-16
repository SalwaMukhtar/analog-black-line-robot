#define leftmotorreverse 3
#define leftmotorforward 5
#define rightmotorreverse 6
#define rightmotorforward 9

#define leftIR  A0
#define rightIR  A1
void setup(){
  pinMode(leftmotorforward,OUTPUT);
  pinMode(rightmotorforward,OUTPUT);
  pinMode(leftmotorreverse, OUTPUT);
  pinMode(rightmotorreverse,OUTPUT); 
  pinMode(leftIR ,INPUT);
  pinMode(rightIR ,INPUT);

  Serial.begin(9600);
}
void loop(){
  if (analogRead(leftIR) < 500 && analogRead(rightIR) < 500)// Forward
  {
    analogWrite(leftmotorforward, 150);
    analogWrite(rightmotorforward, 150);  
  }
  else if (analogRead(leftIR) <500 && analogRead(rightIR) >= 500)// Right
  {
    analogWrite(leftmotorforward,130);
    analogWrite(rightmotorforward,LOW ); 
  }
  else if (analogRead(leftIR) >= 500 && analogRead(rightIR)< 500 )// Left
  {
    analogWrite(leftmotorforward,LOW );
    analogWrite(rightmotorforward,130 ); 
  }
  else if (analogRead(leftIR) >=500  && analogRead(rightIR) >=500 )// Stop
  {
    analogWrite(leftmotorforward,LOW );
    analogWrite(rightmotorforward,LOW ); 
  }
  delay(1);
}
