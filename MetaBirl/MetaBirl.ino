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
#define LED 10
#define H5 13

#define sensorFrente A4
#define sensorTras A5

#define TRIGGER_ESQUERDO  A0
#define ECHO_ESQUERDO     A1
#define MAX_ESQUERDO 200
#define TRIGGER_DIREITO  A2
#define ECHO_DIREITO     A3
#define MAX_DIREITO 200

NewPing sonarEsquerdo(TRIGGER_ESQUERDO, ECHO_ESQUERDO, MAX_ESQUERDO);
NewPing sonarDireito(TRIGGER_DIREITO, ECHO_DIREITO, MAX_DIREITO);
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


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(R1F, OUTPUT);
  pinMode(R1T, OUTPUT);
  pinMode(R2F, OUTPUT);
  pinMode(R2T, OUTPUT);
  pinMode(R3F, OUTPUT);
  pinMode(R3T, OUTPUT);
  pinMode(R4F, OUTPUT);
  pinMode(R4T, OUTPUT);
  pinMode(H5, OUTPUT);
  
  digitalWrite(LED, LOW);
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
void irFrente(){
  digitalWrite(R1F, HIGH);
  digitalWrite(R2F, HIGH);
  digitalWrite(R3F, HIGH);
  digitalWrite(R4F, HIGH);
  delay(tempo);
  parar();
}
void irTras(){
  digitalWrite(R1T, HIGH);
  digitalWrite(R2T, HIGH);
  digitalWrite(R3T, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void irEsquerdaFrente(){ //G - 71
  digitalWrite(R2F, HIGH);
  digitalWrite(R3T, HIGH);
  digitalWrite(R4F, HIGH);
  delay(tempo);
  parar();
}
void irDireitaFrente(){ //I - 73
  digitalWrite(R1F, HIGH);
  digitalWrite(R3F, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void irEsquerdaTras(){ //H - 72
  digitalWrite(R1F, HIGH);
  digitalWrite(R2T, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void irDireitaTras(){ //J - 74
  digitalWrite(R1T, HIGH);
  digitalWrite(R2F, HIGH);
  digitalWrite(R3T, HIGH);
  delay(tempo);
  parar();
}
void irEsquerda(){
  digitalWrite(R1T, HIGH);
  digitalWrite(R2F, HIGH);
  digitalWrite(R3T, HIGH);
  digitalWrite(R4F, HIGH);
  delay(tempo);
  parar();
}
void irDireita(){
  digitalWrite(R1F, HIGH);
  digitalWrite(R2T, HIGH);
  digitalWrite(R3F, HIGH);
  digitalWrite(R4T, HIGH);
  delay(tempo);
  parar();
}
void parar(){
  digitalWrite(R1F, LOW);
  digitalWrite(R1T, LOW);
  digitalWrite(R2F, LOW);
  digitalWrite(R2T, LOW);
  digitalWrite(R3F, LOW);
  digitalWrite(R3T, LOW);
  digitalWrite(R4F, LOW);
  digitalWrite(R4T, LOW);
}
void acender(){
  digitalWrite(LED, HIGH);
}
void apagar(){
  digitalWrite(LED, LOW);
}

void loop() {
  if(Serial.available() >0 ){
    comando = Serial.read();
    if(comando == 87){// 87 = B, 119 = b
      if(digitalRead(sensorTras) == 1){
        irFrente();
      }else
      if(digitalRead(sensorFrente) == 1){
        irTras();
      }else
      if(sonarEsquerdo.ping_cm() != 0 and sonarDireito.ping_cm() == 0){
        irEsquerda();
      }else
      if(sonarDireito.ping_cm() != 0 and sonarEsquerdo.ping_cm() == 0){
        irDireita();
      }else
      if(sonarEsquerdo.ping_cm() != 0 and sonarDireito.ping_cm() != 0){
        irFrente();
      }
    }
    else{
      if(comando == 70){//F
        irFrente();
      }else
      if(comando == 82){//B
        irDireita();
      }else
      if(comando == 76){//L
        irEsquerda();
      }else
      if(comando == 66){//R
        irTras();
      }else 
      if(comando == 73){
        irDireitaFrente();
      }else
      if(comando == 71){
        irEsquerdaFrente();
      }else
      if(comando == 74){
        irDireitaTras();
      }else
      if(comando == 72){
        irDireitaFrente();
      }else
      if(true){
        acender();
      }
    }
   }
  }

