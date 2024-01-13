# Arduino workshop by Robotics Student Association of TU Delft

Analog pins for feeding sigals - used for motors, sensors, etc.

- download and install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)

```ino
void setup() {
 // put your setup code here, to run once:
 // configuration and setup, before the real code starts
 // running

}

void loop() {
 // put your main code here, to run repeatedly:
 // while(1) { ... }
}
```

Something more -> go to Tools -> Board -> Select the board that you use (Arduino Uno, Arduino Nano, etc.)
Code is based on C/C++ language so you need to compile based on the board that you use.

Not all boards work the same with the same code, so you need to select the right one.

To use foreign sensors ( that are not from Arduino ) you need to install the library for that sensor. Go to Sketch -> Include Library -> Manage Libraries -> Search for the library that you need -> Install. After that, you can use the library in your code by importing it with `#include <library_name.h>`.

The `Hello world` of Arduino is making an LED blink.

### Blinking LED

#### Breadboard

The breadboard has 2 sides, one for power and one for ground. The power side is marked with a red line and the ground side is marked with a blue line.
There is also an area in the middle there you can connect components. The middle area is connected horizontally, but not vertically. The power and ground sides are connected vertically, but not horizontally.

# LED Blinking

https://docs.arduino.cc/built-in-examples/basics/Blink

```ino
int led=7; // use digital port 7
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT); // set the led pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500); // wait for 500ms
  digitalWrite(led,HIGH); // turn on the led
  delay(500); // wait for 500ms
  digitalWrite(led,LOW); // turn off the led
}
```

# Distance sensor

```ino
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

```

# Joystick

[Webpage](https://arduinogetstarted.com/tutorials/arduino-joystick)

```ino
int xjoy=6, yjoy=7;
float xread, yread;
/*
 * Joystick controls
    * x-axis: A0
    * y-axis: A1
 */
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

```

# Motor driver and motor + Joystick

```ino
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
```

# Using pwm to control the speed of the motor

[link to article discussing this](https://support.arduino.cc/hc/en-us/articles/9350537961500-Use-PWM-output-with-Arduino)
