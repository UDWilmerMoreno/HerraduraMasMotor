#include <Arduino.h>
#define PinInterrupcion0 3
volatile int contador0 = 0;
int contadoranteror0 = 0;
#define M1Adelante 8
#define M1Atras 9
int TiempoEjecucion = 17;
char dato;

void interrupcion0(){
  contador0++;
}

void setup()
{
  Serial.begin(115200);
  pinMode(M1Adelante, OUTPUT);
  pinMode(M1Atras, OUTPUT);
  Serial.print(contador0);
  attachInterrupt(digitalPinToInterrupt(PinInterrupcion0), interrupcion0, RISING);
}

void Adelante()
{
  digitalWrite(M1Adelante, HIGH);
  digitalWrite(M1Atras, LOW);
}

void Atras()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, HIGH);
}

void Derecha()
{
  digitalWrite(M1Adelante, HIGH);
  digitalWrite(M1Atras, LOW);
}

void Izquierda()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, HIGH);
}
void Parar()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, LOW);
}

void loop()
{
  Parar();
  if (contador0 != contadoranteror0)
  {
    Serial.print(contador0);
    contadoranteror0 = contador0;
  }
  if (Serial.available() > 0)
  {
    dato = Serial.read();
    switch (dato)
    {
    case 'w':
      Serial.println("Posicion: w= Adelante");
      contador0 = 0;
      Adelante();
      while (contador0 < TiempoEjecucion)
      { 
      }
      break;
    case 's':
      Serial.println("Posicion: s= Atras");
      contador0 = 0;
      Atras();
      delay(TiempoEjecucion);
      break;
    case 'd':
      Serial.println("Posicion: d= Derecha");
      contador0 = 0;
      Derecha();
      delay(TiempoEjecucion);
      break;
    case 'a':
      Serial.println("Posicion: a= Izquierda");
      contador0 = 0;
      Izquierda();
      delay(TiempoEjecucion);
      break;
    case 'q':
      Serial.println("Posicion: q= Parar");
      contador0 = 0;
      Parar();
      delay(500);
      break;
    case 'z':
      Serial.println("TiempoDeEjecucion: z= 1s");
      TiempoEjecucion = 2;
      break;
    case 'x':
      Serial.println("TiempoDeEjecucion: x= 2s");
      TiempoEjecucion = 7;
      break;
    case 'c':
      Serial.println("TiempoDeEjecucion: c= 3s");
      TiempoEjecucion = 12;
      break;
    case 'v':
      Serial.println("TiempoDeEjecucion: v= 4s");
      TiempoEjecucion = 17;
      break;
    case 'b':
      Serial.println("TiempoDeEjecucion: b= 5s");
      TiempoEjecucion = 22;
      break;
    case 'n':
      Serial.println("TiempoDeEjecucion: n= 6s");
      TiempoEjecucion = 27;
      break;
    case 'm':
      Serial.println("TiempoDeEjecucion: m= 7s");
      TiempoEjecucion = 32;
      break;
    default:
      Serial.println("Caracter no reconocido");
      break;
    }
  }
}