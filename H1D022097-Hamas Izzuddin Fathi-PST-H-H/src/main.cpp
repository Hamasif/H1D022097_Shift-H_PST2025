#include <Arduino.h>
#include <Servo.h>

const int echoPin = D0;
const int trgPin = D1;
const int ledHijau = D2;
const int ledMerah = D3;
const int servoPin = D4;

Servo pagarServo;

long durasi;
int jarak;
int batasJarak = 150;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(trgPin,OUTPUT);
  pinMode(ledHijau,OUTPUT);
  pinMode(ledMerah,OUTPUT);
  pagarServo.attach(D5);
  pagarServo.write(0);
}

void loop() {
  digitalWrite(trgPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trgPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trgPin,LOW);

  durasi = pulseIn(echoPin,HIGH);
  jarak = durasi * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.println(jarak);
  Serial.println(" cm");

  if (jarak > 0 && jarak <= batasJarak) {
    pagarServo.write(90); 
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledMerah, LOW);
  } else {
    pagarServo.write(0); 
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledMerah, HIGH);
  }
  delay(500);
}