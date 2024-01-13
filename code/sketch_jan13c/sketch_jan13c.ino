int xjoy=6, yjoy=7;
float xread, yread;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xjoy, INPUT);
  pinMode(yjoy, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  xread = analogRead(A0);
  yread = analogRead(A1);
  Serial.print("x-coordinate: ");
  Serial.println(xread);
  Serial.print("y-coordinate: ");
  Serial.println(yread);
  delay(500);
  
}
