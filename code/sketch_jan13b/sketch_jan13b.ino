int trig=8,echo=9;
void setup() {
  // put your setup code here, to run once:

  // open the connection as a serial bus, with a bitrate of 9.6k
  Serial.begin(9600); //
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);

}
float duration_us, distance_cm;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("distance in cms:");
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration_us = pulseIn(echo, HIGH);
  distance_cm = 0.017*duration_us;
  Serial.println(distance_cm);
  delay(500);
}
