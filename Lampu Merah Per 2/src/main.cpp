/*#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(1, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}*/

#include <Arduino.h>

int ALED = D2;
int BLED = D0;
int CLEk = D4;

void setup() {
  pinMode(ALED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(CLEk, OUTPUT);
}

void loop() {
  digitalWrite(ALED, HIGH);
  delay(500);
  digitalWrite(ALED, LOW);
  digitalWrite(BLED, HIGH);
  delay(500);
  digitalWrite(BLED, LOW);
  digitalWrite(CLEk, HIGH);
  delay(500);
  digitalWrite(CLEk, LOW);
}