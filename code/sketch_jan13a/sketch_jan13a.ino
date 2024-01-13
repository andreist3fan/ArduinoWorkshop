int led=7; // use digital port 7
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
}
