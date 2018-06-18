#include <NewPing.h>
#include <HC05.h>

#define DT 4
#define DF 5
#define ET 6
#define EF 7

//INT1 - DIREITO TRÁS - DT
//INT2 - DIREITO FRENTE - DF
//INT3 - ESQUERDO TRÁS - EF
//INT4 - ESQUERDO FRENTE - ET

int comando;
int tempo = 25; //MS
int ultrasom = 0;

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
  digitalWrite(DF, HIGH);
  digitalWrite(EF, HIGH);
  delay(25);
  parar();
}
void irTras() {
  digitalWrite(DT, HIGH);
  digitalWrite(ET, HIGH);
  delay(25);
  parar();
}
void irDireitaFrente() { //I - 73
  digitalWrite(EF, HIGH);
  delay(25);
  parar();
}
void irEsquerdaFrente() { //G - 71
  digitalWrite(DF, HIGH);
  delay(25);
  parar();
}
void irDireitaTras() { //J - 74
  digitalWrite(DT, HIGH);
  delay(25);
  parar();
}
void irEsquerdaTras() { //H - 72
  digitalWrite(ET, HIGH);
  delay(25);
  parar();
}
void irEsquerda() {
  digitalWrite(ET, HIGH);
  digitalWrite(DF, HIGH);
  delay(25);
  parar();
}
void irDireita() {
  digitalWrite(EF, HIGH);
  digitalWrite(DT, HIGH);
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
    }
  }
}
