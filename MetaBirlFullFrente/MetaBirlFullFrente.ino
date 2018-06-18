#include <NewPing.h>
#include <HC05.h>

#define R1F 7
#define R1T 6
#define R2F 9
#define R2T 8
#define R3F 5
#define R3T 4
#define R4F 2
#define R4T 3
#define H5 13
#define sensorFrente A2
#define sensorTras A3

#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define TRIGGER_PIN  A0  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A1  // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// Posição das Rodas no carro:
//  #####
//  1###2
//  #####
//  3###4
//  #####
// Rodas: R(1,2,3,4)Frente(F),Traz(T)


int comando;
int led;
int tempo = 25; //MS
int ultrasom = 0;
int contFrente = 0;
int contTras = 0;

void setup() {
  pinMode(R1F, OUTPUT);
  pinMode(R1T, OUTPUT);
  pinMode(R2F, OUTPUT);
  pinMode(R2T, OUTPUT);

  pinMode(R3F, OUTPUT);
  pinMode(R3T, OUTPUT);
  pinMode(R4F, OUTPUT);
  pinMode(R4T, OUTPUT);

  pinMode(H5, OUTPUT);

  digitalWrite(R1F, LOW);
  digitalWrite(R1T, LOW);
  digitalWrite(R2F, LOW);
  digitalWrite(R2T, LOW);
  digitalWrite(R3F, LOW);
  digitalWrite(R3T, LOW);
  digitalWrite(R4F, LOW);
  digitalWrite(R4T, LOW);
  digitalWrite(H5, HIGH);

  Serial.begin(38400);
}
void irFrente() {
  digitalWrite(R1F, HIGH);
  digitalWrite(R2F, HIGH);
  digitalWrite(R3F, HIGH);
  digitalWrite(R4F, HIGH);
  delay(tempo);
  parar();
}
void irTras() {
  digitalWrite(R1T, HIGH);
  digitalWrite(R2T, HIGH);
  digitalWrite(R3T, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void irEsquerdaFrente() { //G - 71
  digitalWrite(R2F, HIGH);
  digitalWrite(R3T, HIGH);
  digitalWrite(R4F, HIGH);
  delay(tempo);
  parar();
}
void irDireitaFrente() { //I - 73
  digitalWrite(R1F, HIGH);
  digitalWrite(R3F, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void irEsquerdaTras() { //H - 72
  digitalWrite(R1F, HIGH);
  digitalWrite(R2T, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void irDireitaTras() { //J - 74
  digitalWrite(R1T, HIGH);
  digitalWrite(R2F, HIGH);
  digitalWrite(R3T, HIGH);
  delay(tempo);
  parar();
}
void irEsquerda() {
  digitalWrite(R1T, HIGH);
  digitalWrite(R2F, HIGH);
  digitalWrite(R3T, HIGH);
  digitalWrite(R4F, HIGH);
  delay(tempo);
  parar();
}
void irDireita() {
  digitalWrite(R1F, HIGH);
  digitalWrite(R2T, HIGH);
  digitalWrite(R3F, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void parar() {
  digitalWrite(R1F, LOW);
  digitalWrite(R1T, LOW);
  digitalWrite(R2F, LOW);
  digitalWrite(R2T, LOW);
  digitalWrite(R3F, LOW);
  digitalWrite(R3T, LOW);
  digitalWrite(R4F, LOW);
  digitalWrite(R4T, LOW);
}

void loop() {
  digitalWrite(R1F, HIGH);
  digitalWrite(R2F, HIGH);
  digitalWrite(R3F, HIGH);
  digitalWrite(R4F, HIGH);
}


