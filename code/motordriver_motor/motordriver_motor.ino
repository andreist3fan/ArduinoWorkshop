#include <Servo.h>
int enable = 9, in1 = 6, in2 = 7;
int xjoy=6, yjoy=7;
float xread, yread;
void setup() {
  // put your setup code here, to run once:
  Serial.println("setup");

  pinMode(enable, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
//
  Serial.begin(9600);
  pinMode(xjoy, INPUT);
  pinMode(yjoy, INPUT);

  //Servo servo = new Servo(pin1)
  //servo.write(0-255)
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(enable, HIGH);
  xread = analogRead(A0);
  yread = analogRead(A1);
  
  if(xread>600){

    Serial.println("entered ->");
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    delay(10);
    digitalWrite(in1,LOW);

  }
  else if (xread<400){ 
    Serial.println("entered <-");
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    delay(10);
    digitalWrite(in2,LOW);
  }


}
