// C++ code
//
#include <Servo.h>

// defining the varible of the potentiometer
int Pot = 0;
// defining the varible that is gonna be fed into the servo (the value of potentiometer)
int Out = 0;
//defining the varible of the switch which controllers shoot loader
int but = 0;

// defining servo 1
Servo servo_6;
// defining servo 2
Servo servo_3;
// defining servo 3
Servo servo_5;

void setup()
{
  //defining the pins for motor driver
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  // defining pins for potentimeter 1
  pinMode(A1, INPUT);
  servo_6.attach(6, 500, 2500);
  // defining button pin
  pinMode(4, INPUT);
  servo_3.attach(3, 500, 2500);
  // defining pins for potentimeter 1
  pinMode(A0, INPUT);
  servo_5.attach(5, 500, 2500);
}

void loop()
{
  // writing the values for the pins
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);

  Pot = analogRead(A1);
  Out = map(Pot, 0, 1023, 0, 180);
  servo_6.write(Out);

  but = digitalRead(4);
  if (but == 1) {
    servo_3.write(90);
  } else {
    servo_3.write(0);
  }

  Pot = analogRead(A0);
  Out = map(Pot, 0, 1023, 0, 180);
  servo_5.write(Out);
  delay(10); // Delay a little bit to improve simulation performance
}
