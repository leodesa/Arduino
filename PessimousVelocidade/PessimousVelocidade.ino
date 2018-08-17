#include <NewPing.h>
#include <HC05.h>

#define DT 9
#define DF 8
#define ET 11
#define EF 10

//INT1 - DIREITO TRÁS - DT
//INT2 - DIREITO FRENTE - DF
//INT3 - ESQUERDO TRÁS - EF
//INT4 - ESQUERDO FRENTE - ET

int comando;
int tempo = 25; //MS
int ultrasom = 0;
int velocidade =0;

void setup() {
  pinMode(DF, OUTPUT);
  pinMode(DT, OUTPUT);
  pinMode(ET, OUTPUT);
  pinMode(EF, OUTPUT);

  digitalWrite(DF, LOW);
  digitalWrite(DT, LOW);
  digitalWrite(ET, LOW);
  digitalWrite(EF, LOW);

  Serial.begin(38400);
}
void irFrente() {
  analogWrite(DF, velocidade);
  analogWrite(EF, velocidade);
  delay(25);
  parar();
}
void irTras() {
  analogWrite(DT, velocidade);
  analogWrite(ET, velocidade);
  delay(25);
  parar();
}
void irDireitaFrente() { //I - 73
  analogWrite(EF, velocidade);
  delay(25);
  parar();
}
void irEsquerdaFrente() { //G - 71
  analogWrite(DF, velocidade);
  delay(25);
  parar();
}
void irDireitaTras() { //J - 74
  analogWrite(DT, velocidade);
  delay(25);
  parar();
}
void irEsquerdaTras() { //H - 72
  analogWrite(ET, velocidade);
  delay(25);
  parar();
}
void irEsquerda() {
  analogWrite(ET, velocidade);
  analogWrite(DF, velocidade);
  delay(25);
  parar();
}
void irDireita() {
  analogWrite(EF, velocidade);
  analogWrite(DT, velocidade);
  delay(25);
  parar();
}
void parar() {
  digitalWrite(DT, LOW);
  digitalWrite(EF, LOW);
  digitalWrite(DF, LOW);
  digitalWrite(ET, LOW);
}

void loop() {
  if (Serial.available() > 0 ) {
    comando = Serial.read();
    Serial.println(comando);
    if (comando == 70) {
      irFrente();
    } else if (comando == 82) {
      irDireita();
    } else if (comando == 76) {
      irEsquerda();
    } else if (comando == 66) {
      irTras();
    } else if (comando == 73) {
      irDireitaFrente();
    } else if (comando == 71) {
      irEsquerdaFrente();
    } else if (comando == 74) {
      irDireitaTras();
    } else if (comando == 72) {
      irDireitaFrente();
    } else if (comando == 48) {
      velocidade = 0;
    } else if (comando == 49) {
      velocidade = 28;
    } else if (comando == 50) {
      velocidade = 56;
    } else if (comando == 51) {
      velocidade = 84;
    } else if (comando == 52) {
      velocidade = 112;
    } else if (comando == 53) {
      velocidade = 140;
    } else if (comando == 54) {
      velocidade = 168;
    } else if (comando == 55) {
      velocidade = 196;
    } else if (comando == 56) {
      velocidade = 224;
    } else if (comando == 57) {
      velocidade = 240;
    } else if (comando == 113) {
      velocidade = 255;
    }
  }
}
